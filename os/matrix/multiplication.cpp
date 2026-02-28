/* includes */
// #include "stdafx.h"
#include <chrono> // measure the tile via using some functions included here
#include <ctime>
#include <iomanip>
#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <omp.h>    //openMP
#include <thread>   // std::thread
#include <vector>

/* namespaces */
using namespace std;
using namespace std::chrono; // for the   high_resolution_clock

/* global variable declarations */
/**
 *  mutex for critical section
 */
mutex mtx;
const unsigned long long int Dim = 1000;
vector<vector<unsigned long long int>> matrixA;
vector<vector<unsigned long long int>> matrixB;
/**
 *  calculated sequentially
 */
vector<vector<unsigned long long int>> matrixC;
/**
 *  calculated in parallel using std::thread
 */
vector<vector<unsigned long long int>> matrixD;
/**
 *  calculated parallel using openMP
 */
// vector<vector<unsigned long long int>> matrixE;

/* function declatations */
void sequential_Matrix_Addition();
void parallel_Matrix_Addition(int from, int to);
void sequential_Matrix_Multiplication();
void parallel_Matrix_Multiplication(int from, int to);
void openMP_Matrix_Addition();
void print10X10(const vector<vector<unsigned long long int>> &matrix);
void constructMatrix(const int &Dim,
                     vector<vector<unsigned long long int>> &matrix);
unsigned long long int dotProduct(int row, int column);

/**
 * Main
 */
int main() {
  srand(time(nullptr));
  constructMatrix(Dim, matrixA);
  constructMatrix(Dim, matrixB);
  constructMatrix(Dim, matrixC);
  constructMatrix(Dim, matrixD);
  // initiializing vectors
  int count = 0;
  for (int row = 0; row < Dim; row++)
    for (int column = 0; column < Dim; column++) { // just arbitrary numbers
      matrixA[row][column] = rand() % 50001;
      matrixB[row][column] = rand() % 50001;
      matrixC[row][column] = 0;
      matrixD[row][column] = 0;
      // matrixE[row][column] = 0;
    }
  // print the first 3 vectors for testing
  print10X10(matrixA);
  print10X10(matrixB);
  print10X10(matrixC);

  // sequential matrix mulitplication
  cout << "Start Sequential Operation " << endl;
  auto start = high_resolution_clock::now();
  sequential_Matrix_Multiplication();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Sequential time: " << duration.count() << endl;

  // Parallelmatrix Addition

  int from = 0;
  int to = 0;
  int workload = Dim / 4;
  int dim1 = workload;
  int dim2 = workload * 2;
  int dim3 = workload * 3;
  int dim4 = Dim - 1;
  /*
  cout << workload << endl;
  cout << dim1 << endl;
  cout << dim2 << endl;
  cout << dim3 << endl;
  cout << dim4 << endl;
  */

  cout << "Start Parallel Operation Using std::theard" << endl;
  start = high_resolution_clock::now();
  // creating threads and dividing the workload
  std::thread th1(parallel_Matrix_Multiplication, 0, dim1);
  std::thread th2(parallel_Matrix_Multiplication, (dim1 + 1), dim2);
  std::thread th3(parallel_Matrix_Multiplication, (dim2 + 1), dim3);
  std::thread th4(parallel_Matrix_Multiplication, (dim3 + 1), dim4);

  th1.join();
  th2.join();
  th3.join();
  th4.join();

  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Parallel time in microseconds: " << duration.count() << endl;

  ////openmp**********************************
  // cout << "Start Parallel Operation Using openMP" << endl;
  // start = high_resolution_clock::now();
  // openMP_Matrix_Addition();

  // stop = high_resolution_clock::now();
  // duration = duration_cast<microseconds>(stop - start);
  // cout << "Parallel time in microseconds with openMP: " << duration.count()
  // << endl;
  ////****************************************

  print10X10(matrixC);
  print10X10(matrixD);

  return 0;
}

/* function implementations */

/**
 * go through all rows and columns and preform a dot product for each entry
 */
void sequential_Matrix_Multiplication() {
  for (int row = 0; row < matrixD.size(); ++row) {
    for (int column = 0; column < matrixD.size(); ++column) {
      matrixC[row][column] = dotProduct(row, column);
    }
  }
}

/**
 * go through rows within limit, and all colums within those and perform a dot
 * product for each entry
 */
void parallel_Matrix_Multiplication(int from, int to) {
  for (int row = from; row <= to; ++row) {
    for (int column = 0; column < matrixD.size(); ++column) {
      matrixD[row][column] = dotProduct(row, column);
    }
  }
}

/**
 * go through all rows and colums and add each entry from matrixA and matrixB
 * into matrixC
 * preconditions: matrixA, matrixB, and matrixC are not null and all have the
 * same size
 */
void sequential_Matrix_Addition() {
  for (int row = 0; row < matrixD.size(); ++row) {
    for (int column = 0; column < matrixD.size(); ++column) {

      matrixC[row][column] = (matrixA[row][column] + matrixB[row][column]);
    }
  }
}

/**
 * go through rows within limit and all colums and add each entry from matrixA
 * and matrixB into matrixD
 * preconditions: matrixA, matrixB, and matrixD are not null and all have the
 * same size
 */
void parallel_Matrix_Addition(int from, int to) {
  for (int row = from; row <= to; ++row) {
    for (int column = 0; column < matrixD.size(); ++column) {
      matrixD[row][column] = (matrixA[row][column] + matrixB[row][column]);
    }
  }
}

/**
 * this function prints the first and last 10 rows and columns, or the whole
 * matrix.
 */
void print10X10(const vector<vector<unsigned long long int>> &matrix) {
  unsigned long long int count = 10 < matrix.size() ? 10 : matrix.size();
  for (int row = 0; row < count; row++) {
    for (int column = 0; column < 10; column++) {
      cout << setw(7) << matrix[row][column] << " ";
    }
    cout << endl;
  }
  cout << "--------------------------------" << endl;
}

/**
 * fill matrix with Dim rows and colums
 */
void constructMatrix(const int &Dim,
                     vector<vector<unsigned long long int>> &matrix) {
  for (int i = 0; i < Dim; i++) {
    matrix.push_back(vector<unsigned long long int>(Dim)); // Add an empty row
  }
}

/**
 * multiply a 1xN and an Nx1 "matricies" to get a singlar number
 */
unsigned long long int dotProduct(int row, int column) {
  unsigned long long int accumulator = 0;
  for (int i = 0; i < matrixA.size(); i++) {
    accumulator += matrixA[row][i] * matrixB[i][column];
  }
  return accumulator;
}

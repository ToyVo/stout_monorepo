#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fill(int **p, int rowSize, int columnSize);
void print(int **p, int rowSize, int columnSize);

int main() {
  int **board;
  int rows, columns;

  cout << "Enter the number of rows and columns(separted by a space): " << endl;
  cin >> rows >> columns;
  cout << endl;

  board = new int *[rows];

  for (int i = 0; i < rows; i++) {
    board[i] = new int[columns];
  }

  fill(board, rows, columns);
  cout << "Board: " << endl;

  print(board, rows, columns);

  return EXIT_SUCCESS;
}

void fill(int **p, int rowSize, int columnSize) {
  for (int i = 0; i < rowSize; i++) {
    cout << "Enter " << columnSize << " number(s) for row number " << i
         << " (separated by a space): ";

    for (int j = 0; j < columnSize; j++)
      cin >> p[i][j];
    cout << endl;
  }
}
void print(int **p, int rowSize, int columnSize) {
  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < columnSize; j++)
      cout << setw(5) << p[i][j];
    cout << endl;
  }
}

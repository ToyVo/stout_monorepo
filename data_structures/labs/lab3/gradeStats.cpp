// Problem 2
// Collin Diekvoss

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getData(ifstream &inputFile, vector<string> &roster, vector<double> &list);
double findMean(vector<double> list);
double findStdDev(vector<double> list);
double maxScore(vector<double> list);
void printSummary(vector<string> st, vector<double> list, double mean,
                  double std, double max);

int main() {
  // (1) two vectors: a vector of string named as students for storing students'
  // names a vector of double named as grades for storing students' scores
  vector<string> students;
  vector<double> grades;

  // (2) create ifstream object infile and use it to open a data file
  ifstream infile;
  infile.open("data.txt");
  if (!infile) {
    cout << "file not found" << endl;
    return 1;
  }

  // (3) call function getData()
  // this function reads a data file and store the information into two vectors.
  getData(infile, students, grades);

  // (4) call three functions for statistics:
  // findMean(), findStdDev(), maxScore()
  double mean, std, max;
  mean = findMean(grades);
  std = findStdDev(grades);
  max = maxScore(grades);

  // (5) call function printSummary()
  printSummary(students, grades, mean, std, max);

  // (6) close the file
  infile.close();

  return 0;
}

// implement each of the following functions:
// getData(), findMean(), findStdDev(), maxScore(), printSummary()
void getData(ifstream &inputFile, vector<string> &roster,
             vector<double> &list) {
  // variables to store the values read in
  string name;
  double grade;

  // read and push values
  while (inputFile >> name) {
    roster.push_back(name);
    inputFile >> grade;
    list.push_back(grade);
  }
}

// calculate average
double findMean(vector<double> list) {
  double total = 0;
  for (int i = 0; i < list.size(); i++) {
    total += list[i];
  }
  total = total / list.size();
  return total;
}

// calculate std variation by adding up all values minus the average, square
// that and then divide everything by n, and finally square root everything
double findStdDev(vector<double> list) {
  double mean = findMean(list);
  double std = 0;
  for (int i = 0; i < list.size(); i++) {
    std += (list[i] - mean) * (list[i] - mean);
  }
  std = std / list.size();
  std = sqrt(std);
}

// find the top score
double maxScore(vector<double> list) {
  double max = 0;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] > max) {
      max = list[i];
    }
  }
  return max;
}

// print everything
void printSummary(vector<string> st, vector<double> list, double mean,
                  double std, double max) {
  cout << "Class Mean: " << mean << endl;
  cout << "Class Standard Deviation: " << std << endl;
  cout << "Highest Score: " << max << endl;
  cout << "Students with scores above mean: " << endl;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] > mean)
      cout << st[i] << endl;
  }
  cout << "Student(s) with highest score: " << endl;
  ;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] == max)
      cout << st[i] << endl;
  }
}
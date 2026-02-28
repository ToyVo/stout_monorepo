#include "MovieData.h"
#include <iostream>
#include <string>

using namespace std;

MovieData::MovieData() {
  setTitle("NULL");
  setDirector("NULL");
  setYear(0);
  setTime(0);
  setCost(0);
  setRevenue(0);
}

MovieData::MovieData(string t, string d, int y, double n, double c, double r) {
  setTitle(t);
  setDirector(d);
  setYear(y);
  setTime(n);
  setCost(c);
  setRevenue(r);
}

void MovieData::setTitle(string t) { title = t; }

void MovieData::setDirector(string d) { director = d; }

void MovieData::setYear(int y) { year = y; }

void MovieData::setTime(double n) { time = n; }

void MovieData::setCost(double c) { cost = c; }

void MovieData::setRevenue(double r) { revenue = r; }

string MovieData::getTitle() { return title; }

string MovieData::getDirector() { return director; }

int MovieData::getYear() { return year; }

double MovieData::getTime() { return time; }

double MovieData::getCost() { return cost; }

double MovieData::getRevenue() { return revenue; }

void MovieData::print() {
  cout << "Title: " << title << endl;
  cout << "Director: " << director << endl;
  cout << "Release Year: " << year << endl;
  cout << "Runtime: " << time << " minutes" << endl;
  cout << "Cost: $" << cost << endl;
  cout << "First Year Revenue: $" << revenue << endl;
  cout << "Profit of: $" << (revenue - cost) << endl;
  cout << endl;
}
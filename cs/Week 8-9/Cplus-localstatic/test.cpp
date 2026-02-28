
int main() {
  // Call the showStatic function three times
  showStatic();
  showStatic();
  showStatic();

  system("pause");
  return 0;
}

void showStatic() {
  static int numCalls = 1; // Static local variable
  cout << "This function has been called " << numCalls << " times." << endl;
  numCalls++;
}
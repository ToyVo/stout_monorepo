// Example0ThreadingInC.cpp : This file contains the 'main' function. Program
// execution begins and ends there.

#include <iostream>
#include <thread>
using namespace std;

// this function will work as a runner and called by the new thread
void greeting(void) {
  cout << "Hello, CS442 Students!\n";
  cout << "This is thread No " << this_thread::get_id() << endl;
}

int main(void) {
  // creates a thread and starts it with the specified function
  thread myThread(greeting);

  // needed so that the program does not terminate before the stared thread
  // finishes. That is, make the main thread wait for the new thread.
  myThread.join();
  cout << "by main thread  " << this_thread::get_id() << endl;
  return 0;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
  pid_t pid;
  char *commandString[2];
  string command = "ls";   // this is the ls unix command
  string argument1 = "-l"; // this is the argument for the ls
  commandString[0] = (char *)command.c_str();
  // this is how to convert a string variable to a c_string
  commandString[1] = (char *)argument1.c_str();
  pid = fork();
  if (pid == 0) {
    // means you are inside the child process
    if (execvp(commandString[0], commandString) < 0) {
      cerr << "*** ERROR: exec failed\n";
      exit(1);
    }
    cout << "A New Child was created\n ";

  } else if (pid < 0) {
    // no new child was created (failed)
    cout << "No New Child Was created\n ";
    return 0;
  } else {
    // means you are inside the parent process
    wait(0); // wait for child to finish
    cout << "I am the parent\n";
  }
  return 0;
}
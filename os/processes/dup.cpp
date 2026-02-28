#include <iostream>
#include <stdio.h>
#include <stdlib.h> /* exit, EXIT_FAILURE */
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
  string message = "Passwrd is UW-Stout19";
  int fd[2];
  pid_t childpid;

  if (pipe(fd) < 0) // create a pipe
    exit(1);        // error. No pipe was created.
  if ((childpid = fork()) == -1) {
    perror("fork did not work; Sorry!");
    exit(1);
  }

  if (childpid == 0) {
    /* Child process closes up input side of pipe */
    close(fd[0]);
    /* Send "string" through the output side of pipe */
    dup2(fd[1], 1);
    cout << message << endl;
    exit(0);
  } else {
    wait(NULL);
    /* Parent process closes up output side of pipe */
    close(fd[1]);
    /* Read in a string from the pipe */

    string comingMessage;
    int orgSTDIN = dup(0); // store the original input FD
    dup2(fd[0], 0);
    getline(cin, comingMessage);

    cout << "From Parent: Received string: " << comingMessage << endl;

    dup2(orgSTDIN, 0); /// get the input FD back to normal
                       // testing the STD in and out
    cout << "Please enter ID No -> ";
    int ID;
    cin >> ID;
    cout << ID << endl;
  }
  return (0);
}
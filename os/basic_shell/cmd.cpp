//
// Created by Collin Diekvoss on 3/4/20.
//

#include "cmd.hpp"
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>

PipeType eval_cmd(const std::string &input_cmd, std::string &cmd1,
                  std::string &cmd2) {
  cmd1 = "";
  cmd2 = "";
  std::istringstream stream(input_cmd);
  std::string token;
  PipeType pipeType = NOTHING;
  while (stream >> token) {
    if (pipeType == NOTHING) {
      pipeType = is_token_pipeable(token);
      if (pipeType == NOTHING) {
        cmd1 += token;
        cmd1 += " ";
      }
    } else {
      cmd2 += token;
      cmd2 += " ";
    }
  }
  return pipeType;
}

void exe_cmd(const std::string &cmd) {
  char *command[get_number_of_tokens(cmd) + 1];
  convert_str_to_c_string_array(cmd, command);
  pid_t child_pid;
  child_pid = fork();
  if (child_pid == 0) {
    if (execvp(command[0], command) < 0) {
      perror(command[0]);
      exit(EXIT_FAILURE);
    }
  } else if (child_pid < 0) {
    perror("Fork Failed, no new child was created");
    exit(EXIT_FAILURE);
  } else {
    waitpid(child_pid, nullptr, 0);
  }
}

void pipe_cmd(const std::string &cmd1, const std::string &cmd2) {
  char *command1[get_number_of_tokens(cmd1) + 1];
  char *command2[get_number_of_tokens(cmd2) + 1];
  convert_str_to_c_string_array(cmd1, command1);
  convert_str_to_c_string_array(cmd2, command2);
  int fd[2];
  pipe(fd);
  pid_t pid;

  if (fork() == 0) {
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);

    if (execvp(command2[0], command2) < 0) {
      perror("execvp failed");
      exit(EXIT_FAILURE);
    }

  } else if ((pid = fork()) == 0) {
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);

    if (execvp(command1[0], command1) < 0) {
      perror("execvp failed");
      exit(EXIT_FAILURE);
    }

  } else
    waitpid(pid, nullptr, 0);
}

void redirect_in_cmd(const std::string &cmd, const std::string &filename) {
  // convert command and filename to cstrings
  char *command[get_number_of_tokens(cmd) + 1];
  char *file[get_number_of_tokens(filename) + 1];
  convert_str_to_c_string_array(cmd, command);
  convert_str_to_c_string_array(filename, file);

  // get file descriptors
  int stdin = dup(STDIN_FILENO);
  int fd = open(file[0], O_RDONLY);
  if (fd < 0) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }

  // execute command
  pid_t child_pid = fork();
  if (child_pid == 0) {
    dup2(fd, STDIN_FILENO);
    if (execvp(command[0], command) < 0) {
      perror(command[0]);
      exit(EXIT_FAILURE);
    }
  } else if (child_pid < 0) {
    perror("Fork Failed, no new child was created");
    exit(EXIT_FAILURE);
  } else {
    waitpid(child_pid, nullptr, 0);
    dup2(stdin, STDIN_FILENO);
    close(fd);
  }
}

void redirect_out_cmd(const std::string &cmd, const std::string &filename) {
  // convert command and filename to cstrings
  char *command[get_number_of_tokens(cmd) + 1];
  char *file[get_number_of_tokens(filename) + 1];
  convert_str_to_c_string_array(cmd, command);
  convert_str_to_c_string_array(filename, file);

  // get file descriptors
  int stdout = dup(STDOUT_FILENO);
  int fd = open(file[0], O_WRONLY | O_CREAT, 0666);
  if (fd < 0) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }

  // execute command
  pid_t child_pid = fork();
  if (child_pid == 0) {
    dup2(fd, STDOUT_FILENO);
    if (execvp(command[0], command) < 0) {
      perror(command[0]);
      exit(EXIT_FAILURE);
    }
  } else if (child_pid < 0) {
    perror("Fork Failed, no new child was created");
    exit(EXIT_FAILURE);
  } else {
    waitpid(child_pid, nullptr, 0);
    dup2(stdout, STDOUT_FILENO);
    close(fd);
  }
}

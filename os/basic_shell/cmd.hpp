//
// Created by Collin Diekvoss on 3/4/20.
//

#ifndef ASSIGNMENT4_CMD_HPP
#define ASSIGNMENT4_CMD_HPP

#include "util.hpp"
#include <string>

/**
 * Splits command into two parts, the command and a second command or file name
 * @param input_cmd
 * @param cmd1
 * @param cmd2
 * @return
 */
PipeType eval_cmd(const std::string &input_cmd, std::string &cmd1,
                  std::string &cmd2);

/**
 * Pipes the output of the first command to the input of the second
 * @param cmd1
 * @param cmd2
 */
void pipe_cmd(const std::string &cmd1, const std::string &cmd2);

/**
 * read input to a command from stdin to some file
 * @param cmd
 * @param filename
 */
void redirect_in_cmd(const std::string &cmd, const std::string &filename);

/**
 * redirect output from some command to a file (overwrite)
 * @param cmd
 * @param filename
 */
void redirect_out_cmd(const std::string &cmd, const std::string &filename);

/**
 * execute a command with any arguments
 * @param cmd
 */
void exe_cmd(const std::string &cmd);

#endif // ASSIGNMENT4_CMD_HPP

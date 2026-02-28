//
// Created by Collin Diekvoss on 3/4/20.
//

#ifndef ASSIGNMENT4_HISTORY_HPP
#define ASSIGNMENT4_HISTORY_HPP

#include <string>

/**
 * writes whatever command was entered into a file, weather it was valid or not
 * @param cmd
 */
void write_history(const std::string &cmd);

/**
 * outputs whatever is in history to the screen
 */
void read_history();

#endif // ASSIGNMENT4_HISTORY_HPP

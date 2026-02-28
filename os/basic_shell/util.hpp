//
// Created by Collin Diekvoss on 3/4/20.
//

#ifndef ASSIGNMENT4_UTIL_HPP
#define ASSIGNMENT4_UTIL_HPP

#include <string>

/**
 * represents the different types of commands that could be put in
 */
enum PipeType { PIPE, REDIRECT_IN, REDIRECT_OUT, NOTHING };

/**
 * convert the string to a null terminated c string array
 * @param cmd
 * @param cStringArray
 */
void convert_str_to_c_string_array(const std::string &cmd, char **cStringArray);

/**
 * identify the token if it is a redirect or pipe
 * @param token
 * @return
 */
PipeType is_token_pipeable(const std::string &token);

/**
 * get the number of tokens in the command, used to initialize the size of the
 * c string array
 * @param cmd
 * @return
 */
int get_number_of_tokens(const std::string &cmd);

#endif // ASSIGNMENT4_UTIL_HPP

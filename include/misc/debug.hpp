#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>
#include <csignal>
#include "misc/definitions.hpp"

/**
 * A pure print statement, meant for only debugging. 
 * 
 * Should not be found in final version of source code.
 */
void print_(const std::string &text);

/**
 * Prints a 64 bit bitboard to stdout, in chessboard order.
 */
void dump64(u64 x);

/**
 * Prints a 32 bit int to stdout, in order.
 */
void dump32(int x);

#endif

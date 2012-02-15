/*
 * Exceptions.cpp
 *
 *  Created on: 11-02-2012
 *      Author: skoczeq
 */

#include "Exceptions.h"

NumberException::NumberException()
{

}

FileError::FileError()
{

}

void handler(int sig)
{
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);
  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, 2);
  exit(1);
}

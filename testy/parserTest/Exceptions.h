/*
 * Exceptions.h
 *
 *  Created on: 11-02-2012
 *      Author: skoczeq
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>
#include <cstdio>
#include <execinfo.h>
#include <csignal>
#include <cstdlib>

class NumberException: public std::exception
{
public:
	NumberException();
};

class FileError: public std::exception
{
public:
	FileError();
};

void handler(int sig);

#endif /* EXCEPTIONS_H_ */

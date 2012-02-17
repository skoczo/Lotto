/*
 * Trojka.h
 *
 *  Created on: 16-02-2012
 *      Author: skoczeq
 */

#ifndef TROJKA_H_
#define TROJKA_H_

#include <iostream>
#include <sstream>

class Trojka
{
private:
	int a, b, c;
public:
	Trojka(int a, int b, int c);
	virtual ~Trojka();

	int getA(){return a;}
	int getB(){return b;}
	int getC(){return c;}

	const std::string toString();
};

#endif /* TROJKA_H_ */

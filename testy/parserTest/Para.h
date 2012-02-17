/*
 * Para.h
 *
 *  Created on: 15-02-2012
 *      Author: skoczeq
 */

#ifndef PARA_H_
#define PARA_H_

#include <iostream>
#include <sstream>

class Para
{
private:
	int a, b;
public:
	Para(int a, int b);
	virtual ~Para();
	int operator==(const Para &p)const
	{
		return a == p.getA() && b == p.getB();
	}
	const std::string toString();

	int getA() const
	{
		return a;
	}
	int getB() const
	{
		return b;
	}
};

#endif /* PARA_H_ */

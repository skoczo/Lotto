/*
 * Para.cpp
 *
 *  Created on: 15-02-2012
 *      Author: skoczeq
 */

#include "Para.h"

Para::Para(int a, int b)
{
	if (a > b)
	{
		this->b = a;
		this->a = b;
	}
	else
	{
		this->a = a;
		this->b = b;
	}

}

Para::~Para()
{
	// TODO Auto-generated destructor stub
}

const std::string Para::toString()
{
	std::stringstream ss;
	std::string str;

	ss<<a;
	str = ss.str();
	ss.str("");

	ss<<b;
	str += ", " + ss.str();

	return str;
}

/*
 * Trojka.cpp
 *
 *  Created on: 16-02-2012
 *      Author: skoczeq
 */

#include "Trojka.h"

Trojka::Trojka(int a, int b, int c)
{
	int tab[] =
	{ a, b, c };

	bool przestawiono = true;
	while (przestawiono)
	{
		przestawiono = false;

		for (int i = 0; i < 2; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				przestawiono = true;
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}

	this->a = tab[0];
	this->b = tab[1];
	this->c = tab[2];
}

Trojka::~Trojka()
{
	// TODO Auto-generated destructor stub
}

const std::string Trojka::toString()
{
	std::stringstream ss;
	std::string str;

	ss << a;
	str = ss.str();
	ss.str("");

	ss << b;
	str += ", " + ss.str();

	ss.str("");

	ss << c;
	str += ", " + ss.str();

	return str;
}

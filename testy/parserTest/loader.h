#ifndef LOADER_H
#define LOADER_H

#include <QList>
#include <QFile>
#include <sstream>
#include "sample.h"
#include "lotto.h"
#include "Exceptions.h"

extern bool debug;

class Loader
{
private:
	QList<Sample*> list;

public:
	Loader();
	QList<Sample*> getList()
	{
		return list;
	}
private:
	int getNumber(unsigned int &i, std::string &data);
	std::string getData(unsigned int &i, std::string &data);
	int* getNumbers(unsigned int &i, std::string &data);
};

#endif

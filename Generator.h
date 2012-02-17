/*
 * Generator.h
 *
 *  Created on: 17-02-2012
 *      Author: skoczeq
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <QMap>
#include <QString>
#include <iostream>
#include "Trojka.h"
#include "loader.h"

class Loader;

extern bool debug;

class Generator
{
public:
	Generator();
	virtual ~Generator();
	static void generojTrojki(QMap<QString, int> *trojkiMap, Loader *loader);
	static int iloscKombinacji(int iloscElementow, int zbior);
	static int silnia(int liczba);
	static void generojPary(QMap<QString, int> *paryMap, Loader *loader);
};

#endif /* GENERATOR_H_ */

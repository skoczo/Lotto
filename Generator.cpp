/*
 * Generator.cpp
 *
 *  Created on: 17-02-2012
 *      Author: skoczeq
 */

#include "Generator.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::generojTrojki(QMap<QString, int> *trojkiMap, Loader *loader)
{
    int ilosc = iloscKombinacji(3, 49);

    if(debug)
    	std::cout << ilosc << std::endl;

	for (int i = 1; i < 48; i++)
		{
			for (int j = i + 1; j <= 48; j++)
			{
				for (int k = j + 1; k <= 49; k++)
				{
					trojkiMap->insert(QString(Trojka(i, j, k).toString().c_str()),
							0);
				}
			}
		}

		if (trojkiMap->size() != ilosc)
		{
			std::cout << "Error: Błędna ilość par!!!! \nJest:" << trojkiMap->size()
					<< "\nA powinno:" << ilosc << std::endl;
			return;
		}

		for (int i = 0; i < loader->getList().size(); i++)
		{
			int *numbers = loader->getList().at(i)->getNumbers();

			for (int j = 0; j < 4; j++)
			{
				for (int k = j + 1; k < 5; k++)
				{
					for (int l = k + 1; l < 6; l++)
					{
						if (numbers[j] > 49 || numbers[j] < 1 || numbers[k] > 49
								|| numbers[k] < 1 || numbers[l] > 49 || numbers[l]
								< 1)
						{
							throw NumberException();
						}
						QMap<QString, int>::iterator
								iter =
										trojkiMap->find(
												QString(
														Trojka(numbers[j],
																numbers[k],
																numbers[l]).toString().c_str()));

						if (iter != trojkiMap->end())
						{
							iter.value()++;
						}
					}
				}
			}
		}

		if (debug)
		{
			std::cout << "Pary\n";
			for (QMap<QString, int>::iterator it = trojkiMap->begin(); it
					!= trojkiMap->end(); it++)
			{
				std::cout << it.key().toStdString() << it.value() << std::endl;
			}
		}
}

int Generator::iloscKombinacji(int iloscElementow, int zbior)
{
	unsigned int wynik = 1;

	for (int i = zbior; i > (zbior - iloscElementow); i--)
	{
		wynik *= i;
	}

	return wynik / silnia(iloscElementow);
}

int Generator::silnia(int liczba)
{
	unsigned int i = 1;

	for (int j = 2; j <= liczba; j++)
	{
		i *= j;
	}

	return i;
}

void Generator::generojPary(QMap<QString, int> *paryMap, Loader *loader)
{
	int ilosc = iloscKombinacji(2, 49);
	std::cout << ilosc << std::endl;

	for (int i = 1; i < 49; i++)
		{
			for (int j = i + 1; j <= 49; j++)
			{
				paryMap->insert(QString(Para(i, j).toString().c_str()), 0);
			}
		}

		if (paryMap->size() != ilosc)
		{
			std::cout << "Error: Błędna ilość par!!!! \nJest:" << paryMap->size()
					<< "\nA powinno:" << ilosc << std::endl;
			return;
		}

		for (int i = 0; i < loader->getList().size(); i++)
		{
			int *numbers = loader->getList().at(i)->getNumbers();

			for (int j = 0; j < 5; j++)
			{
				for (int k = j + 1; k < 6; k++)
				{
					if (numbers[j] > 49 || numbers[j] < 1 || numbers[k] > 49
							|| numbers[k] < 1)
					{
						throw NumberException();
					}
					QMap<QString, int>::iterator
							iter =
									paryMap->find(
											QString(
													Para(numbers[j], numbers[k]).toString().c_str()));

					if (iter != paryMap->end())
					{
						iter.value()++;
					}
				}
			}
		}

		if (debug)
		{
			std::cout << "Pary\n";
			for (QMap<QString, int>::iterator it = paryMap->begin(); it
					!= paryMap->end(); it++)
			{
				std::cout << it.key().toStdString() << it.value() << std::endl;
			}
		}
}

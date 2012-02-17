#include "parsertest.h"

ParserTest::ParserTest()
{
	Loader *l = new Loader();

	Test *test = new Test();

	testPary(test, l);

	testTrojki(test, l);

	delete (test);
}

void ParserTest::testPary(Test *test, Loader *l)
{
	QMap<QString, int> *paryMap = new QMap<QString, int> ();
	Generator::generojPary(paryMap, l);

	test->assert(Generator::iloscKombinacji(2,49), paryMap->size());

	QList<QString> keys = paryMap->keys();
	for (int i = 0; i < keys.size(); i++)
	{
		QString k = keys.at(i);

		if (k == "1, 2" || k == "1, 3" || k == "1, 4" || k == "1, 5" || k
				== "1, 6" || k == "2, 3" || k == "2, 4" || k == "2, 5" || k
				== "2, 6" || k == "3, 4" || k == "3, 5" || k == "3, 6" || k
				== "4, 5" || k == "4, 6" || k == "5, 6")
		{
			test->assert(1, paryMap->value(k));
		}
		else
		{
			test->assert(0, paryMap->value(k));
		}
	}
}

void ParserTest::testTrojki(Test *test, Loader *l)
{
	QMap<QString, int> *trojkiMap = new QMap<QString, int> ();
	Generator::generojTrojki(trojkiMap, l);

	QList<QString> trojki;

	for (int i = 1; i <= 4; i++)
	{
		for (int j = i + 1; j <= 5; j++)
		{
			for (int k = j + 1; k <= 6; k++)
			{
				trojki.push_back(
						QString::number(i) + ", " + QString::number(j) + ", "
								+ QString::number(k));
			}
		}
	}

	test->assert(Generator::iloscKombinacji(3,49), trojkiMap->size());

	QList<QString> keys = trojkiMap->keys();
	for (int i = 0; i < keys.size(); i++)
	{
		QString k = keys.at(i);
		bool liczone = false;

		for (int l = 0; l < trojki.size(); l++)
		{
			if (k == trojki.at(l))
			{
				test->assert(1, trojkiMap->value(k));
				liczone = true;
				break;
			}
		}

		if (!liczone)
		{
			test->assert(0, trojkiMap->value(k));
		}
	}
}

ParserTest::~ParserTest()
{
}

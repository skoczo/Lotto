#include "lotto.h"

std::string Lotto::sampleFile = "dl.txt";

Lotto::Lotto(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);

	tableCzestosc = NULL;
	tablePary = NULL;
	dodajLos = NULL;
	tableTrojki = NULL;
	//	connect(ui.pary, SIGNAL(clicked()), this, SLOT(on_pary_clicked()));
	//	connect(ui.czestosc, SIGNAL(clicked()), this, SLOT(on_czestosc_clicked()));
	//	connect(ui.trojki, SIGNAL(clicked()), this, SLOT(on_trojki_clicked()));

	try
	{
		loader = new Loader();
		if (debug)
		{
			std::cout << loader->getList().size();
		}
	} catch (FileError e)
	{
		QMessageBox::critical(this, "Error", "Nie można otworzyć pliku",
				QMessageBox::Ok);
		throw;
	}
}

Lotto::~Lotto()
{
	delete (loader);
}

void Lotto::przeladoj()
{
    if(dodano){
        dodano = false;
        try {
            delete (loader);
            loader = new Loader();
            if(debug){
                std::cout << loader->getList().size();
            }
        }
        catch(FileError e){
            QMessageBox::critical(this, "Error", "Nie można otworzyć pliku", QMessageBox::Ok);
            throw ;
        }
    }

}

void Lotto::on_trojki_clicked()
{
    przeladoj();

    int ilosc = iloscKombinacji(3, 49);
	std::cout << ilosc << std::endl;

	QMap<QString, int> *trojkiMap = new QMap<QString, int> ();

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

	if (tableTrojki != NULL)
	{
		tableTrojki->close();
		delete (tableTrojki);
	}

	tableTrojki = new TableWindow(this, trojkiMap);
}

void Lotto::on_czestosc_clicked()
{
	przeladoj();

	int czestosc[49];
	for (int i = 0; i < 49; i++)
		czestosc[i] = 0;

	for (int i = 0; i < loader->getList().size(); i++)
	{
		int *numbers = loader->getList().at(i)->getNumbers();

		for (int j = 0; j < 6; j++)
		{
			if (numbers[j] > 49 || numbers[j] < 1)
			{
				throw NumberException();
			}
			else
			{
				czestosc[numbers[j] - 1]++;
			}
		}
	}

	if (tableCzestosc != NULL)
	{
		tableCzestosc->close();
		delete (tableCzestosc);
	}

	tableCzestosc = new TableWindow(this, czestosc, 49);
}

void Lotto::on_pary_clicked()
{
	przeladoj();

	int ilosc = iloscKombinacji(2, 49);
	std::cout << ilosc << std::endl;

	QMap<QString, int> *paryMap = new QMap<QString, int> ();

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

	if (tablePary != NULL)
	{
		tablePary->close();
		delete (tablePary);
	}

	tablePary = new TableWindow(this, paryMap);
}

int Lotto::iloscKombinacji(int iloscElementow, int zbior)
{
	unsigned int wynik = 1;

	for (int i = zbior; i > (zbior - iloscElementow); i--)
	{
		wynik *= i;
	}

	return wynik / silnia(iloscElementow);
}

int Lotto::silnia(int liczba)
{
	unsigned int i = 1;

	for (int j = 2; j <= liczba; j++)
	{
		i *= j;
	}

	return i;
}

void Lotto::on_actionDodaj_losowanie_triggered()
{
	if (dodajLos != NULL)
	{
		dodajLos->close();
		delete (dodajLos);
	}

	dodajLos = new Dodaj(this, loader->getList().size() + 1);
	dodajLos->show();

	dodano = true;
}

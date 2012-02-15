#include "lotto.h"

std::string Lotto::sampleFile = "dl.txt";

Lotto::Lotto(QWidget *parent) :
	QWidget(parent)
{
	ui.setupUi(this);

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

void Lotto::on_trojki_clicked()
{
	int ilosc = iloscKombinacji(3, 49);
	std::cout << ilosc << std::endl;
}

void Lotto::on_czestosc_clicked()
{
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

		delete (numbers);
	}

	new TableWindow(this, czestosc, 49);
}

void Lotto::on_pary_clicked()
{

	int ilosc = iloscKombinacji(2, 49);
	std::cout << ilosc << std::endl;
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

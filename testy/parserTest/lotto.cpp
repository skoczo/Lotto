#include "lotto.h"

bool debug = false;

std::string Lotto::sampleFile = "dl.txt";

Lotto::Lotto(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);

	tableCzestosc = NULL;
	tablePary = NULL;
	dodajLos = NULL;
	tableTrojki = NULL;

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

	QMap<QString, int> *trojkiMap = new QMap<QString, int> ();

	Generator::generojTrojki(trojkiMap, loader);

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

	QMap<QString, int> *paryMap = new QMap<QString, int> ();

	Generator::generojPary(paryMap, loader);

	if (tablePary != NULL)
	{
		tablePary->close();
		delete (tablePary);
	}

	tablePary = new TableWindow(this, paryMap);
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

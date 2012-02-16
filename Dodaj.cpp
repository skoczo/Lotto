/*
 * Dodaj.cpp
 *
 *  Created on: 16-02-2012
 *      Author: skoczeq
 */

#include "Dodaj.h"

Dodaj::Dodaj(QWidget *parent, int ostatni) :
	QDialog(parent)
{
	ui.setupUi(this);

	ui.data->setDisplayFormat("dd.MM.yyyy");
	this->ostatni = ostatni;
	connect(ui.ok, SIGNAL(clicked()), this, SLOT(write()));
	connect(ui.cancel, SIGNAL(clicked()), this, SLOT(close()));

}

Dodaj::~Dodaj()
{

}

void Dodaj::write()
{
	QFile file(Lotto::sampleFile.c_str());
	file.open(QFile::Append);
	QRegExp reg("(\\d+)");

	if (file.exists() && file.isWritable())
	{
		QString data = ui.data->text();
		QString tmpLosowania = ui.liczby->text();
		QString losowania = "";

		int pos = 0, i = 0;
		while ((pos = reg.indexIn(tmpLosowania, pos)) != -1)
		{
			losowania += reg.cap(1);
			if (i < 5)
			{
				losowania += ";";
			}
			pos += reg.matchedLength();

			i++;
		}

		if (i != 6)
		{
			QMessageBox::critical(this, "Błąd", "Błędnie podane losowania!!!");
			file.close();
			return;
		}

		file.write(
				(QString().number(ostatni++) + ";" + data + ";" + losowania).toStdString().c_str());
		file.close();

		QMessageBox::information(this, "Informacja", "Dane zapisane");

		close();
	}
}

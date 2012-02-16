/*
 * Dodaj.h
 *
 *  Created on: 16-02-2012
 *      Author: skoczeq
 */

#ifndef DODAJ_H_
#define DODAJ_H_

#include <QtGui/QWidget>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include "ui_dodaj.h"
#include "lotto.h"

extern std::string sampleFile;

class Dodaj: public QDialog
{
Q_OBJECT
public:
	Dodaj(QWidget *parent, int ostatni);
	~Dodaj();

private:
	Ui::Dodaj ui;
	int ostatni;

private slots:
	void write();
};

#endif /* DODAJ_H_ */

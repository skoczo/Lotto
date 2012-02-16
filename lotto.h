#ifndef LOTTO_H
#define LOTTO_H

#include <QtGui/QWidget>
#include "ui_lotto.h"
#include "loader.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include "sample.h"
#include "TableWindow.h"
#include "Para.h"

extern bool debug;

class Loader;

class Lotto: public QWidget
{
Q_OBJECT

public:
	Lotto(QWidget *parent = 0);
	~Lotto();
	static std::string sampleFile;

private slots:
	void on_trojki_clicked();

	void on_czestosc_clicked();
	void on_pary_clicked();
	int silnia(int liczba);
	int iloscKombinacji(int iloscElementow, int zbior);

private:
	Loader *loader;
	Ui::LottoClass ui;
};

#endif // LOTTO_H

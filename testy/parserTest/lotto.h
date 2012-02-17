#ifndef LOTTO_H
#define LOTTO_H

#include <iostream>
#include <QtGui/QWidget>
#include <QMainWindow>
//#include "ui_lotto.h"
#include "ui_lottoMain.h"
#include "loader.h"
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include "Dodaj.h"
#include "sample.h"
#include "TableWindow.h"
#include "Para.h"
#include "Trojka.h"
#include "Generator.h"

class Loader;
class Dodaj;

class Lotto: public QMainWindow
{
Q_OBJECT

public:
	Lotto(QWidget *parent = 0);
	~Lotto();
	static std::string sampleFile;
	void generojTrojki(QMap<QString, int> *trojkiMap);
	void generojPary(QMap<QString, int> *paryMap);

private slots:
    void on_trojki_clicked();
    void on_czestosc_clicked();
    void on_pary_clicked();
    void on_actionDodaj_losowanie_triggered();
private:
    int silnia(int liczba);
    int iloscKombinacji(int iloscElementow, int zbior);
    void przeladoj();
	TableWindow *tableCzestosc, *tablePary, *tableTrojki;
	Dodaj *dodajLos;
	Loader *loader;
	Ui::lottoMain ui;
	bool dodano;
};

#endif // LOTTO_H

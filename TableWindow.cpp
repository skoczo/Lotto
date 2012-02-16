/*
 * TableWindow.cpp
 *
 *  Created on: 11-02-2012
 *      Author: skoczeq
 */

#include "TableWindow.h"

TableWindow::TableWindow(QWidget *parent, int data[], unsigned int size) :
	QWidget(parent)
{
	this->setWindowFlags(Qt::Window);
	layout = new QHBoxLayout(this);
	table = new QTableWidget(size, 2);

	QStringList kolumny;
	kolumny << "Liczba" << "Ilość losowań";
	table->setHorizontalHeaderLabels(kolumny);
	table->setRowCount(size);
	table->setColumnCount(2);

	for (unsigned int i = 0; i < size; i++)
	{
		QTableWidgetItem *newItem = new QTableWidgetItem();
		newItem->setData(0, i + 1);

		QTableWidgetItem *newItem2 = new QTableWidgetItem();
		newItem2->setData(0, data[i]);

		table->setItem(i, 0, newItem);
		table->setItem(i, 1, newItem2);
	}

	table->setSortingEnabled(true);
	table->sortByColumn(1, Qt::DescendingOrder);
	table->adjustSize();

	layout->addWidget(table);
	setLayout(layout);
	adjustSize();
	show();
}

TableWindow::TableWindow(QWidget *parent, QMap<QString, int> *pary) :
	QWidget(parent)
{
	this->setWindowFlags(Qt::Window);
	layout = new QHBoxLayout(this);
	table = new QTableWidget(pary->size(), 2);

	QStringList kolumny;
	kolumny << "Pary" << "Ilość losowań";
	table->setHorizontalHeaderLabels(kolumny);
	table->setRowCount(pary->size());
	table->setColumnCount(2);

	int i=0;
	for (QMap<QString, int>::iterator it = pary->begin(); it != pary->end(); it++)
	{
		QTableWidgetItem *newItem = new QTableWidgetItem();
//		std::string s = it.key()->toString();
		newItem->setData(0, it.key());

		QTableWidgetItem *newItem2 = new QTableWidgetItem();
		newItem2->setData(0, it.value());

		table->setItem(i, 0, newItem);
		table->setItem(i, 1, newItem2);
		i++;
	}

	table->setSortingEnabled(true);
	table->sortByColumn(1, Qt::DescendingOrder);
	table->adjustSize();

	layout->addWidget(table);
	setLayout(layout);
	adjustSize();
	show();
}

TableWindow::~TableWindow()
{
	delete (layout);
	table->clear();
	delete (table);
}

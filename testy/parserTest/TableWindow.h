/*
 * TableWindow.h
 *
 *  Created on: 11-02-2012
 *      Author: skoczeq
 */

#ifndef TABLEWINDOW_H_
#define TABLEWINDOW_H_

#include <QWidget>
#include <QTableWidget>
#include <sstream>
#include <QStringList>
#include <QHBoxLayout>
#include <QLabel>
#include "Para.h"

#define NUM_OF(x) (sizeof (x) / sizeof *(x))

class TableWindow: public QWidget
{
public:
	TableWindow(QWidget *parent, int data[], unsigned int size);
	TableWindow(QWidget *parent, QMap<QString, int> *);
	virtual ~TableWindow();

private:
	QTableWidget *table;
	QHBoxLayout *layout;
};

#endif /* TABLEWINDOW_H_ */

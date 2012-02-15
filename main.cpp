#include "lotto.h"
#include <QtGui>
#include <QApplication>
#include <QTextCodec>
#include "loader.h"
#include "Exceptions.h"

bool debug = false;

int main(int argc, char *argv[])
{
	signal(SIGSEGV, handler);
	QApplication a(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	Lotto w;
	w.show();
	return a.exec();
}

#ifndef PARSERTEST_H
#define PARSERTEST_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QCoreApplication>
#include <QList>
#include "Generator.h"
#include "../test.h"

class ParserTest : public QObject
{
    Q_OBJECT

public:
    ParserTest();
    ~ParserTest();

private:
    void testPary(Test *test, Loader *l);
    void testTrojki(Test *test, Loader *l);
};

#endif // PARSERTEST_H

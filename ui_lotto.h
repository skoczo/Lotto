/********************************************************************************
** Form generated from reading UI file 'lotto.ui'
**
** Created: Thu Feb 16 18:05:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTTO_H
#define UI_LOTTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LottoClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *czestosc;
    QPushButton *pary;
    QPushButton *trojki;

    void setupUi(QWidget *LottoClass)
    {
        if (LottoClass->objectName().isEmpty())
            LottoClass->setObjectName(QString::fromUtf8("LottoClass"));
        LottoClass->resize(400, 300);
        gridLayout_2 = new QGridLayout(LottoClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        czestosc = new QPushButton(LottoClass);
        czestosc->setObjectName(QString::fromUtf8("czestosc"));

        gridLayout->addWidget(czestosc, 0, 0, 1, 1);

        pary = new QPushButton(LottoClass);
        pary->setObjectName(QString::fromUtf8("pary"));

        gridLayout->addWidget(pary, 0, 1, 1, 1);

        trojki = new QPushButton(LottoClass);
        trojki->setObjectName(QString::fromUtf8("trojki"));

        gridLayout->addWidget(trojki, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(LottoClass);

        QMetaObject::connectSlotsByName(LottoClass);
    } // setupUi

    void retranslateUi(QWidget *LottoClass)
    {
        LottoClass->setWindowTitle(QApplication::translate("LottoClass", "Lotto", 0, QApplication::UnicodeUTF8));
        czestosc->setText(QApplication::translate("LottoClass", "Cz\304\231sto\305\233\304\207 wyst\304\231powania liczb", 0, QApplication::UnicodeUTF8));
        pary->setText(QApplication::translate("LottoClass", "Najcz\304\231stsze pary", 0, QApplication::UnicodeUTF8));
        trojki->setText(QApplication::translate("LottoClass", "Najcz\304\231stsze tr\303\263jki", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LottoClass: public Ui_LottoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTTO_H

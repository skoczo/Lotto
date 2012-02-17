/********************************************************************************
** Form generated from reading UI file 'lottoMain.ui'
**
** Created: Fri Feb 17 21:13:22 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTTOMAIN_H
#define UI_LOTTOMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lottoMain
{
public:
    QAction *actionDodaj_losowanie;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *czestosc;
    QPushButton *pary;
    QPushButton *trojki;
    QMenuBar *menubar;
    QMenu *menuOpcje;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *lottoMain)
    {
        if (lottoMain->objectName().isEmpty())
            lottoMain->setObjectName(QString::fromUtf8("lottoMain"));
        lottoMain->resize(517, 399);
        actionDodaj_losowanie = new QAction(lottoMain);
        actionDodaj_losowanie->setObjectName(QString::fromUtf8("actionDodaj_losowanie"));
        centralwidget = new QWidget(lottoMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        czestosc = new QPushButton(centralwidget);
        czestosc->setObjectName(QString::fromUtf8("czestosc"));

        gridLayout->addWidget(czestosc, 0, 0, 1, 1);

        pary = new QPushButton(centralwidget);
        pary->setObjectName(QString::fromUtf8("pary"));

        gridLayout->addWidget(pary, 0, 1, 1, 1);

        trojki = new QPushButton(centralwidget);
        trojki->setObjectName(QString::fromUtf8("trojki"));

        gridLayout->addWidget(trojki, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        lottoMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(lottoMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 517, 23));
        menuOpcje = new QMenu(menubar);
        menuOpcje->setObjectName(QString::fromUtf8("menuOpcje"));
        lottoMain->setMenuBar(menubar);
        statusbar = new QStatusBar(lottoMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        lottoMain->setStatusBar(statusbar);

        menubar->addAction(menuOpcje->menuAction());
        menuOpcje->addAction(actionDodaj_losowanie);

        retranslateUi(lottoMain);

        QMetaObject::connectSlotsByName(lottoMain);
    } // setupUi

    void retranslateUi(QMainWindow *lottoMain)
    {
        lottoMain->setWindowTitle(QApplication::translate("lottoMain", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionDodaj_losowanie->setText(QApplication::translate("lottoMain", "Dodaj losowanie", 0, QApplication::UnicodeUTF8));
        czestosc->setText(QApplication::translate("lottoMain", "Cz\304\231sto\305\233\304\207 wyst\304\231powania liczb", 0, QApplication::UnicodeUTF8));
        pary->setText(QApplication::translate("lottoMain", "Najcz\304\231stsze pary", 0, QApplication::UnicodeUTF8));
        trojki->setText(QApplication::translate("lottoMain", "Najcz\304\231stsze tr\303\263jki", 0, QApplication::UnicodeUTF8));
        menuOpcje->setTitle(QApplication::translate("lottoMain", "Opcje", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lottoMain: public Ui_lottoMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTTOMAIN_H

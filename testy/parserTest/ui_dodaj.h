/********************************************************************************
** Form generated from reading UI file 'dodaj.ui'
**
** Created: Fri Feb 17 21:13:22 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJ_H
#define UI_DODAJ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dodaj
{
public:
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *dataLabel;
    QLabel *liczbyLabel;
    QDateEdit *data;
    QLineEdit *liczby;
    QFormLayout *formLayout_3;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *Dodaj)
    {
        if (Dodaj->objectName().isEmpty())
            Dodaj->setObjectName(QString::fromUtf8("Dodaj"));
        Dodaj->resize(207, 133);
        formLayout_2 = new QFormLayout(Dodaj);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        dataLabel = new QLabel(Dodaj);
        dataLabel->setObjectName(QString::fromUtf8("dataLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dataLabel);

        liczbyLabel = new QLabel(Dodaj);
        liczbyLabel->setObjectName(QString::fromUtf8("liczbyLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, liczbyLabel);

        data = new QDateEdit(Dodaj);
        data->setObjectName(QString::fromUtf8("data"));

        formLayout->setWidget(0, QFormLayout::FieldRole, data);

        liczby = new QLineEdit(Dodaj);
        liczby->setObjectName(QString::fromUtf8("liczby"));

        formLayout->setWidget(1, QFormLayout::FieldRole, liczby);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        ok = new QPushButton(Dodaj);
        ok->setObjectName(QString::fromUtf8("ok"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, ok);

        cancel = new QPushButton(Dodaj);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cancel);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, formLayout_3);


        retranslateUi(Dodaj);

        QMetaObject::connectSlotsByName(Dodaj);
    } // setupUi

    void retranslateUi(QDialog *Dodaj)
    {
        Dodaj->setWindowTitle(QApplication::translate("Dodaj", "Dialog", 0, QApplication::UnicodeUTF8));
        dataLabel->setText(QApplication::translate("Dodaj", "Data: ", 0, QApplication::UnicodeUTF8));
        liczbyLabel->setText(QApplication::translate("Dodaj", "Liczby: ", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("Dodaj", "Ok", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Dodaj", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dodaj: public Ui_Dodaj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJ_H

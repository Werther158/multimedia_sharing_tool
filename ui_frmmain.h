/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmMain
{
public:
    QLabel *lblStart;
    QPushButton *btnServer;
    QPushButton *btnClient;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblLang;
    QPushButton *btnLang;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExit;

    void setupUi(QWidget *FrmMain)
    {
        if (FrmMain->objectName().isEmpty())
            FrmMain->setObjectName(QString::fromUtf8("FrmMain"));
        FrmMain->resize(379, 268);
        lblStart = new QLabel(FrmMain);
        lblStart->setObjectName(QString::fromUtf8("lblStart"));
        lblStart->setGeometry(QRect(30, 40, 71, 21));
        btnServer = new QPushButton(FrmMain);
        btnServer->setObjectName(QString::fromUtf8("btnServer"));
        btnServer->setGeometry(QRect(130, 80, 111, 41));
        btnClient = new QPushButton(FrmMain);
        btnClient->setObjectName(QString::fromUtf8("btnClient"));
        btnClient->setGeometry(QRect(130, 130, 111, 41));
        widget = new QWidget(FrmMain);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 230, 341, 29));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblLang = new QLabel(widget);
        lblLang->setObjectName(QString::fromUtf8("lblLang"));

        horizontalLayout->addWidget(lblLang);

        btnLang = new QPushButton(widget);
        btnLang->setObjectName(QString::fromUtf8("btnLang"));

        horizontalLayout->addWidget(btnLang);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnExit = new QPushButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_2->addWidget(btnExit);


        retranslateUi(FrmMain);

        QMetaObject::connectSlotsByName(FrmMain);
    } // setupUi

    void retranslateUi(QWidget *FrmMain)
    {
        FrmMain->setWindowTitle(QApplication::translate("FrmMain", "MST - Multimedia Sharing Tool", nullptr));
        lblStart->setText(QApplication::translate("FrmMain", "lblStart", nullptr));
        btnServer->setText(QApplication::translate("FrmMain", "btnServer", nullptr));
        btnClient->setText(QApplication::translate("FrmMain", "btnClient", nullptr));
        lblLang->setText(QApplication::translate("FrmMain", "lblLang", nullptr));
        btnLang->setText(QApplication::translate("FrmMain", "btnLang", nullptr));
        btnExit->setText(QApplication::translate("FrmMain", "btnExit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmMain: public Ui_FrmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H

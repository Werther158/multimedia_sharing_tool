/********************************************************************************
** Form generated from reading UI file 'frmconnected.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONNECTED_H
#define UI_FRMCONNECTED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmConnected
{
public:
    QCheckBox *checkBox;
    QPushButton *btnDisconnect;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QScrollBar *horizontalScrollBar;
    QLabel *label_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QTextEdit *txtBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtLine;
    QPushButton *btnSend;

    void setupUi(QWidget *FrmConnected)
    {
        if (FrmConnected->objectName().isEmpty())
            FrmConnected->setObjectName(QString::fromUtf8("FrmConnected"));
        FrmConnected->resize(400, 300);
        checkBox = new QCheckBox(FrmConnected);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 60, 92, 23));
        btnDisconnect = new QPushButton(FrmConnected);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(290, 260, 89, 25));
        widget = new QWidget(FrmConnected);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 331, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalScrollBar = new QScrollBar(widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setMinimumSize(QSize(141, 16));
        horizontalScrollBar->setMaximum(100);
        horizontalScrollBar->setSliderPosition(100);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalScrollBar);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        widget1 = new QWidget(FrmConnected);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 90, 331, 151));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        txtBox = new QTextEdit(widget1);
        txtBox->setObjectName(QString::fromUtf8("txtBox"));

        verticalLayout->addWidget(txtBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        txtLine = new QLineEdit(widget1);
        txtLine->setObjectName(QString::fromUtf8("txtLine"));

        horizontalLayout_2->addWidget(txtLine);

        btnSend = new QPushButton(widget1);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMaximumSize(QSize(51, 25));

        horizontalLayout_2->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FrmConnected);

        QMetaObject::connectSlotsByName(FrmConnected);
    } // setupUi

    void retranslateUi(QWidget *FrmConnected)
    {
        FrmConnected->setWindowTitle(QCoreApplication::translate("FrmConnected", "MST - Connected to server", nullptr));
        checkBox->setText(QCoreApplication::translate("FrmConnected", "Fullscreen", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("FrmConnected", "btnDisconnect", nullptr));
        label->setText(QCoreApplication::translate("FrmConnected", "lblResize", nullptr));
        label_2->setText(QCoreApplication::translate("FrmConnected", "lblResize2", nullptr));
        btnSend->setText(QCoreApplication::translate("FrmConnected", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmConnected: public Ui_FrmConnected {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONNECTED_H

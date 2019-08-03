/********************************************************************************
** Form generated from reading UI file 'frmrunning.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMRUNNING_H
#define UI_FRMRUNNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmRunning
{
public:
    QPushButton *btnStop;
    QPushButton *btnToggleConfig;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblState;
    QSpacerItem *horizontalSpacer;
    QLabel *lblState2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblState3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QListView *listConfigurations;
    QTextEdit *txtBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtLine;
    QPushButton *btnSend;
    QPushButton *btnStartStopStream;

    void setupUi(QWidget *FrmRunning)
    {
        if (FrmRunning->objectName().isEmpty())
            FrmRunning->setObjectName(QString::fromUtf8("FrmRunning"));
        FrmRunning->resize(400, 300);
        btnStop = new QPushButton(FrmRunning);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(258, 260, 111, 25));
        btnToggleConfig = new QPushButton(FrmRunning);
        btnToggleConfig->setObjectName(QString::fromUtf8("btnToggleConfig"));
        btnToggleConfig->setGeometry(QRect(40, 260, 31, 25));
        layoutWidget = new QWidget(FrmRunning);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 10, 204, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblState = new QLabel(layoutWidget);
        lblState->setObjectName(QString::fromUtf8("lblState"));

        horizontalLayout->addWidget(lblState);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lblState2 = new QLabel(layoutWidget);
        lblState2->setObjectName(QString::fromUtf8("lblState2"));

        horizontalLayout->addWidget(lblState2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lblState3 = new QLabel(layoutWidget);
        lblState3->setObjectName(QString::fromUtf8("lblState3"));

        horizontalLayout->addWidget(lblState3);

        layoutWidget1 = new QWidget(FrmRunning);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 40, 311, 211));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listConfigurations = new QListView(layoutWidget1);
        listConfigurations->setObjectName(QString::fromUtf8("listConfigurations"));

        verticalLayout->addWidget(listConfigurations);

        txtBox = new QTextEdit(layoutWidget1);
        txtBox->setObjectName(QString::fromUtf8("txtBox"));
        txtBox->setReadOnly(true);

        verticalLayout->addWidget(txtBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        txtLine = new QLineEdit(layoutWidget1);
        txtLine->setObjectName(QString::fromUtf8("txtLine"));

        horizontalLayout_2->addWidget(txtLine);

        btnSend = new QPushButton(layoutWidget1);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMaximumSize(QSize(51, 25));

        horizontalLayout_2->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_2);

        btnStartStopStream = new QPushButton(FrmRunning);
        btnStartStopStream->setObjectName(QString::fromUtf8("btnStartStopStream"));
        btnStartStopStream->setGeometry(QRect(100, 260, 131, 25));

        retranslateUi(FrmRunning);

        QMetaObject::connectSlotsByName(FrmRunning);
    } // setupUi

    void retranslateUi(QWidget *FrmRunning)
    {
        FrmRunning->setWindowTitle(QApplication::translate("FrmRunning", "MST - Server running", nullptr));
        btnStop->setText(QApplication::translate("FrmRunning", "btnStop", nullptr));
        btnToggleConfig->setText(QApplication::translate("FrmRunning", "btnToggleConfig", nullptr));
        lblState->setText(QApplication::translate("FrmRunning", "lblState", nullptr));
        lblState2->setText(QApplication::translate("FrmRunning", "lblState2", nullptr));
        lblState3->setText(QApplication::translate("FrmRunning", "lblState3", nullptr));
        btnSend->setText(QApplication::translate("FrmRunning", ">", nullptr));
        btnStartStopStream->setText(QApplication::translate("FrmRunning", "btnStartStopStream", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmRunning: public Ui_FrmRunning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMRUNNING_H

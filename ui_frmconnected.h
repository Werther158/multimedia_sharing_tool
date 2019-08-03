/********************************************************************************
** Form generated from reading UI file 'frmconnected.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmConnected
{
public:
    QCheckBox *chkFullScreen;
    QPushButton *btnDisconnect;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblResize;
    QSpacerItem *horizontalSpacer;
    QScrollBar *scrollbarResize;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblResize2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QListView *listConfigurations;
    QTextEdit *txtBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtLine;
    QPushButton *btnSend;
    QPushButton *btnToggleConfig;
    QPushButton *btnStartStopStreaming;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblState;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblState2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lblState3;

    void setupUi(QWidget *FrmConnected)
    {
        if (FrmConnected->objectName().isEmpty())
            FrmConnected->setObjectName(QString::fromUtf8("FrmConnected"));
        FrmConnected->resize(431, 327);
        chkFullScreen = new QCheckBox(FrmConnected);
        chkFullScreen->setObjectName(QString::fromUtf8("chkFullScreen"));
        chkFullScreen->setGeometry(QRect(30, 30, 201, 23));
        btnDisconnect = new QPushButton(FrmConnected);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(330, 290, 89, 25));
        layoutWidget = new QWidget(FrmConnected);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 297, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblResize = new QLabel(layoutWidget);
        lblResize->setObjectName(QString::fromUtf8("lblResize"));

        horizontalLayout->addWidget(lblResize);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollbarResize = new QScrollBar(layoutWidget);
        scrollbarResize->setObjectName(QString::fromUtf8("scrollbarResize"));
        scrollbarResize->setMinimumSize(QSize(141, 16));
        scrollbarResize->setMaximum(100);
        scrollbarResize->setSliderPosition(100);
        scrollbarResize->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(scrollbarResize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lblResize2 = new QLabel(layoutWidget);
        lblResize2->setObjectName(QString::fromUtf8("lblResize2"));

        horizontalLayout->addWidget(lblResize2);

        layoutWidget1 = new QWidget(FrmConnected);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 90, 371, 191));
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

        btnToggleConfig = new QPushButton(FrmConnected);
        btnToggleConfig->setObjectName(QString::fromUtf8("btnToggleConfig"));
        btnToggleConfig->setGeometry(QRect(30, 290, 31, 25));
        btnStartStopStreaming = new QPushButton(FrmConnected);
        btnStartStopStreaming->setObjectName(QString::fromUtf8("btnStartStopStreaming"));
        btnStartStopStreaming->setGeometry(QRect(70, 290, 131, 25));
        layoutWidget2 = new QWidget(FrmConnected);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(273, 20, 204, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblState = new QLabel(layoutWidget2);
        lblState->setObjectName(QString::fromUtf8("lblState"));

        horizontalLayout_3->addWidget(lblState);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lblState2 = new QLabel(layoutWidget2);
        lblState2->setObjectName(QString::fromUtf8("lblState2"));

        horizontalLayout_3->addWidget(lblState2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        lblState3 = new QLabel(layoutWidget2);
        lblState3->setObjectName(QString::fromUtf8("lblState3"));

        horizontalLayout_3->addWidget(lblState3);


        retranslateUi(FrmConnected);

        QMetaObject::connectSlotsByName(FrmConnected);
    } // setupUi

    void retranslateUi(QWidget *FrmConnected)
    {
        FrmConnected->setWindowTitle(QApplication::translate("FrmConnected", "MST - Connecting...", nullptr));
        chkFullScreen->setText(QApplication::translate("FrmConnected", "Fullscreen", nullptr));
        btnDisconnect->setText(QApplication::translate("FrmConnected", "btnDisconnect", nullptr));
        lblResize->setText(QApplication::translate("FrmConnected", "lblResize", nullptr));
        lblResize2->setText(QApplication::translate("FrmConnected", "lblResize2", nullptr));
        btnSend->setText(QApplication::translate("FrmConnected", ">", nullptr));
        btnToggleConfig->setText(QApplication::translate("FrmConnected", "btnToggleConfig", nullptr));
        btnStartStopStreaming->setText(QApplication::translate("FrmConnected", "btnStartStopStreaming", nullptr));
        lblState->setText(QApplication::translate("FrmConnected", "lblState", nullptr));
        lblState2->setText(QApplication::translate("FrmConnected", "lblState2", nullptr));
        lblState3->setText(QApplication::translate("FrmConnected", "lblState3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmConnected: public Ui_FrmConnected {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONNECTED_H

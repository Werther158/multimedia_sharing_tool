/********************************************************************************
** Form generated from reading UI file 'frmclient.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCLIENT_H
#define UI_FRMCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmClient
{
public:
    QLabel *lblInfoServer;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *lblBandwidth;
    QLabel *lblBandwidthvalue;
    QLabel *label_3;
    QFrame *line_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblSource;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *cmbSource;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblResolution;
    QComboBox *cmbResolution;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblFps;
    QComboBox *cmbFps;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lblBuffer;
    QComboBox *cmbBuffer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lblVideo;
    QComboBox *cmbVideo;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lblColorScale;
    QComboBox *cmbColorScale;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lblEncoding;
    QComboBox *cmbEncoding;
    QHBoxLayout *horizontalLayout_12;
    QLabel *lblAudio;
    QComboBox *cmbAudio;
    QHBoxLayout *horizontalLayout_13;
    QLabel *lblControls;
    QComboBox *cmbControls;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *btnLoadConfig;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnSaveConfig;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnConnect;
    QLabel *lblConfig;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblIp;
    QLabel *lblPort;
    QLabel *lblPassword;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *txtIp;
    QLineEdit *txtPort;
    QLineEdit *txtPassword;

    void setupUi(QWidget *FrmClient)
    {
        if (FrmClient->objectName().isEmpty())
            FrmClient->setObjectName(QString::fromUtf8("FrmClient"));
        FrmClient->resize(550, 450);
        lblInfoServer = new QLabel(FrmClient);
        lblInfoServer->setObjectName(QString::fromUtf8("lblInfoServer"));
        lblInfoServer->setGeometry(QRect(20, 10, 101, 17));
        line = new QFrame(FrmClient);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 381, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(FrmClient);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 150, 561, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(FrmClient);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 200, 381, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lblBandwidth = new QLabel(FrmClient);
        lblBandwidth->setObjectName(QString::fromUtf8("lblBandwidth"));
        lblBandwidth->setGeometry(QRect(20, 360, 211, 17));
        lblBandwidthvalue = new QLabel(FrmClient);
        lblBandwidthvalue->setObjectName(QString::fromUtf8("lblBandwidthvalue"));
        lblBandwidthvalue->setGeometry(QRect(260, 360, 67, 17));
        label_3 = new QLabel(FrmClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 360, 67, 17));
        line_4 = new QFrame(FrmClient);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 390, 561, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(FrmClient);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 50, 204, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblSource = new QLabel(layoutWidget);
        lblSource->setObjectName(QString::fromUtf8("lblSource"));

        horizontalLayout_3->addWidget(lblSource);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        cmbSource = new QComboBox(layoutWidget);
        cmbSource->setObjectName(QString::fromUtf8("cmbSource"));

        horizontalLayout_3->addWidget(cmbSource);

        layoutWidget1 = new QWidget(FrmClient);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 210, 491, 130));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblResolution = new QLabel(layoutWidget1);
        lblResolution->setObjectName(QString::fromUtf8("lblResolution"));

        horizontalLayout_4->addWidget(lblResolution);

        cmbResolution = new QComboBox(layoutWidget1);
        cmbResolution->setObjectName(QString::fromUtf8("cmbResolution"));

        horizontalLayout_4->addWidget(cmbResolution);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblFps = new QLabel(layoutWidget1);
        lblFps->setObjectName(QString::fromUtf8("lblFps"));

        horizontalLayout_7->addWidget(lblFps);

        cmbFps = new QComboBox(layoutWidget1);
        cmbFps->setObjectName(QString::fromUtf8("cmbFps"));

        horizontalLayout_7->addWidget(cmbFps);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lblBuffer = new QLabel(layoutWidget1);
        lblBuffer->setObjectName(QString::fromUtf8("lblBuffer"));

        horizontalLayout_8->addWidget(lblBuffer);

        cmbBuffer = new QComboBox(layoutWidget1);
        cmbBuffer->setObjectName(QString::fromUtf8("cmbBuffer"));

        horizontalLayout_8->addWidget(cmbBuffer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lblVideo = new QLabel(layoutWidget1);
        lblVideo->setObjectName(QString::fromUtf8("lblVideo"));

        horizontalLayout_9->addWidget(lblVideo);

        cmbVideo = new QComboBox(layoutWidget1);
        cmbVideo->setObjectName(QString::fromUtf8("cmbVideo"));

        horizontalLayout_9->addWidget(cmbVideo);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_14->addLayout(verticalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(238, 125, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lblColorScale = new QLabel(layoutWidget1);
        lblColorScale->setObjectName(QString::fromUtf8("lblColorScale"));

        horizontalLayout_10->addWidget(lblColorScale);

        cmbColorScale = new QComboBox(layoutWidget1);
        cmbColorScale->setObjectName(QString::fromUtf8("cmbColorScale"));

        horizontalLayout_10->addWidget(cmbColorScale);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lblEncoding = new QLabel(layoutWidget1);
        lblEncoding->setObjectName(QString::fromUtf8("lblEncoding"));

        horizontalLayout_11->addWidget(lblEncoding);

        cmbEncoding = new QComboBox(layoutWidget1);
        cmbEncoding->setObjectName(QString::fromUtf8("cmbEncoding"));

        horizontalLayout_11->addWidget(cmbEncoding);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lblAudio = new QLabel(layoutWidget1);
        lblAudio->setObjectName(QString::fromUtf8("lblAudio"));

        horizontalLayout_12->addWidget(lblAudio);

        cmbAudio = new QComboBox(layoutWidget1);
        cmbAudio->setObjectName(QString::fromUtf8("cmbAudio"));

        horizontalLayout_12->addWidget(cmbAudio);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lblControls = new QLabel(layoutWidget1);
        lblControls->setObjectName(QString::fromUtf8("lblControls"));

        horizontalLayout_13->addWidget(lblControls);

        cmbControls = new QComboBox(layoutWidget1);
        cmbControls->setObjectName(QString::fromUtf8("cmbControls"));

        horizontalLayout_13->addWidget(cmbControls);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_3);

        layoutWidget2 = new QWidget(FrmClient);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 410, 521, 29));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        btnBack = new QPushButton(layoutWidget2);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        horizontalLayout_16->addWidget(btnBack);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        btnLoadConfig = new QPushButton(layoutWidget2);
        btnLoadConfig->setObjectName(QString::fromUtf8("btnLoadConfig"));

        horizontalLayout_15->addWidget(btnLoadConfig);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        btnSaveConfig = new QPushButton(layoutWidget2);
        btnSaveConfig->setObjectName(QString::fromUtf8("btnSaveConfig"));

        horizontalLayout_15->addWidget(btnSaveConfig);


        horizontalLayout_16->addLayout(horizontalLayout_15);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        btnConnect = new QPushButton(layoutWidget2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        horizontalLayout_16->addWidget(btnConnect);

        lblConfig = new QLabel(FrmClient);
        lblConfig->setObjectName(QString::fromUtf8("lblConfig"));
        lblConfig->setGeometry(QRect(20, 180, 413, 17));
        widget = new QWidget(FrmClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 284, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lblIp = new QLabel(widget);
        lblIp->setObjectName(QString::fromUtf8("lblIp"));

        verticalLayout_6->addWidget(lblIp);

        lblPort = new QLabel(widget);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));

        verticalLayout_6->addWidget(lblPort);

        lblPassword = new QLabel(widget);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));

        verticalLayout_6->addWidget(lblPassword);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        txtIp = new QLineEdit(widget);
        txtIp->setObjectName(QString::fromUtf8("txtIp"));

        verticalLayout_4->addWidget(txtIp);

        txtPort = new QLineEdit(widget);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));

        verticalLayout_4->addWidget(txtPort);

        txtPassword = new QLineEdit(widget);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));

        verticalLayout_4->addWidget(txtPassword);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(FrmClient);

        QMetaObject::connectSlotsByName(FrmClient);
    } // setupUi

    void retranslateUi(QWidget *FrmClient)
    {
        FrmClient->setWindowTitle(QCoreApplication::translate("FrmClient", "MST - Client", nullptr));
        lblInfoServer->setText(QCoreApplication::translate("FrmClient", "lblInfoServer", nullptr));
        lblBandwidth->setText(QCoreApplication::translate("FrmClient", "lblBandwidth", nullptr));
        lblBandwidthvalue->setText(QCoreApplication::translate("FrmClient", "lblBandwidthvalue", nullptr));
        label_3->setText(QCoreApplication::translate("FrmClient", "mbit/s", nullptr));
        lblSource->setText(QCoreApplication::translate("FrmClient", "lblSource", nullptr));
        lblResolution->setText(QCoreApplication::translate("FrmClient", "lblResolution", nullptr));
        lblFps->setText(QCoreApplication::translate("FrmClient", "lblFps", nullptr));
        lblBuffer->setText(QCoreApplication::translate("FrmClient", "lblBuffer", nullptr));
        lblVideo->setText(QCoreApplication::translate("FrmClient", "lblVideo", nullptr));
        lblColorScale->setText(QCoreApplication::translate("FrmClient", "lblColorScale", nullptr));
        lblEncoding->setText(QCoreApplication::translate("FrmClient", "lblEncoding", nullptr));
        lblAudio->setText(QCoreApplication::translate("FrmClient", "lblAudio", nullptr));
        lblControls->setText(QCoreApplication::translate("FrmClient", "lblControls", nullptr));
        btnBack->setText(QCoreApplication::translate("FrmClient", "btnBack", nullptr));
        btnLoadConfig->setText(QCoreApplication::translate("FrmClient", "btnLoadConfig", nullptr));
        btnSaveConfig->setText(QCoreApplication::translate("FrmClient", "btnSaveConfig", nullptr));
        btnConnect->setText(QCoreApplication::translate("FrmClient", "btnConnect", nullptr));
        lblConfig->setText(QCoreApplication::translate("FrmClient", "lblConfig", nullptr));
        lblIp->setText(QCoreApplication::translate("FrmClient", "lblIp", nullptr));
        lblPort->setText(QCoreApplication::translate("FrmClient", "lblPort", nullptr));
        lblPassword->setText(QCoreApplication::translate("FrmClient", "lblPassword", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmClient: public Ui_FrmClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCLIENT_H

/********************************************************************************
** Form generated from reading UI file 'frmserver.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSERVER_H
#define UI_FRMSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_FrmServer
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
    QHBoxLayout *horizontalLayout_6;
    QLabel *lblConfig;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lblLeaveConfig;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *chkLeaveConfig;
    QWidget *layoutWidget2;
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
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *btnLoadConfig;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnSaveConfig;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnStartServer;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lblIp;
    QLabel *lblPort;
    QLabel *lblPassword;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblIp2;
    QLineEdit *txtPort;
    QLineEdit *txtPassword;

    void setupUi(QWidget *FrmServer)
    {
        if (FrmServer->objectName().isEmpty())
            FrmServer->setObjectName(QString::fromUtf8("FrmServer"));
        FrmServer->resize(550, 450);
        lblInfoServer = new QLabel(FrmServer);
        lblInfoServer->setObjectName(QString::fromUtf8("lblInfoServer"));
        lblInfoServer->setGeometry(QRect(20, 10, 101, 17));
        line = new QFrame(FrmServer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 381, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(FrmServer);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 150, 561, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(FrmServer);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 200, 381, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lblBandwidth = new QLabel(FrmServer);
        lblBandwidth->setObjectName(QString::fromUtf8("lblBandwidth"));
        lblBandwidth->setGeometry(QRect(20, 360, 211, 17));
        lblBandwidthvalue = new QLabel(FrmServer);
        lblBandwidthvalue->setObjectName(QString::fromUtf8("lblBandwidthvalue"));
        lblBandwidthvalue->setGeometry(QRect(260, 360, 67, 17));
        label_3 = new QLabel(FrmServer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 360, 67, 17));
        line_4 = new QFrame(FrmServer);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 390, 561, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(FrmServer);
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

        layoutWidget1 = new QWidget(FrmServer);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 180, 415, 19));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lblConfig = new QLabel(layoutWidget1);
        lblConfig->setObjectName(QString::fromUtf8("lblConfig"));

        horizontalLayout_6->addWidget(lblConfig);

        horizontalSpacer_4 = new QSpacerItem(198, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        lblLeaveConfig = new QLabel(layoutWidget1);
        lblLeaveConfig->setObjectName(QString::fromUtf8("lblLeaveConfig"));

        horizontalLayout_6->addWidget(lblLeaveConfig);

        horizontalSpacer_5 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        chkLeaveConfig = new QCheckBox(layoutWidget1);
        chkLeaveConfig->setObjectName(QString::fromUtf8("chkLeaveConfig"));

        horizontalLayout_6->addWidget(chkLeaveConfig);

        layoutWidget2 = new QWidget(FrmServer);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 210, 491, 130));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblResolution = new QLabel(layoutWidget2);
        lblResolution->setObjectName(QString::fromUtf8("lblResolution"));

        horizontalLayout_4->addWidget(lblResolution);

        cmbResolution = new QComboBox(layoutWidget2);
        cmbResolution->setObjectName(QString::fromUtf8("cmbResolution"));

        horizontalLayout_4->addWidget(cmbResolution);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblFps = new QLabel(layoutWidget2);
        lblFps->setObjectName(QString::fromUtf8("lblFps"));

        horizontalLayout_7->addWidget(lblFps);

        cmbFps = new QComboBox(layoutWidget2);
        cmbFps->setObjectName(QString::fromUtf8("cmbFps"));

        horizontalLayout_7->addWidget(cmbFps);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lblBuffer = new QLabel(layoutWidget2);
        lblBuffer->setObjectName(QString::fromUtf8("lblBuffer"));

        horizontalLayout_8->addWidget(lblBuffer);

        cmbBuffer = new QComboBox(layoutWidget2);
        cmbBuffer->setObjectName(QString::fromUtf8("cmbBuffer"));

        horizontalLayout_8->addWidget(cmbBuffer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lblVideo = new QLabel(layoutWidget2);
        lblVideo->setObjectName(QString::fromUtf8("lblVideo"));

        horizontalLayout_9->addWidget(lblVideo);

        cmbVideo = new QComboBox(layoutWidget2);
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
        lblColorScale = new QLabel(layoutWidget2);
        lblColorScale->setObjectName(QString::fromUtf8("lblColorScale"));

        horizontalLayout_10->addWidget(lblColorScale);

        cmbColorScale = new QComboBox(layoutWidget2);
        cmbColorScale->setObjectName(QString::fromUtf8("cmbColorScale"));

        horizontalLayout_10->addWidget(cmbColorScale);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lblEncoding = new QLabel(layoutWidget2);
        lblEncoding->setObjectName(QString::fromUtf8("lblEncoding"));

        horizontalLayout_11->addWidget(lblEncoding);

        cmbEncoding = new QComboBox(layoutWidget2);
        cmbEncoding->setObjectName(QString::fromUtf8("cmbEncoding"));

        horizontalLayout_11->addWidget(cmbEncoding);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lblAudio = new QLabel(layoutWidget2);
        lblAudio->setObjectName(QString::fromUtf8("lblAudio"));

        horizontalLayout_12->addWidget(lblAudio);

        cmbAudio = new QComboBox(layoutWidget2);
        cmbAudio->setObjectName(QString::fromUtf8("cmbAudio"));

        horizontalLayout_12->addWidget(cmbAudio);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lblControls = new QLabel(layoutWidget2);
        lblControls->setObjectName(QString::fromUtf8("lblControls"));

        horizontalLayout_13->addWidget(lblControls);

        cmbControls = new QComboBox(layoutWidget2);
        cmbControls->setObjectName(QString::fromUtf8("cmbControls"));

        horizontalLayout_13->addWidget(cmbControls);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_3);

        layoutWidget3 = new QWidget(FrmServer);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 410, 521, 29));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        btnBack = new QPushButton(layoutWidget3);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        horizontalLayout_16->addWidget(btnBack);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        btnLoadConfig = new QPushButton(layoutWidget3);
        btnLoadConfig->setObjectName(QString::fromUtf8("btnLoadConfig"));

        horizontalLayout_15->addWidget(btnLoadConfig);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        btnSaveConfig = new QPushButton(layoutWidget3);
        btnSaveConfig->setObjectName(QString::fromUtf8("btnSaveConfig"));

        horizontalLayout_15->addWidget(btnSaveConfig);


        horizontalLayout_16->addLayout(horizontalLayout_15);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        btnStartServer = new QPushButton(layoutWidget3);
        btnStartServer->setObjectName(QString::fromUtf8("btnStartServer"));

        horizontalLayout_16->addWidget(btnStartServer);

        layoutWidget4 = new QWidget(FrmServer);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 50, 284, 83));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblIp = new QLabel(layoutWidget4);
        lblIp->setObjectName(QString::fromUtf8("lblIp"));

        verticalLayout->addWidget(lblIp);

        lblPort = new QLabel(layoutWidget4);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));

        verticalLayout->addWidget(lblPort);

        lblPassword = new QLabel(layoutWidget4);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));

        verticalLayout->addWidget(lblPassword);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_10);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblIp2 = new QLabel(layoutWidget4);
        lblIp2->setObjectName(QString::fromUtf8("lblIp2"));

        verticalLayout_5->addWidget(lblIp2);

        txtPort = new QLineEdit(layoutWidget4);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));

        verticalLayout_5->addWidget(txtPort);

        txtPassword = new QLineEdit(layoutWidget4);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));

        verticalLayout_5->addWidget(txtPassword);


        horizontalLayout->addLayout(verticalLayout_5);


        retranslateUi(FrmServer);

        QMetaObject::connectSlotsByName(FrmServer);
    } // setupUi

    void retranslateUi(QWidget *FrmServer)
    {
        FrmServer->setWindowTitle(QCoreApplication::translate("FrmServer", "MST - Server", nullptr));
        lblInfoServer->setText(QCoreApplication::translate("FrmServer", "lblInfoServer", nullptr));
        lblBandwidth->setText(QCoreApplication::translate("FrmServer", "lblBandwidth", nullptr));
        lblBandwidthvalue->setText(QCoreApplication::translate("FrmServer", "lblBandwidthvalue", nullptr));
        label_3->setText(QCoreApplication::translate("FrmServer", "mbit/s", nullptr));
        lblSource->setText(QCoreApplication::translate("FrmServer", "lblSource", nullptr));
        lblConfig->setText(QCoreApplication::translate("FrmServer", "lblConfig", nullptr));
        lblLeaveConfig->setText(QCoreApplication::translate("FrmServer", "lblLeaveConfig", nullptr));
        chkLeaveConfig->setText(QString());
        lblResolution->setText(QCoreApplication::translate("FrmServer", "lblResolution", nullptr));
        lblFps->setText(QCoreApplication::translate("FrmServer", "lblFps", nullptr));
        lblBuffer->setText(QCoreApplication::translate("FrmServer", "lblBuffer", nullptr));
        lblVideo->setText(QCoreApplication::translate("FrmServer", "lblVideo", nullptr));
        lblColorScale->setText(QCoreApplication::translate("FrmServer", "lblColorScale", nullptr));
        lblEncoding->setText(QCoreApplication::translate("FrmServer", "lblEncoding", nullptr));
        lblAudio->setText(QCoreApplication::translate("FrmServer", "lblAudio", nullptr));
        lblControls->setText(QCoreApplication::translate("FrmServer", "lblControls", nullptr));
        btnBack->setText(QCoreApplication::translate("FrmServer", "btnBack", nullptr));
        btnLoadConfig->setText(QCoreApplication::translate("FrmServer", "btnLoadConfig", nullptr));
        btnSaveConfig->setText(QCoreApplication::translate("FrmServer", "btnSaveConfig", nullptr));
        btnStartServer->setText(QCoreApplication::translate("FrmServer", "btnStartServer", nullptr));
        lblIp->setText(QCoreApplication::translate("FrmServer", "lblIp", nullptr));
        lblPort->setText(QCoreApplication::translate("FrmServer", "lblPort", nullptr));
        lblPassword->setText(QCoreApplication::translate("FrmServer", "lblPassword", nullptr));
        lblIp2->setText(QCoreApplication::translate("FrmServer", "lblIp2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmServer: public Ui_FrmServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSERVER_H
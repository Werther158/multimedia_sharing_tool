/********************************************************************************
** Form generated from reading UI file 'frmclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
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
    QWidget *layoutWidget4;
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
    QWidget *layoutWidget1;
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
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblIpServer;
    QLabel *lblPort;
    QLabel *lblPassword;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *txtIpServer;
    QLineEdit *txtPort;
    QLineEdit *txtPassword;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblIpClient;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblIpClient2;

    void setupUi(QWidget *FrmClient)
    {
        if (FrmClient->objectName().isEmpty())
            FrmClient->setObjectName(QString::fromUtf8("FrmClient"));
        FrmClient->resize(550, 450);
        lblInfoServer = new QLabel(FrmClient);
        lblInfoServer->setObjectName(QString::fromUtf8("lblInfoServer"));
        lblInfoServer->setGeometry(QRect(20, 10, 341, 17));
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
        layoutWidget4 = new QWidget(FrmClient);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 210, 491, 130));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblResolution = new QLabel(layoutWidget4);
        lblResolution->setObjectName(QString::fromUtf8("lblResolution"));

        horizontalLayout_4->addWidget(lblResolution);

        cmbResolution = new QComboBox(layoutWidget4);
        cmbResolution->setObjectName(QString::fromUtf8("cmbResolution"));

        horizontalLayout_4->addWidget(cmbResolution);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblFps = new QLabel(layoutWidget4);
        lblFps->setObjectName(QString::fromUtf8("lblFps"));

        horizontalLayout_7->addWidget(lblFps);

        cmbFps = new QComboBox(layoutWidget4);
        cmbFps->setObjectName(QString::fromUtf8("cmbFps"));

        horizontalLayout_7->addWidget(cmbFps);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lblBuffer = new QLabel(layoutWidget4);
        lblBuffer->setObjectName(QString::fromUtf8("lblBuffer"));

        horizontalLayout_8->addWidget(lblBuffer);

        cmbBuffer = new QComboBox(layoutWidget4);
        cmbBuffer->setObjectName(QString::fromUtf8("cmbBuffer"));

        horizontalLayout_8->addWidget(cmbBuffer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lblVideo = new QLabel(layoutWidget4);
        lblVideo->setObjectName(QString::fromUtf8("lblVideo"));

        horizontalLayout_9->addWidget(lblVideo);

        cmbVideo = new QComboBox(layoutWidget4);
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
        lblColorScale = new QLabel(layoutWidget4);
        lblColorScale->setObjectName(QString::fromUtf8("lblColorScale"));

        horizontalLayout_10->addWidget(lblColorScale);

        cmbColorScale = new QComboBox(layoutWidget4);
        cmbColorScale->setObjectName(QString::fromUtf8("cmbColorScale"));

        horizontalLayout_10->addWidget(cmbColorScale);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lblEncoding = new QLabel(layoutWidget4);
        lblEncoding->setObjectName(QString::fromUtf8("lblEncoding"));

        horizontalLayout_11->addWidget(lblEncoding);

        cmbEncoding = new QComboBox(layoutWidget4);
        cmbEncoding->setObjectName(QString::fromUtf8("cmbEncoding"));

        horizontalLayout_11->addWidget(cmbEncoding);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lblAudio = new QLabel(layoutWidget4);
        lblAudio->setObjectName(QString::fromUtf8("lblAudio"));

        horizontalLayout_12->addWidget(lblAudio);

        cmbAudio = new QComboBox(layoutWidget4);
        cmbAudio->setObjectName(QString::fromUtf8("cmbAudio"));

        horizontalLayout_12->addWidget(cmbAudio);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lblControls = new QLabel(layoutWidget4);
        lblControls->setObjectName(QString::fromUtf8("lblControls"));

        horizontalLayout_13->addWidget(lblControls);

        cmbControls = new QComboBox(layoutWidget4);
        cmbControls->setObjectName(QString::fromUtf8("cmbControls"));

        horizontalLayout_13->addWidget(cmbControls);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(FrmClient);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 410, 531, 29));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        btnBack = new QPushButton(layoutWidget1);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        horizontalLayout_16->addWidget(btnBack);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        btnLoadConfig = new QPushButton(layoutWidget1);
        btnLoadConfig->setObjectName(QString::fromUtf8("btnLoadConfig"));

        horizontalLayout_15->addWidget(btnLoadConfig);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        btnSaveConfig = new QPushButton(layoutWidget1);
        btnSaveConfig->setObjectName(QString::fromUtf8("btnSaveConfig"));

        horizontalLayout_15->addWidget(btnSaveConfig);


        horizontalLayout_16->addLayout(horizontalLayout_15);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        btnConnect = new QPushButton(layoutWidget1);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        horizontalLayout_16->addWidget(btnConnect);

        lblConfig = new QLabel(FrmClient);
        lblConfig->setObjectName(QString::fromUtf8("lblConfig"));
        lblConfig->setGeometry(QRect(20, 180, 413, 17));
        layoutWidget2 = new QWidget(FrmClient);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 50, 284, 91));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lblIpServer = new QLabel(layoutWidget2);
        lblIpServer->setObjectName(QString::fromUtf8("lblIpServer"));

        verticalLayout_6->addWidget(lblIpServer);

        lblPort = new QLabel(layoutWidget2);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));

        verticalLayout_6->addWidget(lblPort);

        lblPassword = new QLabel(layoutWidget2);
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
        txtIpServer = new QLineEdit(layoutWidget2);
        txtIpServer->setObjectName(QString::fromUtf8("txtIpServer"));

        verticalLayout_4->addWidget(txtIpServer);

        txtPort = new QLineEdit(layoutWidget2);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));

        verticalLayout_4->addWidget(txtPort);

        txtPassword = new QLineEdit(layoutWidget2);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));

        verticalLayout_4->addWidget(txtPassword);


        horizontalLayout->addLayout(verticalLayout_4);

        layoutWidget3 = new QWidget(FrmClient);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(320, 50, 191, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblIpClient = new QLabel(layoutWidget3);
        lblIpClient->setObjectName(QString::fromUtf8("lblIpClient"));

        horizontalLayout_3->addWidget(lblIpClient);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lblIpClient2 = new QLabel(layoutWidget3);
        lblIpClient2->setObjectName(QString::fromUtf8("lblIpClient2"));

        horizontalLayout_3->addWidget(lblIpClient2);


        retranslateUi(FrmClient);

        QMetaObject::connectSlotsByName(FrmClient);
    } // setupUi

    void retranslateUi(QWidget *FrmClient)
    {
        FrmClient->setWindowTitle(QApplication::translate("FrmClient", "MST - Client", nullptr));
        lblInfoServer->setText(QApplication::translate("FrmClient", "lblInfoServer", nullptr));
        lblBandwidth->setText(QApplication::translate("FrmClient", "lblBandwidth", nullptr));
        lblBandwidthvalue->setText(QApplication::translate("FrmClient", "lblBandwidthvalue", nullptr));
        label_3->setText(QApplication::translate("FrmClient", "mbit/s", nullptr));
        lblResolution->setText(QApplication::translate("FrmClient", "lblResolution", nullptr));
        lblFps->setText(QApplication::translate("FrmClient", "lblFps", nullptr));
        lblBuffer->setText(QApplication::translate("FrmClient", "lblBuffer", nullptr));
        lblVideo->setText(QApplication::translate("FrmClient", "lblVideo", nullptr));
        lblColorScale->setText(QApplication::translate("FrmClient", "lblColorScale", nullptr));
        lblEncoding->setText(QApplication::translate("FrmClient", "lblEncoding", nullptr));
        lblAudio->setText(QApplication::translate("FrmClient", "lblAudio", nullptr));
        lblControls->setText(QApplication::translate("FrmClient", "lblControls", nullptr));
        btnBack->setText(QApplication::translate("FrmClient", "btnBack", nullptr));
        btnLoadConfig->setText(QApplication::translate("FrmClient", "btnLoadConfig", nullptr));
        btnSaveConfig->setText(QApplication::translate("FrmClient", "btnSaveConfig", nullptr));
        btnConnect->setText(QApplication::translate("FrmClient", "btnConnect", nullptr));
        lblConfig->setText(QApplication::translate("FrmClient", "lblConfig", nullptr));
        lblIpServer->setText(QApplication::translate("FrmClient", "lblIpServer", nullptr));
        lblPort->setText(QApplication::translate("FrmClient", "lblPort", nullptr));
        lblPassword->setText(QApplication::translate("FrmClient", "lblPassword", nullptr));
        txtIpServer->setText(QString());
        lblIpClient->setText(QApplication::translate("FrmClient", "lblIpClient", nullptr));
        lblIpClient2->setText(QApplication::translate("FrmClient", "lblIpClient2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmClient: public Ui_FrmClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCLIENT_H
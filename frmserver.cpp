#include "frmserver.h"
#include "ui_frmserver.h"

FrmServer::FrmServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmServer)
{
    ui->setupUi(this);
}

FrmServer::~FrmServer()
{
    delete ui;
}

void FrmServer::setDict(Dictionary* d)
{
    dict = d;
    ui->lblInfoServer->setText(QString::fromStdString((*dict).getTextOflblInfoServer()));
    ui->lblIp->setText(QString::fromStdString((*dict).getTextOflblIp()));
    ui->lblPort->setText(QString::fromStdString((*dict).getTextOflblPort()));
    ui->lblPassword->setText(QString::fromStdString((*dict).getTextOflblPassword()));
    ui->lblSource->setText(QString::fromStdString((*dict).getTextOflblSource()));
    ui->lblConfig->setText(QString::fromStdString((*dict).getTextOflblConfig()));
    ui->lblLeaveConfig->setText(QString::fromStdString((*dict).getTextOflblLeaveConfig()));
    ui->lblResolution->setText(QString::fromStdString((*dict).getTextOflblResolution()));
    ui->lblFps->setText(QString::fromStdString((*dict).getTextOflblFps()));
    ui->lblBuffer->setText(QString::fromStdString((*dict).getTextOflblBuffer()));
    ui->lblVideo->setText(QString::fromStdString((*dict).getTextOflblVideo()));
    ui->lblColorScale->setText(QString::fromStdString((*dict).getTextOflblColorScale()));
    ui->lblEncoding->setText(QString::fromStdString((*dict).getTextOflblEncoding()));
    ui->lblAudio->setText(QString::fromStdString((*dict).getTextOflblAudio()));
    ui->lblControls->setText(QString::fromStdString((*dict).getTextOflblControls()));
    ui->lblBandwidth->setText(QString::fromStdString((*dict).getTextOflblBandwidth()));
    ui->lblBandwidthvalue->setText(QString::fromStdString((*dict).getTextOflblBandwidthvalue()));
    ui->btnBack->setText(QString::fromStdString((*dict).getTextOfbtnBack()));
    ui->btnLoadConfig->setText(QString::fromStdString((*dict).getTextOfbtnLoadConfig()));
    ui->btnSaveConfig->setText(QString::fromStdString((*dict).getTextOfbtnSaveConfig()));
    ui->btnStartServer->setText(QString::fromStdString((*dict).getTextOfbtnStartServer()));
}

void FrmServer::setSelector(int *selector)
{
    this->selector = selector;
}
void FrmServer::on_btnBack_clicked()
{
    *selector = 0;
    this->close();
}

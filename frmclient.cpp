#include "frmclient.h"
#include "ui_frmclient.h"

FrmClient::FrmClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmClient)
{
    ui->setupUi(this);
    setFixedSize(size());
}

FrmClient::~FrmClient()
{
    if(*selector == 2)
        *selector = -1;
    delete ui;
}

void FrmClient::setDict(Dictionary* d)
{
    dict = d;
    ui->lblInfoServer->setText(QString::fromStdString((*dict).getTextOflblInfoServer()));
    (*dict).setTextOflblIpC(ui->lblIp);
    (*dict).setTextOflblPort(ui->lblPort);
    (*dict).setTextOflblPasswordC(ui->lblPassword);
    ui->lblConfig->setText(QString::fromStdString((*dict).getTextOflblConfig()));
    (*dict).setTextOflblResolution(ui->lblResolution);
    (*dict).setTextOflblFps(ui->lblFps);
    (*dict).setTextOflblBuffer(ui->lblBuffer);
    (*dict).setTextOflblVideo(ui->lblVideo);
    (*dict).setTextOflblColorScale(ui->lblColorScale);
    (*dict).setTextOflblEncoding(ui->lblEncoding);
    (*dict).setTextOflblAudio(ui->lblAudio);
    (*dict).setTextOflblControls(ui->lblControls);
    ui->lblBandwidth->setText(QString::fromStdString((*dict).getTextOflblBandwidth()));
    ui->lblBandwidthvalue->setText(QString::fromStdString((*dict).getTextOflblBandwidthvalue()));
    ui->btnBack->setText(QString::fromStdString((*dict).getTextOfbtnBack()));
    ui->btnLoadConfig->setText(QString::fromStdString((*dict).getTextOfbtnLoadConfig()));
    ui->btnSaveConfig->setText(QString::fromStdString((*dict).getTextOfbtnSaveConfig()));
    ui->btnConnect->setText(QString::fromStdString((*dict).getTextOfbtnConnect()));
    (*dict).fillcmbResolution(ui->cmbResolution);
    (*dict).fillcmbColorScale(ui->cmbColorScale);
    (*dict).fillcmbFps(ui->cmbFps);
    (*dict).fillcmbBuffer(ui->cmbBuffer);
    (*dict).fillcmbControls(ui->cmbControls);
}

void FrmClient::setSelector(int *selector)
{
    this->selector = selector;
}
void FrmClient::on_btnBack_clicked()
{
    *selector = 0;
    this->close();
}

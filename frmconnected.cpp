#include "frmconnected.h"
#include "ui_frmconnected.h"

FrmConnected::FrmConnected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmConnected)
{
    ui->setupUi(this);
    ui->lblResize2->setText("100%");
}

FrmConnected::~FrmConnected()
{
    delete ui;
}

void FrmConnected::setDict(Dictionary* dict)
{
    this->dict = dict;
    (*dict).getTextOflblResize(ui->lblResize);
    ui->chkFullScreen->setText(QString::fromStdString((*dict).getTextOfchkFullscreen()));
    ui->btnDisconnect->setText(QString::fromStdString((*dict).getTextOfbtnDisconnect()));
}

void FrmConnected::setSelector(int* selector)
{
    this->selector = selector;
}

void FrmConnected::on_btnDisconnect_clicked()
{
    *selector = 2;
    this->close();
}

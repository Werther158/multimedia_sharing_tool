#include "frmconnected.h"
#include "ui_frmconnected.h"

FrmConnected::FrmConnected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmConnected)
{
    ui->setupUi(this);
}

FrmConnected::~FrmConnected()
{
    delete ui;
}

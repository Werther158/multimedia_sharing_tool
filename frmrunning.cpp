#include "frmrunning.h"
#include "ui_frmrunning.h"

FrmRunning::FrmRunning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmRunning)
{
    ui->setupUi(this);
}

FrmRunning::~FrmRunning()
{
    delete ui;
}

#include "frmmain.h"
#include "ui_frmmain.h"
#include "dictionary.h"
#include "QString"

#include "iostream"

FrmMain::FrmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmMain)
{
    current_theme = light;
    ui->setupUi(this);
    setFixedSize(size());
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::setDict(Dictionary d)
{
    dict = d;
    ui->lblStart->setText(QString::fromStdString(dict.getTextOflblStart()));
    ui->btnServer->setText(QString::fromStdString(dict.getTextOfbtnServer()));
    ui->btnClient->setText(QString::fromStdString(dict.getTextOfbtnClient()));
    ui->lblTheme->setText(QString::fromStdString(dict.getTextOflblTheme()));
    ui->lblLang->setText(QString::fromStdString(dict.getTextOflblLang()));
    if(current_theme == light)
        ui->btnTheme->setText(QString::fromStdString(dict.getTextOfbtnTheme().voices[1]));
    else
        ui->btnTheme->setText(QString::fromStdString(dict.getTextOfbtnTheme().voices[0]));
    ui->btnLang->setText(QString::fromStdString(dict.getTextOfbtnLang()));
}

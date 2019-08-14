#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    setFixedSize(size());

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()- static_cast<int>(width()*0.5),center.y()- static_cast<int>(height()*0.5));

    // Set Icons
    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap server_img(":/resources/media/server.png");
    QIcon ServerIcon(server_img);
    ui->btnServer->setIcon(ServerIcon);
    ui->btnServer->setIconSize(server_img.rect().size());

    QPixmap client_img(":/resources/media/client.png");
    QIcon ClientIcon(client_img);
    ui->btnClient->setIcon(ClientIcon);
    ui->btnClient->setIconSize(client_img.rect().size());

    QPixmap exit_img(":/resources/media/exit.png");
    QIcon ExitIcon(exit_img);
    ui->btnExit->setIcon(ExitIcon);
    ui->btnExit->setIconSize(exit_img.rect().size());
}

FrmMain::~FrmMain()
{
    if(*selector == 0)
        *selector = -1;
    delete ui;
}

void FrmMain::setDict(Dictionary* d)
{
    dict = d;
    ui->lblStart->setText(QString::fromStdString((*dict).getTextOflblStart()));
    ui->btnServer->setText(QString::fromStdString((*dict).getTextOfbtnServer()));
    ui->btnClient->setText(QString::fromStdString((*dict).getTextOfbtnClient()));
    ui->lblLang->setText(QString::fromStdString((*dict).getTextOflblLang()));
    (*dict).setIconOfbtnLang(ui->btnLang);
    ui->btnExit->setText(QString::fromStdString((*dict).getTextOfbtnExit()));
}

void FrmMain::on_btnLang_clicked()
{
    if (dict->getLanguage() == italian)
        dict->setLanguage(english);
    else
        dict->setLanguage(italian);

    setDict(dict);
}

void FrmMain::setSelector(int *selector)
{
    this->selector = selector;
}

void FrmMain::on_btnServer_clicked()
{
    *selector = 1;
    this->close();
}

void FrmMain::on_btnClient_clicked()
{
    *selector = 2;
    this->close();
}

void FrmMain::on_btnExit_clicked()
{
    *selector = -1;
    this->close();
}

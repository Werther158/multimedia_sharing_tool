#include "frmrunning.h"
#include "ui_frmrunning.h"

FrmRunning::FrmRunning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmRunning)
{
    ui->setupUi(this);

    QPixmap yellow_state(QDir::currentPath() + "/media/yellow_state.png");
    ui->lblState2->setPixmap(yellow_state);

    QPixmap eye(QDir::currentPath() + "/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    tcp_server_thread = new TcpServerThread();
    QObject::connect(tcp_server_thread, SIGNAL(writeText(QString)), this, SLOT(writeTextOnTxtBox(QString)));
    tcp_server_thread->start();
}

FrmRunning::~FrmRunning()
{
    delete ui;
}

void FrmRunning::setDict(Dictionary* dict)
{
    this->dict = dict;
    (*dict).getTextOflblStateRunning(ui->lblState);
    ui->btnStop->setText(QString::fromStdString((*dict).getTextOfbtnStopRunning()));
}

void FrmRunning::setSelector(int* selector)
{
    this->selector = selector;
}

void FrmRunning::on_btnStop_clicked()
{
    *selector = 1;
    this->close();
}

void FrmRunning::writeTextOnTxtBox(QString str)
{
    ui->txtBox->append(str);
}

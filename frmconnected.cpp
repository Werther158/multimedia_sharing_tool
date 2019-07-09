#include "frmconnected.h"
#include "ui_frmconnected.h"

FrmConnected::FrmConnected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmConnected)
{
    ui->setupUi(this);
    ui->lblResize2->setText("100%");

    QPixmap eye(QDir::currentPath() + "/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    // Start TcpClientThread
    tcp_client_thread = new TcpClientThread();
    tcp_client_thread->setConnectivity(&c);
    QObject::connect(tcp_client_thread, SIGNAL(writeText(QString)), this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(tcp_client_thread, SIGNAL(clientConnected()), this, SLOT(clientConnected()));
    QObject::connect(tcp_client_thread, SIGNAL(otherGuyDisconnected()), this, SLOT(otherGuyDisconnected()));
    tcp_client_thread->start();
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
    c.tcpWriteCommand(-1);
    disconnect(tcp_client_thread, nullptr, nullptr, nullptr);
    tcp_client_thread->terminate();
    tcp_client_thread->wait();
    *selector = 2;
    this->close();
}

void FrmConnected::on_btnSend_clicked()
{
    if(ui->txtLine->text() != "")
    {
        c.tcpWriteData(ui->txtLine->text());
        ui->txtLine->setText("");
    }
}

void FrmConnected::writeTextOnTxtBox(QString str)
{
    ui->txtBox->append(str);
}

void FrmConnected::clientConnected()
{
    this->setWindowTitle("MST - Connected");
}

void FrmConnected::otherGuyDisconnected()
{
    tcp_client_thread->terminate();
    tcp_client_thread->wait();
    *selector = 2;
    this->close();
}

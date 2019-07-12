#include "frmrunning.h"
#include "ui_frmrunning.h"

FrmRunning::FrmRunning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmRunning)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowIcon(QIcon("./media/mst_logo.png"));

    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->btnStopStream->setEnabled(false);
    enableListConfiguration();

    startServer();

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()- static_cast<int>(width()*0.5),center.y()- static_cast<int>(height()*0.5));
}

FrmRunning::~FrmRunning()
{
    delete ui;
}

void FrmRunning::startServer()
{
    QPixmap grey_state(QDir::currentPath() + "/media/grey_state.png");
    ui->lblState2->setPixmap(grey_state);
    QPixmap stream_inactive_pix(QDir::currentPath() + "/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);

    tcp_server_thread = new TcpServerThread();
    tcp_server_thread->setConnectivity(&c);
    QObject::connect(tcp_server_thread, SIGNAL(writeText(QString)), this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(tcp_server_thread, SIGNAL(clientConnected()), this, SLOT(clientConnected()));
    QObject::connect(tcp_server_thread, SIGNAL(otherGuyDisconnected()), this, SLOT(otherGuyDisconnected()));
    QObject::connect(tcp_server_thread, SIGNAL(startServerStream()), this, SLOT(startServerStream()));
    QObject::connect(tcp_server_thread, SIGNAL(streamingEnded()), this, SLOT(streamingEnded()));
    tcp_server_thread->start();
}

void FrmRunning::setDict(Dictionary* dict)
{
    this->dict = dict;
    (*dict).getTextOflblStateRunning(ui->lblState);
    (*dict).setTooltipOflblState2(ui->lblState2);
    (*dict).setTooltipOflblState3(ui->lblState3);
    ui->btnStop->setText(QString::fromStdString((*dict).getTextOfbtnStopRunning()));
    ui->btnStopStream->setText(QString::fromStdString((*dict).getTextOfbtnStopStream()));
}

void FrmRunning::setSelector(int* selector)
{
    this->selector = selector;
}

void FrmRunning::on_btnStop_clicked()
{
    client_connected = false;
    c.tcpWriteCommand(-1);
    stopThreads();
    *selector = 1;
    this->close();
}

void FrmRunning::writeTextOnTxtBox(QString str)
{
    ui->txtBox->append(str);
}

void FrmRunning::on_btnSend_clicked()
{
    if(ui->txtLine->text() != "" && client_connected)
    {
        c.tcpWriteData(ui->txtLine->text());
        ui->txtLine->setText("");
    }
}

void FrmRunning::clientConnected()
{
    client_connected = true;
    QPixmap green_state(QDir::currentPath() + "/media/green_state.png");
    ui->lblState2->setPixmap(green_state);
}

void FrmRunning::otherGuyDisconnected()
{
    client_connected = false;
    stopThreads();
    ui->txtBox->clear();
    startServer();
}

void FrmRunning::stopThreads()
{
    disconnect(tcp_server_thread, nullptr, nullptr, nullptr);
    tcp_server_thread->terminate();
    tcp_server_thread->wait();
    c.killTcpSocket();

    if(is_stream_active)
    {
        ui->btnStopStream->setEnabled(false);
        disconnect(server_stream_thread, nullptr, nullptr, nullptr);
        server_stream_thread->~ServerStreamThread();
        is_stream_active = false;
    }
}

void FrmRunning::enableListConfiguration()
{
    QPixmap eye(QDir::currentPath() + "/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    ui->listConfigurations->setHidden(false);
}
void FrmRunning::disableListConfiguration()
{
    QPixmap eyegrey(QDir::currentPath() + "/media/eyegrey.png");
    QIcon eye_button(eyegrey);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eyegrey.size());

    ui->listConfigurations->setHidden(true);
}

void FrmRunning::on_btnToggleConfig_clicked()
{
    if(listconfig_active)
    {
        disableListConfiguration();
        listconfig_active = false;
    }
    else
    {
        enableListConfiguration();
        listconfig_active = true;
    }
}

void FrmRunning::startServerStream()
{
    ui->txtBox->append("Streaming started");
    // Start serverStreamThread
    server_stream_thread = new ServerStreamThread();
    QObject::connect(server_stream_thread, SIGNAL(writeText(QString)), this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(server_stream_thread, SIGNAL(stopStream()), this, SLOT(stopStream()));
    server_stream_thread->start();
    ui->btnStopStream->setEnabled(true);
    is_stream_active = true;
    QPixmap stream_active_pix(QDir::currentPath() + "/media/stream_active.png");
    ui->lblState3->setPixmap(stream_active_pix);
}

void FrmRunning::stopStream()
{
    ui->txtBox->append("Streaming ended");
    ui->btnStopStream->setEnabled(false);
    c.tcpWriteCommand(-3);
    is_stream_active = false;
    disconnect(server_stream_thread, nullptr, nullptr, nullptr);
    server_stream_thread->~ServerStreamThread();
    QPixmap stream_inactive_pix(QDir::currentPath() + "/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);
}

void FrmRunning::on_btnStopStream_clicked()
{
    stopStream();
}

void FrmRunning::streamingEnded()
{
    ui->txtBox->append("Streaming ended");
    QPixmap stream_inactive_pix(QDir::currentPath() + "/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);
    if(is_stream_active)
    {
        ui->btnStopStream->setEnabled(false);
        disconnect(server_stream_thread, nullptr, nullptr, nullptr);
        server_stream_thread->~ServerStreamThread();
        is_stream_active = false;
    }
}

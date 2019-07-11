#include "frmconnected.h"
#include "ui_frmconnected.h"

FrmConnected::FrmConnected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmConnected)
{
    ui->setupUi(this);
    ui->lblResize2->setText("100%");
    setFixedSize(size());
    setWindowIcon(QIcon("./media/mst_logo.png"));
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    enableListConfiguration();

    QPixmap grey_state(QDir::currentPath() + "/media/grey_state.png");
    ui->lblState2->setPixmap(grey_state);
    uiStreamingInactive();
    // Start TcpClientThread
    tcp_client_thread = new TcpClientThread();
    tcp_client_thread->setConnectivity(&c);
    QObject::connect(tcp_client_thread, SIGNAL(writeText(QString)), this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(tcp_client_thread, SIGNAL(clientConnected()), this, SLOT(clientConnected()));
    QObject::connect(tcp_client_thread, SIGNAL(otherGuyDisconnected()), this, SLOT(otherGuyDisconnected()));
    QObject::connect(tcp_client_thread, SIGNAL(stopReceivingVideoStream(bool)), this, SLOT(stopReceivingVideoStream(bool)));
    tcp_client_thread->start();

    ui->btnStartStreaming->setEnabled(false);
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
    (*dict).getTextOfbtnStartStreaming(ui->btnStartStreaming);
    (*dict).getTextOflblStateRunning(ui->lblState);
    (*dict).setTooltipOflblState2(ui->lblState2);
    (*dict).setTooltipOflblState3(ui->lblState3);
}

void FrmConnected::setSelector(int* selector)
{
    this->selector = selector;
}

void FrmConnected::on_btnDisconnect_clicked()
{
    client_connected = false;
    c.tcpWriteCommand(-1);
    stopThreads();
    *selector = 2;
    this->close();
}

void FrmConnected::on_btnSend_clicked()
{
    if(ui->txtLine->text() != "" && client_connected)
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
    client_connected = true;
    this->setWindowTitle("MST - Connected");
    ui->btnStartStreaming->setEnabled(true);
    QPixmap green_state(QDir::currentPath() + "/media/green_state.png");
    ui->lblState2->setPixmap(green_state);
}

void FrmConnected::otherGuyDisconnected()
{
    client_connected = false;
    stopThreads();
    *selector = 2;
    this->close();
}

void FrmConnected::enableListConfiguration()
{
    QPixmap eye(QDir::currentPath() + "/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    ui->listConfigurations->setHidden(false);
}

void FrmConnected::disableListConfiguration()
{
    QPixmap eyegrey(QDir::currentPath() + "/media/eyegrey.png");
    QIcon eye_button(eyegrey);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eyegrey.size());

    ui->listConfigurations->setHidden(true);
}

void FrmConnected::on_btnToggleConfig_clicked()
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

void FrmConnected::sendStartStreamingCommand()
{
    uiStreamingActive();
    c.tcpWriteCommand(-2);
}

void FrmConnected::on_btnStartStreaming_clicked()
{
    if(client_connected)
    {
        // Start streaming thread
        ui->txtBox->append("Streaming started");
        client_stream_thread = new ClientStreamThread();
        QObject::connect(client_stream_thread, SIGNAL(sendStartStreamingCommand()), this, SLOT(sendStartStreamingCommand()));
        QObject::connect(client_stream_thread, SIGNAL(streamingEnded()), this, SLOT(streamingEnded()));
        client_stream_thread->start();
        is_stream_active = true;
        ui->btnStartStreaming->setEnabled(false);
    }
}

void FrmConnected::stopThreads()
{
    disconnect(tcp_client_thread, nullptr, nullptr, nullptr);
    tcp_client_thread->terminate();
    tcp_client_thread->wait();
    c.killTcpSocket();

    if(is_stream_active)
    {
        std::system("killall ffplay");
        disconnect(client_stream_thread, nullptr, nullptr, nullptr);
        client_stream_thread->~ClientStreamThread();
        is_stream_active = false;
        uiStreamingInactive();
    }
}

void FrmConnected::stopReceivingVideoStream(bool is_video_ended)
{
    if(is_stream_active)
    {
        if(!is_video_ended)
            std::system("killall ffplay");

        ui->txtBox->append("Streaming ended");
        disconnect(client_stream_thread, nullptr, nullptr, nullptr);
        client_stream_thread->~ClientStreamThread();
        is_stream_active = false;
        ui->btnStartStreaming->setEnabled(true);
        uiStreamingInactive();
    }
}

void FrmConnected::uiStreamingActive()
{
    QPixmap stream_active_pix(QDir::currentPath() + "/media/stream_active.png");
    ui->lblState3->setPixmap(stream_active_pix);
    ui->chkFullScreen->setEnabled(true);
    ui->lblResize->setEnabled(true);
    ui->scrollbarResize->setEnabled(true);
    ui->lblResize2->setEnabled(true);
}

void FrmConnected::uiStreamingInactive()
{
    QPixmap stream_inactive_pix(QDir::currentPath() + "/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);
    ui->chkFullScreen->setEnabled(false);
    ui->lblResize->setEnabled(false);
    ui->scrollbarResize->setEnabled(false);
    ui->lblResize2->setEnabled(false);
}

void FrmConnected::streamingEnded()
{
    stopReceivingVideoStream(true);
    c.tcpWriteCommand(-4);
}

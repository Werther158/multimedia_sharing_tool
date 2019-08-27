//_____________________________________________________________________________
//_____________________________________________________________________________
//                             FRAME CONNECTED
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "frmconnected.h"
#include "ui_frmconnected.h"

FrmConnected::FrmConnected(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmConnected)
{
    ui->setupUi(this);
    ui->lblResize2->setText("100%");
    setFixedSize(size());
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    client_connected = false;
    listconfig_active = true;
    is_stream_active = false;

    enableListConfiguration();

    QPixmap grey_state(":/resources/media/grey_state.png");
    ui->lblState2->setPixmap(grey_state);
    uiStreamingInactive();
    // Start TcpClientThread
    tcp_client_thread = new TcpClientThread();
    tcp_client_thread->setConnectivity(&c);
    QObject::connect(tcp_client_thread, SIGNAL(writeText(QString)),
                     this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(tcp_client_thread, SIGNAL(clientConnected()),
                     this, SLOT(clientConnected()));
    QObject::connect(tcp_client_thread, SIGNAL(otherGuyDisconnected()),
                     this, SLOT(otherGuyDisconnected()));
    QObject::connect(tcp_client_thread, SIGNAL(stopReceivingVideoStream(bool)),
                     this, SLOT(stopReceivingVideoStream(bool)));
    QObject::connect(tcp_client_thread, SIGNAL(startStreaming()),
                     this, SLOT(startStreaming()));
    tcp_client_thread->start();

    ui->btnStartStopStreaming->setEnabled(false);

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()- static_cast<int>(width()*0.5),
         center.y()- static_cast<int>(height()*0.5));

    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap disconnect_img(":/resources/media/disconnect.png");
    QIcon DisconnectIcon(disconnect_img);
    ui->btnDisconnect->setIcon(DisconnectIcon);
    ui->btnDisconnect->setIconSize(disconnect_img.rect().size());

    // Fill listConfigurations
    QStandardItemModel *model = new QStandardItemModel(6, 1, this);
    (*dict).fillModel(model);
    ui->listConfigurations->setModel(model);
}

FrmConnected::~FrmConnected()
{
    delete ui;
}

/**
 * Set text of gui controls according to the current selected language.
 * @param   : dict; set current dictionary based on current language.
 * @return  : void.
*/
void FrmConnected::setDict(Dictionary* dict)
{
    this->dict = dict;
    (*dict).getTextOflblResize(ui->lblResize);
    ui->chkFullScreen->setText(QString::fromStdString
                               ((*dict).getTextOfchkFullscreen()));
    ui->btnDisconnect->setText(QString::fromStdString
                               ((*dict).getTextOfbtnDisconnect(0)));
    (*dict).getTextOfbtnStartStreaming(ui->btnStartStopStreaming, 0);
    (*dict).getTextOflblStateRunning(ui->lblState);
    (*dict).setTooltipOflblState2(ui->lblState2);
    (*dict).setTooltipOflblState3(ui->lblState3);
}

/**
 * Set the application selector.
 * @param   : selector; variable passed from the main.
 * @return  : void.
*/
void FrmConnected::setSelector(int* selector)
{
    this->selector = selector;
}

/**
 * Stop running threads and close current frame.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::on_btnDisconnect_clicked()
{
    if(client_connected)
    {
        ui->btnDisconnect->setEnabled(false);
        ui->btnDisconnect->repaint();
        client_connected = false;
        c.tcpWriteCommand(-1);
    }

    stopThreads();
    *selector = 2;
    this->close();
}

/**
 * Send a text message to the server.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::on_btnSend_clicked()
{
    if(ui->txtLine->text() != "" && client_connected)
    {
        c.tcpWriteData(ui->txtLine->text());
        ui->txtLine->setText("");
    }
}

/**
 * Append text on textBox.
 * @param   : str; QString to append.
 * @return  : void.
*/
void FrmConnected::writeTextOnTxtBox(QString str)
{
    ui->txtBox->append(str);
}

/**
 * Write on textBox the connection event of the client and change gui labels.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::clientConnected()
{
    client_connected = true;
    ui->btnDisconnect->setText(QString::fromStdString
                               ((*dict).getTextOfbtnDisconnect(1)));
    this->setWindowTitle("MST - Connected");
    ui->btnStartStopStreaming->setEnabled(true);
    QPixmap green_state(":/resources/media/green_state.png");
    ui->lblState2->setPixmap(green_state);
}

/**
 * Close the client session when the server is shutted down.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::otherGuyDisconnected()
{
    client_connected = false;
    stopThreads();
    *selector = 2;
    this->close();
}

/**
 * Set list configuration visible.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::enableListConfiguration()
{
    QPixmap eye(":/resources/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    ui->listConfigurations->setHidden(false);
}

/**
 * Set list configuration not visible.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::disableListConfiguration()
{
    QPixmap eyegrey(":/resources/media/eyegrey.png");
    QIcon eye_button(eyegrey);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eyegrey.size());

    ui->listConfigurations->setHidden(true);
}

/**
 * Enable (or disable) list configuration.
 * @param   : void.
 * @return  : void.
*/
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

/**
 * Set streaming active and send streaming command.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::sendStartStreamingCommand()
{
    uiStreamingActive();
    c.tcpWriteCommand(-2);
}

/**
 * Start streaming thread.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::startStreaming()
{
    ui->txtBox->append("Streaming started");
    (*dict).getTextOfbtnStartStreaming(ui->btnStartStopStreaming, 1);
    client_stream_thread = new ClientStreamThread();
    QObject::connect(client_stream_thread, SIGNAL(sendStartStreamingCommand()),
                     this, SLOT(sendStartStreamingCommand()));
    QObject::connect(client_stream_thread, SIGNAL(streamingEnded()),
                     this, SLOT(streamingEnded()));
    client_stream_thread->start();
    is_stream_active = true;
}

/**
 * Activate (or deactivate) streaming.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::on_btnStartStopStreaming_clicked()
{
    if(client_connected)
    {
        if(is_stream_active)
        {
            ui->btnStartStopStreaming->setEnabled(false);
            ui->btnStartStopStreaming->repaint();
            c.tcpWriteCommand(-4);
            ui->btnStartStopStreaming->setEnabled(true);
        }
        else
        {
            ui->btnStartStopStreaming->setEnabled(false);
            ui->btnStartStopStreaming->repaint();
            startStreaming();
            ui->btnStartStopStreaming->setEnabled(true);
        }
    }
}

/**
 * Stop all active sub-threads.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::stopThreads()
{
    disconnect(tcp_client_thread, nullptr, nullptr, nullptr);
    tcp_client_thread->terminate();
    tcp_client_thread->wait();
    c.killTcpSocket();

    if(is_stream_active)
    {
        std::system("bash -c \"killall ffplay\"");
        disconnect(client_stream_thread, nullptr, nullptr, nullptr);
        client_stream_thread->~ClientStreamThread();
        is_stream_active = false;
        uiStreamingInactive();
    }
}

/**
 * Kill FFplay and set streaming ended.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::stopReceivingVideoStream(bool is_video_ended)
{
    if(is_stream_active)
    {
        if(!is_video_ended)
            std::system("bash -c \"killall ffplay\"");

        ui->txtBox->append("Streaming ended");
        disconnect(client_stream_thread, nullptr, nullptr, nullptr);
        client_stream_thread->~ClientStreamThread();
        is_stream_active = false;
        uiStreamingInactive();
        (*dict).getTextOfbtnStartStreaming(ui->btnStartStopStreaming, 0);
    }
}

/**
 * Set streaming active.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::uiStreamingActive()
{
    QPixmap stream_active_pix(":/resources/media/stream_active.png");
    ui->lblState3->setPixmap(stream_active_pix);
    ui->chkFullScreen->setEnabled(true);
    ui->lblResize->setEnabled(true);
    ui->scrollbarResize->setEnabled(true);
    ui->lblResize2->setEnabled(true);
}

/**
 * Set streaming inactive.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::uiStreamingInactive()
{
    QPixmap stream_inactive_pix(":/resources/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);
    ui->chkFullScreen->setEnabled(false);
    ui->lblResize->setEnabled(false);
    ui->scrollbarResize->setEnabled(false);
    ui->lblResize2->setEnabled(false);
}

/**
 * Send streaming ended command.
 * @param   : void.
 * @return  : void.
*/
void FrmConnected::streamingEnded()
{
    c.tcpWriteCommand(-4);
}

#include "frmrunning.h"
#include "ui_frmrunning.h"


FrmRunning::FrmRunning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmRunning)
{
    ui->setupUi(this);
    setFixedSize(size());

    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->btnStartStopStream->setEnabled(false);
    enableListConfiguration();

    startServer();

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()- static_cast<int>(width()*0.5),center.y()- static_cast<int>(height()*0.5));

    ui->txtLine->installEventFilter(this);

    // Set icons

    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap sserver_img(":/resources/media/stop_server.png");
    QIcon SServerIcon(sserver_img);
    ui->btnStop->setIcon(SServerIcon);
    ui->btnStop->setIconSize(sserver_img.rect().size());

    qRegisterMetaType<cv::Mat>("cv::Mat");
}

FrmRunning::~FrmRunning()
{
    delete ui;
}

void FrmRunning::startServer()
{
    QPixmap grey_state(":/resources/media/grey_state.png");
    ui->lblState2->setPixmap(grey_state);
    QPixmap stream_inactive_pix(":/resources/media/stream_inactive.png");
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
    (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
    ui->btnStop->setText(QString::fromStdString((*dict).getTextOfbtnStopRunning()));
}

void FrmRunning::setSelector(int* selector)
{
    this->selector = selector;
}

void FrmRunning::on_btnStop_clicked()
{
    ui->btnStartStopStream->setEnabled(false);
    ui->btnStartStopStream->repaint();
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
    QPixmap green_state(":/resources/media/green_state.png");
    ui->lblState2->setPixmap(green_state);
    ui->btnStartStopStream->setEnabled(true);
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
        ui->btnStartStopStream->setEnabled(false);
        ui->btnStartStopStream->repaint();
        (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
        disconnect(camera_thread, nullptr, nullptr, nullptr);
        camera_thread->~CameraThread();
        is_stream_active = false;
    }
}

void FrmRunning::enableListConfiguration()
{
    QPixmap eye(":/resources/media/eye.png");
    QIcon eye_button(eye);
    ui->btnToggleConfig->setText("");
    ui->btnToggleConfig->setIcon(eye_button);
    ui->btnToggleConfig->setIconSize(eye.size());

    ui->listConfigurations->setHidden(false);
}

void FrmRunning::disableListConfiguration()
{
    QPixmap eyegrey(":/resources/media/eyegrey.png");
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
    // Start cameraThread
    camera_thread = new CameraThread();
    QObject::connect(this, SIGNAL(takePictureDone()), camera_thread, SLOT(takePictureDone()));
    QObject::connect(camera_thread, SIGNAL(takeAScreenPicture()), this, SLOT(takeAScreenPicture()));
    QObject::connect(camera_thread, SIGNAL(saveCameraFrame(cv::Mat)), this, SLOT(saveCameraFrame(cv::Mat)));
    QObject::connect(this, SIGNAL(cameraFrameSaved()), camera_thread, SLOT(cameraFrameSaved()));
    camera_thread->start();

    is_stream_active = true;
    QPixmap stream_active_pix(":/resources/media/stream_active.png");
    ui->lblState3->setPixmap(stream_active_pix);
    (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 1);
    ui->btnStartStopStream->setEnabled(true);
}

void FrmRunning::stopStream()
{
    ui->txtBox->append("Streaming ended");
   (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
    c.tcpWriteCommand(-3);
    is_stream_active = false;
    disconnect(camera_thread, nullptr, nullptr, nullptr);
    camera_thread->~CameraThread();
    QPixmap stream_inactive_pix(":/resources/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);
}

void FrmRunning::on_btnStartStopStream_clicked()
{
    if(is_stream_active) // Stop stream
    {
        ui->btnStartStopStream->setEnabled(false);
        ui->btnStartStopStream->repaint();
        stopStream();
        (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
        ui->btnStartStopStream->setEnabled(true);
    }
    else // Start stream
    {
        ui->btnStartStopStream->setEnabled(false);
        ui->btnStartStopStream->repaint();
        c.tcpWriteCommand(-5);
    }
}

void FrmRunning::streamingEnded()
{
    ui->btnStartStopStream->setEnabled(false);
    ui->btnStartStopStream->repaint();
    if(is_stream_active)
        stopStream();
    (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
    ui->btnStartStopStream->setEnabled(true);
}

/**
 * Cattura dello schermo (deve prendere in ingresso l'area
 * tracciata dall'utente) e salvataggio in formato bmp.
 * @return  : void.
*/
void FrmRunning::takeAScreenPicture()
{
    ScreenShot screen(static_cast<int>(Configurations::rect.x),
                      static_cast<int>(Configurations::rect.y),
                      static_cast<int>(Configurations::rect.width),
                      static_cast<int>(Configurations::rect.height));
    cv::Mat imgCamera;
    screen(imgCamera);


    // Save image to /mst-temp/frames tik-tok folder
    imwrite(Configurations::current_frame_path + "/output.bmp", imgCamera);

    emit takePictureDone();
}

void FrmRunning::saveCameraFrame(cv::Mat frame)
{
    imwrite(Configurations::current_frame_path + "/output.bmp", frame);
    emit cameraFrameSaved();
}

//_____________________________________________________________________________
//_____________________________________________________________________________
//                             FRAME RUNNING
//_____________________________________________________________________________
//_____________________________________________________________________________

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
    move(center.x()- static_cast<int>(width()*0.5),
         center.y()- static_cast<int>(height()*0.5));

    ui->txtLine->installEventFilter(this);

    // Set icons

    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap sserver_img(":/resources/media/stop_server.png");
    QIcon SServerIcon(sserver_img);
    ui->btnStop->setIcon(SServerIcon);
    ui->btnStop->setIconSize(sserver_img.rect().size());

    fillListConfiguration();

    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<std::string>("std::string");
}

FrmRunning::~FrmRunning()
{
    delete ui;
}

/**
 * Fill listConfiguration accordingly to Configurations class parameters.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::fillListConfiguration()
{
    QStandardItemModel *model = new QStandardItemModel(7, 1, this);
    (*dict).fillModel(model);
    ui->listConfigurations->setModel(model);
}

/**
 * Set gui and start TCP server.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::startServer()
{
    QPixmap grey_state(":/resources/media/grey_state.png");
    ui->lblState2->setPixmap(grey_state);
    QPixmap stream_inactive_pix(":/resources/media/stream_inactive.png");
    ui->lblState3->setPixmap(stream_inactive_pix);

    tcp_server_thread = new TcpServerThread();
    tcp_server_thread->setConnectivity(&c);
    QObject::connect(tcp_server_thread, SIGNAL(writeText(QString)),
                     this, SLOT(writeTextOnTxtBox(QString)));
    QObject::connect(tcp_server_thread, SIGNAL(clientConnected()),
                     this, SLOT(clientConnected()));
    QObject::connect(tcp_server_thread, SIGNAL(otherGuyDisconnected()),
                     this, SLOT(otherGuyDisconnected()));
    QObject::connect(tcp_server_thread, SIGNAL(startServerStream()),
                     this, SLOT(startServerStream()));
    QObject::connect(tcp_server_thread, SIGNAL(streamingEnded()),
                     this, SLOT(streamingEnded()));
    tcp_server_thread->start();
}

/**
 * Set text of gui controls according to the current selected language.
 * @param   : dict; set current dictionary based on current language.
 * @return  : void.
*/
void FrmRunning::setDict(Dictionary* dict)
{
    this->dict = dict;
    (*dict).getTextOflblStateRunning(ui->lblState);
    (*dict).setTooltipOflblState2(ui->lblState2);
    (*dict).setTooltipOflblState3(ui->lblState3);
    (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 0);
    ui->btnStop->setText(QString::fromStdString
                         ((*dict).getTextOfbtnStopRunning()));
}

/**
 * Set the application selector.
 * @param   : selector; variable passed from the main.
 * @return  : void.
*/
void FrmRunning::setSelector(int* selector)
{
    this->selector = selector;
}

/**
 * Stop stream and send to client the stream stop command.
 * @param   : void.
 * @return  : void.
*/
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

/**
 * Append text to txtBox.
 * @param   : str; QString to append.
 * @return  : void.
*/
void FrmRunning::writeTextOnTxtBox(QString str)
{
    ui->txtBox->append(str);
}

/**
 * Send a text message to the client.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::on_btnSend_clicked()
{
    if(ui->txtLine->text() != "" && client_connected)
    {
        c.tcpWriteData(ui->txtLine->text());
        ui->txtLine->setText("");
    }
}

/**
 * Set boolean value of client connected at true and set the gui.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::clientConnected()
{
    char* resolution;

    fillListConfiguration();
    resolution = std::strtok((char*)Configurations::resolution_choices
                             [Configurations::resolution].c_str(), " x");
    if(Configurations::strToPositiveDigit(resolution) != -1)
    {
        Configurations::frame_size_changed = true;
        // Set new resolution to frame
        Configurations::frame_width = Configurations::strToPositiveDigit(resolution);
        resolution = std::strtok(nullptr, " x");
        Configurations::frame_height = Configurations::strToPositiveDigit(resolution);
    }
    client_connected = true;
    QPixmap green_state(":/resources/media/green_state.png");
    ui->lblState2->setPixmap(green_state);
    ui->btnStartStopStream->setEnabled(true);
}

/**
 * If client disconnects, set boolean value of client connected at false,
 * stop threads and restart the server.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::otherGuyDisconnected()
{
    client_connected = false;
    stopThreads();
    ui->txtBox->clear();
    startServer();
}

/**
 * Set list configuration visible.
 * @param   : void.
 * @return  : void.
*/
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

/**
 * Set list configuration visible.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::enableListConfiguration()
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
void FrmRunning::disableListConfiguration()
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

/**
 * Start camera thread and start sending video stream.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::startServerStream()
{
    ui->txtBox->append("Streaming started");
    // Start cameraThread
    camera_thread = new CameraThread();
    QObject::connect(this, SIGNAL(pictureReady()),
                     camera_thread, SLOT(pictureReady()));
    QObject::connect(camera_thread, SIGNAL(takeAScreenPicture()),
                     this, SLOT(takeAScreenPicture()));
    QObject::connect(camera_thread, SIGNAL(saveCameraFrame(cv::Mat)),
                     this, SLOT(saveCameraFrame(cv::Mat)));
    QObject::connect(this, SIGNAL(cameraFrameSaved()),
                     camera_thread, SLOT(cameraFrameSaved()));
    QObject::connect(camera_thread, SIGNAL(imageScaleBlur(std::string)),
                     this, SLOT(imageScaleBlur(std::string)));
    camera_thread->start();

    is_stream_active = true;
    QPixmap stream_active_pix(":/resources/media/stream_active.png");
    ui->lblState3->setPixmap(stream_active_pix);
    (*dict).setTIbtnStartStopStream(ui->btnStartStopStream, 1);
    ui->btnStartStopStream->setEnabled(true);
}

/**
 * Quit camera thread and stop stream.
 * @param   : void.
 * @return  : void.
*/
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

/**
 * Start (or stop) the streaming.
 * @param   : void.
 * @return  : void.
*/
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

/**
 * Set the gui to streaming stopped and call stopStream method.
 * @param   : void.
 * @return  : void.
*/
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

    emit pictureReady();
}

/**
 * Write camera frame to disk and emit write done signal.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::saveCameraFrame(cv::Mat frame)
{
    imwrite(Configurations::current_frame_path + "/output.bmp", frame);
    emit cameraFrameSaved();
}

/**
 * Scale resolution of a bmp image using CUDA.
 * @param   : void.
 * @return  : void.
*/
void FrmRunning::imageScaleBlur(std::string frame_path)
{
    cv::Mat input_host = cv::imread(frame_path);
    cv::Mat output_host;
    cv::cuda::GpuMat input_device(input_host);
    cv::cuda::GpuMat output_device, output_both;
    cv::Size size;

    if(Configurations::frame_size_changed)
    {
        // Set new resolution to frame
        size.width = Configurations::frame_width;
        size.height = Configurations::frame_height;
        cv::cuda::resize(input_device, output_device, size);
        if(Configurations::blur_effect != 0)
        {
            cv::Ptr<cv::cuda::Filter> gauss = cv::cuda::createGaussianFilter
                    (output_device.type(), output_both.type(),
                     cv::Size(21, 21), Configurations::blur_effect * 2,
                     Configurations::blur_effect * 2);
            gauss->apply(output_device, output_both);
        }
        else
            output_device.copyTo(output_both);

        output_both.download(output_host);
    }
    else
        input_host.copyTo(output_host);

    input_host.release();
    output_device.release();
    output_both.release();

    imwrite(frame_path, output_host);
    emit pictureReady();
}

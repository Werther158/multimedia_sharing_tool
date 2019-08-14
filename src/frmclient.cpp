#include "frmclient.h"
#include "ui_frmclient.h"

FrmClient::FrmClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmClient)
{
    ui->setupUi(this);
    std::string public_ip = Connectivity::getPublicIp();
    ui->lblIpClient2->setText(QString::fromStdString(public_ip));
    ui->txtIpServer->setText("127.0.0.1");
    ui->txtPort->setText("49152");
    setFixedSize(size());

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()- static_cast<int>(width()*0.5),center.y()- static_cast<int>(height()*0.5));

    // Set icons

    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap back_img(":/resources/media/back.png");
    QIcon BackIcon(back_img);
    ui->btnBack->setIcon(BackIcon);
    ui->btnBack->setIconSize(back_img.rect().size());

    QPixmap load_img(":/resources/media/load.png");
    QIcon LoadIcon(load_img);
    ui->btnLoadConfig->setIcon(LoadIcon);
    ui->btnLoadConfig->setIconSize(load_img.rect().size());

    QPixmap save_img(":/resources/media/save.png");
    QIcon SaveIcon(save_img);
    ui->btnSaveConfig->setIcon(SaveIcon);
    ui->btnSaveConfig->setIconSize(save_img.rect().size());

    QPixmap connect_img(":/resources/media/connect.png");
    QIcon ConnectIcon(connect_img);
    ui->btnConnect->setIcon(ConnectIcon);
    ui->btnConnect->setIconSize(connect_img.rect().size());
}

FrmClient::~FrmClient()
{
    if(*selector == 2)
        *selector = -1;
    delete ui;
}

void FrmClient::setDict(Dictionary* dict)
{
    this->dict = dict;
    ui->lblInfoServer->setText(QString::fromStdString((*dict).getTextOflblInfoServer()));
    (*dict).setTextOflblIpClientC(ui->lblIpClient);
    (*dict).setTextOflblIpServerC(ui->lblIpServer);
    (*dict).setTextOflblPort(ui->lblPort);
    (*dict).setTextOflblPasswordC(ui->lblPassword);
    ui->lblConfig->setText(QString::fromStdString((*dict).getTextOflblConfig()));
    (*dict).setTextOflblResolution(ui->lblResolution);
    (*dict).setTextOflblFps(ui->lblFps);
    (*dict).setTextOflblBuffer(ui->lblBuffer);
    (*dict).setTextOflblVideo(ui->lblVideo);
    (*dict).setTextOflblColorScale(ui->lblColorScale);
    (*dict).setTextOflblEncoding(ui->lblEncoding);
    (*dict).setTextOflblAudio(ui->lblAudio);
    (*dict).setTextOflblControls(ui->lblControls);
    ui->lblBandwidth->setText(QString::fromStdString((*dict).getTextOflblBandwidth()));
    ui->lblBandwidthvalue->setText(QString::fromStdString((*dict).getTextOflblBandwidthvalue()));
    ui->btnBack->setText(QString::fromStdString((*dict).getTextOfbtnBack()));
    ui->btnLoadConfig->setText(QString::fromStdString((*dict).getTextOfbtnLoadConfig()));
    ui->btnSaveConfig->setText(QString::fromStdString((*dict).getTextOfbtnSaveConfig()));
    ui->btnConnect->setText(QString::fromStdString((*dict).getTextOfbtnConnect()));
    (*dict).fillcmbResolution(ui->cmbResolution);
    (*dict).fillcmbColorScale(ui->cmbColorScale);
    (*dict).fillcmbFps(ui->cmbFps);
    (*dict).fillcmbBuffer(ui->cmbBuffer);
    (*dict).fillcmbControls(ui->cmbControls);
}

void FrmClient::setSelector(int *selector)
{
    this->selector = selector;
}

void FrmClient::on_btnBack_clicked()
{
    *selector = 0;
    this->close();
}

void FrmClient::setConfigurations()
{
    Configurations::system = CLIENT;
    Configurations::source = 0;
    Configurations::server_ip = ui->txtIpServer->text().toStdString();
    Configurations::client_ip = ui->lblIpClient2->text().toStdString();
    Configurations::port = static_cast<uint16_t>(stoi(ui->txtPort->text().toStdString()));
    Configurations::password = ui->txtPassword->text().toStdString();
    Configurations::leave_client_config = false;
    Configurations::resolution = static_cast<uint8_t>(ui->cmbResolution->currentIndex());
    Configurations::fps = static_cast<uint8_t>(ui->cmbFps->currentIndex());
    Configurations::buffer = static_cast<uint8_t>(ui->cmbBuffer->currentIndex());
    Configurations::color_scale = static_cast<uint8_t>(ui->cmbColorScale->currentIndex());
    Configurations::controls = static_cast<uint8_t>(ui->cmbControls->currentIndex());
    Configurations::file_name = "";
}

void FrmClient::on_btnConnect_clicked()
{
    ui->btnConnect->setEnabled(false);
    ui->btnConnect->repaint();
    setConfigurations();

    // Control that all data are correct
    if(Configurations::server_ip != "") // Controllo da cambiare, molto debole.
    {
        *selector = 4;
        this->close();
    }

}

//_____________________________________________________________________________
//_____________________________________________________________________________
//                             FRAME CLIENT
//_____________________________________________________________________________
//_____________________________________________________________________________

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
    move(center.x()- static_cast<int>(width()*0.5),
         center.y()- static_cast<int>(height()*0.5));

    // Set icons

    setWindowIcon(QIcon(":/resources/media/mst_logo.png"));

    QPixmap back_img(":/resources/media/back.png");
    QIcon BackIcon(back_img);
    ui->btnBack->setIcon(BackIcon);
    ui->btnBack->setIconSize(back_img.rect().size());

    QPixmap load_img(":/resources/media/load.png");
    QIcon LoadIcon(load_img);

    QPixmap save_img(":/resources/media/save.png");
    QIcon SaveIcon(save_img);

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

/**
 * Set text of gui controls according to the current selected language.
 * @param   : dict; set current dictionary based on current language.
 * @return  : void.
*/
void FrmClient::setDict(Dictionary* dict)
{
    this->dict = dict;
    ui->lblInfoServer->setText(QString::fromStdString
                               ((*dict).getTextOflblInfoServer()));
    (*dict).setTextOflblIpClientC(ui->lblIpClient);
    (*dict).setTextOflblIpServerC(ui->lblIpServer);
    (*dict).setTextOflblPort(ui->lblPort);
    (*dict).setTextOflblPasswordC(ui->lblPassword);
    ui->lblConfig->setText(QString::fromStdString
                           ((*dict).getTextOflblConfig()));
    (*dict).setTextOflblResolution(ui->lblResolution);
    (*dict).setTextOflblFps(ui->lblFps);
    (*dict).setTextOflblColorScale(ui->lblColorScale);
    (*dict).setTextOflblVideoChunk(ui->lblVideoChunk);
    (*dict).setTextOflblNetwork(ui->lblNetwork);
    ui->btnBack->setText(QString::fromStdString((*dict).getTextOfbtnBack()));
    ui->btnConnect->setText(QString::fromStdString
                            ((*dict).getTextOfbtnConnect()));
    (*dict).fillcmbResolution(ui->cmbResolution);
    (*dict).fillcmbColorScale(ui->cmbColorScale);
    (*dict).fillcmbFps(ui->cmbFps);
    (*dict).fillcmbVideoChunk(ui->cmbVideoChunk);
    (*dict).fillcmbNetwork(ui->cmbNetwork);
}

/**
 * Set the application selector.
 * @param   : selector; variable passed from the main.
 * @return  : void.
*/
void FrmClient::setSelector(int *selector)
{
    this->selector = selector;
}

/**
 * Return to Frame Main.
 * @param   : void.
 * @return  : void.
*/
void FrmClient::on_btnBack_clicked()
{
    *selector = 0;
    this->close();
}

/**
 * Set configurations variables.
 * @param   : void.
 * @return  : void.
*/
void FrmClient::setConfigurations()
{
    Configurations::system = CLIENT;
    Configurations::source = 0;
    Configurations::server_ip = ui->txtIpServer->text().toStdString();
    Configurations::client_ip = ui->lblIpClient2->text().toStdString();
    Configurations::port = static_cast<uint16_t>
            (stoi(ui->txtPort->text().toStdString()));
    Configurations::password = ui->txtPassword->text().toStdString();
    Configurations::leave_client_config = false;
    Configurations::resolution = static_cast<uint8_t>
            (ui->cmbResolution->currentIndex());
    Configurations::fps = static_cast<uint8_t>(ui->cmbFps->currentIndex());
    Configurations::color_scale = static_cast<uint8_t>
            (ui->cmbColorScale->currentIndex());
    Configurations::file_name = "";
    Configurations::video_chunk_seconds = (ui->cmbVideoChunk->currentIndex()
                                           * 5) + 5;
    if(ui->chkIntrusionDetection->checkState() == Qt::Unchecked)
        Configurations::intrusion_detection_enabled = false;
    else
        Configurations::intrusion_detection_enabled = true;
    Configurations::network = ui->cmbNetwork->currentText().toStdString();
}

/**
 * Start the connection to the server.
 * @param   : void.
 * @return  : void.
*/
void FrmClient::on_btnConnect_clicked()
{
    ui->btnConnect->setEnabled(false);
    ui->btnConnect->repaint();
    setConfigurations();

    // Control that all data are correct
    if(Configurations::server_ip != "")
    {
        *selector = 4;
        this->close();
    }

}

/**
 * Change gui on Inttrusion detection checked/unchecked action.
 * @param   : void.
 * @return  : void.
*/
void FrmClient::on_chkIntrusionDetection_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        // Deactivated
        ui->lblNetwork->setEnabled(false);
        ui->cmbNetwork->setEnabled(false);
    }
    else
    {
        // Activated
        ui->lblNetwork->setEnabled(true);
        ui->cmbNetwork->setEnabled(true);
    }
}

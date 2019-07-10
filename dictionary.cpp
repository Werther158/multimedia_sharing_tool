#include "dictionary.h"
#include "string"

Dictionary::Dictionary()
{
}

void Dictionary::setLanguage(lang current_language)
{
    this->current_language = current_language;
}

lang Dictionary::getLanguage()
{
    return current_language;
}

std::string Dictionary::choices(std::string s1, std::string s2)
{
    if (current_language == italian)
            return s1;
    if (current_language == english)
        return s2;
    return "empty";
}

// FrmMain
std::string Dictionary::getTextOflblStart()
{
    return choices("Avviare:", "Start:");
}

std::string Dictionary::getTextOfbtnServer()
{
    return "Server";
}

std::string Dictionary::getTextOfbtnClient()
{
    return "Client";
}

std::string Dictionary::getTextOflblLang()
{
    return choices("Lingua", "Language");
}

std::string Dictionary::getTextOfbtnLang()
{
    return choices("ENG", "ITA");
}

std::string Dictionary::getTextOfbtnExit()
{
    return choices("Esci", "Exit");
}

// FrmServer
std::string Dictionary::getTextOflblInfoServer()
{
    return choices("Configurazione connessione", "Connection settings");
}

void Dictionary::setTextOflblIpServerS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Il tuo indirizzo IP pubblico, da comunicare al client.\nSe il sistema non è connesso ad internet sarà mostrato l'indirizzo 127.0.0.1.",
                                                   "Your public IP address, tell it to the client.\nIf your system isn't connected to internet, 127.0.0.1 will be shown.")));
    lbl->setText("Tuo IP:");
}

void Dictionary::setTextOflblIpClientS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Inserire l'indirizzo IP del client, pubblico o privato.",
                                                   "Insert client's IP address, either public or private.")));
    lbl->setText("Client IP:");
}

void Dictionary::setTextOflblPort(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Porta del server.", "Server port.")));
    lbl->setText(QString::fromStdString(choices("Porta:", "Port:")));
}

void Dictionary::setTextOflblPasswordS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("E' possibile impostare una password per la connessione del client.\nLasciare vuoto questo campo per non utilizzare nessuna password.",
                                                   "It is possible to set a password for client connection.\nLeave it blank in order to use no password.")));
    lbl->setText("Password:");
}

void Dictionary::setTextOflblSource(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Sorgente video da inviare al client.", "Video source to use.")));
    lbl->setText(QString::fromStdString(choices("Sorgente:", "Source:")));
}

std::string Dictionary::getTextOflblConfig()
{
    return choices("Configurazione streaming", "Streaming configuration");
}

std::string Dictionary::getTextOflblLeaveConfig()
{
    return choices("Lascia la configurazione al client:", "Leave the configuration to client:");
}

void Dictionary::setTextOflblResolution(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Risoluzione di output.", "Output resolution.")));
    lbl->setText(QString::fromStdString(choices("Risoluzione:", "Resolution:")));
}

void Dictionary::setTextOflblFps(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("FPS massimi desiderati in output.", "Maximum output FPS desired.")));
    lbl->setText("FPS:");
}

void Dictionary::setTextOflblBuffer(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Buffer disponibile in output.\nUn valore maggiore consente di avere una "
                                                   "fluidità maggiore, ma aumenterà la latenza.", "Available output buffer.\nA greater value "
                                                   "makes the output streaming smoother, but it increases latency.")));
    lbl->setText("Buffer:");
}

void Dictionary::setTextOflblVideo(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Compressione video.", "Video compression.")));
    lbl->setText("Video:");
}

void Dictionary::setTextOflblColorScale(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Scala colori dei pixel delle immagini in output.",
                                                   "Color scale of output image's pixels.")));
    lbl->setText(QString::fromStdString(choices("Scala colori:", "Color scale:")));
}

void Dictionary::setTextOflblEncoding(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Tipologie di codifica video.", "Encoding types.")));
    lbl->setText(QString::fromStdString(choices("Codifica:", "Encoding:")));
}

void Dictionary::setTextOflblAudio(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Compressione audio.", "Audio compression.")));
    lbl->setText("Audio:");
}

void Dictionary::setTextOflblControls(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Controlli sul server disponibili al client.\nT -> Tastiera\nM -> Mouse\nC -> Controller", "Server's controls available to the client.\nK -> Keayboard\nM -> Mouse\nC -> Controller")));
    lbl->setText(QString::fromStdString(choices("Controlli:", "Controls:")));
}

std::string Dictionary::getTextOflblBandwidth()
{
    return choices("Banda utilizzata stimata:", "Estimated bandwidth use:");
}

std::string Dictionary::getTextOflblBandwidthvalue()
{
    return "N";
}

std::string Dictionary::getTextOfbtnBack()
{
    return choices("Indietro", "Back");
}

std::string Dictionary::getTextOfbtnLoadConfig()
{
    return choices("Carica configurazione", "Load configuration");
}

std::string Dictionary::getTextOfbtnSaveConfig()
{
    return choices("Salva configurazione", "Save configuration");
}

std::string Dictionary::getTextOfbtnStartServer()
{
    return choices("Avvia server", "Start server");
}

void Dictionary::fillcmbSource(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("File video", "Video file")));
    cmb->addItem(QString::fromStdString(choices("Camera", "Camera")));
    cmb->addItem(QString::fromStdString(choices("Schermo", "Screen")));
}

void Dictionary::fillcmbResolution(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("3840 x 2160");
    cmb->addItem("2560 x 1440");
    cmb->addItem("1920 x 1080");
    cmb->addItem("1600 x 900");
    cmb->addItem("1280 x 720");
    cmb->addItem("854 x 480");
    cmb->addItem("640 x 360");
    cmb->addItem("426 x 240");
    cmb->addItem("256 x 144");
}

void Dictionary::fillcmbColorScale(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("24 bpp");
    cmb->addItem("16 bpp");
    cmb->addItem("15 bpp");
    cmb->addItem("8 bpp");
    cmb->addItem("4 bpp");
    cmb->addItem("2 bpp");
    cmb->addItem("1 bpp");
}

void Dictionary::fillcmbFps(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("60");
    cmb->addItem("59");
    cmb->addItem("55");
    cmb->addItem("50");
    cmb->addItem("45");
    cmb->addItem("40");
    cmb->addItem("35");
    cmb->addItem("30");
    cmb->addItem("25");
    cmb->addItem("20");
    cmb->addItem("15");
}

void Dictionary::fillcmbBuffer(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Disabilitato", "Disabled")));
    cmb->addItem(QString::fromStdString(choices("128 frame", "128 frames")));
    cmb->addItem(QString::fromStdString(choices("64 frame", "64 frames")));
    cmb->addItem(QString::fromStdString(choices("32 frame", "32 frames")));
    cmb->addItem(QString::fromStdString(choices("16 frame", "16 frames")));
    cmb->addItem(QString::fromStdString(choices("8 frame", "8 frames")));
}

void Dictionary::fillcmbControls(QComboBox *cmb)
{
   cmb->addItem(QString::fromStdString(choices("Disabilitati", "Disabled")));
   cmb->addItem(QString::fromStdString(choices("T + M", "K + M")));
   cmb->addItem(QString::fromStdString(choices("C", "C")));
   cmb->addItem(QString::fromStdString(choices("T + M + C", "K + M + C")));
}

// FrmClient
std::string Dictionary::getTextOfbtnConnect()
{
    return choices("Connetti", "Connect");
}

void Dictionary::setTextOflblIpClientC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Il tuo indirizzo IP pubblico, da comunicare al server.\nSe il sistema non è connesso ad internet sarà mostrato l'indirizzo 127.0.0.1.",
                                                   "Your public IP address, tell it to the server.\nIf your system isn't connected to internet, 127.0.0.1 will be shown.")));
    lbl->setText("Tuo IP:");
}

void Dictionary::setTextOflblIpServerC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Inserire l'indirizzo IP del server, pubblico o privato.",
                                                   "Insert server's IP address, either public or private.")));
    lbl->setText("Server IP:");
}

void Dictionary::setTextOflblPasswordC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Password per connettersi al server.\nSe lato server non è impostata alcuna password, lasciare il campo vuoto.",
                                                   "Server connection password.\nIf server side no password is specified, leave the field blank.")));
    lbl->setText("Password:");
}


// Open a file
std::string Dictionary::getTextOpenafile()
{
    return choices("Apri un file", "Open a file");
}


// FrmRunning
void Dictionary::getTextOflblStateRunning(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Indica lo stato attuale del server.\nPosiziona il cursore sulle icone di stato per avere più informazioni.",
                                                   "Indicates the actual state of the server.\nPlace the cursor over the status icons for more information.")));
    lbl->setText(QString::fromStdString(choices("Stato:", "State:")));
}

std::string Dictionary::getTextOfbtnStopRunning()
{
    return choices("Ferma server", "Stop server");
}

std::string Dictionary::getTextOfbtnStopStream()
{
    return choices("Ferma streaming", "Stop streaming");
}

void Dictionary::setTooltipOflblState2(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Stato del collegamento Client-Server.\nGrigio: in attesa di collegamento.\nVerde: client collegato.",
                                                   "Client-Server connection state.\nGrey: waiting for a connection.\nGreen: client connected.")));
}

void Dictionary::setTooltipOflblState3(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Stato dello streaming video Client-Server.\nGrigio: non attivo.\nVerde: attivo.",
                                                   "Client-Server video streaming state.\nGrey: not active.\nGreen: active.")));
}

// FrmConnected
void Dictionary::getTextOflblResize(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString(choices("Permette di ridimensionare la grandezza del video in output.\nN.B. Un valore diverso dal 100% richiede calcoli aggiuntivi che possono risultare in un calo di prestazioni.",
                                                   "Allow to resize the dimensions of output video.\nN.B. A value different from 100% needs some more computing capabilities and it could lead to lower performance.")));
    lbl->setText(QString::fromStdString(choices("Ridimensiona:", "Resize:")));
}

std::string Dictionary::getTextOfchkFullscreen()
{
    return choices("Schermo intero", "Fullscreen");
}

std::string Dictionary::getTextOfbtnDisconnect()
{
    return choices("Disconnetti", "Disconnect");
}

void Dictionary::getTextOfbtnStartStreaming(QPushButton *btn)
{
    btn->setToolTip(QString::fromStdString(choices("Crea una connessione UDP con il server e inizia ad acquisire lo streaming video.",
                                                   "Start a UDP connection with the server and begin to capture video streaming.")));
    btn->setText(QString::fromStdString(choices("Avvia streaming", "Start streaming")));
}

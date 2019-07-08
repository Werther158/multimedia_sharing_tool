#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "stdlib.h"
#include "string"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

enum lang {
    italian,
    english
};

class Dictionary
{
private:
    lang current_language;
public:
    Dictionary();
    lang getLanguage();
    void setLanguage(lang current_language);
    std::string choices(std::string s1, std::string s2);

    // FrmMain
    std::string getTextOflblStart();
    std::string getTextOfbtnServer();
    std::string getTextOfbtnClient();
    std::string getTextOflblLang();
    std::string getTextOfbtnLang();

    // FrmServer
    std::string getTextOflblInfoServer();
    void setTextOflblIpServerS(QLabel *lbl);
    void setTextOflblIpClientS(QLabel *lbl);
    void setTextOflblPort(QLabel *lbl);
    void setTextOflblPasswordS(QLabel *lbl);
    void setTextOflblSource(QLabel *lbl);
    std::string getTextOflblConfig();
    std::string getTextOflblLeaveConfig();
    void setTextOflblResolution(QLabel *lbl);
    void setTextOflblFps(QLabel *lbl);
    void setTextOflblBuffer(QLabel *lbl);
    void setTextOflblVideo(QLabel *lbl);
    void setTextOflblColorScale(QLabel *lbl);
    void setTextOflblEncoding(QLabel *lbl);
    void setTextOflblAudio(QLabel *lbl);
    void setTextOflblControls(QLabel *lbl);
    std::string getTextOflblBandwidth();
    std::string getTextOflblBandwidthvalue();
    std::string getTextOfbtnBack();
    std::string getTextOfbtnLoadConfig();
    std::string getTextOfbtnSaveConfig();
    std::string getTextOfbtnStartServer();
    std::string getTextOfbtnExit();
    void fillcmbSource(QComboBox *cmb);
    void fillcmbResolution(QComboBox *cmb);
    void fillcmbColorScale(QComboBox *cmb);
    void fillcmbFps(QComboBox *cmb);
    void fillcmbBuffer(QComboBox *cmb);
    void fillcmbControls(QComboBox *cmb);

    // FrmClient
    std::string getTextOfbtnConnect();
    void setTextOflblIpClientC(QLabel *lbl);
    void setTextOflblIpServerC(QLabel *lbl);
    void setTextOflblPortC(QLabel *lbl);
    void setTextOflblPasswordC(QLabel *lbl);

    // Open a file
    std::string getTextOpenafile();

    // FrmRunning
    void getTextOflblStateRunning(QLabel *lbl);
    std::string getTextOfbtnStopRunning();
};

#endif // DICTIONARY_H

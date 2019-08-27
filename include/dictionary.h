#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "stdlib.h"
#include "string"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

enum lang {
    italian,
    english
};

class Dictionary
{
private:
    lang current_language; // Language switch (Italian / English)
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
    void setIconOfbtnLang(QPushButton *btn);

    // FrmServer
    std::string getTextOflblInfoServer();
    void setTextOflblIpServerS(QLabel *lbl);
    void setTextOflblIpClientS(QLabel *lbl);
    void setTextOflblPort(QLabel *lbl);
    void setTextOflblPasswordS(QLabel *lbl);
    void setTextOflblSource(QLabel *lbl);
    void setTextOflblVideoChunk(QLabel *lbl);
    std::string getTextOflblConfig();
    std::string getTextOflblLeaveConfig();
    void setTextOflblResolution(QLabel *lbl);
    void setTextOflblFps(QLabel *lbl);
    void setTextOflblColorScale(QLabel *lbl);
    void setTextOflblNetwork(QLabel *lbl);
    std::string getTextOfbtnBack();
    std::string getTextOfbtnStartServer();
    std::string getTextOfbtnExit();
    void fillcmbSource(QComboBox *cmb);
    void fillcmbResolution(QComboBox *cmb);
    void fillcmbColorScale(QComboBox *cmb);
    void fillcmbFps(QComboBox *cmb);
    void fillcmbVideoChunk(QComboBox *cmb);
    void fillcmbNetwork(QComboBox *cmb);

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
    void setTIbtnStartStopStream(QPushButton *btn, int select);
    void setTooltipOflblState2(QLabel *lbl);
    void setTooltipOflblState3(QLabel *lbl);

    // FrmConnected
    void getTextOflblResize(QLabel *lbl);
    std::string getTextOfchkFullscreen();
    std::string getTextOfbtnDisconnect(int select);
    void getTextOfbtnStartStreaming(QPushButton *btn, int select);
};

#endif // DICTIONARY_H

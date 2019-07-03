#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "stdlib.h"
#include "string"

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
    std::string getTextOflblIp();
    std::string getTextOflblPort();
    std::string getTextOflblPassword();
    std::string getTextOflblSource();
    std::string getTextOflblConfig();
    std::string getTextOflblLeaveConfig();
    std::string getTextOflblResolution();
    std::string getTextOflblFps();
    std::string getTextOflblBuffer();
    std::string getTextOflblVideo();
    std::string getTextOflblColorScale();
    std::string getTextOflblEncoding();
    std::string getTextOflblAudio();
    std::string getTextOflblControls();
    std::string getTextOflblBandwidth();
    std::string getTextOflblBandwidthvalue();
    std::string getTextOfbtnBack();
    std::string getTextOfbtnLoadConfig();
    std::string getTextOfbtnSaveConfig();
    std::string getTextOfbtnStartServer();
    std::string getTextOfbtnExit();

    // FrmClient
    std::string getTextOfbtnConnect();
};

#endif // DICTIONARY_H

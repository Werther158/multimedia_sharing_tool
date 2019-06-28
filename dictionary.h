#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "stdlib.h"
#include "string"

enum lang {
    italian,
    english
};

struct choices{
    std::string voices[2];
};
class Dictionary
{
private:
    lang current_language;
public:
    Dictionary();
    void setLanguage(lang l);

    //FrmMain
    std::string getTextOflblStart();
    std::string getTextOfbtnServer();
    std::string getTextOfbtnClient();
    std::string getTextOflblTheme();
    std::string getTextOflblLang();
    choices getTextOfbtnTheme();
    std::string getTextOfbtnLang();
};

#endif // DICTIONARY_H

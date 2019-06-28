#include "dictionary.h"
#include "string"

Dictionary::Dictionary()
{
}

void Dictionary::setLanguage(lang l)
{
    current_language = l;
}


// FrmMain
std::string Dictionary::getTextOflblStart()
{
    if (current_language == italian)
            return "Avviare:";
    if (current_language == english)
        return "Start:";
    return "empty";
}

std::string Dictionary::getTextOfbtnServer()
{
    return "Server";
}

std::string Dictionary::getTextOfbtnClient()
{
    return "Client";
}

std::string Dictionary::getTextOflblTheme()
{
    if (current_language == italian)
            return "Tema:";
    if (current_language == english)
        return "Theme:";
    return "empty";
}

std::string Dictionary::getTextOflblLang()
{
    if (current_language == italian)
            return "Lingua:";
    if (current_language == english)
        return "Language:";
    return "empty";
}

choices Dictionary::getTextOfbtnTheme()
{
    choices c;
    c.voices[0] = c.voices[1] = "empty";

    if (current_language == italian)
    {
        c.voices[0] = "Chiaro";
        c.voices[1] = "Scuro";
    }
    if (current_language == english)
    {
        c.voices[0] = "Light";
        c.voices[1] = "Dark";
    }
    return c;
}

std::string Dictionary::getTextOfbtnLang()
{
    if (current_language == italian)
            return "ENG";
    if (current_language == english)
        return "ITA";
    return "empty";
}

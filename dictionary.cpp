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
    return choices("Info server", "Info server");
}

std::string Dictionary::getTextOflblIp()
{
    return choices("IP:", "IP:");
}

std::string Dictionary::getTextOflblPort()
{
    return choices("Porta:", "Port:");
}

std::string Dictionary::getTextOflblPassword()
{
    return choices("Password:", "Password:");
}

std::string Dictionary::getTextOflblSource()
{
    return choices("Sorgente:", "Source:");
}

std::string Dictionary::getTextOflblConfig()
{
    return choices("Configurazione", "Configuration:");
}

std::string Dictionary::getTextOflblLeaveConfig()
{
    return choices("Lascia la configurazione al client:", "Leave the configuration to client:");
}

std::string Dictionary::getTextOflblResolution()
{
    return choices("Risoluzione:", "Resolution:");
}

std::string Dictionary::getTextOflblFps()
{
    return choices("FPS:", "FPS:");
}

std::string Dictionary::getTextOflblBuffer()
{
    return choices("Buffer:", "Buffer:");
}

std::string Dictionary::getTextOflblVideo()
{
    return choices("Video:", "Video:");
}

std::string Dictionary::getTextOflblColorScale()
{
    return choices("Scala colori:", "Color scale:");
}

std::string Dictionary::getTextOflblEncoding()
{
    return choices("Codifica:", "Encoding:");
}

std::string Dictionary::getTextOflblAudio()
{
    return choices("Audio:", "Audio:");
}

std::string Dictionary::getTextOflblControls()
{
    return choices("Controlli:", "Controls:");
}

std::string Dictionary::getTextOflblBandwidth()
{
    return choices("Banda utilizzata stimata:", "Estimated bandwidth use:");
}

std::string Dictionary::getTextOflblBandwidthvalue()
{
    return choices("N", "N");
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

// FrmClient
std::string Dictionary::getTextOfbtnConnect()
{
    return choices("Connetti", "Connect");
}

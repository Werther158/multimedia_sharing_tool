#include <frmmain.h>
#include <frmserver.h>
#include <frmclient.h>
#include <frmrunning.h>
#include <frmconnected.h>
#include <tcpclientthread.h>
#include <tcpserverthread.h>
#include <QApplication>
#include "dictionary.h"

#include "iostream"

int main(int argc, char *argv[])
{
    Dictionary dict;
    int selector;

    dict.setLanguage(english);
    selector = 0;

    while(selector != -1)
    {
        if(selector == 0) // FrmMain
        {
            QApplication a(argc, argv);
            FrmMain f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }
        if(selector == 1) // FrmServer
        {
            QApplication a(argc, argv);
            FrmServer f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }
        if(selector == 2) // FrmClient
        {
            QApplication a(argc, argv);
            FrmClient f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }

        if(selector == 3) // FrmRunning
        {
            QApplication a(argc, argv);
            FrmRunning f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }

        if(selector == 4) // FrmConnected
        {
            QApplication a(argc, argv);
            FrmConnected f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }
    }

    return 0;
}

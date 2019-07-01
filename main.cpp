#include "frmmain.h"
#include "frmserver.h"
#include "frmclient.h"
#include <QApplication>
#include "dictionary.h"
#include <utilities.h>

#include "iostream"

int main(int argc, char *argv[])
{
    Dictionary dict;
    int selector;

    dict.setLanguage(italian);
    selector = 0;

    curl_test();

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
    }

    return 0;
}

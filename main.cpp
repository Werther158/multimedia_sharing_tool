#include "frmmain.h"
#include "frmserver.h"
#include <QApplication>
#include "dictionary.h"

#include "iostream"

int main(int argc, char *argv[])
{
    Dictionary dict;
    int selector;

    dict.setLanguage(italian);
    selector = 0;

    while(selector != -1)
    {
        if(selector == 0)
        {
            QApplication a(argc, argv);
            FrmMain f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }
        if(selector == 1)
        {
            QApplication a(argc, argv);
            FrmServer f;
            f.setDict(&dict);
            f.setSelector(&selector);
            f.show();
            a.exec();
        }
    }

    return 0;
}

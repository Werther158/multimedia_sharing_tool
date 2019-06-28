#include "frmmain.h"
#include <QApplication>
#include "dictionary.h"

#include "iostream"

int main(int argc, char *argv[])
{
    Dictionary dict;
    dict.setLanguage(italian);

    QApplication a(argc, argv);
    FrmMain w;
    w.setDict(dict);
    w.show();

    return a.exec();
}

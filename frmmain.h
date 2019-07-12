#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include <QString>
#include <QCloseEvent>
#include <qdesktopwidget.h>
#include "dictionary.h"

namespace Ui {
class FrmMain;
}

class FrmMain : public QWidget
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();
    void setDict(Dictionary* dict);
    void setSelector(int* selector);

private slots:
    void on_btnLang_clicked();
    void on_btnServer_clicked();

    void on_btnClient_clicked();

    void on_btnExit_clicked();

private:
    Ui::FrmMain *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMMAIN_H

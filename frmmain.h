#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
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
    void setDict(Dictionary d);

private:
    enum theme {
        light,
        dark
    };
    Ui::FrmMain *ui;
    Dictionary dict;
    theme current_theme;
};

#endif // FRMMAIN_H

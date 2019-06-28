#ifndef FRMSERVER_H
#define FRMSERVER_H

#include <QWidget>
#include "dictionary.h"

namespace Ui {
class FrmServer;
}

class FrmServer : public QWidget
{
    Q_OBJECT

public:
    explicit FrmServer(QWidget *parent = nullptr);
    ~FrmServer();
    void setDict(Dictionary* d);
    void setSelector(int* selector);

private slots:
    void on_btnBack_clicked();

private:
    Ui::FrmServer *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMSERVER_H
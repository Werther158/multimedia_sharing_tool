#ifndef FRMCLIENT_H
#define FRMCLIENT_H

#include <QWidget>
#include "dictionary.h"
#include <connectivity.h>
#include <configurations.h>

namespace Ui {
class FrmClient;
}

class FrmClient : public QWidget
{
    Q_OBJECT

public:
    explicit FrmClient(QWidget *parent = nullptr);
    ~FrmClient();
    void setDict(Dictionary* dict);
    void setSelector(int* selector);
    void setConfigurations();
private slots:
    void on_btnBack_clicked();
    void on_btnConnect_clicked();

private:
    Ui::FrmClient *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMCLIENT_H

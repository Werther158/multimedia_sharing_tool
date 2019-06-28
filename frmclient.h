#ifndef FRMCLIENT_H
#define FRMCLIENT_H

#include <QWidget>
#include "dictionary.h"

namespace Ui {
class FrmClient;
}

class FrmClient : public QWidget
{
    Q_OBJECT

public:
    explicit FrmClient(QWidget *parent = nullptr);
    ~FrmClient();
    void setDict(Dictionary* d);
    void setSelector(int* selector);

private slots:
    void on_btnBack_clicked();

private:
    Ui::FrmClient *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMCLIENT_H

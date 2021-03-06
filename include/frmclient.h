#ifndef FRMCLIENT_H
#define FRMCLIENT_H

#include "dictionary.h"
#include "connectivity.h"
#include "configurations.h"
#include "tcpclientthread.h"
#include <QWidget>
#include <qdesktopwidget.h>

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
    void on_chkIntrusionDetection_stateChanged(int arg1);

private:
    Ui::FrmClient *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMCLIENT_H

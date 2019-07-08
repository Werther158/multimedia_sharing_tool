#ifndef FRMCONNECTED_H
#define FRMCONNECTED_H

#include <dictionary.h>
#include <configurations.h>
#include <connectivity.h>
#include <QWidget>

namespace Ui {
class FrmConnected;
}

class FrmConnected : public QWidget
{
    Q_OBJECT

public:
    explicit FrmConnected(QWidget *parent = nullptr);
    ~FrmConnected();
    void setDict(Dictionary *dict);
    void setSelector(int *selector);
private slots:
    void on_btnDisconnect_clicked();

private:
    Ui::FrmConnected *ui;
    Dictionary *dict;
    int *selector;
};

#endif // FRMCONNECTED_H

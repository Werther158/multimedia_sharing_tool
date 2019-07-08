#ifndef FRMRUNNING_H
#define FRMRUNNING_H

#include <dictionary.h>
#include <connectivity.h>
#include <configurations.h>
#include <QWidget>
#include <QDir>

namespace Ui {
class FrmRunning;
}

class FrmRunning : public QWidget
{
    Q_OBJECT

public:
    explicit FrmRunning(QWidget *parent = nullptr);
    ~FrmRunning();
    void setDict(Dictionary* dict);
    void setSelector(int* selector);

private slots:
    void on_btnStop_clicked();

private:
    Ui::FrmRunning *ui;
    Dictionary* dict;
    int* selector;
};

#endif // FRMRUNNING_H

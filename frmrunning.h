#ifndef FRMRUNNING_H
#define FRMRUNNING_H

#include <QWidget>

namespace Ui {
class FrmRunning;
}

class FrmRunning : public QWidget
{
    Q_OBJECT

public:
    explicit FrmRunning(QWidget *parent = nullptr);
    ~FrmRunning();

private:
    Ui::FrmRunning *ui;
};

#endif // FRMRUNNING_H

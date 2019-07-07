#ifndef FRMCONNECTED_H
#define FRMCONNECTED_H

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

private:
    Ui::FrmConnected *ui;
};

#endif // FRMCONNECTED_H

#ifndef FRMRUNNING_H
#define FRMRUNNING_H

#include <dictionary.h>
#include <connectivity.h>
#include <configurations.h>
#include <tcpserverthread.h>
#include <serverstreamthread.h>
#include <QWidget>
#include <QDir>
#include <qdesktopwidget.h>

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
    void writeTextOnTxtBox(QString str);
    void on_btnSend_clicked();
    void clientConnected();
    void otherGuyDisconnected();
    void on_btnToggleConfig_clicked();
    void startServerStream();
    void on_btnStopStream_clicked();
    void streamingEnded();
    void stopStream();
private:
    Ui::FrmRunning *ui;
    Dictionary* dict;
    int* selector;
    TcpServerThread *tcp_server_thread;
    ServerStreamThread *server_stream_thread;
    Connectivity c;

    bool client_connected = false;
    bool listconfig_active = true;
    bool is_stream_active = false;

    void startServer();
    void stopThreads();
    void enableListConfiguration();
    void disableListConfiguration();
};

#endif // FRMRUNNING_H

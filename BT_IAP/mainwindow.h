#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <String>
#include <QString>
#include <semaphore.h>
#include <mythread.h>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <map>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
#include <QPlainTextEdit>
#include "iappackages.h"

extern sem_t open_serial;
#define ACK_TIMEOUT 8

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void OnClickedClearScr();
    void OnClickedConnect();
    void OnClickedDisconnect();
    void OnClickedSendMessage();
    void OnClickedChooseFile();
    void OnClickedUpdate();
    void OnClickedUpdateCancel();
    void OnClickedSearchPort();
    bool OnCheckHexSend();
    void ChangeProgressBar(qint64 num);
    void TimerReset();
    void SendAPart();
    void checkDevOnline();


public:
    QString GetComNum();
    QVariant GetBaudrate();
    QVariant GetDataBit();
    QVariant GetStopBit();
    QString GetVerifyBit();

    void AddComInf(QString num);
    QString GetMessage();
    QString GetFilePath();
    bool SetFilePathDis(QString path);
    bool SetDevStateText(QString Text);
    bool SetDevStateStyle(QString style);
    void AppendTxt2TranscationScr(QString Text);

//serial code patch
    QStringList GetPortList();
    bool OpenSerial(QString com, QVariant Sbaud, QVariant SDataBit, QString SFlowCtrl, QString SParuty, QVariant  SStopbit );
    void SendInfo();
    void receiveInfo();
    void SendInfo_ProgressBar(QByteArray info_arry);
    void myQdebug(QString text);


private slots:
    void on_pushButton_clicked();

    void on_CheckOnline_clicked();

public:
    QByteArray crc = "";

private:
    Ui::MainWindow *ui;
    QSerialPort m_serialPort;
    QTimer count ;
    QTimer cheack_port_online ;
    int part_num;
    QList<QByteArray> part_list;
    double progress_value = 0.0;
    double each_part_bar;
    int a_part_size = 1024;
    IapPackages iap_pack;
    int ACK = 0;
    //MyThread *thread1;

};

#endif // MAINWINDOW_H

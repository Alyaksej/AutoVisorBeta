#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

struct Settings
{
    QString                  name;
    qint32                   baudRate;
    QSerialPort::DataBits    dataBits;
    QSerialPort::Parity      parity;
    QSerialPort::StopBits    stopBits;
    QSerialPort::FlowControl flowControl;
};

class Port : public QObject
{
    Q_OBJECT

public:
    explicit Port(QObject *parent = 0);

    ~Port();

    QSerialPort thisPort;

    Settings    SettingsPort;

public slots:
    void WriteSettingsPort(QString name, int baudrate, int DataBits,
                           int Parity, int StopBits, int FlowControl);


};

#endif // PORT_H

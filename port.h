#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#define TIMEOUT 100

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

signals:
    void error_(QString err);

public slots:
    void WriteSettingsPort(QString name, int baudrate, int DataBits,
                           int Parity, int StopBits, int FlowControl);
    void ConnectPort(void);

    void DisconnectPort();

    void WriteToPort(QByteArray data);

private slots:
    void handleError(QSerialPort::SerialPortError error);
};

#endif // PORT_H

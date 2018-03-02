#include "port.h"

Port::Port(QObject *parent) : QObject(parent)
{

}

Port :: ~Port()
{

}

//Настройка параметроы порта-------------------------------------------------------
void Port :: WriteSettingsPort(QString name, int baudrate, int DataBits,
                               int Parity, int StopBits, int FlowControl)
{
    SettingsPort.name        = name;
    SettingsPort.baudRate    = (QSerialPort :: BaudRate)baudrate;
    SettingsPort.dataBits    = (QSerialPort :: DataBits)DataBits;
    SettingsPort.parity      = (QSerialPort :: Parity)Parity;
    SettingsPort.stopBits    = (QSerialPort :: StopBits)StopBits;
    SettingsPort.flowControl = (QSerialPort :: FlowControl)FlowControl;
}

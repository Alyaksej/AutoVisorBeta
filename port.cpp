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

//Подключение порта------------------------------------------------------------------------------
void Port :: ConnectPort(void)
{
    thisPort.setPortName(SettingsPort.name);
    if(thisPort.open(QIODevice::ReadWrite))
    {
        if(thisPort.setBaudRate(SettingsPort.baudRate)
                && thisPort.setDataBits(SettingsPort.dataBits)
                && thisPort.setParity(SettingsPort.parity)
                && thisPort.setStopBits(SettingsPort.stopBits)
                && thisPort.setFlowControl(SettingsPort.flowControl))
        {
            if(thisPort.isOpen())
            {
                error_((SettingsPort.name+ "  Порт открыт:\r"));//если открыт - прнимаем надпись "Порт открыт"
            }
        }
        else
        {
            thisPort.close();
            error_(thisPort.errorString().toLocal8Bit());
        }
    }
    else
    {
        thisPort.close();
        error_(thisPort.errorString().toLocal8Bit());
    }
}

//Выдает сообщение об ошибке---------------------------------------------------------------------
void Port::handleError(QSerialPort::SerialPortError error)
{
    if ( (thisPort.isOpen()) && (error == QSerialPort::ResourceError))
    {
        error_(thisPort.errorString().toLocal8Bit());
        DisconnectPort();
    }
}

//Отключение порта-------------------------------------------------------------------------------
void  Port::DisconnectPort()
{
    if(thisPort.isOpen())
    {
        thisPort.close();
        error_(SettingsPort.name.toLocal8Bit() + " Порт закрыт!\r");
    }
}

//Запись данных в порт-----------------------------------------------------------------------------
void Port :: WriteToPort(QByteArray data)
{
    if(thisPort.isOpen())
    {
        thisPort.write(data);
        thisPort.waitForBytesWritten(TIMEOUT);
    }
}

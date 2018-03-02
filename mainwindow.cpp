#include <QSerialPort>
#include <QSerialPortInfo>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DataBase();//Создаём обект по классу для работы с данными БД
    db->connectToDataBase();

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showPortInfo(int)));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(fillPortInfo()));

    fillPortInfo();
    fillPortParameters();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Определяем параметры порта-----------------------------------------------------------------------------
void MainWindow::fillPortParameters()
{
    // Скорость потока
    ui->comboBox_2->addItem(QLatin1String("115200"), QSerialPort::Baud115200);
    ui->comboBox_2->addItem(QLatin1String("38400"),  QSerialPort::Baud38400);
    ui->comboBox_2->addItem(QLatin1String("19200"),  QSerialPort::Baud19200);
    ui->comboBox_2->addItem(QLatin1String("9600"),   QSerialPort::Baud9600);
    ui->comboBox_2->addItem(QLatin1String("Custom"));
    // Определение бита четности
    ui->comboBox_3->addItem(QLatin1String("None"),  QSerialPort::NoParity);
    ui->comboBox_3->addItem(QLatin1String("Even"),  QSerialPort::EvenParity);
    ui->comboBox_3->addItem(QLatin1String("Odd"),   QSerialPort::OddParity);
    ui->comboBox_3->addItem(QLatin1String("Mark"),  QSerialPort::MarkParity);
    ui->comboBox_3->addItem(QLatin1String("Space"), QSerialPort::SpaceParity);
    // Определение стопового бита
    ui->comboBox_4->addItem(QLatin1String("1"),   QSerialPort::OneStop);
    #ifdef Q_OS_WIN
    ui->comboBox_4->addItem(QLatin1String("1.5"), QSerialPort::OneAndHalfStop);
    #endif
    ui->comboBox_4->addItem(QLatin1String("2"),   QSerialPort::TwoStop);
    // Контроль потока
    ui->comboBox_5->addItem(QLatin1String("None"),     QSerialPort::NoFlowControl);
    ui->comboBox_5->addItem(QLatin1String("RTS/CTS"),  QSerialPort::HardwareControl);
    ui->comboBox_5->addItem(QLatin1String("XON/XOFF"), QSerialPort::SoftwareControl);
    // Длина потока
    ui->comboBox_6->addItem(QLatin1String("5"), QSerialPort::Data5);
    ui->comboBox_6->addItem(QLatin1String("6"), QSerialPort::Data6);
    ui->comboBox_6->addItem(QLatin1String("7"), QSerialPort::Data7);
    ui->comboBox_6->addItem(QLatin1String("8"), QSerialPort::Data8);
    ui->comboBox_6->setCurrentIndex(3);

}

//Показать доступнуе COM-порты--------------------------------------------------------------------------
void MainWindow::fillPortInfo()
{
    ui->comboBox->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QStringList list;
        list << info.portName()
             << info.description()
             << info.manufacturer()
             << info.systemLocation()
             << (info.vendorIdentifier()  ? QString::number(info.vendorIdentifier(),  16) : QString())
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : QString());
        ui->comboBox->addItem(list.first(), list);
    }
}

//Информация о портах--------------------------------------------------------------------------------------
void MainWindow::showPortInfo(int idx)
{
    if (idx != -1)
    {
        QStringList list = ui->comboBox->itemData(idx).toStringList();
        ui->label_7->setText(tr("Описание: %1").arg(list.at(1)));
        ui->label_8->setText(tr("Производитель: %1").arg(list.at(2)));
        ui->label_9->setText(tr("Расположение: %1").arg(list.at(3)));
        ui->label_10->setText(tr("ID производителя: %1").arg(list.at(4)));
        ui->label_11->setText(tr("ID устройства: %1").arg(list.at(5)));
    }
}

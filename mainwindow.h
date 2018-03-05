#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

#include <database.h>
#include <port.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void fillPortParameters();

private slots:
    void showPortInfo(int idx);

    void fillPortInfo();

    void checkCustomBaudRatePolicy(int idx);

private:
    Ui::MainWindow *ui;
    DataBase       *db;
    QSqlTableModel *model;
    Port           *PortNew;

};

#endif // MAINWINDOW_H

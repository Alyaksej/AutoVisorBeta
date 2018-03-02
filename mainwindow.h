#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

#include <database.h>

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

private:
    Ui::MainWindow *ui;
    DataBase       *db;
    QSqlTableModel *model;

};

#endif // MAINWINDOW_H

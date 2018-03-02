#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>

//Директивы имен таблицы, плей таблицы, и базы данных
#define DATABASE_NAME     "DataBase.db"
#define DATABASE_HOSTNAME "DataBaseH"

#define TABLE             "Table Maine"
#define TABLE_ID_DEVICE   "ID device"
#define TABLE_NUMBER_MESS "Number messages"

#define TABLE_DATA        "Table Data"
#define TABLE_DATE        "Date"
#define TABLE_TIME        "Time"
#define TABLE_MESS        "Message"

class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();

    bool insertToDataBase(const QVariant &data);
private:
    QSqlDatabase db;

private:
    bool openDataBase();

    bool restoreDataBase();

    void closeDataBase();

    bool creatTable();

    bool creatTabelData();
};

#endif // DATABASE_H

#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

//Подключение к базе данных--------------------------------------------------------------------------------
void DataBase::connectToDataBase()
{
    if(!QFile("D:/Projects/AutoVisorBeta/DataBase/" DATABASE_NAME).exists())//Проверяем существует ли БД
    {
        this->restoreDataBase();//Если нет - восстанавливаем
    }
    else
    {
        this->openDataBase();//Если да - открываем
    }
}

//Восстановление БД
bool DataBase::restoreDataBase()
{
    if(this->openDataBase())
    {
        if(!this->creatTable())
        {
            return false;
        }
        else
            return true;
    }
    else
    {
        qDebug()<<"Не удалось открыть БД";
        return false;
    }
    return false;
}

//Открытие БД
bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/Projects/AutoVisorBeta/DataBase/" DATABASE_NAME);
    if(db.open())
    {
        return true;
    }
    else
        return false;
}

//Закрытие БД
void DataBase::closeDataBase()
{
    db.close();
}

//Создание таблицы в базе данных
bool DataBase::creatTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE" TABLE "("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   TABLE_ID_DEVICE   " VARCHAR(255)  NULL,"
                   TABLE_NUMBER_MESS " VARCHAR(255)  NULL,"

                   " )"))
    {
        qDebug()<<"Error of create DataBase"<<TABLE;
        qDebug()<<query.lastError().text();
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

//Создание таблицы БД для данных
bool DataBase::creatTabelData()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE" TABLE_DATA "("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   TABLE_DATE   " DATE           NOT NULL,"
                   TABLE_TIME   " TIME           NOT NULL,"
                   TABLE_MESS   " VARCHAR(255)   NOT NULL,"
                   " )"))
    {
        qDebug()<<"Error of create DataBase"<<TABLE_DATA;
        qDebug()<<query.lastError().text();
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

//Заполнение БД данными------------------------------------------------------------------------------------
bool DataBase::insertToDataBase(const QVariant &data)//
{
    QSqlQuery query;

   // query.prepare("INSERT INTO" TABLE "(")
}

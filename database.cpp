#include "database.h"

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
}

DataBase::DataBase(QString path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
}

bool DataBase::Connect()
{
    return db.open();
}

void DataBase::Disconnect()
{
    db.close();
}

AccountModel DataBase::CheckAccount(QString login, QString password)
{
    QString sql = "SELECT id, login, password FROM table_account WHERE login = '" + login + "' AND password = '" + password + "'";
    QSqlQuery query;
    query.exec(sql);

    AccountModel temp;

    query.next();
    temp.id = query.value(0).toInt();
    temp.login = query.value(1).toString();
    temp.password = query.value(2).toString();

    return temp;
}

#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "AccountModel.h"

class DataBase
{
private:
    QSqlDatabase db;

public:
    DataBase();
    DataBase(QString path);
    bool Connect();
    void Disconnect();

    AccountModel CheckAccount(QString login, QString password);
};

#endif // DATABASE_H

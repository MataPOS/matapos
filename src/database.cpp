#include "database.h"

Database::Database(QObject *parent)
    : QObject{parent}
{

}

 // TO CONNECT THE DATABASE
bool Database::connOpen(){
    mydb.setDatabaseName("/Users/tobiabass11/Project matapos v1/database.db");

    if(!mydb.open()) {
        qDebug()<<("Database failed to open");
        return false;
    }
    else {
        qDebug()<<("Database opened successfully");
        return true;
    }
}

// TO DISCONNECT THE DATABASE
void Database::connClose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

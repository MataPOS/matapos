#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

class Database : public QObject
{
    Q_OBJECT

public:
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    // FUNCTION DECLARATION FOR OPENING AND CLOSING DATABASE
    bool connOpen();
    void connClose();


public:
    explicit Database(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H

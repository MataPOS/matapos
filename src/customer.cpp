#include "customer.h"
#include "database.h"


Customer::Customer(QObject *parent)
    : QObject{parent}
{

}

void Customer::getCustomerInfo(QString customerId)
{
    QSqlQuery qry;
    qry.prepare("select * from customers where customerId= '"+ customerId+"'");

    if(qry.exec()){
        while(qry.next()){
            customerAccountBalance = qry.value(4).toString();
            customerPin = qry.value(5).toString();
            customerEmail = qry.value(6).toString();
        }
        customerInfo = customerId + "\t\t" + customerAccountBalance + "\t\t" + customerPin;
        qDebug()<<(customerId);
    }

}

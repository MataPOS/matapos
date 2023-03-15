#include "product.h"
#include "database.h"

Product::Product(QObject *parent)
    : QObject{parent}
{

}


void Product::getProduct(int productIds)
{
    QString pro = QString::number(productIds);
    QSqlQuery qry;
    qry.prepare("select * from products where productId= '"+ pro+"'");

    if(qry.exec()){
        while(qry.next()){
            productId = qry.value(0).toString();
            productName = qry.value(1).toString();
            productPrice = qry.value(2).toString();
            productWeight = qry.value(3).toString();
            productQuantity = qry.value(4).toString();
        }
        productInfo = productId + "\t\t" + productName + "\t\t" + productPrice + "\t\t" + productWeight + "\t\t" + productQuantity;
        qDebug()<<(productId);
    }

}

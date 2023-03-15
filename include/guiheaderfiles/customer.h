#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>

class Customer : public QObject
{
    Q_OBJECT

public:
    QString customerAccountBalance, customerPin, customerEmail, customerInfo;
    void getCustomerInfo(QString customerId);

public:
    explicit Customer(QObject *parent = nullptr);

signals:

};

#endif // CUSTOMER_H

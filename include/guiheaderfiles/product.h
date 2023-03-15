#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT

public:
    QString productId, productName, productPrice, productWeight, productQuantity, productInfo;
    void getProduct(int proudctIds);

public:
    explicit Product(QObject *parent = nullptr);

signals:

};

#endif // PRODUCT_H

#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H

#include <QObject>

class customerInfo : public QObject
{
    Q_OBJECT
public:
    explicit customerInfo(QObject *parent = nullptr);

signals:

};

#endif // CUSTOMERINFO_H

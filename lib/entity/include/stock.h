#ifndef STOCK_H
#define STOCK_H

#include <QString>

/**
* Stock item details

*/

class Stock {

public:
	QString id;
	QString uniqueId;
	QString itemName;
	QString price;
	QString qty;

};

#endif

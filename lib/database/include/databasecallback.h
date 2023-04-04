#ifndef DATABASECALLBACK_H
#define DATABASECALLBACK_H

#include "customer.h"
#include "stock.h"

/**
 * Database callback to be implemented by clients
 * */
class DatabaseCallback {
	public:
		virtual void customerDataAvailable(Customer customerData) = 0;
		virtual void itemDataAvailable(Stock itemData) = 0;
};
#endif

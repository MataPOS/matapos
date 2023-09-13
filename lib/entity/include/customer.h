#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

/**
Customer class holds customer data for program to process

*/

class Customer {

	public:
		QString id;
		QString uniqueId;
		QString firstName;
		QString lastName;
		QString cardNumber;
		QString emailId;
		QString credit;

};

#endif

#ifndef DATABASE_H
#define DATABASE_H

#include "customer.h"
#include "stock.h"

#include <QSqlDatabase>
#include <QtSql>
#include <QString>


class Database {

	
	public:
		Database();
		~Database();

		void createCustomerTable();
		void createStockTable();

		Customer queryCustomerDetails(std::string uniqueId);
		Stock queryItemDetails(std::string uniqueId);

		void connOpen();
		void connClose();

	private:
		Customer prepareCustomerObj(QSqlQuery query);
		Stock prepareItemObj(QSqlQuery query);
		QSqlDatabase mataposDb;
		


};


#endif

#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql>

class Database {

	
	public:
		Database();
		~Database();

		void createCustomerTable();
		void createStockTable();

		void queryCustomerDetails();
		void queryItemDetails();

		void connOpen();
		void connClose();

	private:
		QSqlDatabase mataposDb;
		


};


#endif

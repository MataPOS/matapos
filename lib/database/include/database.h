#ifndef DATABASE_H
#define DATABASE_H

#include "customer.h"
#include "stock.h"
#include "barcodereader.h"
#include "databasecallback.h"
#include "cart.h"
#include "stock.h"


#include <QSqlDatabase>
#include <QtSql>
#include <QString>
#include <memory>

class Database {
	
	public:
		
		
		static Database& getDatabaseInstance();
		void createCustomerTable();
		
		void registerCallback(DatabaseCallback* clientCallbackPtr);

		void queryCustomerDetails(std::string uniqueId);
		void queryItemDetails(std::string uniqueId);
		std::string checkoutCustomer(Cart cart);
		std::string debitTotal(std::string customerId, double totalCost);
		std::string updateStock(std::vector<Stock> itemList);

		void connOpen();
		void connClose();

		/**
		 * BarcodeReader callback implementation	
		 * */
		 
		 BarcodeReader barcodereader;
		 
		struct UniqueIdAvailableCallback: BarcodeReaderCallback {
			Database* databasePtr = nullptr;
			public:
				void uniqueIdAvailable(std::string uniqueId, std::string flow) {
					if(nullptr != databasePtr) {
						if(flow == "customer_identification") {
						
						std::cout<<"Calling customer query ";
							databasePtr -> queryCustomerDetails(uniqueId);
						} else {
							databasePtr -> queryItemDetails(uniqueId);
						}
					}	
				}
		};

		UniqueIdAvailableCallback uniqueIdAvailableCallback;

	private:
		
		
		Database();
		~Database();
		
		Database(const Database&) = delete;
		Database& operator=(const Database&) = delete;
		
		Customer prepareCustomerObj(QSqlQuery query);
		Stock prepareItemObj(QSqlQuery query);
		QSqlDatabase mataposDb;
		QString databasetype;
		QString databasepath;
		
		std::vector<DatabaseCallback*> databaseCallbackPtr;

};
#endif

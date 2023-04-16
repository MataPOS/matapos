#define DEBUG

#include "database.h"
#include <iostream>


Database Database::getDatabaseInstance() {
	static Database databaseSingleton;
	return databaseSingleton;
	
}

Database::Database() {
	
	uniqueIdAvailableCallback.databasePtr = this;
	barcodereader.registerBarcodereaderCallback(&uniqueIdAvailableCallback);
	
	databasetype = "QSQLITE";
	databasepath = "../lib/database/src/matapos_db.db";

	mataposDb = QSqlDatabase::addDatabase(databasetype);
	mataposDb.setDatabaseName(databasepath);

}


Database::~Database() {


}


/*
Implement checkout process
*/
void Database::checkoutCustomer(Cart cart) {
	
	//deduct credit
	debitTotal(cart.customerId, cart.totalCost);
	//update stock
	updateStock(cart.itemList);
	
	for(auto dbCallback : databaseCallbackPtr) {
			dbCallback -> checkoutSuccess();
	}
		
}


void Database::updateStock(std::vector<CartItem> itemList) {
	
	connOpen();
	
	QSqlQuery query(mataposDb);
	
	
	for (CartItem item : itemList) {
	
		QString uniqueIdQString = QString::fromStdString(item.uniqueId);
		QString purchasedQty = QString::number(item.qty);
		
		query.prepare("UPDATE stock SET qty=qty- '"+purchasedQty+"' WHERE unique_id like '"+uniqueIdQString+"' ");

		if(query.exec()) {
			#ifdef DEBUG
			std::cout << std::endl << "item qty updated!" << std::endl;
			#endif

			connClose();

		} else {
			#ifdef DEBUG
			std::cout << std::endl << "Could not update item qty..." << std::endl;
			#endif
		}

		connClose();
	}
	
}

/*
Update customer credit after purchase
*/
void Database::debitTotal(std::string customerId, float totalCost) {
	connOpen();
	
	QSqlQuery query(mataposDb);
	QString uniqueIdQString = QString::fromStdString(customerId);
	query.prepare("UPDATE customer SET credit=credit-totalCost WHERE unique_id like '"+uniqueIdQString+"' ");

	if(query.exec()) {
		#ifdef DEBUG
		std::cout << std::endl << "Amount debited successfully!" << std::endl;
		#endif

		connClose();

	} else {
		#ifdef DEBUG
		std::cout << std::endl << "Could not debit amount..." << std::endl;
		#endif
	}

	connClose();
}

void Database::registerCallback(DatabaseCallback* clientCallbackPtr) {
	std::cout<<"Inside database register callback ";
	databaseCallbackPtr.push_back(clientCallbackPtr);
}


void Database::queryCustomerDetails(std::string uniqueId) {
	
	connOpen();
	
	QSqlQuery query(mataposDb);
	QString uniqueIdQString = QString::fromStdString(uniqueId);
	query.prepare("SELECT * from customer WHERE unique_id like '"+uniqueIdQString+"'");

	if(query.exec()) {
		#ifdef DEBUG
		std::cout << std::endl << "Customer details retrieved successfully!" << std::endl;
		#endif

		connClose();
	
		for(auto dbCallback : databaseCallbackPtr) {
			dbCallback -> customerDataAvailable(prepareCustomerObj(query));
		}
		

	} else {
		#ifdef DEBUG
		std::cout << std::endl << "Could not retrieve customer details..." << std::endl;
		#endif
	}

	connClose();


}

Customer Database::prepareCustomerObj(QSqlQuery query) {
	
	Customer customer;

	while(query.next()){
            
        customer.id = query.value(0).toString();
        customer.uniqueId = query.value(1).toString();
        customer.firstName = query.value(2).toString();
        customer.lastName = query.value(3).toString();
        customer.cardNumber = query.value(4).toString();
        customer.emailId = query.value(5).toString();
        customer.credit = query.value(6).toString();
    }	

    return customer;
}


void Database::queryItemDetails(std::string uniqueId) {
	
	connOpen();
	
	QSqlQuery query(mataposDb);
	
	QString uniqueIdQString = QString::fromStdString(uniqueId);
	query.prepare("SELECT * from stock WHERE unique_id like '"+uniqueIdQString+"'");

	if(query.exec()) {
		#ifdef DEBUG
		std::cout << std::endl << "Item details retrieved successfully!" << std::endl;
		#endif

		connClose();
		
		for(auto dbCallback : databaseCallbackPtr) {
			dbCallback -> itemDataAvailable(prepareItemObj(query));
		}
	

	} else {
		#ifdef DEBUG
		std::cout << std::endl << "Could not retrieve item details..." << std::endl;
		#endif
	}

	connClose();

}

Stock Database::prepareItemObj(QSqlQuery query) {
	
	Stock stock;

	while(query.next()){
	
        stock.id = query.value(0).toString();
        stock.uniqueId = query.value(1).toString();
        stock.itemName = query.value(2).toString();
        stock.price = query.value(3).toString();
        stock.qty = query.value(4).toString();
        
    }	

    return stock;
}


void Database::createCustomerTable(){
	connOpen();
	QSqlQuery query(mataposDb);
	QString createCustomerTableQuery = "CREATE TABLE customer (id INTEGER PRIMARY KEY AUTOINCREMENT,"
									   "unique_id TEXT,first_name TEXT,last_name TEXT,"
									   "card_number TEXT,email_id TEXT, credit real);";

	//QString createCustomerTableQuery = "CREATE TABLE weather(id INTEGER PRIMARY KEY AUTOINCREMENT, temperature REAL, humidity REAL, date DATETIME);";
	if(query.exec(createCustomerTableQuery)) {
		#ifdef DEBUG
		std::cout << std::endl << "customer table created successfully!" << std::endl;
		#endif
	} else {
		#ifdef DEBUG
		std::cout << std::endl << "Could not create customer table in DB..." << std::endl;
		#endif
	}
	connClose();
}



/**
 * Establish contact with database
 * */
void Database::connOpen() {
	if(!mataposDb.open()) {
		#ifdef DEBUG
		std::cout << std::endl << "connection to matapos_db failed..." << std::endl;
		#endif	
	} else {
		#ifdef DEBUG
		std::cout << std::endl << "connection to matapos_db successfull!" << std::endl;
		#endif	
	}
}

/**
 * Close connection with database
 * */
void Database::connClose() {

	mataposDb.close();
	

}


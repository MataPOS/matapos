#define DEBUG

#include "database.h"
#include <iostream>

Database::Database() {

	mataposDb = QSqlDatabase::addDatabase("QSQLITE");
	mataposDb.setDatabaseName("/home/avinash/coursework/real_time_embedded/matapos_proj/matapos/lib/database/src/matapos_db.db");

}


Database::~Database() {


}

Customer Database::queryCustomerDetails(std::string uniqueId) {
	
	connOpen();
	
	QSqlQuery query(mataposDb);
	
	query.prepare("SELECT * from customer WHERE unique_id like '?'");
	query.addBindValue(QString::fromStdString(uniqueId));

	if(query.exec()) {
		#ifdef DEBUG
		std::cout << std::endl << "Customer details retrieved successfully!" << std::endl;
		#endif

		connClose();

		return prepareCustomerObj(query);
		

	} else {
		#ifdef DEBUG
		std::cout << std::endl << "Could not retrieve customer details..." << std::endl;
		#endif
	}

	connClose();
	return null;

}

Customer Database::prepareCustomerObj(QSqlQuery query) {
	
	Customer customer;

	while(query.next()){
        customer.id = query.value(1).toString();
        customer.uniqueId = query.value(2).toString();
        customer.firstName = query.value(3).toString();
        customer.lastName = query.value(4).toString();
        customer.cardNumber = query.value(5).toString();
        customer.emailId = query.value(6).toString();
    }	

    return customer;
}


Stock Database::queryItemDetails(std::string uniqueId) {
	
	connOpen();
	
	QSqlQuery query(mataposDb);
	
	query.prepare("SELECT * from stock WHERE unique_id like '?'");
	query.addBindValue(QString::fromStdString(uniqueId));

	if(query.exec()) {
		#ifdef DEBUG
		std::cout << std::endl << "Item details retrieved successfully!" << std::endl;
		#endif

		connClose();

		return prepareItemObj(query);
		

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
        stock.id = query.value(1).toString();
        stock.uniqueId = query.value(2).toString();
        stock.itemName = query.value(3).toString();
        stock.price = query.value(4).toString();
        stock.qty = query.value(5).toString();
        
    }	

    return stock;
}


void Database::createCustomerTable(){
	connOpen();
	QSqlQuery query(mataposDb);
	QString createCustomerTableQuery = "CREATE TABLE customer (id INTEGER PRIMARY KEY AUTOINCREMENT,"
									   "unique_id TEXT,first_name TEXT,last_name TEXT,"
									   "card_number TEXT,email_id TEXT);";

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


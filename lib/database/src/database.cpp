#define DEBUG

#include "database.h"
#include <iostream>

Database::Database() {

	mataposDb = QSqlDatabase::addDatabase("QSQLITE");
	mataposDb.setDatabaseName("/home/avinash/coursework/real_time_embedded/matapos_proj/matapos/lib/database/src/matapos_db.db");

}


Database::~Database() {


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


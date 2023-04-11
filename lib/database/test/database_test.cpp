#include <gtest/gtest.h>
#include <iostream>

#include "database.h"
#include "databasecallback.h"
#include "customer.h"
#include "stock.h"


class Client{

public:
	Client() {
	
	};
	
	struct ClientCallback: public DatabaseCallback {
	
		void customerDataAvailable(Customer customerData) {
			
		}
		
		void itemDataAvailable(Stock itemData) {
		
		}
	};
	
	ClientCallback* callbackPtr = nullptr;
};



TEST(ExampleTests, DemonstrateGTestMacros) {

	EXPECT_TRUE(true);
}

/**
 Test registerCallback method
**/
TEST(DATABASE_H_TEST, registersCallbackClient) {

	Database* database = new Database();
	Client* client = new Client();
	
	database->registerCallback(client->callbackPtr);
	std::cout << std::endl << client <<std::endl;
	std::cout << std::endl << database->databaseCallbackPtr <<std::endl;
	EXPECT_EQ(client->callbackPtr, database->databaseCallbackPtr);
		
	
}

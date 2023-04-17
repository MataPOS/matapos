
#include "window.h"
#include<QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	
	Database& db = Database::getDatabaseInstance();
	Stock stock;

	std::vector<Stock> itemList;
	
	stock.id = QString::fromStdString("1");
	stock.uniqueId = QString::fromStdString("stock01");
	stock.itemName = QString::fromStdString("cornflakes");
	stock.price = QString::fromStdString("2.65");
	stock.qty = QString::fromStdString("1");

	
	itemList.push_back(stock);

	Cart cart;
	cart.customerId = "cust01";
	cart.itemList = itemList;
	cart.totalCost = 10.0;	
	
	db.checkoutCustomer(cart);
	
	
	
	return app.exec();

}

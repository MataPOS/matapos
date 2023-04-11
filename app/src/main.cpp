#include <QApplication>
#include "window.h"
#include "database.h"

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);
	
	Database* db = new Database();
	
	
	db->createCustomerTable();
	
	
	return app.exec();
}

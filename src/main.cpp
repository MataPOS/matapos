
#include <guiheaderfiles/window.h>
#include<QApplication>
#include<iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	
	std::cout<<"Inside Main ";
	
	window *w;
	
	w = new window();

	w->start();
	
	
	
	return app.exec();

}

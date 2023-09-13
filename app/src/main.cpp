
#include "window.h"
#include<QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	
		
	window *w;
	w = new window();

	w->start();
	
	
	
	
	return app.exec();

}

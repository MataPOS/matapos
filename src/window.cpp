#include "guiheaderfiles/window.h"
#include <iostream>

 window::window()
{
	std::cout<<"started window start ";
	w = new WelcomeScreen;
	
	stackedWidget = new QStackedWidget;
	stackedWidget->addWidget(w);

	std::cout<<"started window end ";
}




void window::start()
{

	stackedWidget->setCurrentIndex(0);
			
			
	stackedWidget->show();
	
	

}






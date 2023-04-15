#include "window.h"

#include <iostream>

 window::window()
{
	
	stackedWidget = new QStackedWidget;
	
	w = new WelcomeScreen;
	
	
	c= new CartScreen;	
	
	cartscreen_mycheckout.win = this;
	c->registerCheckoutPressed(&cartscreen_mycheckout);
	
	cartscreen_mycancel.win = this;
	c->registerCancelPressed(&cartscreen_mycancel);
	
	
	stackedWidget->addWidget(w);
	stackedWidget->addWidget(c);
	
	welcomescreen_customeridentified.win = this;
	w->registerCustomerIdentified(&welcomescreen_customeridentified);
	
	camera.start();
		

}




void window::start() // start the initial screen here
{



	stackedWidget->setCurrentIndex(0);
	c->stop();
	w->start();

			
	stackedWidget->show();
	
	

}



void window::CartScreenCheckout() // define here what happens if customer presses checkout button in cartscreen. Modify this function to recieve customer data, and initiate the next screen
{
	std::cout<<"in window's cartscreen checkout function";
	stackedWidget->setCurrentIndex(0);
	stackedWidget->show();
	c->stop();
	w->start();
}

void window::CartScreenCancel() // define here what happens if customer presses cancel button in cartscreen. Modify this function to recieve customer data, and initiate the next screen
{
	std::cout<<"in window's cartscreen cancel function";
	stackedWidget->setCurrentIndex(0);
	stackedWidget->show();
	c->stop();
	w->start();
}




void window::WelcomeScreenCustomerIdentified()
{

	stackedWidget->setCurrentIndex(1);
	w->stop();
	c->start();
	


}

// Add more functions depending one the user actions.


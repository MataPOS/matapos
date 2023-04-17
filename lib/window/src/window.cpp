#include "window.h"

#include <iostream>

 window::window()
{
	
     setWindowTitle("MATAPOS v2.0");
     setFixedSize(400,500);
     QFont font("Courier New");
     font.setStyleHint(QFont::Monospace);
     QWidget::setFont(font);
     
     stackedWidget = new QStackedWidget;
     
     w = new WelcomeScreen;
	
     c= new CartScreen;
     
     p = new PaymentScreen;
     
     paymentscreen_mypayment.win = this;
     p->registerPaymentPressed(&paymentscreen_mypayment);
     
     paymentscreen_myback.win = this;
     p->registerBackPressed(&paymentscreen_myback);
	
     cartscreen_mycheckout.win = this;
     c->registerCheckoutPressed(&cartscreen_mycheckout);
	
     cartscreen_mycancel.win = this;
     c->registerCancelPressed(&cartscreen_mycancel);
	
	
     stackedWidget->addWidget(w);
     stackedWidget->addWidget(c);
	
     welcomescreen_customeridentified.win = this;
     w->registerCustomerIdentified(&welcomescreen_customeridentified);
     
     
     stackedWidget->addWidget(p);
     
     
	
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
	stackedWidget->setCurrentIndex(2);
	stackedWidget->show();
	c->stop();
	w->stop();
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



void window::PaymentScreenPayment() // define here what happens if customer presses the pay button in the paymentscreen.
{

	
	stackedWidget->setCurrentIndex(0);

	w->start();

			
	stackedWidget->show();
	std::cout<<" In the Windows PaymentScreenPayment function ";

}



void window::PaymentScreenBack() //define here what happens if customer presses the back button in the paymentscreen.
{

	stackedWidget->setCurrentIndex(1);

	c->start();
	std::cout<<" In the Windows PaymentScreenBack function ";

}

// Add more functions depending one the user actions.


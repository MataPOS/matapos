#include "window.h"
#include <QTimer>

#include <iostream>

 window::window()
{
	
     setWindowTitle("MATAPOS v2.0");
     //setFixedSize(600,800);
     QFont font("Courier New");
     font.setStyleHint(QFont::Monospace);
     QWidget::setFont(font);
     
     stackedWidget = new QStackedWidget(this);
     
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
    // this->addWidget(stackedWidget);		
	
	this->show();
		

}




void window::start() // start the initial screen here
{


	this->resize(400,600);
	stackedWidget->setCurrentIndex(0);
	c->stop();
	w->start();

	
	//stackedWidget->show();
	
	

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
	this->resize(400,600);
	w->start();
}




void window::WelcomeScreenCustomerIdentified()
{
	this->resize(c->sizeHint());
	stackedWidget->setCurrentIndex(1);
	w->stop();
	this->resize(600,600);
	c->start();
	


}



void window::PaymentScreenPayment() // define here what happens if customer presses the pay button in the paymentscreen.
{

	
	QTimer *timer = new QTimer(this);
	QMessageBox *messageBox = new QMessageBox(this);
	messageBox->setText("Thank you for shopping with us");

	connect(timer, &QTimer::timeout, [=]() {messageBox->hide();});
	timer->start(1000);
	
	messageBox->show();
	
	stackedWidget->setCurrentIndex(0);
	
	this->resize(400,600);
	w->start();

			
	stackedWidget->show();
	std::cout<<" In the Windows PaymentScreenPayment function ";

}



void window::PaymentScreenBack() //define here what happens if customer presses the back button in the paymentscreen.
{

	stackedWidget->setCurrentIndex(1);
	
	this->resize(550,600);
	c->start();
	std::cout<<" In the Windows PaymentScreenBack function ";

}

// Add more functions depending one the user actions.


#include "window.h"
#include <QTimer>

#include <iostream>
/**
* This constructor sets the Welcome Screen and CartScreen

*/

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
     
     cartscreen_mycheckout.win = this;
     c->registerCheckoutPressed(&cartscreen_mycheckout);
	
     cartscreen_mycancel.win = this;
     c->registerCancelPressed(&cartscreen_mycancel);
	
	
     stackedWidget->addWidget(w);
     stackedWidget->addWidget(c);
	
     welcomescreen_customeridentified.win = this;
     w->registerCustomerIdentified(&welcomescreen_customeridentified);
     
     
   
     
	
     camera.start();
    		
	
	this->show();
		

}


/**
* Starts the window

*/


void window::start() // start the initial screen here
{


	this->resize(400,600);
	stackedWidget->setCurrentIndex(0);
	c->stop();
	w->start();

	
	
	
	

}

/**
* This is called when checkout is pressed in cartscreen

*/


void window::CartScreenCheckout() 
{
	std::cout<<"in window's cartscreen checkout function";
	
	QTimer *timer = new QTimer(this);
	QMessageBox *messageBox = new QMessageBox(this);
	messageBox->setText("Thank you for shopping with us");

	connect(timer, &QTimer::timeout, [=]() {messageBox->hide();});
	timer->start(1000);
	
	messageBox->show();
	
	stackedWidget->setCurrentIndex(0);
	stackedWidget->show();
	c->cleardata();
	c->stop();
	this->resize(400,600);
	w->start();
}

/**
* This is called when cancel is pressed in cartscreen

*/

void window::CartScreenCancel() // define here what happens if customer presses cancel button in cartscreen. Modify this function to recieve customer data, and initiate the next screen
{
	std::cout<<"in window's cartscreen cancel function";
	stackedWidget->setCurrentIndex(0);
	stackedWidget->show();
	c->cleardata();
	c->stop();
	this->resize(400,600);
	w->start();
}


/**
* This is called when customer is identified welcomescreen

*/

void window::WelcomeScreenCustomerIdentified()
{
	this->resize(c->sizeHint());
	stackedWidget->setCurrentIndex(1);
	w->stop();
	this->resize(600,600);
	c->start();
	


}






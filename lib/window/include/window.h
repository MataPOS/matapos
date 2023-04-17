#ifndef WINDOW_H
#define WINDOW_H

#include <QStackedWidget>
#include"WelcomeScreen.h"
#include "CartScreen.h"
#include<iostream>
/**
* The Class contains the various screens and controls the flow of MATAPOS program. The CartScreen and WelcomeScreen classes are instantiated in this class, and the two gives out all their event signals here. This enables window class to make decisions for next state.

*/


class window: public QWidget
{

private:

	WelcomeScreen *w;
	CartScreen *c;
	
	
	QStackedWidget *stackedWidget;
	
	Camera& camera = Camera::getCamera();
    
    QFont *font;


public:
	window();
	void start();
	void CartScreenCheckout();
	void CartScreenCancel();
	void WelcomeScreenCustomerIdentified();
	
	

	struct mycheckout : CartScreen::CheckoutPressed
	{
	
		window* win = nullptr;
		
		virtual void checkoutpressed()
		{
			win->CartScreenCheckout();
		
		}
	
	};
	
	mycheckout cartscreen_mycheckout;
	
	
	struct mycancel : CartScreen::CancelPressed
	{
	
		window* win = nullptr;
		
		virtual void cancelpressed()
		{
			win->CartScreenCancel();
		
		}
	
	};
	
	mycancel cartscreen_mycancel;
	
	
	
	struct mycustomeridentified : WelcomeScreen::CustomerIdentified

	{
	
		window* win = nullptr;
		virtual void customeridentifiedfunction()
		{
		
			win->WelcomeScreenCustomerIdentified();
		}
		
	
	};
	
	
	mycustomeridentified welcomescreen_customeridentified;
	
	

	

};

#endif

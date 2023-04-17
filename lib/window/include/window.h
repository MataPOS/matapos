#ifndef WINDOW_H
#define WINDOW_H

#include <QStackedWidget>
#include"WelcomeScreen.h"
#include "CartScreen.h"
#include "PaymentScreen.h"
#include<iostream>


class window: public QWidget
{

private:

	WelcomeScreen *w;
	CartScreen *c;
	PaymentScreen *p;
	
	QStackedWidget *stackedWidget;
	
	Camera& camera = Camera::getCamera();
    
    QFont *font;


public:
	window();
	void start();
	void CartScreenCheckout();
	void CartScreenCancel();
	void WelcomeScreenCustomerIdentified();
	void PaymentScreenPayment();
	void PaymentScreenBack();
	

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
	
	
	
	struct mypayment : PaymentScreen::PaymentPressed
	{
	
		window* win = nullptr;
		
		virtual void paymentpressed()
		{
			win->PaymentScreenPayment();
		
		}
	
	};
	
	mypayment paymentscreen_mypayment;
	
	
	
	struct myback : PaymentScreen::BackPressed
	{
	
		window* win = nullptr;
		
		virtual void backpressed()
		{
			win->PaymentScreenBack();
		
		}
	
	};
	
	myback paymentscreen_myback;
	

};

#endif

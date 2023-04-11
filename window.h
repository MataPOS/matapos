#ifndef WINDOW_H
#define WINDOW_H

#include <QStackedWidget>
#include"WelcomeScreen.h"
#include "CartScreen.h"
#include<iostream>


class window: public QWidget
{

private:

	WelcomeScreen *w;
	CartScreen *c;
	
	QStackedWidget *stackedWidget;


public:
	window();
	void start();
	void CartScreenCheckout();
	void CartScreenCancel();

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
	

};

#endif

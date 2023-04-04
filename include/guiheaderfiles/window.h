#ifndef WINDOW_H
#define WINDOW_H

#include <QStackedWidget>
#include"WelcomeScreen.h"
#include<iostream>


class window: public QWidget
{

private:

	WelcomeScreen *w;
	
	
	QStackedWidget *stackedWidget;


public:
	window();
	void start();


};

#endif

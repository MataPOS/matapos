#ifndef PAYMENTSCREEN_H
#define PAYMENTSCREEN_H


#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QListWidget>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
// #include "camera.h"
// #include "barcodereader.h"
// #include "barcodereadercallback.h"

#include<iostream>
#include<string>




class PaymentScreen : public QWidget
{

	//Q_OBJECT

private:
	

	QLabel *label_PinMessage, *pinLabel;
	QLineEdit *pinEdit;
	
	QPushButton *back;
	QPushButton *pay;

	QHBoxLayout *hLayout_buttons;
	QHBoxLayout *hLayout_pin;
	QVBoxLayout *vLayout;
	
	QLabel *image;
	
	
	
	



public:


	struct PaymentPressed
	{
		virtual void paymentpressed() = 0;
	
	};
	
	PaymentPressed* paymentPressed = nullptr;
	
	void registerPaymentPressed(PaymentPressed* pp)
	{
		paymentPressed = pp;
	
	}



	
	struct BackPressed
	{
		virtual void backpressed() = 0;
	
	};
	
	BackPressed* backPressed = nullptr;
	
	void registerBackPressed(BackPressed* bp)
	{
		backPressed = bp;
	
	}



	
	PaymentScreen();
	
	
signals:

private slots:
 	void payment_pressed();
 	void back_pressed();	
  

};

#endif

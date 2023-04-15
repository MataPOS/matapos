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
	

	QLabel *label_EnterPin;
	QPushButton *cancel;
	QPushButton *pay;

	QHBoxLayout *hLayout_buttons;
	QHBoxLayout *hLayout_pin;
	QVBoxLayout *vLayout;
	
	QLabel *image;
	
	
	
	



public:
	
signals:

private slots:
 	void payment_pressed();
 	void cancel_pressed();	
  

};

#endif
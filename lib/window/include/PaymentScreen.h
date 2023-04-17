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
	
	PaymentScreen();
signals:

private slots:
 	void payment_pressed();
 	void back_pressed();	
  

};

#endif

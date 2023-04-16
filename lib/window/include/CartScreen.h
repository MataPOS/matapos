#ifndef CARTSCREEN_H
#define CARTSCREEN_H


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
#include "camera.h"
#include "stock.h"
#include "database.h"
#include "databasecallback.h"
#include<iostream>
#include<string>




class CartScreen : public QWidget
{

	//Q_OBJECT

private:
	

	QLabel *label_ScanMessage;
	QLabel *label_Price;
	QListWidget *item_list;
	QPushButton *cancel;
	QPushButton *checkout;

	QHBoxLayout *hLayout_buttons;
	QHBoxLayout *hLayout_display;
	QVBoxLayout *vLayout_display;
	QVBoxLayout *vLayout_cart;
	QVBoxLayout *vLayout;
	
	QLabel *image;
	
	
	
	



public:
	
	
	class myDatabaseCallback : public DatabaseCallback {
	
		public : CartScreen* cartscreenptr = nullptr;
		
	
		public: 
		
		virtual void customerDataAvailable(Customer customerData) // Cartscreen do not need customer data
		{
			
			std::cout<<"Inside Cartscreen customer data available function ";
			return;
		
		}
	
		virtual void itemDataAvailable(Stock itemData) // Welcomescreen does not need item scan, so method not defined here.
		{
			if(nullptr != cartscreenptr)
			{
			std::cout<<"Inside cartscreen item data available function ";
			cartscreenptr->item_identified(itemData);
			}
		}
		
		virtual void checkoutSuccess() // Welcomescreen does not need item scan, so method not defined here.
		{
		
			std::cout<<"Inside cartscreen item data available function ";
			
		
		}
	
	
	};
	
	
	myDatabaseCallback mydatabasecallback;
	void item_identified(Stock);

	Database& Cdatabase = Database::getDatabaseInstance();
	
	
	/*
	struct ItemIdentified
	{
		virtual void itemidentifiedfunction() = 0;
		
	
	};
	
	ItemIdentified* itemidentifiedptr;
	
	
	void registerItemIdentified(ItemIdentified* ii)
	{
		itemidentifiedptr = ii;
	
	}
	*/
	
	///////////////////////////////////////
	
	
	struct CheckoutPressed
	{
		virtual void checkoutpressed() = 0;
	
	};
	
	CheckoutPressed* checkoutPressed = nullptr;
	
	void registerCheckoutPressed(CheckoutPressed* cp)
	{
		checkoutPressed = cp;
	
	}
	
	
	
	struct CancelPressed
	{
		virtual void cancelpressed() = 0;
	
	};
	
	CancelPressed* cancelPressed = nullptr;
	
	void registerCancelPressed(CancelPressed* cp)
	{
		cancelPressed = cp;
	
	}
	
	
	
	
	
	CartScreen();
	~CartScreen();
	

	
	void start(); // for starting the camera
	void stop(); // for stopping the camera
	
	void post_frames(const cv::Mat &mat); // this function recieves images and saves in QLabel varial "image", which is displayed on the screen
	
	Camera& camera = Camera::getCamera(); // getting the singleton instance of the camera class
	
	
	
	//Camera Image callback structure - recieves camera real time images from the camera driver and posts it to post_frame method
	struct CartCameraCallback :CameraCallback {
	
	CartScreen *CScreen = nullptr;
	
	virtual void frameAvailable(cv::Mat &frame)
	{
		if(nullptr != CScreen)
		{
			
			CScreen->post_frames(frame);

		
		}
	
	
	}

	
	};
	
 	CartCameraCallback cartcameracallback; // instance variable
 	
signals:

private slots:
 	void checkout_pressed();
 	void cancel_pressed();	
  

};

#endif

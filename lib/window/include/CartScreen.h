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
#include "barcodereader.h"
#include "barcodereadercallback.h"

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
	BarcodeReader barcodereader;
	
	class mybarcodereadercallback : public BarcodeReaderCallback {

	public:
		CartScreen* Cartscreenptr = nullptr;
		
		virtual void uniqueIdAvailable(std::string data, std::string flow){
		
		if(nullptr != Cartscreenptr)
		{
		
			Cartscreenptr->getProductInfo(data);
					
		}
		
		
		}
		};
		
	mybarcodereadercallback mbreadercallback;
	
	
	
	
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
	
	void getProductInfo(std::string);
	
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

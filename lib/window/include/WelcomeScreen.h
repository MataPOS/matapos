
#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H


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



class WelcomeScreen : public QWidget
{

//Q_OBJECT

private:

	QLabel *label_WelcomeMessage;
	QLabel *logolabel;
	QVBoxLayout *vLayout;
	QScrollArea *scrollarea;
	QLabel *image;


public:
	
	BarcodeReader barcodereader;
	
	class mybarcodereadercallback : public BarcodeReaderCallback {

	public:
		WelcomeScreen* welcomescreenptr = nullptr;
		
		virtual void uniqueIdAvailable(std::string data, std::string flow){
		
		if(nullptr != welcomescreenptr)
		{
		
			welcomescreenptr->customer_identified(data);
					
		}
		
		
		}
		};
		
	mybarcodereadercallback mbreadercallback;
	
	struct CustomerIdentified
	{
		virtual void customeridentifiedfunction() = 0;
		
	
	};
	
	CustomerIdentified* customeridentifiedptr;
	
	void registerCustomerIdentified(CustomerIdentified* ci)
	{
		customeridentifiedptr = ci;
	
	}
	
	
	Camera& camera = Camera::getCamera();
	WelcomeScreen();
	~WelcomeScreen();
	void qr_scanned();
	
	void post_frames(const cv::Mat &mat);
	
	void start();
	void stop();
	
	
	void customer_identified(std::string); // this function will call the callback for the next screen after the customer is identified
	
	//Camera Image callback structure to be implemented
	struct MyCameraCallback :CameraCallback {
	
	WelcomeScreen* WScreen = nullptr;
	
	virtual void frameAvailable(cv::Mat &frame)
	{
		if(nullptr != WScreen)
		{
			
			WScreen->post_frames(frame);
		
		}
	
	
	}

	
	};
	
	MyCameraCallback mycameracallback;
  

};

#endif

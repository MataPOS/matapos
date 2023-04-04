
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

#include "camera/camera.h"
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
	
	Camera camera;
	WelcomeScreen();
	~WelcomeScreen();
	void qr_scanned();
	
	void post_frames(const cv::Mat &mat);
	
	
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

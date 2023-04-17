

#include"WelcomeScreen.h"
#include<iostream>

 WelcomeScreen::WelcomeScreen()
{
     setFixedSize(600,800);
     //BASIC SETTINGS FOR THE APPLICATION WINDOW
     setWindowTitle("MATAPOS v1.0");
     setFixedSize(400,500);
     QFont font("Courier New");
     font.setStyleHint(QFont::Monospace);
     QWidget::setFont(font);

	mycameracallback.WScreen = this;
	
	camera.registerFrameAvailableCallback(&mycameracallback);
	
	mydatabasecallback.welcomescreenptr = this;
	database.registerCallback(&mydatabasecallback);	
	
	
	image = new QLabel;
	
	
	label_WelcomeMessage = new QLabel;
	label_WelcomeMessage->setText("Welcome, please scan your QR code");
	label_WelcomeMessage->setAlignment(Qt::AlignCenter);
	label_WelcomeMessage->show();
	
	
	//ADD LOGO TO WELCOME SCREEN
     logolabel = new QLabel;
     logolabel->setText("");
     QPixmap pix("../lib/window/src/Logo.png");
     int w = logolabel->width();
     int h = logolabel->height();
    
     logolabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

     logolabel->setAlignment(Qt::AlignCenter);


    //SCREEN LAYOUT

    vLayout = new QVBoxLayout;
    vLayout->addWidget(label_WelcomeMessage);
    vLayout->addWidget(image);
    vLayout->addWidget(logolabel);
    this->setLayout(vLayout);

}


WelcomeScreen::~WelcomeScreen()
{

	camera.stop();

}

void WelcomeScreen::qr_scanned()
{
	std::cout<<"QR Scanned";
}


void WelcomeScreen::post_frames(const cv::Mat &mat)
{
	const QImage frame(mat.data , mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
	image->setPixmap(QPixmap::fromImage(frame));
	image->setAlignment(Qt::AlignCenter);

}




void WelcomeScreen::start()
{
	
	mydatabasecallback.welcomescreenptr = this;

	
	//camera.start();
	mycameracallback.WScreen = this;
	//mbreadercallback.welcomescreenptr = this;

}

void WelcomeScreen::stop()
{

	mycameracallback.WScreen = nullptr;
	mydatabasecallback.welcomescreenptr = nullptr;

}


void WelcomeScreen::customer_identified(Customer customer) // 15 April 2023 : plan to do something with the customer data here.
{

	customeridentifiedptr->customeridentifiedfunction();


}



void WelcomeScreen::cleardata()
{




}



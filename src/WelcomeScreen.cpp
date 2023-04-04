

#include"guiheaderfiles/WelcomeScreen.h"
#include<iostream>

 WelcomeScreen::WelcomeScreen()
{

	mycameracallback.WScreen = this;
	
	camera.registerFrameAvailableCallback(&mycameracallback);
	
	
	
	image = new QLabel;
	
	
	label_WelcomeMessage = new QLabel;
	label_WelcomeMessage->setText("Welcome Please scan your QR code");
	label_WelcomeMessage->setAlignment(Qt::AlignCenter);
	label_WelcomeMessage->show();
	
	
	//Add logo to the screen
	logolabel = new QLabel;
	logolabel->setText("");
	//int w = logolabel->width();
    //int h = logolabel->height();
    //logolabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //logolabel->setAlignment(Qt::AlignCenter);

    //Screen Layout

    vLayout = new QVBoxLayout;
    vLayout->addWidget(label_WelcomeMessage);
    //vLayout->addWidget(scrollarea);
    vLayout->addWidget(image);
    vLayout->addWidget(logolabel);
    this->setLayout(vLayout);
    camera.start();

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

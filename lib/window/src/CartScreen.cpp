#include "CartScreen.h"
#include "window.h"
#include <iostream>


CartScreen::CartScreen()

{
	
	cartcameracallback.CScreen = this;
	
	camera.registerFrameAvailableCallback(&cartcameracallback);
	
	
	
	mydatabasecallback.cartscreenptr = this;
	Cdatabase.registerCallback(&mydatabasecallback);	
	

	image = new QLabel;

	label_ScanMessage = new QLabel;
	label_ScanMessage->setText("SCAN YOUR ITEMS");



	label_Price = new QLabel;
	label_Price->setText("£ TOTAL PRICE");



	item_list = new QListWidget;
	
	
	// SETTING UP THE NECESSARY
	cancel = new QPushButton("CANCEL", this);
	cancel->setStyleSheet("background-color: red;"
                          "qproperty-icon: url(../lib/window/src/close.png);");


	checkout = new QPushButton("CHECKOUT", this);
	checkout->setStyleSheet("background-color: green;"
                            "qproperty-icon: url(../lib/window/src/check.png);");

	connect(checkout, &QPushButton::clicked, this, &CartScreen::checkout_pressed);
	
	connect(cancel, &QPushButton::clicked, this, &CartScreen::cancel_pressed);

	hLayout_buttons = new QHBoxLayout;
	hLayout_buttons->addWidget(cancel);
	hLayout_buttons->addWidget(checkout);

	vLayout_cart = new QVBoxLayout;
	vLayout_cart->addWidget(item_list);
	vLayout_cart->addWidget(label_Price);


	hLayout_display = new QHBoxLayout;
	hLayout_display->addWidget(image);
	hLayout_display->addLayout(vLayout_cart);



	vLayout = new QVBoxLayout;
	vLayout->addWidget(label_ScanMessage);
	vLayout->addLayout(hLayout_display);
	vLayout->addLayout(hLayout_buttons);
	

	this->setLayout(vLayout);
	

}

	CartScreen::~CartScreen()
	{
	
	}
	
	

	void CartScreen::item_identified(Stock itemData)
	
	{
		// customize here to edit the list of items
		
		//item_list->addItem(QString::fromStdString(itemData.itemName));
		item_list->addItem(itemData.itemName);

	}
	

	void CartScreen::cancel_pressed() // define all the actions here to be taken to verify if all conditions are meeting before cancel can be pressed, and then execute the callback function
	{
		
		cancelPressed->cancelpressed();

	}
	
	void CartScreen::checkout_pressed() // define all the actions here to be taken to verify if all conditions are meeting before checkout can be pressed, and then execute the callback function

	{
		
		checkoutPressed->checkoutpressed();
		

	}


	
	void CartScreen::post_frames(const cv::Mat &mat)

	{
		

		const QImage frame(mat.data , mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		image->setPixmap(QPixmap::fromImage(frame));
		image->setAlignment(Qt::AlignCenter);

	}
	
	
	void CartScreen::start()
{
	cartcameracallback.CScreen = this;
	
	mydatabasecallback.cartscreenptr = this;
	

	//camera.start();

}

void CartScreen::stop()
{

	cartcameracallback.CScreen = nullptr;

	mydatabasecallback.cartscreenptr = nullptr;
	
	//camera.stop();

}





#include "CartScreen.h"
#include "window.h"
#include <iostream>
#include <QKeyEvent>

/**
* Constructor for the Cart Screen. It sets the Qt layout, and the various callback functions for different events such as button pressed, and item identified

*/

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
	label_Price->setText("£0.00");



	item_list = new QListWidget;
	item_list->setFixedSize(400,400);
	
	
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
	
	QString listHeader = "ITEM\t\tPRICE\n";
	
	item_list->addItem(listHeader);
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
	
	
	
	
	void CartScreen::customer_identified(Customer customerdata) {
	
		customer = customerdata;
		std::cout<<customer.uniqueId.toStdString();
	}
	
	
	
	void CartScreen::item_identified(Stock itemData)
	
	{
		std::cout<<"Item adding to the list ";
		
		QString productInfo = itemData.itemName + "\t\t£" + itemData.price + "\n";
		
		item_list->addItem(productInfo);
		customerCart.itemList.push_back(itemData);
		
    		total += itemData.price.toDouble();
    		customerCart.totalCost += itemData.price.toDouble();
    		std::cout<<"customer id "<<(customer.uniqueId).toStdString()<<std::endl;
    		customerCart.customerId = (customer.uniqueId).toStdString();
    		
    		QString totalDisplayed = "Total = £ " + QString::number(total);
    		
    		label_Price->setText(totalDisplayed);
    		
		std::cout<<"Item name is "<<itemData.itemName.toStdString()<<"\n ";

	}
	

	void CartScreen::cancel_pressed() 
	{
		
		cancelPressed->cancelpressed();

	}
	
	void CartScreen::checkout_pressed() 

	{
		customerCart.totalCost = total;
		for(Stock s : customerCart.itemList)
		{
		std::cout<<s.id.toStdString()<<std::endl;
		}
		Cdatabase.checkoutCustomer(customerCart);
		checkoutPressed->checkoutpressed();
		

	}

	void CartScreen::keyPressEvent(QKeyEvent *event){
		if (event->key() == Qt::Key_Escape){
		cancel_pressed();
		}
		
		 if(event->key() == Qt::Key_Enter){
		checkout_pressed();
		}
	}

/**
* Recieves the camera live feed frames

*/
	
	void CartScreen::post_frames(const cv::Mat &mat)

	{
		

		const QImage frame(mat.data , mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		image->setPixmap(QPixmap::fromImage(frame));
		image->setAlignment(Qt::AlignCenter);

	}
	
	
	/**
* Start receiving data from camera and database

*/
	
	void CartScreen::start()
{
	cartcameracallback.CScreen = this;
	
	mydatabasecallback.cartscreenptr = this;
	

	//camera.start();

}

/**
* Stop receiving data from camera and database

*/

void CartScreen::stop()
{

	cartcameracallback.CScreen = nullptr;

	mydatabasecallback.cartscreenptr = nullptr;
	
	//camera.stop();

}

/**
* Clears all the temporary data so that new customer can use the program

*/


void CartScreen::cleardata()
{
	item_list->clear();
	label_Price->setText("£0.00");
	total = 0;
	customerCart.itemList.clear();
	customerCart.totalCost = 0;
	

}

#include "PaymentScreen.h"
#include "window.h"
#include <iostream>


PaymentScreen::PaymentScreen()
{
	
    label_PinMessage = new QLabel;
    label_PinMessage->setText("ENTER YOUR UNIQUE PIN");
    label_PinMessage->setAlignment(Qt::AlignCenter);


    label_TotalPrice = new QLabel;
    label_TotalPrice->setText("£");
    label_TotalPrice->setAlignment(Qt::AlignCenter);


    pinLabel = new QLabel;
    pinLabel->setText("PIN");


    pinEdit = new QLineEdit;
    pinEdit->setMaxLength(4);
    pinEdit->setProperty("mandatoryField", true);


    back = new QPushButton("BACK", this);
    back->setStyleSheet("background-color: red;"
                            "qproperty-icon: url(../lib/window/src/close.png);");
                            
   connect(back, &QPushButton::clicked, this, &PaymentScreen::back_pressed);


    pay = new QPushButton("PAY", this);
    pay->setStyleSheet("background-color: green;"
                            "qproperty-icon: url(../lib/window/src/check.png);");

   connect(pay, &QPushButton::clicked, this, &PaymentScreen::payment_pressed);
 


    // SETTING PAGE LAYOUT
    hLayout_pin = new QHBoxLayout;
    hLayout_pin->addWidget(pinLabel);
    hLayout_pin->addWidget(pinEdit);

    hLayout_buttons = new QHBoxLayout;
    hLayout_buttons->addWidget(back);
    hLayout_buttons->addWidget(pay);

    vLayout = new QVBoxLayout;
    vLayout->addWidget(label_PinMessage);
    vLayout->addWidget(label_TotalPrice);
    vLayout->addLayout(hLayout_pin);
    vLayout->addLayout(hLayout_buttons);
    this->setLayout(vLayout);
	
}	


void PaymentScreen::payment_pressed()

{

	std::cout<<" Payment pressed ";
	
	paymentPressed->paymentpressed();

	/*call database method to check if pin is correct -> if correct then database checks if sufficient balance is available -> if available then deduct the total price from balance -> return success if all process is done, otherwise return the respective error message. In case of success call the window callback to proceed to the next screen */

}



void PaymentScreen::back_pressed()
{


	std::cout<<" Back button pressed ";
	
	backPressed->backpressed();
	
	/* clear any temporary variable here, and clear the pinEdit text, then call the window callback to go back to Cartscreen*/

}


void PaymentScreen::cleardata()
{




}


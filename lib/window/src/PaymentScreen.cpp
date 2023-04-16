#include "PaymentScreen.h"
#include "window.h"
#include <iostream>


PaymentScreen::PaymentScreen()
{
	
    label_PinMessage = new QLabel;
    label_PinMessage->setText("ENTER YOUR UNIQUE PIN");


    pinLabel = new QLabel;
    pinLabel->setText("PIN");


    pinEdit = new QLineEdit;
    pinEdit->setMaxLength(4);
    pinEdit->setProperty("mandatoryField", true);


    back = new QPushButton("BACK", this);
    back->setStyleSheet("background-color: red;"
                            "qproperty-icon: url(../lib/window/src/close.png);");


    pay = new QPushButton("PAY", this);
    pay->setStyleSheet("background-color: green;"
                            "qproperty-icon: url(../lib/window/src/check.png);");


    // SETTING PAGE LAYOUT
    hLayout_pin = new QHBoxLayout;
    hLayout_pin->addWidget(pinLabel);
    hLayout_pin->addWidget(pinEdit);

    hLayout_buttons = new QHBoxLayout;
    hLayout_buttons->addWidget(back);
    hLayout_buttons->addWidget(pay);

    vLayout = new QVBoxLayout;
    vLayout->addWidget(label_PinMessage);
    vLayout->addLayout(hLayout_pin);
    vLayout->addLayout(hLayout_buttons);
    this->setLayout(vLayout);
	
}	


void PaymentScreen::payment_pressed()

{
   /* if (amountInAccount >= totalPriceToBePaid) {
        //move to first page
        
    } */
}

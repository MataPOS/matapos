#include "window.h"
#include "database.h"
#include "customer.h"
#include "product.h"

#include <QString>
#include <QPixmap>
#include <QVector>

Customer customer;
Product product;
Database database;

// MAINWINDOW CONTAINER
Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("MATAPOS v1.0");

    // SETTING THE FONT FOR THE APPLICATION
    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    QWidget::setFont(font);

    // CREATING THE PAGES
    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    // OPEN CONNECTION
    database.connOpen();

    // RETRIEVE CUSTOMER DATA
    customer.getCustomerInfo("1");

//    product.getProductInfo(1);

    // PAGE 1
    welcomeMessage = new QLabel;
    welcomeMessage->setText("WELCOME, PLEASE SCAN YOUR QR CODE");
    welcomeMessage->setAlignment(Qt::AlignCenter);
    welcomeMessage->show();
    cameraArea = new QScrollArea;
    // cameraArea->setWidget(); add camera for livefeed later
    cameraArea->show();


    // ADDING LOGO TO PAGE 1
    logo = new QLabel;
    logo->setText("");
    QPixmap pix(":/db/Brand initial Simple Logo.png");
    int w = logo->width();
    int h = logo->height();
    logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    logo->setAlignment(Qt::AlignCenter);


    // SETTING PAGE 1 LAYOUT
    vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(welcomeMessage);
    vLayout2->addWidget(cameraArea);
    vLayout2->addWidget(logo);
    page1->setLayout(vLayout2);


    // DUMMY CONTROL TO SWITCH FROM PAGE 1 TO PAGE 2 (TO BE REMOVED)
    QTimer *timer = new QTimer(this);
    timer->singleShot(5000, this, SLOT(goToPage2()));


    // PAGE 2
    scanMessage = new QLabel;
    scanMessage->setText("SCAN YOUR ITEMS");
    totalPriceLabel = new QLabel;
    totalPriceLabel->setText("£ TOATL PRICE");
    shoppingCart = new QListWidget;
    cancel = new QPushButton("CANCEL", this);
    checkout = new QPushButton("CHECKOUT", this);




    // SETTING PAGE 2 LAYOUT
    hLayout = new QHBoxLayout;
    hLayout->addWidget(cancel);
    hLayout->addWidget(checkout);
    vLayout3 = new QVBoxLayout;
    vLayout3->addWidget(scanMessage);
    vLayout3->addWidget(shoppingCart);
    vLayout3->addWidget(totalPriceLabel);
    vLayout3->addLayout(hLayout);
    page2->setLayout(vLayout3);


    // BUTTONS CONTROL FOR PAGE 2
    connect(cancel, SIGNAL(clicked()), this, SLOT(goToPage1()));
    connect(checkout, SIGNAL(clicked()), this, SLOT(goToPage3()));


    // PAGE 3
    pinMessage = new QLabel;
    pinMessage->setText("ENTER YOUR UNIQUE PIN");
    pinLabel = new QLabel;
    pinLabel->setText("PIN");
    lineEditPin = new QLineEdit;
    back = new QPushButton("BACK", this);
    confirm = new QPushButton("CONFIRM", this);


    // SETTING PAGE 3 LAYOUT
    hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(pinLabel);
    hLayout2->addWidget(lineEditPin);
    hLayout3 = new QHBoxLayout;
    hLayout3->addWidget(back);
    hLayout3->addWidget(confirm);
    vLayout4 = new QVBoxLayout;
    vLayout4->addWidget(pinMessage);
    vLayout4->addLayout(hLayout2);
    vLayout4->addLayout(hLayout3);
    page3->setLayout(vLayout4);


    // BUTTONS CONTROL FOR PAGE 3
    connect(back,  &QPushButton::clicked, this, &Window::goToPage2);
    connect(confirm, &QPushButton::clicked, this, &Window::paymentVerification);


    // STACKING THE PAGES
    stackedPages = new QStackedWidget;
    stackedPages->addWidget(page1);
    stackedPages->addWidget(page2);
    stackedPages->addWidget(page3);


    // SETTING STACKED PAGES LAYOUT
    vLayout = new QVBoxLayout;
    vLayout->addWidget(stackedPages);
    setLayout(vLayout);


}


// SIGNALS TO NAVIGATE BETWEEN PAGES
void Window::goToPage1() {
    stackedPages->setCurrentIndex(0);
}

void Window::goToPage2() {
    scanItem(); // REMOVE LATER
    stackedPages->setCurrentIndex(1);
}

void Window::goToPage3() {
    stackedPages->setCurrentIndex(2);
}

// DUMMY FUNCTION FOR SCANNING ITEM AND INCREASING TOTAL PRICE
void Window::scanItem() {
    QVector<QString> products;
    double totalPrice = 0.00;
    for (int i = 0; i < 6; i++){
        product.getProductInfo(i);
        products.push_back(product.productInfo);
        shoppingCart->addItem(product.productInfo);
        totalPrice = totalPrice + product.productPrice.toDouble();
        QString total = "Total = £ " + QString::number(totalPrice);
        totalPriceLabel->setText(total);
    }
    paymentVerification(totalPrice);
}

// DUMMY FOR PAYMENT VERIFICATION
void Window::paymentVerification(double totalPrice) {
    double total = totalPrice;
    QString pin = lineEditPin->text();
    if(customer.customerAccountBalance.toDouble() >= total && pin == customer.customerPin) {
        stackedPages->setCurrentIndex(0);
        qDebug()<<(total);
    }
    else {
        qDebug()<<("Wrong Pin");
    }
}

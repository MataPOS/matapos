#include "guiheaderfiles/window.h"
#include <QString>

#include <QPixmap>

// MAINWINDOW CONTAINER
Window::Window()
{
    setWindowTitle("name_of_the_application");

    // SETTING THE FONT FOR THE APPLICATION
    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    QWidget::setFont(font);

    // CREATE THE PAGES
    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    // PAGE 1
    label = new QLabel;
    label->setText("WELCOME, PLEASE SCAN YOUR QR CODE");
    label->setAlignment(Qt::AlignCenter);
    label->show();
    scrollArea = new QScrollArea;
    // scrollArea->setWidget(); // TO FIT THE CAMERA ACTION IN
    scrollArea->show();

    // ADD LOGO TO PAGE 1
    logoLabel = new QLabel;
    logoLabel->setText("");
    QPixmap pix(":/db/Brand initial Simple Logo.png");
    int w = logoLabel->width();
    int h = logoLabel->height();
    logoLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    logoLabel->setAlignment(Qt::AlignCenter);

    // PAGE 1 LAYOUT
    vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(label);
    vLayout2->addWidget(scrollArea);
    vLayout2->addWidget(logoLabel);
    page1->setLayout(vLayout2);

    // DUMMY CONTROL TO SWITCH FROM PAGE 1 TO PAGE 2
    getCustomerInfo();
    QTimer *timer = new QTimer(this);
    timer->singleShot(5000, this, SLOT(goToPage2()));

    // DATABASE CONNECTION
    if(!connOpen()) {
        QMessageBox::information(this,"Not connected", "Database not connected");
    }
    else {
        QMessageBox::information(this, "Connected", "Database is connected Successfully");
    }

    // PAGE 2
    label2 = new QLabel;
    label2->setText("SCAN YOUR ITEMS");
    label3 = new QLabel;
    label3->setText("£ TOATL PRICE");
    listWidget = new QListWidget;
    cancel = new QPushButton("CANCEL", this);
    checkout = new QPushButton("CHECKOUT", this);

    // PAGE 2 LAYOUT
    hLayout = new QHBoxLayout;
    hLayout->addWidget(cancel);
    hLayout->addWidget(checkout);
    vLayout3 = new QVBoxLayout;
    vLayout3->addWidget(label2);
    vLayout3->addWidget(listWidget);
    vLayout3->addWidget(label3);
    vLayout3->addLayout(hLayout);
    page2->setLayout(vLayout3);

    // PUSHBUTTONS CONTROL FOR PAGE 2
    getProductInfo();
    connect(cancel, SIGNAL(clicked()), this, SLOT(goToPage1()));
    connect(checkout, SIGNAL(clicked()), this, SLOT(goToPage3())); // include code to accommodate condition for being clickable


    // PAGE 3
    label4 = new QLabel;
    label4->setText("ENTER YOUR UNIQUE PIN");
    label5 = new QLabel;
    label5->setText("PIN");
    lineEditPin = new QLineEdit;
    back = new QPushButton;
    back->setText("BACK");
    confirm = new QPushButton;
    confirm->setText("CONFIRM");

    // PAGE 3 LAYOUT
    hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(label5);
    hLayout2->addWidget(lineEditPin);
    hLayout3 = new QHBoxLayout;
    hLayout3->addWidget(back);
    hLayout3->addWidget(confirm);
    vLayout4 = new QVBoxLayout;
    vLayout4->addWidget(label4);
    vLayout4->addLayout(hLayout2);
    vLayout4->addLayout(hLayout3);
    page3->setLayout(vLayout4);

    // PUSHBUTTONS CONTROL FOR PAGE 3
    connect(back,  &QPushButton::clicked, this, &Window::goToPage2);
    connect(confirm, &QPushButton::clicked, this, &Window::goToPage1);

    // STACK THE PAGES
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(page1);
    stackedWidget->addWidget(page2);
    stackedWidget->addWidget(page3);

    // LAYOUT THE STACKS
    vLayout = new QVBoxLayout;
    vLayout->addWidget(stackedWidget);
    setLayout(vLayout);
}

// SIGNALS TO NAVIGATE BETWEEN PAGES
void Window::goToPage1()
{
    stackedWidget->setCurrentIndex(0);
}

void Window::goToPage2()
{
    stackedWidget->setCurrentIndex(1);
}

void Window::goToPage3()
{
    stackedWidget->setCurrentIndex(2);
}

// GET CUSTOMER DATA FROM DATABASE
void Window::getCustomerInfo()
{
    connOpen();
    QString customerId = "1", customerAccountBalance, customerAccountPin, customerEmail;
    QSqlQuery qry;
    qry.prepare("select * from customers where customerId= '"+ customerId+"'");

    if(qry.exec()){
        while(qry.next()){
            customerAccountBalance = qry.value(4).toInt();
            customerAccountPin = qry.value(5).toString();
            customerEmail = qry.value(6).toString();
        }
        connClose();
    }

}

// TO GET PRODUCT DETAILS AFTER SCAN
void Window::getProductInfo()
{
    QString productId = "1";
    QString productName, productPrice;
    QSqlQuery qry;
    qry.prepare("select * from products where id= '"+ productId+"'");

    if (qry.exec()){
        while(qry.next()){
            productId = qry.value(0).toString();
            productName = qry.value(1).toString();
            productPrice = qry.value(2).toString();
        }
        QString product = productId + "\t\t" + productName + "\t\t" + productPrice;
        listWidget->addItem(product);
    }
}

// CONFIRM PAYMENT
void Window::transactionVerification()
{

}

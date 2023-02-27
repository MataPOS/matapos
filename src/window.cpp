#include "window.h"
#include <QString>
#include <vector>
#include <QMessageBox>

// MAINWINDOW CONTAINER
Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("name_of_the_application");

    // CREATE THE PAGES
    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    // PAGE 1
    label = new QLabel;
    label->setText("WELCOME, PLEASE SCAN YOUR QR CODE");
    label->show();
    scrollArea = new QScrollArea;
    //scrollArea->setWidget();
    scrollArea->show();

    // PAGE 1 LAYOUT
    vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(label);
    vLayout2->addWidget(scrollArea);
    page1->setLayout(vLayout2);

    // DUMMY CONTROL TO SWITCH FROM PAGE 1 TO PAGE 2
    QTimer *timer = new QTimer(this);
    timer->singleShot(5000, this, SLOT(goToPage2()));

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
    connect(cancel, SIGNAL(clicked()), this, SLOT(goToPage1()));
    connect(checkout, SIGNAL(clicked()), this, SLOT(goToPage3())); // include code to accommodate condition for being clickable


    // PAGE 3
    label4 = new QLabel;
    label4->setText("ENTER YOUR UNIQUE PIN");
    label5 = new QLabel;
    label5->setText("PIN");
    lineEdit = new QLineEdit;
    back = new QPushButton;
    back->setText("BACK");
    confirm = new QPushButton;
    confirm->setText("CONFIRM");

    // PAGE 3 LAYOUT
    hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(label5);
    hLayout2->addWidget(lineEdit);
    hLayout3 = new QHBoxLayout;
    hLayout3->addWidget(back);
    hLayout3->addWidget(confirm);
    vLayout4 = new QVBoxLayout;
    vLayout4->addWidget(label4);
    vLayout4->addLayout(hLayout2);
    vLayout4->addLayout(hLayout3);
    page3->setLayout(vLayout4);

    // PUSHBUTTONS CONTROL FOR PAGE 3
    connect(back, SIGNAL(clicked()), this, SLOT(goToPage2()));
    connect(confirm, SIGNAL(clicked()), this, SLOT(goToPage1()));

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

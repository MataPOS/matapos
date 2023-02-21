#include "customerdialog.h"
#include "ui_customerdialog.h"
#include <vector>
#include <string>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>

using namespace std;

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    /*Timer to exit thank you page and return to Welcome page
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(backToWelcomePage()));
    timer->start(20000);*/
}

//CREATING GLOBAL VARIABLES FOR STOCKS
struct stock
{
    string productSerialNumber;
    string productName;
    double productPrice;
    double productWeight;
};

//DECLARE VARIOUS VECTORS
vector<stock> v;
//vector<stock> vv;
double totalPrice = 0.00; //for total price
vector<stock> itemsArray;


/*creating the inventory using array
string productSerialNumber[5] = {"S4PYX", "9BJ2D","4QDI0", "7FGLO", "CBHM3"};
string productName[5] = {"Soda", "Biscuit", "Notepad", "Water", "Fruit"};
double productPrice[5] = {2.00, 1.70, 3.00, 1.00, 3.79};
double productWeight[5] = {4.30, 2.40, 4.54, 3.11, 6.34};*/


CustomerDialog::~CustomerDialog()
{
    delete ui;
}

//NAVIGATION THROUGH DIFFERENT PAGES
void CustomerDialog::on_pushButtonCamera_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    itemsArray.clear();
    v.clear();
    totalPrice = 0;
    ui->listWidgetCart->clear();
    ui->lineEditCardNumber->clear();
    ui->lineEditEmail->clear();
    ui->lineEditPin->clear();
    ui->lineEditSerialNumber->clear();
    ui->labelTotal->clear();
}


void CustomerDialog::on_pushButtonCheckout_clicked()
{
    //CONDITION TO ACCESS CHECKOUT SCREEN
    if (itemsArray.size() > 0)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    /*else
    {
        QMessageBox::warning(this, "Error", "Scan an item");
    }*/
    //ui->stackedWidget->setCurrentIndex(2);
}


void CustomerDialog::on_pushButtonCancelShopping_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//FOR RECEIPT INFORMATION
struct receiptInfo
{
    int receiptNumber = 0;
    QString customerEmail, cardNumber;
};

void CustomerDialog::on_pushButtonConfirmPayment_clicked()
{
    QString cardNumberAccessed = ui->lineEditCardNumber->text();
    QString pinAccessed = ui->lineEditPin->text();
    if (cardNumberAccessed == "9490119801" && pinAccessed == "0787")
    {
        //CREATING RECEIPT FILE
        /*ofstream outputFile;*/
        receiptInfo ri;
        ri.receiptNumber += 1; //can also use a random number generator
        ri.customerEmail = ui->lineEditEmail->text();
        ri.cardNumber = ui->lineEditCardNumber->text();
        //QString productSerialNumber, productPrice, productName;


        QFile salesFile("/Users/tobiabass11/FirstGUI/SalesRecord.txt");

        if (salesFile.open(QIODevice::WriteOnly | QFile::Text))
        {
            QTextStream out(&salesFile);
            out << "Receipt Number: " << ri.receiptNumber << Qt::endl;
            out << "Customer Email: " << ri.customerEmail << Qt::endl;
            out << "Card Information: " << ri.cardNumber << Qt::endl;
            out << "____________________________________________________" << Qt::endl;
            out << "SN" << "\t\t" << "Items Description" << "\t\t" << "Price" << Qt::endl;

            string str;

            //QString productSerialNumber, productPrice, productName;
            for (unsigned long i = 0; i < itemsArray.size(); i++)
            {
                /*productSerialNumber = QString::fromStdString(vv[i].productSerialNumber);
                productName = QString::fromStdString(vv[i].productName);
                productPrice = QString::number(vv[i].productPrice);
                out << productSerialNumber << "\t\t" << productName << "\t\t" << productPrice << Qt::endl;*/
                /*out << v[i].productSerialNumber << "\t\t" << v[i].productName << "\t\t" << (v[i].productPrice) << Qt::endl;
                QString str;
                str = v[i].productSerialNumber << "\t\t" << v[i].productName << "\t\t" << to_string(v[i].productPrice);
                out << str << Qt::endl;*/
                str = itemsArray[i].productSerialNumber + "\t\t" + itemsArray[i].productName + "\t\t" + "\t\t" + to_string(itemsArray[i].productPrice) + "\n";
                out << QString::fromStdString(str.c_str()) <<Qt::endl;
            }
            //out << productSerialNumber << "\t\t" << productName << "\t\t" << productPrice << Qt::endl;
            out << "Total Paid: \t\t £" << totalPrice << Qt::endl;
            out << "Thank you for shopping with us" << Qt::endl;
            salesFile.flush(); //clear file
            salesFile.close(); //close file
        }
        else
        {
             QMessageBox::warning(this, "Error", "Unable to print receipt");
        }


        /*outputFile.open("SalesRecord.txt", ios::app);

        if (outputFile)
        {
           outputFile << "Receipt Number: " << ri.receiptNumber << endl;
           outputFile << "Customer Email: " << ri.customerEmail.toStdString() << endl;
           outputFile << "Card Information: " << ri.cardNumber.toStdString() << endl;
           outputFile << "____________________________________________________" << endl;
           outputFile << "SN" << "\t\t" << "Items" << "\t\t" << "Price" <<endl;
           for (int i = 0; i < v.size(); i++)
           {
               outputFile << v[i].productSerialNumber << "\t\t" << v[i].productName << "\t\t" << (v[i].productPrice) << endl;
           }
           outputFile << "Total Paid: \t\t" << "£" << totalPrice  << endl;
        }*/


        ui->stackedWidget->setCurrentIndex(3);
        //TIMER TO EXIT THANK YOU PAGE AND RETURN TO WELCOME PAGE
        timer = new QTimer(this);
        //timer->setInterval(5000);
        timer->singleShot(5000, this, SLOT(backToWelcomePage()));
        //connect(timer, SIGNAL(timeout()), this, SLOT(backToWelcomePage()));
        //timer->start(5000);
        //timer->stop();

    }
}


void CustomerDialog::on_pushButtonBackToCart_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void CustomerDialog::backToWelcomePage()
{
    ui->stackedWidget->setCurrentIndex(0);
}


//DEMO OF THE SCANNING OPERATION
void CustomerDialog::on_pushButtonScan_clicked()
{
    QString serialNumberAccessed = ui->lineEditSerialNumber->text();

    //CONDITIONS FOR PUSHING BACK PRODUCT INFORMATION FROM DATABASE
    if (serialNumberAccessed == "S4PYX") {
        stock sk;
        sk.productSerialNumber = "S4PYX";
        sk.productName ="Soda";
        sk.productPrice = 2.00;
        sk.productWeight = 4.30;

        v.push_back(sk);
        itemsArray.push_back(sk);
    }
    else if (serialNumberAccessed == "9BJ2D") {
        stock sk;
        sk.productSerialNumber = "9BJ2D";
        sk.productName ="Biscuit";
        sk.productPrice = 1.70;
        sk.productWeight = 4.54;

        v.push_back(sk);
        itemsArray.push_back(sk);
    }
    else if (serialNumberAccessed == "4QDI0") {
        stock sk;
        sk.productSerialNumber = "4QDI0";
        sk.productName ="Notepad";
        sk.productPrice = 3.00;
        sk.productWeight = 4.54;

        v.push_back(sk);
        itemsArray.push_back(sk);
    }
    else if (serialNumberAccessed == "7FGLO") {
        stock sk;
        sk.productSerialNumber = "7FGLO";
        sk.productName ="Water";
        sk.productPrice = 1.00;
        sk.productWeight = 3.11;

        v.push_back(sk);
        itemsArray.push_back(sk);
    }
    else if (serialNumberAccessed == "CBHM3") {
        stock sk;
        sk.productSerialNumber = "CBHM3";
        sk.productName ="Fruit";
        sk.productPrice = 3.79;
        sk.productWeight = 6.34;

        v.push_back(sk);
        itemsArray.push_back(sk);
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid item, wait for assistance");
    }

    //ADDING ITEMS TO CART AND CALCULATING TOTAL PRICE
    string str;
    str = v[0].productSerialNumber + "\t\t" + v[0].productName + "\t\t" + to_string(v[0].productPrice); //converting the vector value to string and double to string
    //itemsArray.push_back(str);
    ui->listWidgetCart->addItem(str.c_str());
    totalPrice += v[0].productPrice;
    str = "£" + to_string(totalPrice);
    ui->labelTotal->setText(str.c_str());
    v.clear();
}


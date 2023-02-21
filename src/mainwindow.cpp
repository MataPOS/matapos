#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //to add logo image to login window
    QPixmap pix(":/resources/img/Team Logo copy.png");
    /*int w = ui->label_logo->width(); //to get width of label to resize image
    int h = ui->label_logo->height(); //to get height of label to resize image*/
    ui->label_logo->setPixmap(pix.scaled(500,600,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}

//LOGGING IN CONDITIONS
void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username == "matapos" && password == "matapos") {
        QMessageBox::information(this, "Login", "Successful");
        hide(); //to close the first window
        customerDialog = new CustomerDialog(this);
        customerDialog->show(); //To show the second window for customer use
    }
    else {
        QMessageBox::warning(this, "Login", "Failed, try again");
    }
}


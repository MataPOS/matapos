#include "adminaccesswindow.h"
#include "ui_adminaccesswindow.h"
#include <QMessageBox>

AdminAccessWindow::AdminAccessWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAccessWindow)
{
    ui->setupUi(this);
}

AdminAccessWindow::~AdminAccessWindow()
{
    delete ui;
}

//To use Login button and verify admin name and password
void AdminAccessWindow::on_pushButtonLogin_clicked()
{
    QString adminName; ui->lineEditAdminName->text();
    QString password; ui->lineEditPassword->text();

    if (adminName == "matapos" && password == "matapos") {
        QMessageBox::information(this, "Administrator Login", "Login Successful");
    }
    else {
        QMessageBox::warning(this, "Administrator Login", "Login Failed, Try Again!!!");
    }
}


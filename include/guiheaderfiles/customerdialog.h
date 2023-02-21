#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>
#include <QTimer>
#include <string>
#include <vector>
using namespace std;

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = nullptr);
    ~CustomerDialog();

private slots:
    void on_pushButtonCamera_clicked();

    void on_pushButtonCheckout_clicked();

    void on_pushButtonCancelShopping_clicked();

    void on_pushButtonConfirmPayment_clicked();

    void on_pushButtonBackToCart_clicked();

    void backToWelcomePage();

    //void on_pushButtonScanner_clicked();

    void on_pushButtonScan_clicked();

private:
    Ui::CustomerDialog *ui;
    QTimer *timer;
};

#endif // CUSTOMERDIALOG_H

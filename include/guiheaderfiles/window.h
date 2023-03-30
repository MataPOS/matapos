#ifndef WINDOW_H
#define WINDOW_H




#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QMainWindow>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QListWidget>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QtSql>

class Window : public QWidget
{
    Q_OBJECT

// FUNCTIONS TO OPEN AND CLOSE DATABASE CONNECTION
public:
    QSqlDatabase myDb;

    void connClose(){
        myDb.close();
        myDb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        // DATABASE CONNECTION
        myDb = QSqlDatabase::addDatabase("QSQLITE");
        myDb.setDatabaseName("/Users/tobiabass11/gui pushed/database.db");

        if(!myDb.open()) {
            qDebug()<<("Database failed to open");
            return false;
        }
        else {
            qDebug()<<("Database opened successfully");
            return true;
        }
    }

public:
    Window();

private:
    QMainWindow *mainWindow;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;
    QStackedWidget *stackedWidget;
    QVBoxLayout *vLayout;
    QVBoxLayout *vLayout2;
    QVBoxLayout *vLayout3;
    QVBoxLayout *vLayout4;
    QHBoxLayout *hLayout;
    QHBoxLayout *hLayout2;
    QHBoxLayout *hLayout3;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *logoLabel;
    QScrollArea *scrollArea;
    QListWidget *listWidget;
    QPushButton *cancel;
    QPushButton *checkout;
    QPushButton *back;
    QPushButton *confirm;
    QTimer *timer;
    QLineEdit *lineEditPin;
    QFont *font;



signals:
private slots:
    void goToPage1();
    void goToPage2();
    void goToPage3();
    void getCustomerInfo();
    void getProductInfo();
    void transactionVerification();
};

#endif // WINDOW_H

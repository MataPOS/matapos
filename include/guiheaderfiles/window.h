#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QListWidget>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

private:
    QMainWindow *mainWindow;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;
    QStackedWidget *stackedPages;
    QVBoxLayout *vLayout;
    QVBoxLayout *vLayout2;
    QVBoxLayout *vLayout3;
    QVBoxLayout *vLayout4;
    QHBoxLayout *hLayout;
    QHBoxLayout *hLayout2;
    QHBoxLayout *hLayout3;
    QLabel *welcomeMessage;
    QLabel *scanMessage;
    QLabel *totalPriceLabel;
    QLabel *pinMessage;
    QLabel *pinLabel;
    QLabel *logo;
    QScrollArea *cameraArea;
    QListWidget *shoppingCart;
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
    void paymentVerification();
    void scanItem();
};

#endif // WINDOW_H

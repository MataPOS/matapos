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
    QScrollArea *scrollArea;
    QListWidget *listWidget;
    QPushButton *cancel;
    QPushButton *checkout;
    QPushButton *back;
    QPushButton *confirm;
    QTimer *timer;
    QLineEdit *lineEdit;



signals:
private slots:
    void goToPage1();
    void goToPage2();
    void goToPage3();
};

#endif // WINDOW_H

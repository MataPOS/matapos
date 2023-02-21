#ifndef ADMINACCESSWINDOW_H
#define ADMINACCESSWINDOW_H

#include <QDialog>

namespace Ui {
class AdminAccessWindow;
}

class AdminAccessWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAccessWindow(QWidget *parent = nullptr);
    ~AdminAccessWindow();

private slots:
    void on_pushButtonLogin_clicked();

private:
    Ui::AdminAccessWindow *ui;
};

#endif // ADMINACCESSWINDOW_H

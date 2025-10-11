#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(MainWindow *mw,QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_btn_Back_clicked();

private:
    Ui::Register *ui;
    MainWindow *main_window;
};

#endif // REGISTER_H

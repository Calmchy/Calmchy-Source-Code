#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _register = new Register(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Register_clicked()
{
    this->hide();
    _register->show();
}


void MainWindow::on_btn_Exit_clicked()
{
    this->close();
}


#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"

Register::Register(MainWindow *mw,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Register),   // ui comes from ui_register.h
    main_window(mw) {
    ui->setupUi(this); // this loads widgets from your .ui file
}

Register::~Register()
{
    delete ui;
}

void Register::on_btn_Back_clicked()
{
    this->hide();
    main_window->show();
}


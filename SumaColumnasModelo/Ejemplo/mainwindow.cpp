#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingresoa.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionIngreso_triggered()
{
   IngresoA *ingresom = new IngresoA();
   ingresom->show();
}

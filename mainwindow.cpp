#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->comboBox->addItem(QIcon(":/rec/img/new.png"), "Mark");
//    ui->comboBox->addItem(QIcon(":/rec/img/open.png"), "John");
//    ui->comboBox->addItem(QIcon(":/rec/img/exit.png"), "July");

    for (int i = 0; i < 10; i++) {
        ui->comboBox->addItem(QIcon(":/rec/img/exit.png"), QString::number(i) + "name");
    }

    ui->comboBox->insertItem(3, QIcon(":/rec/img/exit.png"), "new text");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "title", QString::number(ui->comboBox->currentIndex()));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    } else {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

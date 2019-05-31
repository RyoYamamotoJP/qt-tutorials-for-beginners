#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/Users/ryo/Downloads/qt.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->statusBar->addPermanentWidget(ui->label_3);
    ui->statusBar->addPermanentWidget(ui->progressBar);
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
//        QMessageBox::information(this, "Login", "Username and password is correct");
//        hide();
//        secDialog = new SecDialog(this);
//        secDialog->show();
        ui->statusBar->showMessage("Username and password is correct", 5000);
        ui->label_3->setText("Username and password is correct");
    } else {
//        QMessageBox::warning(this, "Login", "Username and password is not correct");
        ui->statusBar->showMessage("Username and password is not correct", 5000);
        ui->label_3->setText("Username and password is not correct");
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;
    foreach (QFileInfo var, dir.drives()) {
        ui->comboBox->addItem(var.absoluteFilePath());
    }

    QDir dir2("/Users/ryo/work/QDirDemo");
    foreach (QFileInfo var, dir2.entryInfoList()) {
        if (var.isDir())
            ui->listWidget->addItem("Dir: " + var.absoluteFilePath());
        if (var.isFile())
            ui->listWidget->addItem("File: " + var.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("/Users/ryo/work/QDirDemo/YYY");
    if (dir.exists()) {
        QMessageBox::information(this, "", "dir exists");
    } else {
        dir.mkpath("/Users/ryo/work/QDirDemo/YYY");
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::myfunction);
    timer->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    qDebug() << "update..";
}

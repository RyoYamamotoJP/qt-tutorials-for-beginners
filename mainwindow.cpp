#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::myfunction);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if ((time.second() % 2) == 0) {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->label_date_time->setText(time_text);
}

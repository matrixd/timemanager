#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *TimeTableObj = new QWidget(this);
    TimeTableObj->setGeometry(0,0,100,300);
    TimeTableObj->setStyleSheet("background-color: rgb(81, 255, 0);");

    QListWidgetItem* item;
     item = new QListWidgetItem();
     ui->taskList->addItem(item);
     TimeTableObj->show();
     item->setSizeHint(TimeTableObj->size());
     ui->taskList->setItemWidget(item, TimeTableObj);
     qDebug() << "start";
}

MainWindow::~MainWindow()
{
    delete ui;
}

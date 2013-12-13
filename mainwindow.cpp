#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem* item;
     item = new QListWidgetItem();
     ui->taskList->addItem(item);
     item->setBackgroundColor(QColor(215,139,143));
     item->setSizeHint(QSize(100,100));
     item->setData(1,QTime(5,0));
     item = new QListWidgetItem();
     ui->taskList->addItem(item);
     item->setBackgroundColor(QColor(0,255,0));
     item->setSizeHint(QSize(100,100));
     item->setData(1, QTime(4,0));
     qDebug() << "start";
}

MainWindow::~MainWindow()
{
    delete ui;
}

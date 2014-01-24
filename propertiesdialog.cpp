#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

PropertiesDialog::PropertiesDialog(QTime duration, QString descr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesDialog)
{
    ui->setupUi(this);
    ui->textEdit->setText(descr);
    ui->timeEdit->setTime(duration);
}

PropertiesDialog::~PropertiesDialog()
{
    delete ui;
}

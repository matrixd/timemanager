#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class PropertiesDialog;
}

class PropertiesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PropertiesDialog(QTime duration=QTime(0,0), QString descr=QString(""), QWidget *parent = 0);
    ~PropertiesDialog();
    
private:
    Ui::PropertiesDialog *ui;
};

#endif // PROPERTIESDIALOG_H

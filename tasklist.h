#ifndef TASKLIST_H
#define TASKLIST_H

#include <QListWidget>
#include <QDragEnterEvent>
#include <QTime>
#include <propertiesdialog.h>

class TaskList : public QListWidget
{
    Q_OBJECT
public:
    explicit TaskList(QWidget *parent = 0);
private:
    void dragEnterEvent(QDragEnterEvent*);
    void startDrag(Qt::DropActions);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
signals:
    void listChanged();
    
private slots:
    void editDialog(QListWidgetItem*);
    
};

#endif // TASKLIST_H

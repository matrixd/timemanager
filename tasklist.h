#ifndef TASKLIST_H
#define TASKLIST_H

#include <QListWidget>
#include <QDragEnterEvent>

class TaskList : public QListWidget
{
    Q_OBJECT
public:
    explicit TaskList(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent*);
    void startDrag(Qt::DropActions);
    
signals:
    
public slots:
    
};

#endif // TASKLIST_H

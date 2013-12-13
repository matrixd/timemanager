#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QListWidget>
#include <QDragEnterEvent>
#include <QDebug>
#include <tasklist.h>

class TimeTable : public TaskList
{
    Q_OBJECT
public:
    explicit TimeTable(QWidget *parent = 0);
private:
    void dropEvent(QDropEvent *event);
    void addEmptyItem();

signals:
    
public slots:
    void refresh();
    
};

#endif // TIMETABLE_H

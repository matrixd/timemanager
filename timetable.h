#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QListWidget>
#include <QDragEnterEvent>
#include <QDebug>

class TimeTable : public QListWidget
{
    Q_OBJECT
public:
    explicit TimeTable(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);

signals:
    
public slots:
    
};

#endif // TIMETABLE_H

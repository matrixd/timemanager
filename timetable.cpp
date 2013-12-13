#include "timetable.h"

TimeTable::TimeTable(QWidget *parent) :
    QListWidget(parent)
{
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
}

void TimeTable::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("timetable/item"))
        event->accept();
    else
        event->ignore();
}

void TimeTable::dragLeaveEvent(QDragLeaveEvent *event)
 {
     event->accept();
 }

void TimeTable::dragMoveEvent(QDragMoveEvent *event)
 {
     if (event->mimeData()->hasFormat("timetable/item")) {
         event->setDropAction(Qt::MoveAction);
         event->accept();
     } else {
         event->ignore();
     }
 }

 void TimeTable::dropEvent(QDropEvent *event)
 {
     if (event->mimeData()->hasFormat("timetable/item")) {

         QByteArray itemData = event->mimeData()->data("timetable/item");
         qDebug() << itemData;

         event->setDropAction(Qt::MoveAction);
         event->accept();
     }
 }


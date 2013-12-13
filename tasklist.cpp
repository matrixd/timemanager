#include "tasklist.h"
#include "QDebug"

TaskList::TaskList(QWidget *parent) :
    QListWidget(parent)
{
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
}

void TaskList::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("timetable/item"))
        event->accept();
    else
        event->ignore();
}

void TaskList::dragLeaveEvent(QDragLeaveEvent *event)
 {
     event->accept();
 }

void TaskList::dragMoveEvent(QDragMoveEvent *event)
 {
     if (event->mimeData()->hasFormat("timetable/item")) {
         event->setDropAction(Qt::MoveAction);
         event->accept();
     } else {
         event->ignore();
     }
 }


void TaskList::startDrag(Qt::DropActions /*supportedActions*/)
{
    QListWidgetItem *item = currentItem();

    QMimeData *mimeData = new QMimeData;
    QByteArray ar;
    QDataStream ds(&ar, QIODevice::WriteOnly);
    QString str="test";
    ds  << item->backgroundColor() << str << item->data(1);
    mimeData->setData("timetable/item", ar);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    qDebug() << "starting drag&drop";

    if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
        delete takeItem(row(item));
    emit listChanged();
}

void TaskList::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("timetable/item")) {

        QByteArray tmpd = event->mimeData()->data("timetable/item");
        QDataStream ds(&tmpd, QIODevice::ReadOnly);
        QColor color;
        QString str;
        QVariant duration;
        ds  >> color >> str >> duration;

        QListWidgetItem *item;
        item = new QListWidgetItem();
        item->setSizeHint(QSize(100,100));
        item->setBackgroundColor(color);
        item->setText(str);
        item->setData(1,duration);
        addItem(item);

        event->setDropAction(Qt::MoveAction);
        event->accept();
        emit listChanged();
    }
}

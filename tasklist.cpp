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

void TaskList::startDrag(Qt::DropActions /*supportedActions*/)
{
    QListWidgetItem *item = currentItem();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << 'test';

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("timetable/item", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    qDebug() << "starting drag&drop";
    qDebug() << mimeData->data("timetable/item");
    qDebug() << mimeData->hasFormat("timetable/item");

    if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
        delete takeItem(row(item));
}

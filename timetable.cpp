#include "timetable.h"
#include <QMimeData>
#include <QDrag>
#include <QDropEvent>

TimeTable::TimeTable(QWidget *parent) :
    TaskList(parent)
{
    QObject::connect(this, SIGNAL(listChanged()),
                          this, SLOT(refresh()));
    addEmptyItem();
}

void TimeTable::addEmptyItem(){
    QListWidgetItem* item = new QListWidgetItem();
    item->setText("Drag&drop tasks here");
    item->setSizeHint(QSize(size().width(),size().height()));
    addItem(item);
    setDragEnabled(false);
}

void TimeTable::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("timetable/item")) {
        if(!dragEnabled()){
            clear();
            setDragEnabled(true);
        }

        QByteArray tmpd = event->mimeData()->data("timetable/item");
        QDataStream ds(&tmpd, QIODevice::ReadOnly);
        QColor color;
        QString str;
        QVariant duration;
        ds  >> color >> str >>duration;

        QListWidgetItem *item;
        item = new QListWidgetItem();
        item->setBackgroundColor(color);
        item->setText(str);
        item->setSizeHint(QSize(0,0));
        addItem(item);
        item->setData(1,duration);
        event->setDropAction(Qt::MoveAction);
        event->accept();
        refresh();
    }
}

void TimeTable::refresh(){
    if(count()>1){
        QList<QTime> durs;
        for(int k = 0; k<count();k++){
            durs.append(item(k)->data(1).toTime());
        }
        QTime sumDur;
        foreach(QTime dur, durs)
            sumDur.setHMS(sumDur.hour()+dur.hour(),sumDur.minute()+dur.minute(),0,0);
        qDebug() << sumDur;
        unsigned int sumDuration;
        sumDuration=sumDur.hour()*60+sumDur.minute();
        unsigned int width = size().width();
        qDebug() << width;
        for(int k = 0; k<count();k++){
            QSize newSize;
            newSize.setHeight(size().height());
            newSize.setWidth(width*(durs[k].hour()*60+durs[k].minute())/sumDuration-2);
            //newSize.setWidth(40);
            qDebug() << k <<newSize;
            item(k)->setSizeHint(newSize);
        }
    } else {
        if(count()==1)
            item(0)->setSizeHint(QSize(size().width(),size().height()));
        else
            addEmptyItem();
    }
}

#include "canvas_3.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QDebug>
#include <QFormLayout>

Canvas_3::Canvas_3(QWidget *parent) : QWidget(parent)
{
    canvas = new QPixmap(size());
    canvas->fill(Qt::gray);
}

void Canvas_3::paintEvent(QPaintEvent *pe)
{
    QPainter painter;

    painter.begin(this);
    painter.drawPixmap(rect(), *canvas);
    painter.end();
}

void Canvas_3::mouseMoveEvent(QMouseEvent *myEvent)
{
        qDebug() << "Moved left button " << myEvent->x() << " " << myEvent->y();
        QPainter painter;

        painter.begin(canvas);

        painter.setPen(QPen(Qt::red, 3));
        //painter.drawRect(myEvent->x(), myEvent->y(), 20, 20);
        painter.drawPoint(myEvent->x(), myEvent->y());
        painter.end();

        update();
}

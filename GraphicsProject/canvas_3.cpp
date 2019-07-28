#include "canvas_3.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QDebug>
#include <QFormLayout>

Canvas_3::Canvas_3(QWidget *parent) : QWidget(parent)
{
    canvas = new QImage(500, 500, QImage::Format_ARGB32_Premultiplied);
    canvas->fill(Qt::gray);
    lbl = new QLabel();
    lbl->setPixmap(QPixmap::fromImage(*canvas));

    QFormLayout* layout = new QFormLayout();
    layout->addRow(lbl);
    this->setLayout(layout);
}

/*void Canvas_3::paintEvent(QPaintEvent *pe)
{
    QPainter painter_3;
    painter_3.setPen(QPen(Qt::red));
    painter_3.setRenderHint(QPainter::Antialiasing, true);


    painter_3.end();
}*/

void Canvas_3::mouseMoveEvent(QMouseEvent *myEvent)
{
        qDebug() << "Moved left button " << myEvent->x() << " " << myEvent->y();
        QPainter painter;

        painter.begin(canvas);

        painter.setPen(QPen(Qt::red, 3));
        //painter.drawRect(myEvent->x(), myEvent->y(), 20, 20);
        painter.drawPoint(myEvent->x(), myEvent->y());
        painter.end();
        lbl->setPixmap(QPixmap::fromImage(*canvas));
}

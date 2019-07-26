#include "canvas_2.h"
#include <QPainter>
#include <QPicture>
#include <QDebug>
#include <QVector>

canvas_2::canvas_2(QWidget *parent) : QWidget(parent)
{

}

void canvas_2::paintEvent(QPaintEvent *pe)
{
    QPainter* painter_2 = new QPainter(this);
    painter_2->setPen(QPen(Qt::blue, 5));
    painter_2->setRenderHint(QPainter::Antialiasing, true);

    /*QPicture picture;
    if(!picture.load("newPicture.dat")){
        qDebug() << "cannot load picture.dat file";
    }
    painter_2->drawPicture(QPoint(0, 0), picture);*/
    // QPainterPath example
    QPainterPath path;
    QPointF point_1(width(), height()/2);
    QPointF point_2(width()/2, -height());
    QPointF point_3(width()/2, 2*height());
    QPointF point_4(0, height()/2);
    QRect sampleRect(width()/4, height()/4, width()/2, height()/2);

    QVector<QPointF> points;
    points.push_back(point_1);
    points.push_back(point_2);
    points.push_back(point_3);
    points.push_back(point_4);

    path.moveTo(point_1);
    path.cubicTo(point_2, point_3, point_4);

    path.addRect(sampleRect);
    path.addEllipse(sampleRect);
    path.addPolygon(QPolygonF(points));
    // clipping examples
    painter_2->setClipRect(QRect(50, 50, 100, 100));
    //painter_2->setClipPath(path);
    QRegion region(QRect(50, 50, 500, 300), QRegion::Ellipse);
    QRegion region_2(QRect(300, 100, 500, 500));
    QRegion region_3 = region.subtracted(region_2);
    painter_2->setClipRegion(region_3);

    painter_2->drawPath(path);
    painter_2->end();
}

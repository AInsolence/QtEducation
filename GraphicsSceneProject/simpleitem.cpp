#include "simpleitem.h"

#include <QPainter>
#include <QApplication>

SimpleItem::SimpleItem()
{

}

QRectF SimpleItem::boundingRect() const
{
    QPointF pointerPos(-10 - penWidth, -10 - penWidth);
    QSizeF areaSize(20 + penWidth*2, 20 + penWidth*2);
    return QRectF(pointerPos, areaSize);
}

void SimpleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *wgt)
{
    painter->save();
    painter->setPen(QPen(Qt::blue, penWidth));
    painter->drawEllipse(-10, -10, 20, 20);
    painter->restore();
}

void SimpleItem::mousePressEvent(QGraphicsSceneMouseEvent *me)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    QGraphicsItem::mousePressEvent(me);
}

void SimpleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *me)
{
    QApplication::restoreOverrideCursor();
    QGraphicsItem::mousePressEvent(me);
}

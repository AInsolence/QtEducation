#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H

#include <QGraphicsItem>

class SimpleItem : public QGraphicsItem
{
private:
    enum {penWidth = 3};
public:
    SimpleItem();

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem* item,
                       QWidget* wgt) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* me) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* me) override;
};

#endif // SIMPLEITEM_H

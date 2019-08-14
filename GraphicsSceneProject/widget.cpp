#include "widget.h"

Widget::Widget(QGraphicsScene* pScene, QWidget *parent)
    : QGraphicsView(pScene, parent)
{
}

Widget::~Widget()
{

}

void Widget::slotZoomIn()
{
    scale(1.1, 1.1);
}

void Widget::slotZoomOut()
{
    scale(1/1.1, 1/1.1);
}

void Widget::slotRotateLeft()
{
    rotate(-10);
}

void Widget::slotRotateRight()
{
    rotate(10);
}

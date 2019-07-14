#include "canvas_1.h"

Canvas_1::Canvas_1(QWidget *parent)
    : QWidget(parent)
{

}

Canvas_1::~Canvas_1()
{

}

void Canvas_1::paintEvent(QPaintEvent *pe)
{
    QPainter* painter_1 = new QPainter(this);

    QPen pen_1(QColor(Qt::red).darker(200), 4,
               Qt::DashDotLine, Qt::RoundCap, Qt::MiterJoin);

    QPixmap brushImage(":/image/woman.jpg");
    QBrush brush_1(brushImage);
    // settings
    painter_1->setPen(pen_1);
    painter_1->setBrush(brush_1);

    painter_1->drawEllipse(0,0,this->width(),this->width()/2);

}

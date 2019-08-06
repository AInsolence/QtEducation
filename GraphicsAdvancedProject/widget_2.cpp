#include "widget_2.h"
#include <QPainter>

widget_2::widget_2(QWidget *parent) : QWidget(parent)
{

}

void widget_2::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QImage img(size(), QImage::Format_ARGB32_Premultiplied);

    painter.begin(&img);
    painter.initFrom(this);// initialising pen, brush, palette etc from wgt
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());

    painter.drawEllipse(0, 0, size().width(), size().height());
    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);

}

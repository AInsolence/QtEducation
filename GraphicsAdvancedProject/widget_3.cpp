#include "widget_3.h"
#include <QPainter>
#include <QBitmap>

widget_3::widget_3(QWidget *)
{
    resize(700,300);
}

void widget_3::paintEvent(QPaintEvent *)
{
    QPainter painter;
    // create Pixmap
    QPixmap pix(size());
    // paint image on pixmap
    painter.begin(&pix);
    painter.drawPixmap(rect(), QPixmap(":/image/Hull_02.png"));
    painter.end();
    // create Mask
    QBitmap bmp(size());
    bmp.fill();
    // paint Text on bitMAsk
    painter.begin(&bmp);
    painter.setPen(QPen(Qt::color1));// set opacity color for text on mask
    painter.setFont(QFont("Times", 75, QFont::Bold));
    painter.drawText(rect(), Qt::AlignCenter, "Draw Text");// !!! same size as pix
    painter.end();
    // apply mask bmp to pix
    pix.setMask(bmp);
    // draw pixmap on widget
    painter.begin(this);
    painter.drawPixmap(rect(), pix);
    painter.end();
}

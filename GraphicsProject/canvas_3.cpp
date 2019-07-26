#include "canvas_3.h"
#include <QPainter>
#include <QDebug>

Canvas_3::Canvas_3(QWidget *parent) : QWidget(parent)
{

}

void Canvas_3::paintEvent(QPaintEvent *pe)
{
    QPainter painter_3;
    painter_3.setPen(QPen(Qt::blue, 5));
    painter_3.setRenderHint(QPainter::Antialiasing, true);


    painter_3.end();
}

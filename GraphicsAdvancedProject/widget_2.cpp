#include "widget_2.h"
#include <QPainter>
#include <QLinearGradient>

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
    // gradient text example
    QLinearGradient gradient(0, 0, img.width(), img.height());
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(0.5, Qt::green);
    gradient.setColorAt(0, Qt::blue);

    painter.begin(&img);
    painter.setPen(QPen(gradient, 0));
    painter.setFont(QFont("Times", 40, QFont::Bold));
    QString str = "This is a very long gradient text to sample";
    QString elidedText =
            fontMetrics().elidedText(str, Qt::ElideMiddle, img.width());
    painter.drawText(img.rect(), elidedText);
    painter.end();
    //
    painter.begin(this);
    painter.drawImage(0, 0, img);
}

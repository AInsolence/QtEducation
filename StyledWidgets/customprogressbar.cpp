#include "customprogressbar.h"
#include <QPainter>

CustomProgressBar::CustomProgressBar(QWidget *parent) : QFrame(parent)
{
    setLineWidth(3);
    setFrameStyle(Box | Sunken);
    // set two rules: the first - for a width, and the second - for a height
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
}

void CustomProgressBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QLinearGradient gradient(0, 0, width(), height());

    float currentValue = _progressInPercentage / 100.0f;
    // set gradient in acordance with current percentage value
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(currentValue/2, Qt::blue);
    gradient.setColorAt(currentValue, Qt::green);
    // draw gradient
    painter.fillRect(rect(), Qt::red);// set as background
    painter.setBrush(gradient);
    painter.drawRect(0, 0, static_cast<int>(width()*currentValue), height());
    // set text
    painter.setPen(QPen(Qt::black));
    QString info = QString::number(_progressInPercentage) + "Kb/s";
    painter.drawText(rect(), Qt::AlignCenter, info);

    QFrame::drawFrame(&painter);// draw the wgt's frame
}

QSize CustomProgressBar::sizeHint() const
{
    return QSize(120, 30);
}

void CustomProgressBar::slotSetProgress(int percentage)
{
    _progressInPercentage = percentage > 100 ? 100 : percentage < 0 ? 0 : percentage;
    repaint();
    emit progressChanged(_progressInPercentage);
}

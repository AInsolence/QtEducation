#include "layoutcustomwidget.h"

LayoutCustomWidget::LayoutCustomWidget(QWidget *parent) : QWidget(parent)
{// initialization
    layout = new QBoxLayout(QHBoxLayout::LeftToRight);
    for(int i = 0; i < 3; ++i)
    {
        QString name = QString::number(i);
        buttons.push_back(new QPushButton(name));
        layout->addWidget(buttons[i], 1);
        buttons[i]->setCursor(QCursor(Qt::PointingHandCursor));
    }
    layout->setMargin(5);
    layout->setSpacing(30);
    layout->setGeometry(QRect(100, 100, 500, 50));
    layout->insertStretch(2);
}

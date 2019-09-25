#include "DemoWidget.h"
#include "customline.h"
#include "customprogressbar.h"
#include <QLayout>
#include <QScrollBar>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    CustomLine* hexLine = new CustomLine();
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);
    layout->addWidget(hexLine);

    CustomProgressBar* progBar = new CustomProgressBar();
    layout->addWidget(progBar);

    QScrollBar* scrollBar = new QScrollBar();
    scrollBar->setOrientation(Qt::Horizontal);
    scrollBar->setRange(0, 100);
    layout->addWidget(scrollBar);

    connect(scrollBar, &QScrollBar::valueChanged,
            progBar, &CustomProgressBar::slotSetProgress);
}

Widget::~Widget()
{
}


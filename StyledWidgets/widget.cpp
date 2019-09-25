#include "DemoWidget.h"
#include "customline.h"
#include "customprogressbar.h"
#include <QLayout>
#include <QScrollBar>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QScrollBar>
#include <QSlider>
#include <QList>
#include <QStyleFactory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    CustomLine* hexLine = new CustomLine();
    hexLine->setStyle(QStyleFactory::create("fusion"));
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

    QHBoxLayout* innerLayout_1 = new QHBoxLayout();
    layout->addLayout(innerLayout_1);

    for (int i = 0; i < 3; ++i) {
        QGroupBox* groupBox = new QGroupBox("Box " + QString::number(i));
        QVBoxLayout* innerLayout_2 = new QVBoxLayout();
        innerLayout_1->addWidget(groupBox);
        groupBox->setLayout(innerLayout_2);
        QScrollBar* scroll = new QScrollBar(Qt::Horizontal);
        QCheckBox* checkbox = new QCheckBox("Check box");
        QSlider* slider = new QSlider(Qt::Horizontal);
        QRadioButton* radio = new QRadioButton("Radio button");
        QPushButton* pushBtn = new QPushButton("Push button");
        QPushButton* flatBtn = new QPushButton("Flat button");
        flatBtn->setFlat(true);
        innerLayout_2->addWidget(scroll);
        innerLayout_2->addWidget(checkbox);
        innerLayout_2->addWidget(slider);
        innerLayout_2->addWidget(radio);
        innerLayout_2->addWidget(pushBtn);
        innerLayout_2->addWidget(flatBtn);

        QList<QWidget*> listOfWidgets = groupBox->findChildren<QWidget*>();
        for(auto child : listOfWidgets){
            child->setStyle(QStyleFactory::create("fusion"));
        }
    }
}

Widget::~Widget()
{
}


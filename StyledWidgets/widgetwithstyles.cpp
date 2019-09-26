#include "widgetwithstyles.h"
#include <QLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QScrollBar>
#include <QSlider>
#include <QList>
#include <QStyleFactory>
#include <QComboBox>
#include <QScrollBar>
#include <QApplication>


WidgetWithStyles::WidgetWithStyles(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QGroupBox* groupBox = new QGroupBox("Box");
    QVBoxLayout* layout = new QVBoxLayout();

    this->setLayout(mainLayout);
    mainLayout->addWidget(groupBox);
    groupBox->setLayout(layout);

    QComboBox* combo = new QComboBox();
    combo->addItems(QStyleFactory::keys());

    connect(combo, qOverload<const QString&>(&QComboBox::activated),
                                this, &WidgetWithStyles::slotSetStyle);

    QScrollBar* scroll = new QScrollBar(Qt::Horizontal);
    QCheckBox* checkbox = new QCheckBox("Check box");
    QSlider* slider = new QSlider(Qt::Horizontal);
    QRadioButton* radio = new QRadioButton("Radio button");
    QPushButton* pushBtn = new QPushButton("Push button");
    QPushButton* flatBtn = new QPushButton("Flat button");
    flatBtn->setFlat(true);

    layout->addWidget(combo);
    layout->addWidget(scroll);
    layout->addWidget(checkbox);
    layout->addWidget(slider);
    layout->addWidget(radio);
    layout->addWidget(pushBtn);
    layout->addWidget(flatBtn);
}

void WidgetWithStyles::slotSetStyle(const QString &styleName)
{
    QStyle* style = QStyleFactory::create(styleName);
    QApplication::setStyle(style);
    //this->setStyle(style);
    //repaint();
}

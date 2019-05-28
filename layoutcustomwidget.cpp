#include "layoutcustomwidget.h"

LayoutCustomWidget::LayoutCustomWidget(QWidget *parent) : QWidget(parent)
{// initialization
    layout = new QBoxLayout(QVBoxLayout::TopToBottom);
    int number = 1;
    for(int j = 0; j < 3; ++j)
    {
        rows.push_back(new QHBoxLayout);
        // fill row with buttons
        for(int i = 0; i < 3; ++i, ++number)
        {
            QString name = QString::number(number);
            QPushButton* button = new QPushButton(name);
            rows[j]->addWidget(button);
            button->setCursor(QCursor(Qt::PointingHandCursor));
        }
        // set row style
        rows[j]->setMargin(5);
        rows[j]->setSpacing(30);
        layout->addLayout(rows[j]);
    }
    // add "0"
    QLayout* Box = new QHBoxLayout();
    QWidget* button = new QPushButton("0");
    button->setCursor(QCursor(Qt::PointingHandCursor));
    Box->addWidget(button);
    layout->addLayout(Box);

    //Grid example
    QGridLayout* grid = new QGridLayout();
    QString character = "A";
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j, character[0].unicode() ++)
        {
            grid->addWidget(new QPushButton(character), i, j, Qt::AlignCenter);
        }
    }
    grid->setSpacing(30);
    grid->setMargin(10);
    //grid->setRowStretch(0, 3);
    //grid->setColumnStretch(0, 3);
    layout->addLayout(grid);
}

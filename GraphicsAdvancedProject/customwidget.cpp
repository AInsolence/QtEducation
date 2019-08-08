#include "customwidget.h"
#include "QMouseEvent"
#include <QPushButton>
#include <QDebug>
#include <QApplication>

CustomWidget::CustomWidget(QWidget *parent)// make frameless window
    : QLabel(parent, Qt::FramelessWindowHint | Qt::Window)
{
    QPushButton* exitButton = new QPushButton("X", this);
    constexpr int buttonSize = 35;
    exitButton->setGeometry(this->x() + this->height() - buttonSize, this->y(),
                            buttonSize, buttonSize);
    exitButton->setFlat(true);
    exitButton->setFont(QFont("Times", 18));
    exitButton->setStyleSheet("QPushButton {color: white;}");

    connect(exitButton, &QPushButton::clicked, this, &QLabel::close);
}

void CustomWidget::mousePressEvent(QMouseEvent *me)
{
    m_mouseCursorPosition = me->pos();
}

void CustomWidget::mouseMoveEvent(QMouseEvent *me)
{
    move(me->globalPos() - m_mouseCursorPosition);
}

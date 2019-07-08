#include "widget.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *myEvent)
{
    switch (myEvent->key()) {
    case Qt::Key_Plus:
        if(myEvent->modifiers() & Qt::ShiftModifier){
            resize(width()+50, height()+50);
        }
        break;
    case Qt::Key_Minus:
        if(myEvent->modifiers() & Qt::ShiftModifier){
            resize(width()-50, height()-50);
        }
        break;
    default:
        QWidget::keyPressEvent(myEvent);
    }
}

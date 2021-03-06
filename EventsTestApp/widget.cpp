#include "widget.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QLabel(parent)
{
    resize(300, 300);
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions:");
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

void Widget::mousePressEvent(QMouseEvent *myEvent)
{
    dumpEvent(myEvent, "Mouse pressed");
}

void Widget::mouseReleaseEvent(QMouseEvent *myEvent)
{
    dumpEvent(myEvent, "Mouse released");
}

void Widget::mouseMoveEvent(QMouseEvent *myEvent)
{
    dumpEvent(myEvent, "Mouse moved");
}

void Widget::wheelEvent(QWheelEvent *myEvent)
{
    setText(text() + "\nWheel rotate"
            + "delta = " + QString::number(myEvent->delta()));
}

void Widget::enterEvent(QEvent *myEvent)
{
    setText("Mouse on widget");
}

void Widget::leaveEvent(QEvent *myEvent)
{
    setText("Mouse leave widget");
}

void Widget::resizeEvent(QResizeEvent *myEvent)
{
    setText(
                "Window resized\nOld size: "
                + QString::number(myEvent->oldSize().width())
                + " " + QString::number(myEvent->oldSize().height())
                + "\nNew size: "
                + QString::number(myEvent->size().width())
                + " " + QString::number(myEvent->size().height())
                );
}

void Widget::moveEvent(QMoveEvent *myEvent)
{
    setText(
                "Window moved\nOld position: "
                + QString::number(myEvent->oldPos().x())
                + " " + QString::number(myEvent->oldPos().y())
                + "\nNew position: "
                + QString::number(myEvent->pos().x())
                + " " + QString::number(myEvent->pos().y())
                );
}

void Widget::dumpEvent(QMouseEvent *myEvent, const QString msg)
{
    setText(msg
            + "\n buttons() = " + buttonsInfo(myEvent)
            + "\n x() = " + QString::number(myEvent->x())
            + "\n y() = " + QString::number(myEvent->y())
            + "\n globalX() = " + QString::number(myEvent->globalX())
            + "\n globalY() = " + QString::number(myEvent->globalY())
            + "\n modifiers() = " + modifiersInfo(myEvent)
                );
}

QString Widget::modifiersInfo(QMouseEvent *myEvent)
{
    QString strModifiers;
    if(myEvent->modifiers() & Qt::ShiftModifier){
        strModifiers += "Shift ";
    }
    if(myEvent->modifiers() & Qt::ControlModifier){
        strModifiers += "Ctrl ";
    }
    if(myEvent->modifiers() & Qt::AltModifier){
        strModifiers += "Alt ";
    }
    return strModifiers;
}

QString Widget::buttonsInfo(QMouseEvent *myEvent)
{
    QString strButtons;
    if(myEvent->button() & Qt::LeftButton){
        strButtons += "Left ";
    }
    if(myEvent->button() & Qt::RightButton){
        strButtons += "Right ";
    }
    if(myEvent->button() & Qt::MidButton){
        strButtons += "Middle ";
    }
    return  strButtons;
}

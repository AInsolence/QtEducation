#include "mylabel.h"
#include "QStylePainter"
#include "QStyleOptionButton"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::paintEvent(QPaintEvent *pEvent)
{
    QStylePainter stylePainter(this);
    QStyleOptionButton buttonStyleOption;

    buttonStyleOption.initFrom(this);
    buttonStyleOption.text = "This is a lable!";

    stylePainter.drawControl(QStyle::CE_PushButton, buttonStyleOption);
}

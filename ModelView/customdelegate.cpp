#include "customdelegate.h"

CustomDelegate::CustomDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void CustomDelegate::paint(QPainter *painter,
                           const QStyleOptionViewItem &styleOption,
                           const QModelIndex &index) const
{
    if(styleOption.state & QStyle::State_MouseOver){
        QRect rect = styleOption.rect;
        QLinearGradient gradient(0, 0, rect.width(), rect.height());

        gradient.setColorAt(0, Qt::white);
        gradient.setColorAt(0.5, Qt::blue);
        gradient.setColorAt(1, Qt::green);

        painter->setBrush(gradient);
        painter->drawRect(rect);
    }
    // call paint with new custom parameters
    QStyledItemDelegate::paint(painter, styleOption, index);
}

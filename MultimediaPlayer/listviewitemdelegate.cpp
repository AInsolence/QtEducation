#include "listviewitemdelegate.h"
#include <QFileInfo>
#include <QRegExp>
#include <QPainter>
#include <QItemSelectionModel>
#include <QAbstractItemView>
#include "playlistwidget.h"

ListViewItemDelegate::ListViewItemDelegate(QObject* obj)
    : QStyledItemDelegate (obj)
{

}

QString ListViewItemDelegate::displayText(const QVariant &value,
                                          const QLocale &locale) const
{
    Q_UNUSED(locale)

    // get file name from path
    auto fileName = QFileInfo(value.toString()).fileName();
    // delete file extention
    QRegExp exp("\\.[^.]*$");
    fileName.remove(exp);

    return fileName;
}

void ListViewItemDelegate::paint(QPainter *painter,
                                 const QStyleOptionViewItem &styleOption,
                                 const QModelIndex &index) const
{// TODO set appropriate state
    if(PlaylistWidget::_currentIndex && (index == *PlaylistWidget::_currentIndex))
    {
        QRect rect = styleOption.rect;
        QLinearGradient gradient(0, 0, rect.width(), rect.height());

        gradient.setColorAt(0, Qt::white);
        gradient.setColorAt(1, Qt::gray);

        painter->setBrush(gradient);
        painter->drawRect(rect);
    }
    // call paint with new custom parameters
    QStyledItemDelegate::paint(painter, styleOption, index);
}

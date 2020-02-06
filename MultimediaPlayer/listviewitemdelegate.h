#ifndef LISTVIEWITEMDELEGATE_H
#define LISTVIEWITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>

class ListViewItemDelegate : public QStyledItemDelegate
{
public:
    explicit ListViewItemDelegate(QObject* obj);
protected:
    virtual QString displayText(const QVariant &value,
                        const QLocale &locale) const override;
    virtual void paint(QPainter* painter,
                       const QStyleOptionViewItem& styleOption,
                       const QModelIndex& index) const override;
};

#endif // LISTVIEWITEMDELEGATE_H

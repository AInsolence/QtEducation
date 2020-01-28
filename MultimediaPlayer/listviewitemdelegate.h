#ifndef LISTVIEWITEMDELEGATE_H
#define LISTVIEWITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>

class ListViewItemDelegate : public QStyledItemDelegate
{
public:
    explicit ListViewItemDelegate(QObject* obj);

    virtual QString displayText(const QVariant &value,
                        const QLocale &locale) const override;
};

#endif // LISTVIEWITEMDELEGATE_H

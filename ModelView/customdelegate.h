#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QObject>
#include <QtWidgets>

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CustomDelegate(QObject *parent = nullptr);

    virtual void paint(QPainter* painter,
                       const QStyleOptionViewItem& styleOption,
                       const QModelIndex& index) const override;

signals:

public slots:
};

#endif // CUSTOMDELEGATE_H

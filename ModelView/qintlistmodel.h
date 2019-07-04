#ifndef QINTLISTMODEL_H
#define QINTLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

class QIntListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QList<int> _list;

public:
    QIntListModel(const QList<int>& list, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int Role) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int Section,
                        Qt::Orientation orientation,
                        int Role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index,
                 const QVariant& value,
                 int nRole) override;

};

#endif // QINTLISTMODEL_H

#include "qintlistmodel.h"

QIntListModel::QIntListModel(const QList<int>& list, QObject* parent)
    : QAbstractListModel(parent), _list(list)
{
}

QVariant QIntListModel::data(const QModelIndex &index, int Role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    return (Role == Qt::DisplayRole || Role == Qt::EditRole)
            ? _list.at(index.row())
            : QVariant();
}

int QIntListModel::rowCount(const QModelIndex& parent) const
{
    return _list.size();
}

Qt::ItemFlags QIntListModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractListModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           : flags;// editable only if exists
}

QVariant QIntListModel::headerData(int Section, Qt::Orientation orientation, int Role) const
{
    if(Role != Qt::DisplayRole){
        return QVariant();
    }
    return (orientation == Qt::Horizontal)
            ? QString("Number") : QString::number(Section);
}

bool QIntListModel::setData(const QModelIndex &index, const QVariant &value, int Role)
{
    if(index.isValid() && Role == Qt::EditRole){
        _list.replace(index.row(), value.toInt());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

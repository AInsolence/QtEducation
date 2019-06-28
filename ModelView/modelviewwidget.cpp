#include "modelviewwidget.h"
#include <QLayout>
#include <QStringListModel>
#include <QListView>
#include <QTreeView>
#include <QTableView>
#include <QDebug>
#include "customdelegate.h"

ModelViewWidget::ModelViewWidget(QWidget *parent)
    : QWidget(parent)
{// create data
    QStringList myList;
    myList << "item 1" << "item 2" << "item 3" << "item 4";
    //create model
    QStringListModel* myListModel = new QStringListModel();
    myListModel->setStringList(myList);
    //create views
    QListView* listView = new QListView();
    QTreeView* treeView = new QTreeView();
    QTableView* tableView = new QTableView();

    // set model to views
    listView->setModel(myListModel);
    treeView->setModel(myListModel);
    tableView->setModel(myListModel);

    // create selection mode (CREATE ONLY ON HEAP)
    QItemSelectionModel* selectionModel = new QItemSelectionModel(myListModel);

    listView->setSelectionModel(selectionModel);
    treeView->setSelectionModel(selectionModel);
    tableView->setSelectionModel(selectionModel);

    // set custom style delegate
    listView->setItemDelegate(new CustomDelegate(listView));
    listView->viewport()->setAttribute(Qt::WA_Hover);
    treeView->setItemDelegate(new CustomDelegate(treeView));
    treeView->viewport()->setAttribute(Qt::WA_Hover);
    tableView->setItemDelegate(new CustomDelegate(tableView));
    tableView->viewport()->setAttribute(Qt::WA_Hover);


    // add all views to layout
    QHBoxLayout* mvLayout = new QHBoxLayout();
    mvLayout->addWidget(listView);
    mvLayout->addWidget(treeView);
    mvLayout->addWidget(tableView);

    //********************* QStandardItemModel *************************//
    QStandardItemModel* stModel = new QStandardItemModel(5, 3);
    for (int topRow = 0; topRow < 5; ++topRow) {
        QModelIndex index = stModel->index(topRow, 0);
        stModel->setData(index, "item " + QString::number(topRow + 1));

        // expand our model
        stModel->insertRows(0, 4, index);
        stModel->insertColumns(0, 3, index);
        for(int row = 0; row < 4; ++row){
            for(int col = 0; col < 3; ++col){
                QString data = QString("%1, %2").arg(row).arg(col);
                stModel->setData(stModel->index(row, col, index), data);
            }
        }
    }

    QTreeView* stModelView = new QTreeView();
    stModelView->setModel(stModel);

    // main layout
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(mvLayout);
    mainLayout->addWidget(stModelView);

    setLayout(mainLayout);
    show();
}

ModelViewWidget::~ModelViewWidget()
{

}

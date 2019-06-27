#include "modelviewwidget.h"
#include <QLayout>
#include <QStringListModel>
#include <QListView>
#include <QTreeView>
#include <QTableView>
#include <QDebug>

ModelViewWidget::ModelViewWidget(QWidget *parent)
    : QWidget(parent)
{// create data
    QStringList myList;
    myList << "item 1" << "item 2" << "item 3" << "item 4";
    for(QString name : myList){
        qDebug() << name;
    }
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

    // add all views to layout
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addWidget(listView);
    mainLayout->addWidget(treeView);
    mainLayout->addWidget(tableView);

    setLayout(mainLayout);
    show();
}

ModelViewWidget::~ModelViewWidget()
{

}

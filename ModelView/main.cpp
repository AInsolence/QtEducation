#include "modelviewwidget.h"
#include <QApplication>
#include <QBoxLayout>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QListView>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelViewWidget w;
    w.show();

    QWidget* proxyModelExample = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    proxyModelExample->setLayout(mainLayout);
    proxyModelExample->move(400, 150);
    // create model
    QStringListModel* model = new QStringListModel();
    QStringList dataList;
    dataList << "Anton" << "Anatoly" << "Ivan" << "Ermek" << "Dulat" << "Dima";
    model->setStringList(dataList);
    // create two views for data and sort data models
    QListView* dataView = new QListView();
    dataView->setModel(model);
    mainLayout->addWidget(dataView);
    QListView* sortDataView = new QListView();
    mainLayout->addWidget(sortDataView);
    // create proxy model
    QSortFilterProxyModel* sortedDataModel = new QSortFilterProxyModel();
    sortedDataModel->setSourceModel(model);
    sortDataView->setModel(sortedDataModel);
    // create field do set mask for proxy model
    QLineEdit* maskInputField = new QLineEdit("Input sort mask here");
    mainLayout->addWidget(maskInputField);

    QObject::connect(maskInputField, &QLineEdit::textEdited,
                     sortedDataModel, &QSortFilterProxyModel::setFilterWildcard);

    //proxyModelExample->show();
    QPalette palette(Qt::green, Qt::magenta);
    palette.setColor(QPalette::Inactive, QPalette::Base, Qt::lightGray);
    palette.setColor(QPalette::Text, Qt::blue);
    QApplication::setPalette(palette);

    return a.exec();
}

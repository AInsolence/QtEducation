#include "DemoWidget.h"

#include <QApplication>
#include <QStyle>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(300, 100);
    w.show();
    qDebug() << QStyleFactory::keys();
    QApplication::setStyle(QStyleFactory::create("windows"));
    return a.exec();
}

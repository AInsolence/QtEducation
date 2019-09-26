#include "DemoWidget.h"
#include "widgetwithstyles.h"
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
    qDebug() << "Widget style: " << w.style();
    //w.setStyle(QStyleFactory::create("fusion"));
    QApplication::setStyle(QStyleFactory::create("windows"));

    WidgetWithStyles styledWidget;
    styledWidget.show();

    return a.exec();
}

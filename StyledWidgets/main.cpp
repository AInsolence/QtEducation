#include "DemoWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(300, 100);
    w.show();
    return a.exec();
}

#include "widget.h"
#include <QApplication>
#include <QLabel>
#include "widget_2.h"
#include "widget_3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    widget_2 widget2;
    widget_3 widget3;
    w.show();
    widget2.show();
    widget3.show();


    return a.exec();
}

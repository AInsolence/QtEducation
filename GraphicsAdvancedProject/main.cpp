#include "widget.h"
#include <QApplication>
#include <QLabel>
#include "widget_2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    widget_2 widget2;
    w.show();
    widget2.show();

    return a.exec();
}

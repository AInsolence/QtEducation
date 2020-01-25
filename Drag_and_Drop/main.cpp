#include "dragwidget.h"
#include "dropwidget.h"
#include "dragwidget_2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragWidget w("Hello");
    DropWidget x("Drop Here");
    DragWidget_2 y("You can drag this widget");
    w.show();
    x.show();
    y.show();

    return a.exec();
}

#include "dragwidget.h"
#include "dropwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragWidget w("Hello");
    DropWidget x("Drop Here");
    w.show();
    x.show();

    return a.exec();
}

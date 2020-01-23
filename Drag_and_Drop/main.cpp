#include "dragwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragWidget w("Hello");
    w.show();

    return a.exec();
}

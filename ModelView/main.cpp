#include "modelviewwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelViewWidget w;
    w.show();

    return a.exec();
}

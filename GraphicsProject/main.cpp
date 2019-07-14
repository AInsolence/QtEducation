#include "canvas_1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Canvas_1 w;
    w.show();

    return a.exec();
}

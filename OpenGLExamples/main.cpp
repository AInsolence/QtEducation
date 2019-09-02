#include "oglquad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLQuad w;
    w.resize(300, 300);
    //w.showFullScreen();
    w.show();

    return a.exec();
}

#include "oglquad.h"
#include "oglquad_2.h"
#include "oglpyramide.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLQuad w;
    w.resize(300, 300);
    //w.showFullScreen();
    w.show();

    OGLQuad_2 wgt_2;
    wgt_2.setGeometry(w.pos().x() + w.width(), w.pos().y() + 38, 600, 600);
    wgt_2.show();

    OGLPyramide pyramide;
    pyramide.resize(300, 300);
    pyramide.show();

    return a.exec();
}

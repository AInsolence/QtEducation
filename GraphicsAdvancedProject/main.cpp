#include "widget.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    /*QLabel lbl;
    //lbl.setFixedSize(100, 100);

    //lbl.setPixmap(QPixmap::fromImage(brightness(img, i)));
    lbl.setPixmap(QPixmap(":/image/Hull_02.png"));

    lbl.show();*/

    return a.exec();
}

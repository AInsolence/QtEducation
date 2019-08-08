#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QBitmap>
#include "widget_2.h"
#include "widget_3.h"
#include "customwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget widget1;
    widget_2 widget2;
    widget_3 widget3;

    CustomWidget widget4;
    QPixmap pixmap(":/image/frame_640.png");
    widget4.setPixmap(pixmap);
    //widget4.setMask(pixmap.mask());
    widget4.setAttribute(Qt::WA_TranslucentBackground);

    widget1.show();
    widget2.show();
    widget3.show();
    widget4.show();

    return a.exec();
}

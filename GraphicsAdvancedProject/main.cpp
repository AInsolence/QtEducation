#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QBitmap>
#include <QDebug>
#include <QFontDatabase>
#include <QFontInfo>
#include <QFontMetrics>
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
    // QFont QFontDataBase QFontInfo & QFontMetrics examples
    QFont font("Papyrus", 18, QFont::Normal);
    QFontDatabase base;
    qDebug() << base.families();
    qDebug() << base.styleString(QFont("Times", 18, QFont::Bold));
    qDebug() << base.styleString(QFontInfo(font));
    // QFontInfo
    font.setItalic(true);
    QFontInfo info(font);
    qDebug() << info.family();
    qDebug() << info.italic();
    qDebug() << info.bold();
    // QFontMetrics
    QFontMetrics metrics(font);

    qDebug() << "leftBearing: " << metrics.leftBearing(QChar('.'));
    qDebug() << "rightBearing: " << metrics.rightBearing(QChar('.'));

    qDebug() << "lineSpacing: " <<metrics.lineSpacing();
    qDebug() << "height: " << metrics.height();

    qDebug() << "'A' char width: " << metrics.width('A');
    qDebug() << "\"Hello world\" width: " << metrics.width("Hello world");
    qDebug() << "\"Hello world\" first 5 chars width: "
             << metrics.width("Hello world", 5);

    qDebug() << "ascent: " << metrics.ascent();
    qDebug() << "descent: " << metrics.descent();

    qDebug() << "\"Hello world\" boundingRect: "
             << metrics.boundingRect("Hello world");

    return a.exec();
}

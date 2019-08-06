#include "widget.h"
#include "QLayout"
#include "QLabel"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QImage imgSource(":/image/Hull_02.png");
    QImage img(imgSource.mirrored());// mirrored NOT works for original img

    QHBoxLayout* layout_1 = new QHBoxLayout();

    for (qint32 i = -150; i < 150; i += 50) {
        QLabel* lbl = new QLabel();
        lbl->setFixedSize(img.size());

        lbl->setPixmap(QPixmap::fromImage(brightness(img, i)));
        layout_1->addWidget(lbl);
        if(i/100 == 0){
            img.invertPixels(QImage::InvertRgb);// invert RGB example
        }
    }

    setLayout(layout_1);
    move(150, 200);
}

Widget::~Widget()
{

}

QImage Widget::brightness(const QImage &sourceImg, int brightValue)
{
    QImage tempImg(sourceImg);
    qint32 width = tempImg.width();
    qint32 height =tempImg.height();

    for (qint32 imgPixString = 0; imgPixString < height; ++imgPixString) {
        QRgb* tempLine = reinterpret_cast<QRgb*>(tempImg.scanLine(imgPixString));
        for (qint32 pixelInStr = 0; pixelInStr < width; ++pixelInStr) {
            qint32 r = qRed(*tempLine) + brightValue;
            qint32 g = qGreen(*tempLine) + brightValue;
            qint32 b = qBlue(*tempLine) + brightValue;
            qint32 a = qAlpha(*tempLine);

            *tempLine++ = qRgba(
                                r > 255 ? 255 : r < 0 ? 0 : r,
                                g > 255 ? 255 : g < 0 ? 0 : g,
                                b > 255 ? 255 : b < 0 ? 0 : b,
                                a);
        }
    }

    return  tempImg;
}

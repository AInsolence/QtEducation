#include "canvas_1.h"
#include <QtMath>
#include <QVector>
#include <QPicture>
#include <QDebug>

Canvas_1::Canvas_1(QWidget *parent)
    : QWidget(parent)
{

}

Canvas_1::~Canvas_1()
{

}

void Canvas_1::paintEvent(QPaintEvent *)
{
    QPainter* painter_1 = new QPainter(this);

    QPen pen_1(QColor(Qt::red).darker(200), 3,
               Qt::DashDotLine, Qt::RoundCap, Qt::MiterJoin);

    QPixmap brushImage(":/image/woman.jpg");
    // QBrush brush_1(Qt::red, Qt::HorPattern);
    QBrush brush_1(brushImage);// use as texture pattern
    // settings
    painter_1->setPen(pen_1);
    painter_1->setBrush(brush_1);

    painter_1->drawEllipse(0,0,this->width()/2,this->width()/4);

    // paint primitives examples
    // drawPoint
    const int numOfPoints = 12;
    double startCoordX = 110.0;
    double startCoordY = 300.0;
    double radius = 100.0;

    QPointF points [numOfPoints];

    for(int i = 0; i < numOfPoints; ++i){
        double angle = 2 * M_PI * i/numOfPoints;
        double pointX = startCoordX + cos(angle)*radius;
        double pointY = startCoordY + sin(angle)*radius;
        painter_1->drawPoint(QPointF(pointX, pointY));
        points[i] = QPointF(pointX, pointY);
    }
    // drawPolyline
    painter_1->drawPolyline(points, numOfPoints/2);
    // drawConvexPolygon
    painter_1->drawConvexPolygon(points, 5);// may be faster but only for convex
    // draw rectangles without border
    QConicalGradient gradient(150, 150, 90);
    gradient.setColorAt(0, Qt::green);
    gradient.setColorAt(0.4, Qt::blue);
    gradient.setColorAt(0.8, Qt::red);
    gradient.setColorAt(1, Qt::green);
    QBrush myBrush(gradient);

    painter_1->fillRect(QRect(100, 100, 100, 100), myBrush);
    painter_1->eraseRect(QRect(50, 50, 40, 80));
    // draw simple rectangle
    painter_1->drawRect(300, 100, 100, 200);
    painter_1->drawRoundedRect(QRect(400, 200, 200, 150), 20, 100);
    // draw circle
    painter_1->drawEllipse(400, 50, 50, 50);
    // draw chord and pie
    painter_1->drawChord(500, 50, 200, 200,
                         90*16, 90*16);// connect two angles on ellips
    painter_1->drawPie(600, 50, 200, 200,
                       30*16, 330*16);// pie between two angles

    // Saving and loading QPainter commands in QPicture .dat file
    QPicture picture;

    if(!picture.save("picture.dat")){
        qDebug() << "cannot save picture.dat file";
    }

    if(!picture.load("newPicture.dat")){
        qDebug() << "cannot load picture.dat file";
    }

    // transformations:
    painter_1->save();
    painter_1->scale(0.8, 0.5);
    painter_1->shear(0.5, 0.5);
    painter_1->translate(-130.0, 300.0);
    painter_1->rotate(10);
    painter_1->drawEllipse(200, 200, 200, 300);
    painter_1->restore();

    QTransform matrix;

    //matrix.scale(0.7, 0.5);
    matrix.shear(0.2, 0.5);
    matrix.rotate(15);
    painter_1->setTransform(matrix);
    painter_1->drawText(rect(), Qt::AlignCenter, "Transformed text");

    painter_1->end();

}

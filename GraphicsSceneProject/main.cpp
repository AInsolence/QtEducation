#include "widget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create scene to store all items
    QGraphicsScene scene(QRectF(-100, -100, 600, 600));
    // create items and add them to scene
    QGraphicsRectItem* pRectItem =
            scene.addRect(
                QRect(-30, -30, 120, 80),
                QPen(Qt::black),
                QBrush(Qt::green)
                );
    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);

    // create complex graphics item
    // create tracks
    QGraphicsPixmapItem* leftTrack =
            scene.addPixmap(
                    QPixmap(":/tank/Track_3_A.png"));
    QGraphicsPixmapItem* rightTrack =
            scene.addPixmap(
                    QPixmap(":/tank/Track_3_A.png"));
    // create hull
    QGraphicsPixmapItem* hull =
            scene.addPixmap(
                    QPixmap(":/tank/Hull_01.png"));
    hull->setFlag(QGraphicsItem::ItemIsMovable);
    hull->setZValue(3);
    // connect tracks to hull
    leftTrack->setParentItem(hull);
    rightTrack->setParentItem(hull);

    leftTrack->setPos(40, 10);
    leftTrack->setZValue(0);
    rightTrack->setPos(175, 10);
    // create turret and connet to hull
    QGraphicsPixmapItem* turret =
            new QGraphicsPixmapItem(QPixmap(":/tank/Turret.png"));
    turret->setParentItem(hull);
    turret->setPos(81, 100);
    // create barrel and connet to hull
    QGraphicsPixmapItem* barrel =
            new QGraphicsPixmapItem(QPixmap(":/tank/Gun_04_A.png"));
    barrel->setParentItem(turret);
    barrel->setPos(37, -110);

    // create view to show scene
    QGraphicsView graphicsView(&scene);

    QPushButton buttonLeft("Turn Left");
    QPushButton buttonRight("Turn Right");
    scene.addWidget(&buttonLeft);
    scene.addWidget(&buttonRight);
    buttonLeft.move(0, 400);
    buttonRight.move(165, 400);

    turret->setTransformOriginPoint(turret->boundingRect().width()/2,
                                    turret->boundingRect().height()/2);
    QObject::connect(&buttonLeft, &QPushButton::pressed,
                     [=](){turret->setRotation(turret->rotation() - 10);});
    QObject::connect(&buttonRight, &QPushButton::pressed,
                     [=](){turret->setRotation(turret->rotation() + 10);});

    graphicsView.show();
    return a.exec();
}

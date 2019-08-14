#include "widget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include "simpleitem.h"
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create scene to store all items
    QGraphicsScene scene(QRectF(-100, -100, 1000, 1000));
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

    QPushButton buttonLeft("Turn Turret Left");
    QPushButton buttonRight("Turn Turret Right");
    QPushButton buttonTurnLeft("Turn Left");
    QPushButton buttonTurnRight("Turn Right");
    scene.addWidget(&buttonLeft);
    scene.addWidget(&buttonRight);
    scene.addWidget(&buttonTurnLeft);
    scene.addWidget(&buttonTurnRight);
    buttonLeft.move(0, 400);
    buttonRight.move(165, 400);
    buttonTurnLeft.move(0, 440);
    buttonTurnRight.move(165, 440);

    turret->setTransformOriginPoint(turret->boundingRect().width()/2,
                                    turret->boundingRect().height()/2);
    qreal centerX = hull->boundingRect().width()/2;
    qreal centerY = hull->boundingRect().height()/2;
    QTransform transform = hull->transform();

    QObject::connect(&buttonLeft, &QPushButton::pressed,
                     [=](){turret->setRotation(turret->rotation() - 10);});
    QObject::connect(&buttonRight, &QPushButton::pressed,
                     [=](){turret->setRotation(turret->rotation() + 10);});
    QObject::connect(&buttonTurnLeft, &QPushButton::pressed,
                     [&](){
                            transform.translate( centerX , centerY  );
                            transform.rotate(-30);
                            transform.translate( -centerX , -centerY );
                            hull->setTransform(transform);
                          });
    QObject::connect(&buttonTurnRight, &QPushButton::pressed,
                     [&](){
                            transform.translate( centerX , centerY  );
                            transform.rotate(30);
                            transform.translate( -centerX , -centerY );
                            hull->setTransform(transform);
                          });

    graphicsView.show();

    // create custom GraphicsView
    QWidget mainWidget;
    QVBoxLayout* layout = new QVBoxLayout();
    mainWidget.setLayout(layout);

    QGraphicsScene myScene(QRectF(-100, -100, 600, 600));

    Widget* myCustomView = new Widget(&myScene);
    QPushButton* zoomIn = new QPushButton("&ZOOM IN");
    QPushButton* zoomOut = new QPushButton("Z&OOM OUT");
    QPushButton* rotateLeft = new QPushButton("&ROTATE LEFT");
    QPushButton* rotateRight = new QPushButton("R&OTATE RIGHT");

    QObject::connect(zoomIn, &QPushButton::clicked,
                     myCustomView, &Widget::slotZoomIn);
    QObject::connect(zoomOut, &QPushButton::clicked,
                     myCustomView, &Widget::slotZoomOut);
    QObject::connect(rotateLeft, &QPushButton::clicked,
                     myCustomView, &Widget::slotRotateLeft);
    QObject::connect(rotateRight, &QPushButton::clicked,
                     myCustomView, &Widget::slotRotateRight);

    SimpleItem* simpleItem_1 = new SimpleItem;
    myScene.addItem(simpleItem_1);
    simpleItem_1->setPos(0, 0);
    simpleItem_1->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* hull_2 =
            new QGraphicsPixmapItem(QPixmap(":/tank/Hull_01.png"));

    hull_2->setParentItem(simpleItem_1);

    layout->addWidget(myCustomView);
    layout->addWidget(zoomIn);
    layout->addWidget(zoomOut);
    layout->addWidget(rotateLeft);
    layout->addWidget(rotateRight);

    mainWidget.show();
    return a.exec();
}

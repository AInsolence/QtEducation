#include "widget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include "simpleitem.h"
#include <QLayout>
#include <QMovie>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>

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
    QPushButton buttonFire("Fire");
    scene.addWidget(&buttonLeft);
    scene.addWidget(&buttonRight);
    scene.addWidget(&buttonTurnLeft);
    scene.addWidget(&buttonTurnRight);
    scene.addWidget(&buttonFire);
    buttonLeft.move(0, 400);
    buttonRight.move(165, 400);
    buttonTurnLeft.move(0, 440);
    buttonTurnRight.move(165, 440);
    buttonFire.move(80, 480);

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
    // custom animation
    QObject::connect(&buttonFire, &QPushButton::pressed,
                     [&](){
                            qint8 moveIndex= 10;
                            for (int moveInd = 0;moveInd < moveIndex; moveInd++) {
                                barrel->moveBy(0, 1);
                                QTime dieTime= QTime::currentTime().addMSecs(20);
                                while (QTime::currentTime() < dieTime)
                                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                            }
                            for (int moveInd = 0;moveInd < moveIndex; moveInd++) {
                                barrel->moveBy(0, -1);
                                QTime dieTime= QTime::currentTime().addMSecs(20);
                                while (QTime::currentTime() < dieTime)
                                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                            }
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

    qDebug() << QMovie::supportedFormats();
    // QMovie example
    QMovie* explosionMovie = new QMovie(":/tank/tenor.gif");
    QLabel movieLabel;
    movieLabel.resize(640, 480);
    explosionMovie->setScaledSize(movieLabel.size());
    movieLabel.setMovie(explosionMovie);
    explosionMovie->start();
    explosionMovie->setSpeed(60);// set 60% of real speed
    // QTimer example
    QTimer timer(&movieLabel);
    QObject::connect(&timer, &QTimer::timeout, [&](){
        explosionMovie->stop();
    });
    timer.start(3020);

    // QPropertyAnimation
    QLabel animLabel;
    layout->addWidget(&animLabel);
    animLabel.setPixmap(QPixmap(":/tank/Turret.png"));

    QGraphicsColorizeEffect animEffect;
    animLabel.setGraphicsEffect(&animEffect);

    QPropertyAnimation* animation = new QPropertyAnimation(&animEffect, "color");

    animation->setStartValue(QColor(Qt::white));
    animation->setKeyValueAt(0.25, QColor(Qt::red));
    animation->setKeyValueAt(0.5, QColor(Qt::blue));
    animation->setKeyValueAt(0.75, QColor(Qt::green));
    animation->setEndValue(QColor(Qt::yellow));

    animation->setDuration(3000);
    animation->setLoopCount(-1);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QPushButton button("Animation");
    layout->addWidget(&button);
    QPropertyAnimation *mAnimation = new QPropertyAnimation(&button, "geometry");
    mAnimation->setDuration(10000);
    mAnimation->setStartValue(QRect(0, 0, 100, 30));
    mAnimation->setKeyValueAt(0.5, QRect(250, 250, 100, 30));
    mAnimation->setEndValue(QRect(0, 0, 100, 30));
    mAnimation->setLoopCount(-1);

    mAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    mainWidget.show();
    movieLabel.show();
    return a.exec();
}

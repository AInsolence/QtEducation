#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsView>

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QGraphicsScene* pScene, QWidget *parent = nullptr);
    ~Widget();
public slots:
    void slotZoomIn();
    void slotZoomOut();
    void slotRotateLeft();
    void slotRotateRight();
};

#endif // WIDGET_H

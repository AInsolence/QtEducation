#ifndef CANVAS_1_H
#define CANVAS_1_H

#include <QWidget>
#include <QPainter>

class Canvas_1 : public QWidget
{
    Q_OBJECT

public:
    Canvas_1(QWidget *parent = 0);
    ~Canvas_1();
protected:
    void paintEvent(QPaintEvent* pe) override;
};

#endif // CANVAS_1_H

#ifndef CANVAS_3_H
#define CANVAS_3_H

#include <QWidget>
#include <QLabel>

class Canvas_3 : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas_3(QWidget *parent = nullptr);

    QPixmap* canvas = nullptr;
    QLabel* lbl = nullptr;

protected:
    void paintEvent(QPaintEvent* pe) override;

    virtual void mouseMoveEvent(QMouseEvent* myEvent) override;
};
#endif // CANVAS_3_H

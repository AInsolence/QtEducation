#ifndef CANVAS_3_H
#define CANVAS_3_H

#include <QWidget>

class Canvas_3 : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas_3(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* pe) override;
};

#endif // CANVAS_3_H

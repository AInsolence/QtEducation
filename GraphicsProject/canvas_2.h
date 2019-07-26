#ifndef CANVAS_2_H
#define CANVAS_2_H

#include <QWidget>

class canvas_2 : public QWidget
{
    Q_OBJECT
public:
    explicit canvas_2(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* pe) override;
};

#endif // CANVAS_2_H

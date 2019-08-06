#ifndef WIDGET_2_H
#define WIDGET_2_H

#include <QWidget>

class widget_2 : public QWidget
{
    Q_OBJECT
public:
    explicit widget_2(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* pe) override;
};

#endif // WIDGET_2_H

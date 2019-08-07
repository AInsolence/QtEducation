#ifndef WIDGET_3_H
#define WIDGET_3_H
#include <QLabel>


class widget_3 : public QLabel
{
    Q_OBJECT
public:
    explicit widget_3(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* pe) override;
};

#endif // WIDGET_3_H

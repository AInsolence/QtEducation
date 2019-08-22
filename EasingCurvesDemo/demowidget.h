#ifndef DEMOWIDGET_H
#define DEMOWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>

class DemoWidget : public QWidget
{
    Q_OBJECT

public:
    DemoWidget(QWidget *parent = 0);
    ~DemoWidget();

    QGridLayout* layout = nullptr;
    // buttons to each easy curve type
    QPushButton* Linear = nullptr;
    QPushButton* InExpo = nullptr;
    QPushButton* OutExpo = nullptr;
    QPushButton* InOutExpo = nullptr;
    QPushButton* OutInExpo = nullptr;
    QPushButton* InQuad = nullptr;
    QPushButton* OutQuad = nullptr;
    QPushButton* InOutQuad = nullptr;
    QPushButton* OutInQuad = nullptr;
    QPushButton* InCirc = nullptr;
    QPushButton* OutCirc = nullptr;
    QPushButton* InOutCirc = nullptr;
    QPushButton* OutInCirc = nullptr;
    QPushButton* InCubic = nullptr;
    QPushButton* OutCubic = nullptr;
    QPushButton* InOutCubic = nullptr;
    QPushButton* OutInCubic = nullptr;
    QPushButton* InElastic = nullptr;
    QPushButton* OutElastic = nullptr;
    QPushButton* InOutElastic = nullptr;
    QPushButton* OutInElastic = nullptr;
    QPushButton* InQuart = nullptr;
    QPushButton* OutQuart = nullptr;
    QPushButton* InOutQuart = nullptr;
    QPushButton* OutInQuart = nullptr;
    QPushButton* InBack = nullptr;
    QPushButton* OutBack = nullptr;
    QPushButton* InOutBack = nullptr;
    QPushButton* OutInBack = nullptr;
    QPushButton* InQuint = nullptr;
    QPushButton* OutQuint = nullptr;
    QPushButton* InOutQuint = nullptr;
    QPushButton* OutInQuint = nullptr;
    QPushButton* InBounce = nullptr;
    QPushButton* OutBounce = nullptr;
    QPushButton* InOutBounce = nullptr;
    QPushButton* OutInBounce = nullptr;
    QPushButton* InSine = nullptr;
    QPushButton* OutSine = nullptr;
    QPushButton* InOutSine = nullptr;
    QPushButton* OutInSine = nullptr;
    QPushButton* InCurve = nullptr;
    QPushButton* OutCurve = nullptr;
    QPushButton* SineCurve = nullptr;
    QPushButton* CosineCurve = nullptr;
};

#endif // DEMOWIDGET_H

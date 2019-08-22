#include "demowidget.h"
#include "QEasingCurve"
#include "QPropertyAnimation"
#include "QDebug"

DemoWidget::DemoWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    setGeometry(100, 100, 500, 500);
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setStartValue(QRect(100, 100, 500, 500));
    animation->setKeyValueAt(0.5, QRect(300, 300, this->width() + 100, this->height() + 100));
    animation->setEndValue(QRect(100, 100, 500, 500));
    animation->setLoopCount(1);
    animation->setDuration(2000);

    setLayout(layout);
    // create columns for buttons
    QVBoxLayout* firstColLayout = new QVBoxLayout();
    QVBoxLayout* secondColLayout = new QVBoxLayout();
    QVBoxLayout* thirdColLayout = new QVBoxLayout();
    QVBoxLayout* fourthColLayout = new QVBoxLayout();
    layout->addLayout(firstColLayout);
    layout->addLayout(secondColLayout);
    layout->addLayout(thirdColLayout);
    layout->addLayout(fourthColLayout);
    // buttons to each easy curve type
    QPushButton* Linear = new QPushButton("Linear");
    firstColLayout->addWidget(Linear);
    QPushButton* InExpo = new QPushButton("InExpo");
    secondColLayout->addWidget(InExpo);
    QPushButton* OutExpo = new QPushButton("OutExpo");
    thirdColLayout->addWidget(OutExpo);
    QPushButton* InOutExpo = new QPushButton("InOutExpo");
    fourthColLayout->addWidget(InOutExpo);
    QPushButton* OutInExpo = new QPushButton("OutInExpo");
    firstColLayout->addWidget(OutInExpo);
    QPushButton* InQuad = new QPushButton("InQuad");
    secondColLayout->addWidget(InQuad);
    QPushButton* OutQuad = new QPushButton("OutQuad");
    thirdColLayout->addWidget(OutQuad);
    QPushButton* InOutQuad = new QPushButton("InOutQuad");
    fourthColLayout->addWidget(InOutQuad);
    QPushButton* OutInQuad = new QPushButton("OutInQuad");
    QPushButton* InCirc = new QPushButton("InCirc");
    QPushButton* OutCirc = new QPushButton("OutCirc");
    QPushButton* InOutCirc = new QPushButton("InOutCirc");
    QPushButton* OutInCirc = new QPushButton("OutInCirc");
    QPushButton* InCubic = new QPushButton("InCubic");
    QPushButton* OutCubic = new QPushButton("OutCubic");
    QPushButton* InOutCubic = new QPushButton("InOutCubic");
    QPushButton* OutInCubic = new QPushButton("OutInCubic");
    QPushButton* InElastic = new QPushButton("InElastic");
    QPushButton* OutElastic = new QPushButton("OutElastic");
    QPushButton* InOutElastic = new QPushButton("InOutElastic");
    QPushButton* OutInElastic = new QPushButton("OutInElastic");
    QPushButton* InQuart = new QPushButton("InQuart");
    QPushButton* OutQuart = new QPushButton("OutQuart");
    QPushButton* InOutQuart = new QPushButton("InOutQuart");
    QPushButton* OutInQuart = new QPushButton("OutInQuart");
    QPushButton* InBack = new QPushButton("InBack");
    QPushButton* OutBack = new QPushButton("OutBack");
    QPushButton* InOutBack = new QPushButton("InOutBack");
    QPushButton* OutInBack = new QPushButton("OutInBack");
    QPushButton* InQuint = new QPushButton("InQuint");
    QPushButton* OutQuint = new QPushButton("OutQuint");
    QPushButton* InOutQuint = new QPushButton("InOutQuint");
    QPushButton* OutInQuint = new QPushButton("OutInQuint");
    QPushButton* InBounce = new QPushButton("InBounce");
    firstColLayout->addWidget(InBounce);
    QPushButton* OutBounce = new QPushButton("OutBounce");
    secondColLayout->addWidget(OutBounce);
    QPushButton* InOutBounce = new QPushButton("InOutBounce");
    thirdColLayout->addWidget(InOutBounce);
    QPushButton* OutInBounce = new QPushButton("OutInBounce");
    fourthColLayout->addWidget(OutInBounce);
    QPushButton* InSine = new QPushButton("InSine");
    QPushButton* OutSine = new QPushButton("OutSine");
    QPushButton* InOutSine = new QPushButton("InOutSine");
    QPushButton* OutInSine = new QPushButton("OutInSine");
    QPushButton* InCurve = new QPushButton("InCurve");
    QPushButton* OutCurve = new QPushButton("OutCurve");
    QPushButton* SineCurve = new QPushButton("SineCurve");
    QPushButton* CosineCurve = new QPushButton("CosineCurve");
    // connections
    connect(Linear, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::Linear); animation->start();});
    connect(InExpo, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InExpo); animation->start();});
    connect(OutExpo, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutExpo); animation->start();});
    connect(InOutExpo, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutExpo); animation->start();});
    connect(OutInExpo, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInExpo); animation->start();});
    connect(InQuad, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InQuad); animation->start();});
    connect(OutQuad, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutQuad); animation->start();});
    connect(InOutQuad, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutQuad); animation->start();});
    connect(OutInQuad, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInQuad); animation->start();});
    connect(InCirc, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InCirc); animation->start();});
    connect(OutCirc, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutCirc); animation->start();});
    connect(InOutCirc, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutCirc); animation->start();});
    connect(OutInCirc, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInCirc); animation->start();});
    connect(InCubic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InCubic); animation->start();});
    connect(OutCubic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutCubic); animation->start();});
    connect(InOutCubic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutCubic); animation->start();});
    connect(OutInCubic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInCubic); animation->start();});
    connect(InElastic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InElastic); animation->start();});
    connect(OutElastic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutElastic); animation->start();});
    connect(InOutElastic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutElastic); animation->start();});
    connect(OutInElastic, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInElastic); animation->start();});
    connect(InQuart, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InQuart); animation->start();});
    connect(OutQuart, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutQuart); animation->start();});
    connect(InOutQuart, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutQuart); animation->start();});
    connect(OutInQuart, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInQuart); animation->start();});
    connect(InBack, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InBack); animation->start();});
    connect(OutBack, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutBack); animation->start();});
    connect(InOutBack, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutBack); animation->start();});
    connect(OutInBack, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInBack); animation->start();});
    connect(InQuint, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InQuint); animation->start();});
    connect(OutQuint, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutQuint); animation->start();});
    connect(InOutQuint, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutQuint); animation->start();});
    connect(OutInQuint, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInQuint); animation->start();});
    connect(InBounce, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InBounce); animation->start();});
    connect(OutBounce, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutBounce); animation->start();});
    connect(InOutBounce, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutBounce); animation->start();});
    connect(OutInBounce, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInBounce); animation->start();});
    connect(InSine, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InSine); animation->start();});
    connect(OutSine, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutSine); animation->start();});
    connect(InOutSine, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InOutSine); animation->start();});
    connect(OutInSine, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutInSine); animation->start();});
    connect(InCurve, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::InCurve); animation->start();});
    connect(OutCurve, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::OutCurve); animation->start();});
    connect(SineCurve, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::SineCurve); animation->start();});
    connect(CosineCurve, &QPushButton::clicked, [=](){animation->setEasingCurve(QEasingCurve::CosineCurve); animation->start();});
};


DemoWidget::~DemoWidget()
{

}

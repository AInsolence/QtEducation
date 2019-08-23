#include "pullbutton.h"
#include "QLabel"
#include "QHBoxLayout"
#include "QPushButton"
#include "QStateMachine"
#include "QSignalTransition"
#include "QPropertyAnimation"

PullButton::PullButton(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 50);
    //create on/off labels
    QPushButton* OffLabel = new QPushButton("Off");
    QPushButton* OnLabel = new QPushButton("On");
    OffLabel->setFlat(true);
    OnLabel->setFlat(true);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(OnLabel);
    layout->addStretch(1);
    layout->addWidget(OffLabel);
    // create push button
    QPushButton* pushButton = new QPushButton("Push", this);
    pushButton->setAutoFillBackground(true);
    // create state machine with transitions
    QStateMachine* stateMachine = new QStateMachine();
    // off state
    QState* stateOff = new QState(stateMachine);
    QRect rectOff(0, 0, width()/2, height());
    stateOff->assignProperty(pushButton, "geometry", rectOff);
    stateOff->assignProperty(OffLabel, "visible", true);
    stateOff->assignProperty(OnLabel, "visible", false);
    // on state
    QState* stateOn = new QState(stateMachine);
    QRect rectOn(width()/2, 0, width()/2, height());
    stateOn->assignProperty(pushButton, "geometry", rectOn);
    stateOn->assignProperty(OffLabel, "visible", false);
    stateOn->assignProperty(OnLabel, "visible", true);
    // set init state
    stateMachine->setInitialState(stateOff);
    // create Transitions
    QSignalTransition* transitionOfftoOn =
            stateOff->addTransition(pushButton, &QPushButton::clicked, stateOn);
    QSignalTransition* transitionOntoOff =
            stateOn->addTransition(pushButton, &QPushButton::clicked, stateOff);
    QSignalTransition* transitionOfftoOn_2 =
            stateOff->addTransition(OffLabel, &QPushButton::clicked, stateOn);
    QSignalTransition* transitionOntoOff_2 =
            stateOn->addTransition(OnLabel,  &QPushButton::clicked, stateOff);

    // create Animations
    QPropertyAnimation* animOfftoOn =
            new QPropertyAnimation(pushButton, "geometry");
    QPropertyAnimation* animOntoOff =
            new QPropertyAnimation(pushButton, "geometry");
    // connect animations and transitions
    transitionOfftoOn->addAnimation(animOfftoOn);
    transitionOntoOff->addAnimation(animOntoOff);
    transitionOfftoOn_2->addAnimation(animOfftoOn);
    transitionOntoOff_2->addAnimation(animOntoOff);

    animOfftoOn->setDuration(500);
    animOntoOff->setDuration(100);
    animOfftoOn->setEasingCurve(QEasingCurve::OutExpo);
    animOntoOff->setEasingCurve(QEasingCurve::OutExpo);

    stateMachine->start();

    this->setLayout(layout);
}

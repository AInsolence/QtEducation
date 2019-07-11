#include "keysubstitutefilter.h"
#include <QKeyEvent>
#include <QCoreApplication>

keySubstituteFilter::keySubstituteFilter(QObject *parent) : QObject(parent)
{

}

bool keySubstituteFilter::eventFilter(QObject *eventOwner, QEvent *myEvent)
{
    if(myEvent->type() == QEvent::KeyPress){
        if(dynamic_cast<QKeyEvent*>(myEvent)->key() == Qt::Key_Z){
            QKeyEvent keySubs(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, "A");
            QCoreApplication::sendEvent(eventOwner, &keySubs);
            return  true;
        }
    }
    return false;
}

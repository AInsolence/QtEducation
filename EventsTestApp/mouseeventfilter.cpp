#include "mouseeventfilter.h"
#include <QMouseEvent>
#include <QMessageBox>

mouseEventFilter::mouseEventFilter(QObject *parent) : QObject(parent)
{

}

bool mouseEventFilter::eventFilter(QObject* eventOwner, QEvent* myButtonEvent)
{
    if(myButtonEvent->type() == QEvent::MouseButtonPress){
        if(dynamic_cast<QMouseEvent*>(myButtonEvent)->button() == Qt::LeftButton){
            QString widgetName = eventOwner->metaObject()->className();
            QMessageBox::information(nullptr, "Event owner class name", widgetName);
            return true;
        }
    }
    return false;
}

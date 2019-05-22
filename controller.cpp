#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{ 

}

void Controller::IncreaseNumber()
{
    countingNumber += 1;
    emit NumberChanged(countingNumber);
    if(countingNumber == 6)
    {
        emit StopCounting();
    }
}

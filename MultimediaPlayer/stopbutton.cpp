#include "stopbutton.h"

StopButton::StopButton(const QString&& text,
                       QWidget *parent)
    : IPlayerCommand(text, parent)
{
}

void StopButton::slotExecute() const
{
    _mediaPlayer->stop();
}

#include "fullscreenbutton.h"

FullScreenButton::FullScreenButton(const QString&& text,
                       QWidget *parent)
    : ICommonCommand(text, parent)
{
}

void FullScreenButton::slotExecute()
{
    emit signalSetFullScreen();
}

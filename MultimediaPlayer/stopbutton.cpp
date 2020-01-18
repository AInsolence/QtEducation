#include "stopbutton.h"

StopButton::StopButton(const QString& text,
                       QMediaPlayer& mediaPlayer,
                       QWidget *parent)
    : IPlayerCommand(mediaPlayer, text, parent)
{
}

void StopButton::slotExecute()
{
    _mediaPlayer.stop();
}

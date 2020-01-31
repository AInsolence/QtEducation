#include "nextbutton.h"
#include <QMediaPlaylist>

NextButton::NextButton(const QString&& text,
                       QWidget *parent)
    : IPlayerCommand(text, parent)
{
}

void NextButton::slotExecute() const
{
    _mediaPlayer->playlist()->next();
}

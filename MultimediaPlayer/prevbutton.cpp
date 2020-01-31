#include "prevbutton.h"
#include <QMediaPlaylist>

PrevButton::PrevButton(const QString&& text,
                       QWidget *parent)
    : IPlayerCommand(text, parent)
{
}

void PrevButton::slotExecute() const
{
    _mediaPlayer->playlist()->previous();
}

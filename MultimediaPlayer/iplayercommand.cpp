#include "iplayercommand.h"

IPlayerCommand::IPlayerCommand(QMediaPlayer& mediaPlayer,
                               const QString& text,
                               QWidget *parent) :
    QPushButton(text, parent),
    _mediaPlayer(mediaPlayer)
{
    connect(this, &QPushButton::clicked, this, &IPlayerCommand::slotExecute);
}

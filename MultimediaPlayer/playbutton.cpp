#include "playbutton.h"

PlayButton::PlayButton(const QString&& text,
                       QMediaPlayer& mediaPlayer,
                       QWidget *parent)
    : IPlayerCommand(mediaPlayer, text, parent)
{
}

void PlayButton::slotExecute() const
{
    switch (_mediaPlayer.state()) {
        case QMediaPlayer::PlayingState:
            _mediaPlayer.pause();
            break;
        default:
            _mediaPlayer.play();
            break;
        }
}

#include "pausebutton.h"

PauseButton::PauseButton(const QString&& text,
                       QMediaPlayer& mediaPlayer,
                       QWidget *parent)
    : IPlayerCommand(mediaPlayer, text, parent)
{
}

void PauseButton::slotExecute() const
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

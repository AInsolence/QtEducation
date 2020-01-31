#include "pausebutton.h"

PauseButton::PauseButton(const QString&& text,
                       QWidget *parent)
    : IPlayerCommand(text, parent)
{
}

void PauseButton::slotExecute() const
{
    switch (_mediaPlayer->state()) {
        case QMediaPlayer::PlayingState:
            _mediaPlayer->pause();
            break;
        default:
            _mediaPlayer->play();
        break;
    }
}

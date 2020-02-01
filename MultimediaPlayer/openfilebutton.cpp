#include "openfilebutton.h"
#include <QFileDialog>

OpenFileButton::OpenFileButton(const QString&& text,
                       QMediaPlayer& mediaPlayer,
                       QWidget *parent)
    : ICommonCommand(text, parent),
      _mediaPlayer(mediaPlayer)
{
}

void OpenFileButton::slotExecute()
{
    const QString fileName = QFileDialog::getOpenFileName();

    if(!fileName.isEmpty()){
        emit signalAddFileToPlaylist(fileName);
    }
}

#include "openfilebutton.h"
#include <QFileDialog>

OpenFileButton::OpenFileButton(const QString&& text,
                       QMediaPlayer& mediaPlayer,
                       QLabel& fileNameLabel,
                       QWidget *parent)
    : ICommonCommand(text, parent),
      _mediaPlayer(mediaPlayer),
      _fileNameLabel(fileNameLabel)
{
}

QString OpenFileButton::getLastFileOpened() const
{
    return _lastFileOpened;
}

void OpenFileButton::setLastFileOpened(const QString& fileName)
{
    _lastFileOpened = fileName;
}

void OpenFileButton::slotExecute()
{
    const QString fileName = QFileDialog::getOpenFileName();

    if(!fileName.isEmpty()){
        emit signalAddFileToPlaylist(fileName);
        // TODO change it if playlist will be
        setLastFileOpened(fileName);
        // get song name to show
        QStringList nameParse = fileName.split("/");
        _fileNameLabel.setText(nameParse[nameParse.length() - 1]);
    }
}

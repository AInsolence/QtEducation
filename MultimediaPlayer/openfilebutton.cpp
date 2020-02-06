#include "openfilebutton.h"
#include <QFileDialog>

OpenFileButton::OpenFileButton(const QString&& text,
                       QWidget *parent)
    : ICommonCommand(text, parent)
{
}

void OpenFileButton::slotExecute()
{
    const QString fileName = QFileDialog::getOpenFileName();

    if(!fileName.isEmpty()){
        emit signalAddFileToPlaylist(fileName);
    }
}

void OpenFileButton::slotOpenFolder()
{
    const QString dirName = QFileDialog::getExistingDirectory();

    if(!dirName.isEmpty()){
        emit signalAddFileToPlaylist(dirName);
    }
}

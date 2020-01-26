#include "playlistwidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include "mediaplayer.h"

PlaylistWidget::PlaylistWidget(QWidget *parent) : QListView(parent)
{
    setAcceptDrops(true);
    setModel(&_playlistModel);
}

void PlaylistWidget::dragMoveEvent(QDragMoveEvent *eventDragMove)
{
        eventDragMove->accept();
}

void PlaylistWidget::dragEnterEvent(QDragEnterEvent *eventDrag)
{
        eventDrag->acceptProposedAction();
}

void PlaylistWidget::dropEvent(QDropEvent *eventDrop)
{
    // get text (or other object) from mimeData object
    auto urls = eventDrop->mimeData()->urls();
    // make manipulations with dragged object
    QStringList list = _playlistModel.stringList();
    for (auto url : urls){
        QString localPath = url.toLocalFile();
        QFileInfo info(localPath);
        if(info.isDir()){
            //qDebug() << "Directory: " << localPath;
            list.append(_scanDirectory(localPath, MediaPlayer::_supportedFormats));
        }
        else{
            list.append(localPath);
        }
    }

    _playlistModel.setStringList(list);
}

QStringList PlaylistWidget::_scanDirectory(const QString& dirPath,
                                           const QStringList& filters) const
{
    QStringList result;
    QDirIterator it(dirPath, filters, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        result << it.next();
    }
    return result;
}


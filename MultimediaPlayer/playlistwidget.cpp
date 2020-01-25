#include "playlistwidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

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
//    if(!eventDrag->mimeData()->formats().filter("audio/").empty() ||
//       !eventDrag->mimeData()->formats().filter("video/").empty())
    {
        eventDrag->acceptProposedAction();
    }
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
            qDebug() << "Directory: " << localPath;
            list.append(_scanDirectory(localPath, QStringList() << "*.mp3"));
        }
        else{
            list.append(localPath);
        }
    }

    _playlistModel.setStringList(list);
    qDebug() << "Dropped music: " << eventDrop->mimeData()->formats();
    qDebug() << "Dropped text: " << list;
    qDebug() << "Dropped urls: " << eventDrop->mimeData()->hasUrls();
}

QStringList PlaylistWidget::_scanDirectory(const QString& dirPath,
                                           const QStringList& filters) const
{
    QStringList result;
    QDirIterator it(dirPath, filters, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        result << it.next();
        qDebug() << result << "/n";
    }
    return result;
}

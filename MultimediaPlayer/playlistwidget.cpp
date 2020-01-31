#include "playlistwidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include "mediaplayer.h"
#include "listviewitemdelegate.h"

PlaylistWidget::PlaylistWidget(QWidget *parent) : QListView(parent)
{
    ListViewItemDelegate* delegate = new ListViewItemDelegate(this);

    setAcceptDrops(true);
    setModel(&_playlistModel);
    setEditTriggers(NoEditTriggers);
    setItemDelegate(delegate);

    playlist.setPlaybackMode(QMediaPlaylist::Sequential);

    // connections
    connect(&_playlistModel, &QStringListModel::dataChanged,
                    this, &PlaylistWidget::slotRefreshPlaylist);

    connect(this, &PlaylistWidget::doubleClicked,
            this, &PlaylistWidget::slotSetNewMediaToPlay);
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
    slotRefreshPlaylist();
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

void PlaylistWidget::slotSetNewMediaToPlay(const QModelIndex &index)
{
    playlist.setCurrentIndex(index.row());
    emit signalPlayFromPlaylist();
}

void PlaylistWidget::slotRefreshPlaylist()
{
    QStringList playlistItems = _playlistModel.stringList();
    playlist.clear();// reset playlist
    for(auto filePath : playlistItems){
        playlist.addMedia(QUrl::fromLocalFile(filePath));
    }
}


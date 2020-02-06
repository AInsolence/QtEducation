#include "playlistwidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QVBoxLayout>
#include "mediaplayer.h"
#include "listviewitemdelegate.h"
#include "openfilebutton.h"

QModelIndex* PlaylistWidget::_currentIndex = nullptr;

PlaylistWidget::PlaylistWidget(QWidget *parent) : QListView(parent)
{
    auto delegate = new ListViewItemDelegate(this);
    setMinimumHeight(200);

    setAcceptDrops(true);
    setSelectionMode(QAbstractItemView::NoSelection);
//    setDragEnabled(true);
//    viewport()->setAcceptDrops(true);
//    setDragDropMode(QAbstractItemView::InternalMove);
//    setDropIndicatorShown(true);

//    setSelectionBehavior(QAbstractItemView::SelectRows);

    setModel(&_playlistModel);
    setEditTriggers(NoEditTriggers);
    setItemDelegate(delegate);

    _playlist.setPlaybackMode(QMediaPlaylist::Sequential);

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
    const auto& urls = eventDrop->mimeData()->urls();
    // make manipulations with dragged object
    QStringList list = _playlistModel.stringList();
    for (const auto& url : urls){
        const QString& localPath = url.toLocalFile();
        QFileInfo info(localPath);
        if(info.isDir()){
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
    _currentIndex = &const_cast<QModelIndex&>(index);
    _playlist.setCurrentIndex(index.row());
    emit signalPlayFromPlaylist();
}

void PlaylistWidget::slotAddNewTracks(const QString &filePath)
{
    // make manipulations with opened object
    QStringList list = _playlistModel.stringList();
    QFileInfo info(filePath);
    if(info.isFile()){
        list.append(filePath);
        _playlistModel.setStringList(list);
        slotRefreshPlaylist();
    }
    else{
        list.append(_scanDirectory(filePath, MediaPlayer::_supportedFormats));
        _playlistModel.setStringList(list);
        slotRefreshPlaylist();
    }
}

void PlaylistWidget::slotRefreshPlaylist()
{
    QStringList playlistItems = _playlistModel.stringList();
    _playlist.clear();// reset _playlist
    for(const auto& filePath : playlistItems){
        _playlist.addMedia(QUrl::fromLocalFile(filePath));
    }
}


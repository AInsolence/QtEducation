#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QListView>
#include <QStringListModel>
#include <QDir>
#include <QMediaPlaylist>

class QMediaPlayer;

class PlaylistWidget : public QListView
{
    Q_OBJECT
public:
    explicit PlaylistWidget(QWidget *parent = nullptr);
    inline QMediaPlaylist& getMediaPlaylist(){return _playlist;}
    static QModelIndex* _currentIndex;
protected:
    virtual void dragMoveEvent(QDragMoveEvent *eventDragMove) override;
    virtual void dragEnterEvent(QDragEnterEvent* eventDrag) override;
    virtual void dropEvent(QDropEvent* eventDrop) override;
private:
    QStringListModel _playlistModel;
    QStringList _scanDirectory(const QString& dirPath,
                               const QStringList& filters) const;
    QMediaPlaylist _playlist;
signals:
    void signalPlayFromPlaylist();
private slots:
    void slotRefreshPlaylist();
    void slotSetNewMediaToPlay(const QModelIndex& index);
public slots:
    void slotAddNewTracks(const QString& filePath);

};

#endif // PLAYLISTWIDGET_H

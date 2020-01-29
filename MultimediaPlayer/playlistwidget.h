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
    inline QMediaPlaylist& getMediaPlaylist(){return playlist;}
protected:
    //virtual void mousePressEvent(QMouseEvent* eventPress) override;
    virtual void dragMoveEvent(QDragMoveEvent *eventDragMove) override;
    virtual void dragEnterEvent(QDragEnterEvent* eventDrag) override;
    virtual void dropEvent(QDropEvent* eventDrop) override;
private:
    QStringListModel _playlistModel;
    QStringList _scanDirectory(const QString& dirPath,
                               const QStringList& filters) const;
    QMediaPlaylist playlist;

signals:
    void signalPlayFromPlaylist();
private slots:
    void slotRefreshPlaylist();
    void slotSetNewMediaToPlay(const QModelIndex& index);
};

#endif // PLAYLISTWIDGET_H

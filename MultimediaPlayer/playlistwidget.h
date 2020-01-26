#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QListView>
#include <QStringListModel>
#include <QDir>

class PlaylistWidget : public QListView
{
    Q_OBJECT
public:
    explicit PlaylistWidget(QWidget *parent = nullptr);
protected:
    //virtual void mousePressEvent(QMouseEvent* eventPress) override;


    virtual void dragMoveEvent(QDragMoveEvent *eventDragMove) override;
    virtual void dragEnterEvent(QDragEnterEvent* eventDrag) override;
    virtual void dropEvent(QDropEvent* eventDrop) override;
private:
    QStringListModel _playlistModel;
    QStringList _scanDirectory(const QString& dirPath,
                               const QStringList& filters) const;
};

#endif // PLAYLISTWIDGET_H

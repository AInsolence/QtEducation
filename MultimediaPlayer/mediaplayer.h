#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include "playerwidget.h"
#include "playlistwidget.h"

class MediaPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit MediaPlayer();
    virtual ~MediaPlayer();

    static QStringList _supportedFormats;

private:
    QVector<QWidget*> components;
    PlayerWidget* playerWidget = nullptr;
    PlaylistWidget* playlistWidget = nullptr;
};

#endif // MEDIAPLAYER_H

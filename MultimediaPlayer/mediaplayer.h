#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include "playerwidget.h"
#include "playlistwidget.h"

class MediaPlayer : public QObject
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
    QWidget* videoCanvas = nullptr;
signals:
    void signalThat();
};

#endif // MEDIAPLAYER_H

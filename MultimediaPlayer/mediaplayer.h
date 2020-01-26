#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "playerwidget.h"
#include "playlistwidget.h"

class MediaPlayer : QObject
{
    Q_OBJECT
public:
    explicit MediaPlayer();
    virtual ~MediaPlayer();
    static QStringList _supportedFormats;
private:
    QVector<QWidget*> components;
    QWidget* playerWidget = nullptr;
    QWidget* playlistWidget = nullptr;
    QWidget* videoCanvas = nullptr;
};

#endif // MEDIAPLAYER_H

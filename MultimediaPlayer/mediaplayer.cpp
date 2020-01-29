#include "mediaplayer.h"
#include <QFile>

QStringList MediaPlayer::_supportedFormats;

MediaPlayer::MediaPlayer()
{//TODO set layout for all components
    playerWidget = new PlayerWidget();
    components.push_back(playerWidget);

    playlistWidget = new PlaylistWidget();
    components.push_back(playlistWidget);
    // set playlist
    playerWidget->setPlaylist(playlistWidget->getMediaPlaylist());

    //videoCanvas = nullptr;

    for(auto component : components){
        // style
        QFile styleFile(":/style/style.qss");
        if(styleFile.open(QFile::ReadOnly)){
            QString style (styleFile.readAll());
            component->setStyleSheet(style);
        }
        else {
            qDebug() << "Cannot open style.qss file";
        }
        //component->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
        component->show();
    }
    // settings
    QFile supportedFormats(":/supportedFormats.txt");
    if(supportedFormats.open(QIODevice::ReadOnly | QIODevice::Text)){
        while(!supportedFormats.atEnd()){
            MediaPlayer::_supportedFormats.append("*" + supportedFormats.readLine().simplified());
        }
    }
    // connections
    connect(playlistWidget, &PlaylistWidget::signalPlayFromPlaylist,
            playerWidget, &PlayerWidget::slotPlay);
}

MediaPlayer::~MediaPlayer()
{
}

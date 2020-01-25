#include "mediaplayer.h"
#include <QFile>

MediaPlayer::MediaPlayer()
{//TODO set layout for all components
    playerWidget = new PlayerWidget();
    components.push_back(playerWidget);

    playlistWidget = new PlaylistWidget();
    components.push_back(playlistWidget);
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
}

MediaPlayer::~MediaPlayer()
{
}

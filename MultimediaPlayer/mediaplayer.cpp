#include "mediaplayer.h"
#include <QFile>
#include <QStyleFactory>
#include <QKeyEvent>
#include "myapplication.h"
#include <QVideoWidget>
#include "fullscreenbutton.h"

QStringList MediaPlayer::_supportedFormats;

MediaPlayer::MediaPlayer()
{
    setMinimumWidth(500);
    // video screen
    videoScreen = new VideoWidget(this);
    int videoMinimimHeight = 280;
    videoScreen->setMinimumHeight(videoMinimimHeight);
    videoScreen->hide();
    components.push_back(videoScreen);
    // player
    playerWidget = new PlayerWidget(this);
    components.push_back(playerWidget);
    playlistWidget = new PlaylistWidget(this);
    components.push_back(playlistWidget);
    playerWidget->setPlaylist(playlistWidget->getMediaPlaylist());
    playerWidget->getMediaPlayer().setVideoOutput(videoScreen);
    // layout
    auto layout = new QVBoxLayout(this);
    setLayout(layout);

    for(auto component : components){
        // set style
        QFile styleFile(":/style/style.qss");
        if(styleFile.open(QFile::ReadOnly)){
            QString style (styleFile.readAll());
            component->setStyleSheet(style);
        }
        else {
            qDebug() << "Cannot open style.qss file";
        }
        layout->addWidget(component);// set layout
    }
    // settings
    QFile supportedFormats(":/supportedFormats.txt");
    if(supportedFormats.open(QIODevice::ReadOnly | QIODevice::Text)){
        while(!supportedFormats.atEnd()){
            _supportedFormats.append("*" + supportedFormats.readLine().simplified());
        }
    }
    // connections
    connect(playlistWidget, &PlaylistWidget::signalPlayFromPlaylist,
            playerWidget, &PlayerWidget::slotPlay);
    connect(playerWidget->getOpenFileButton(), &OpenFileButton::signalAddFileToPlaylist,
            playlistWidget, &PlaylistWidget::slotAddNewFile);
    // video connections
    connect(&playerWidget->getMediaPlayer(), &QMediaPlayer::durationChanged,
            this, &MediaPlayer::slotIsVideoAvailable);
    connect(playerWidget->getFullScreenButton(), &FullScreenButton::signalSetFullScreen,
            this, [&](){
                        if(playerWidget->getMediaPlayer().isVideoAvailable()){
                            if (!videoScreen->isFullScreen()){
                                videoScreen->setFullScreen(true);
                            }
                      }
    });


    // set style
    MyApplication::setStyle(QStyleFactory::create("fusion"));

    show();
}

MediaPlayer::~MediaPlayer()
{
    delete playerWidget;
    delete playlistWidget;
    delete videoScreen;
}

void MediaPlayer::slotIsVideoAvailable()
{
    if(playerWidget->getMediaPlayer().isVideoAvailable()){
        videoScreen->show();
    }
    else {
        videoScreen->hide();
        this->resize(300, 150);
    }
}

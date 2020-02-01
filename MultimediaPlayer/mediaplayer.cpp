#include "mediaplayer.h"
#include <QFile>
#include <QStyleFactory>
#include "myapplication.h"

QStringList MediaPlayer::_supportedFormats;

MediaPlayer::MediaPlayer()
{
    setMinimumWidth(500);
    playerWidget = new PlayerWidget(this);
    components.push_back(playerWidget);

    playlistWidget = new PlaylistWidget(this);
    components.push_back(playlistWidget);
    // set playlist
    playerWidget->setPlaylist(playlistWidget->getMediaPlaylist());

    auto layout = new QVBoxLayout(this);
    setLayout(layout);

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
        layout->addWidget(component);
        component->show();
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
    // set style
    MyApplication::setStyle(QStyleFactory::create("fusion"));

    show();
}

MediaPlayer::~MediaPlayer()
{
    delete playerWidget;
    delete playlistWidget;
}

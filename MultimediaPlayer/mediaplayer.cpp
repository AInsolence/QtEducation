#include "mediaplayer.h"
#include <QFile>
#include <QStyleFactory>
#include <QKeyEvent>
#include "myapplication.h"
#include <QVideoWidget>
#include <QSplitter>
#include <QMenuBar>
#include "fullscreenbutton.h"
#include "openfilebutton.h"

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
    // menuBar
    auto menuBar = new QMenuBar(this);
    menuBar->setFixedHeight(24);
    auto playlistMenu = new QMenu("+", this);
    auto openFile = new QAction("Add file ...");
    auto openFolder = new QAction("Add folder ...");
    playlistMenu->addAction(openFile);
    playlistMenu->addAction(openFolder);

    menuBar->addMenu(playlistMenu);
    components.push_back(menuBar);
    // layout
    auto layout = new QVBoxLayout(this);
    setLayout(layout);
    auto splitter = new QSplitter(Qt::Vertical);
    layout->addWidget(splitter);

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
        splitter->addWidget(component);// set layout
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
            playlistWidget, &PlaylistWidget::slotAddNewTracks);
    // playlist menu connections
    connect(openFile, &QAction::triggered,
            playerWidget->getOpenFileButton(), &ICommonCommand::slotExecute);
    connect(openFolder, &QAction::triggered,
            playerWidget->getOpenFileButton(), &OpenFileButton::slotOpenFolder);
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

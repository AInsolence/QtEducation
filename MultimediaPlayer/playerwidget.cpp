#include "playerwidget.h"
#include <QSlider>
#include <QLabel>
#include <QTime>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QSessionManager>
#include "myapplication.h"
#include "playbutton.h"
#include "stopbutton.h"
#include "pausebutton.h"
#include "prevbutton.h"
#include "nextbutton.h"
#include <QModelIndex>
#include <QFileInfo>

PlayerWidget::PlayerWidget(QWidget *parent)
    : QWidget(parent)
{
    mediaPlayer.setParent(this);
    //
    videoScreen.setParent(this);
    videoScreen.setMinimumHeight(300);
    videoScreen.hide();
    mediaPlayer.setVideoOutput(&videoScreen);

    // main window controls

    setWindowTitle("Media Player v0.3");
    // info items init
    durationSlider = new QSlider(Qt::Horizontal, this);
    durationTime = new QToolButton(this);
    durationTime->setText("00:00::00");
    durationTime->setMinimumWidth(100);
    durationTime->setObjectName("durationTime");
    fileNameLabel = new QLabel("", this);
    // player controls init TODO check optimal constructor
    playButton = new PlayButton("|>", this);
    pauseButton = new PauseButton(" || ", this);
    stopButton = new StopButton(QString::fromWCharArray(L"\u23F9"), this);
    prevButton = new PrevButton("<<", this);
    nextButton = new NextButton(">>", this);

    openFileButton = new OpenFileButton(" ^ ", this->mediaPlayer, this);

    fullScreenButton = new QToolButton(this);
    fullScreenButton->setText("<->");

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setMinimumWidth(150);
    // layout
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addWidget(&videoScreen, 2, 0, 1, 11);

    mainLayout->addWidget(fileNameLabel, 3, 1, 1, 6);
    mainLayout->addWidget(durationTime, 3, 9, 1, 3);

    mainLayout->addWidget(durationSlider, 4, 1, 1, 8);
    mainLayout->addWidget(openFileButton, 4, 10, 1, 1);

    mainLayout->addWidget(prevButton, 5, 1, 1, 1);
    mainLayout->addWidget(playButton, 5, 2, 1, 1);
    mainLayout->addWidget(pauseButton, 5, 3, 1, 1);
    mainLayout->addWidget(stopButton, 5, 4, 1, 1);
    mainLayout->addWidget(nextButton, 5, 5, 1, 1);

    mainLayout->addWidget(volumeSlider, 5, 6, 1, 3);
    mainLayout->addWidget(fullScreenButton, 5, 10, 1, 1);

    // track info in label connection
    connect(&mediaPlayer, &QMediaPlayer::currentMediaChanged, this, [=](const QMediaContent& track){
        auto trackName = QFileInfo(track.canonicalUrl().toString()).fileName();
        fileNameLabel->setText(trackName);
    });
    // volume slider connect
    connect(volumeSlider, &QSlider::valueChanged, this, &PlayerWidget::slotSetVolume);
    // duration slider connections
    connect(&mediaPlayer, &QMediaPlayer::durationChanged, this, &PlayerWidget::slotSetDuration);
    connect(&mediaPlayer, &QMediaPlayer::positionChanged, this, &PlayerWidget::slotSetSliderPosition);
    connect(durationSlider, &QSlider::sliderMoved, this, &PlayerWidget::slotSetMediaPosition);
    connect(durationTime, &QPushButton::clicked, this, &PlayerWidget::slotChangeDurationInfo);
    // video connections
    connect(&mediaPlayer, &QMediaPlayer::durationChanged, this, &PlayerWidget::slotIsVideoAvailable);
    connect(fullScreenButton, &QToolButton::clicked, this, &PlayerWidget::slotToFullScreen);

    ensurePolished();

    setLayout(mainLayout);
    /// SETTINGS
    slotReadSettings();
    // set previous file as a current media
    if(!openFileButton->getLastFileOpened().isEmpty()){
        mediaPlayer.setMedia(QUrl::fromLocalFile(openFileButton->getLastFileOpened()));
        mediaPlayer.setPosition(lastFilePosition);
        // get song name to show
        QStringList nameParse = openFileButton->getLastFileOpened().split("/");
        fileNameLabel->setText(nameParse[nameParse.length() - 1]);

        playButton->setEnabled(true);
        pauseButton->setEnabled(true);
        stopButton->setEnabled(true);
    }
    connect(MyApplication::getApp(), &QApplication::commitDataRequest,
            this, &PlayerWidget::slotWriteSettings);
    connect(MyApplication::getApp(), &QApplication::commitDataRequest,
            [](QSessionManager& sm){
                sm.setRestartHint(QSessionManager::RestartAnyway);
    });
}

PlayerWidget::~PlayerWidget()
{
    // ?? parent widget controlled ?? TODO
    // controls
    delete playButton;
    delete pauseButton;
    delete stopButton;
    delete prevButton;
    delete nextButton;
    delete openFileButton;
    delete fullScreenButton;
    // info items
    delete volumeSlider;
    delete durationSlider;
    delete durationTime;
    delete fileNameLabel;
    // layouts
    delete mainLayout;
    delete titleLayout;
}

void PlayerWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Escape:
            if (videoScreen.isFullScreen()){
                    videoScreen.showNormal();
                    videoScreen.setFullScreen(false);
                    qDebug() << "Escape pressed";
            }
            break;
        default:
            break;
    }
}

void PlayerWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    slotWriteSettings();
}

QString PlayerWidget::msecToTimeString(qint64 duration)
{
    qint64 hours = duration/(60*60*1000);
    qint64 minutes = (duration%(60*60*1000))/(60*1000);
    qint64 seconds = duration%(60*1000)/1000;

    return QTime(static_cast<int>(hours),
                 static_cast<int>(minutes),
                 static_cast<int>(seconds)).toString("hh:mm:ss");
}

void PlayerWidget::setDurationTime(qint64 pos)
{
    if(bIsDurationTime){
        durationTime->setText(msecToTimeString(pos));
    }
    else{
        durationTime->setText(msecToTimeString(durationSlider->maximum() - pos));
    }
}

void PlayerWidget::slotPlay()
{
    mediaPlayer.play();
}

void PlayerWidget::slotSetMediaPosition(qint64 pos)
{
    mediaPlayer.setPosition(pos);
    setDurationTime(pos);
}

void PlayerWidget::slotSetSliderPosition(qint64 pos)
{
    durationSlider->setValue(static_cast<int>(pos));
    setDurationTime(pos);
}

void PlayerWidget::slotSetVolume(qint64 value)
{
    mediaPlayer.setVolume(static_cast<int>(value));
}

void PlayerWidget::slotSetDuration(qint64 duration)
{
    durationSlider->setRange(0, static_cast<int>(duration));
    setDurationTime(0);
}

void PlayerWidget::slotChangeDurationInfo()
{
    if(bIsDurationTime){
        bIsDurationTime = false;
    }
    else{
        bIsDurationTime = true;
    }
}

void PlayerWidget::slotIsVideoAvailable()
{
    if(mediaPlayer.isVideoAvailable()){
        videoScreen.show();
    }
    else {
        videoScreen.hide();
        this->resize(300, 150);
    }
}

void PlayerWidget::slotToFullScreen()
{
    if(mediaPlayer.isVideoAvailable()){
        if (!videoScreen.isFullScreen()){
            videoScreen.setFullScreen(true);
        }
        else{
            videoScreen.showNormal();
            videoScreen.setFullScreen(false);
        }
    }
}

void PlayerWidget::slotReadSettings()
{
    QSettings* settings = MyApplication::getApp()->settings();
    settings->beginGroup("/Settings");

    openFileButton->setLastFileOpened(settings->value("/currentFile", "").toString());
    lastFilePosition =
                settings->value("/currentTime", "0").toLongLong();
    volumeSlider->setValue(
                settings->value("/volume", volumeSlider->value()).toInt());
    bIsDurationTime = settings->value("/bIsDurationTime", "true").toBool();

    settings->endGroup();
}

void PlayerWidget::slotWriteSettings()
{
    QSettings* settings = MyApplication::getApp()->settings();
    settings->beginGroup("/Settings");

    settings->setValue("/currentFile", openFileButton->getLastFileOpened());
    settings->setValue("/currentTime", mediaPlayer.position());
    settings->setValue("/volume", volumeSlider->value());
    settings->setValue("/bIsDurationTime", bIsDurationTime);

    settings->endGroup();
}

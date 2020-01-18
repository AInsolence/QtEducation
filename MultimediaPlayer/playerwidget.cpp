#include "playerwidget.h"
#include <QPushButton>
#include <QToolButton>
#include <QSlider>
#include <QLabel>
#include <QLayout>
#include <QFileDialog>
#include <QTime>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QSessionManager>
#include "myapplication.h"
#include "playbutton.h"
#include "stopbutton.h"
#include "pausebutton.h"
#include "openfilebutton.h"

playerWidget::playerWidget(QWidget *parent)
    : QWidget(parent)
{
    mediaPlayer = new QMediaPlayer(this);
    //
    videoScreen = new QVideoWidget(this);
    videoScreen->setMinimumHeight(300);
    videoScreen->hide();
    mediaPlayer->setVideoOutput(videoScreen);

    // main window controls
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    titlebarWidget = new QWidget(this);
    titlebarWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    titlebarWidget->setObjectName("titleBar");
    QGridLayout* titleLayout = new QGridLayout(this);
    titleLayout->setSpacing(0);
    titleLayout->setMargin(0);
    titlebarWidget->setLayout(titleLayout);

    setWindowTitle("Media Player v0.1");
    playerWindowTitle = new QLabel(titlebarWidget);
    playerWindowTitle->setObjectName("playerTitle");
    playerWindowTitle->setText(this->windowTitle());

    QToolButton* shutdownButton = new QToolButton(this);
    shutdownButton->setText("X");
    QToolButton* maximizeButton = new QToolButton(this);
    maximizeButton->setText("|_|");
    QToolButton* minimizeButton = new QToolButton(this);
    minimizeButton->setText("_");


    //titleLayout->addWidget(new QLabel("Icon"), 0, 0, 1, 1);
    titleLayout->addWidget(playerWindowTitle, 0, 1, 1, 8);
    titleLayout->addWidget(minimizeButton, 0, 9, 1, 1);
    titleLayout->addWidget(maximizeButton, 0, 10, 1, 1);
    titleLayout->addWidget(shutdownButton, 0, 11, 1, 1);
    // info items init
    durationSlider = new QSlider(Qt::Horizontal, this);
    durationTime = new QToolButton(this);
    durationTime->setText("00:00::00");
    durationTime->setMinimumWidth(100);
    durationTime->setObjectName("durationTime");
    fileNameLabel = new QLabel("", this);
    // player controls init
    playButton = new PlayButton("&Play", *this->mediaPlayer, this);
    pauseButton = new PauseButton(" || ", *this->mediaPlayer, this);
    stopButton = new StopButton("&stop", *this->mediaPlayer, this);
    openFileButton = new OpenFileButton("&stop", *this->mediaPlayer, *fileNameLabel, this);
    openFileButton->setText(" ^ ");
    openFileButton->setMinimumWidth(40);
    fullScreenButton = new QToolButton(this);
    fullScreenButton->setText("<->");
    fullScreenButton->setMinimumWidth(40);

    playButton->setEnabled(false);
    pauseButton->setEnabled(false);
    stopButton->setEnabled(false);

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setMinimumWidth(150);

    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addWidget(titlebarWidget, 0, 0, 1, 12);

    mainLayout->addWidget(videoScreen, 2, 0, 1, 12);

    mainLayout->addWidget(fileNameLabel, 3, 1, 1, 6);
    mainLayout->addWidget(durationTime, 3, 9, 1, 3);

    mainLayout->addWidget(durationSlider, 4, 1, 1, 8);
    mainLayout->addWidget(openFileButton, 4, 10, 1, 1);

    mainLayout->addWidget(playButton, 5, 1, 1, 1);
    mainLayout->addWidget(pauseButton, 5, 2, 1, 1);
    mainLayout->addWidget(stopButton, 5, 3, 1, 1);
    mainLayout->addWidget(volumeSlider, 5, 6, 1, 3);
    mainLayout->addWidget(fullScreenButton, 5, 10, 1, 1);

    // main controls connections
    connect(shutdownButton, &QToolButton::clicked, this, &playerWidget::close);
    connect(minimizeButton, &QToolButton::clicked, [=](){this->setWindowState(Qt::WindowMinimized);});
    connect(maximizeButton, &QToolButton::clicked, this, &playerWidget::slotMaximized);
    // volume slider connect
    connect(volumeSlider, &QSlider::valueChanged, this, &playerWidget::slotSetVolume);
    // duration slider connections
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &playerWidget::slotSetDuration);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &playerWidget::slotSetSliderPosition);
    connect(durationSlider, &QSlider::sliderMoved, this, &playerWidget::slotSetMediaPosition);
    connect(durationTime, &QPushButton::clicked, this, &playerWidget::slotChangeDurationInfo);
    // video connections
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &playerWidget::slotIsVideoAvailable);
    connect(fullScreenButton, &QToolButton::clicked, this, &playerWidget::slotToFullScreen);
    // style
    QFile styleFile(":/style/style.qss");
    if(styleFile.open(QFile::ReadOnly)){
        QString style (styleFile.readAll());
        setStyleSheet(style);
    }
    else {
        qDebug() << "Cannot open style.qss file";
    }

    ensurePolished();

    setLayout(mainLayout);
    /// SETTINGS
    slotReadSettings();
    // set previous file as a current media
    if(!openFileButton->getLastFileOpened().isEmpty()){
        mediaPlayer->setMedia(QUrl::fromLocalFile(openFileButton->getLastFileOpened()));
        mediaPlayer->setPosition(lastFilePosition);
        // get song name to show
        QStringList nameParse = openFileButton->getLastFileOpened().split("/");
        fileNameLabel->setText(nameParse[nameParse.length() - 1]);

        playButton->setEnabled(true);
        pauseButton->setEnabled(true);
        stopButton->setEnabled(true);
    }
    connect(MyApplication::getApp(), &QApplication::commitDataRequest,
            this, &playerWidget::slotWriteSettings);
    connect(MyApplication::getApp(), &QApplication::commitDataRequest,
            [](QSessionManager& sm){
                sm.setRestartHint(QSessionManager::RestartAnyway);
    });
}

playerWidget::~playerWidget()
{
}

void playerWidget::mouseMoveEvent(QMouseEvent *event)
{
        if( event->buttons().testFlag(Qt::LeftButton) && bIsMovingAvailable) {
            this->move(event->globalPos() - dragPosition);
          }
}

void playerWidget::mousePressEvent(QMouseEvent *event)
{
    if(titlebarWidget->underMouse() || playerWindowTitle->underMouse()){
            bIsMovingAvailable = true;
            dragPosition = event->globalPos() - frameGeometry().topLeft();
      }
}

void playerWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        bIsMovingAvailable = false;
    }
}

void playerWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if(titlebarWidget->underMouse() && playerWindowTitle->underMouse()){
            slotMaximized();
      }
    if(videoScreen->underMouse()){
        slotToFullScreen();
    }
}

void playerWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Escape:
            if (videoScreen->isFullScreen()){
                    videoScreen->showNormal();
                    videoScreen->setFullScreen(false);
                    qDebug() << "Escape pressed";
            }
            break;
        default:
            break;
    }
}

void playerWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    slotWriteSettings();
}

QString playerWidget::msecToTimeString(qint64 duration)
{
    qint64 hours = duration/(60*60*1000);
    qint64 minutes = (duration%(60*60*1000))/(60*1000);
    qint64 seconds = duration%(60*1000)/1000;

    return QTime(static_cast<int>(hours),
                 static_cast<int>(minutes),
                 static_cast<int>(seconds)).toString("hh:mm:ss");
}

void playerWidget::setDurationTime(qint64 pos)
{
    if(bIsDurationTime){
        durationTime->setText(msecToTimeString(pos));
    }
    else{
        durationTime->setText(msecToTimeString(durationSlider->maximum() - pos));
    }
}

void playerWidget::slotMaximized()
{
    if (this->windowState() == Qt::WindowNoState){
        if(mediaPlayer->isVideoAvailable()){
            this->setWindowState(Qt::WindowMaximized);
        }
    }
    else {
        this->setWindowState(Qt::WindowNoState);
    }
}

void playerWidget::slotSetMediaPosition(qint64 pos)
{
    mediaPlayer->setPosition(pos);
    setDurationTime(pos);
}

void playerWidget::slotSetSliderPosition(qint64 pos)
{
    durationSlider->setValue(static_cast<int>(pos));
    setDurationTime(pos);
}

void playerWidget::slotSetVolume(qint64 value)
{
    mediaPlayer->setVolume(static_cast<int>(value));
}

void playerWidget::slotSetDuration(qint64 duration)
{
    durationSlider->setRange(0, static_cast<int>(duration));
    setDurationTime(0);
}

void playerWidget::slotChangeDurationInfo()
{
    if(bIsDurationTime){
        bIsDurationTime = false;
    }
    else{
        bIsDurationTime = true;
    }
}

void playerWidget::slotIsVideoAvailable()
{
    if(mediaPlayer->isVideoAvailable()){
        videoScreen->show();
    }
    else {
        videoScreen->hide();
        this->resize(300, 150);
    }
}

void playerWidget::slotToFullScreen()
{
    if(mediaPlayer->isVideoAvailable()){
        if (!videoScreen->isFullScreen()){
            videoScreen->setFullScreen(true);
        }
        else{
            videoScreen->showNormal();
            videoScreen->setFullScreen(false);
        }
    }
}

void playerWidget::slotReadSettings()
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

void playerWidget::slotWriteSettings()
{
    QSettings* settings = MyApplication::getApp()->settings();
    settings->beginGroup("/Settings");

    settings->setValue("/currentFile", openFileButton->getLastFileOpened());
    settings->setValue("/currentTime", mediaPlayer->position());
    settings->setValue("/volume", volumeSlider->value());
    settings->setValue("/bIsDurationTime", bIsDurationTime);

    settings->endGroup();
}

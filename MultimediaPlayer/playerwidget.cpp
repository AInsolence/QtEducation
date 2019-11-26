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
    QGridLayout* titleLayout = new QGridLayout;
    titleLayout->setSpacing(0);
    titleLayout->setMargin(0);
    titlebarWidget->setLayout(titleLayout);

    setWindowTitle("Media Player v0.1");
    playerWindowTitle = new QLabel(titlebarWidget);
    playerWindowTitle->setObjectName("playerTitle");
    playerWindowTitle->setText(this->windowTitle());

    QToolButton* shutdownButton = new QToolButton();
    shutdownButton->setText("X");
    QToolButton* maximizeButton = new QToolButton();
    maximizeButton->setText("|_|");
    QToolButton* minimizeButton = new QToolButton();
    minimizeButton->setText("_");


    //titleLayout->addWidget(new QLabel("Icon"), 0, 0, 1, 1);
    titleLayout->addWidget(playerWindowTitle, 0, 1, 1, 8);
    titleLayout->addWidget(minimizeButton, 0, 9, 1, 1);
    titleLayout->addWidget(maximizeButton, 0, 10, 1, 1);
    titleLayout->addWidget(shutdownButton, 0, 11, 1, 1);

    // player controls init
    playButton = new QPushButton("&Play");
    pauseButton = new QPushButton(" || ");
    stopButton = new QPushButton("&stop");
    openFileButton = new QToolButton();
    openFileButton->setText("^");
    fullScreenButton = new QToolButton();
    fullScreenButton->setText("<->");

    playButton->setEnabled(false);
    pauseButton->setEnabled(false);
    stopButton->setEnabled(false);

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setMinimumWidth(150);
    // info items init
    durationSlider = new QSlider(Qt::Horizontal);
    currentTime = new QToolButton();
    currentTime->setText("00:00::00");
    currentTime->setMinimumWidth(100);
    fileNameLabel = new QLabel("");

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addWidget(titlebarWidget, 0, 0, 1, 12);

    mainLayout->addWidget(videoScreen, 2, 0, 1, 12);

    mainLayout->addWidget(fileNameLabel, 3, 1, 1, 6);
    mainLayout->addWidget(currentTime, 3, 9, 1, 3);

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
    // control buttons connections
    connect(openFileButton, &QToolButton::clicked, this, &playerWidget::slotOpen);
    connect(playButton, &QPushButton::clicked, this, &playerWidget::slotPlay);
    connect(pauseButton, &QPushButton::clicked, this, &playerWidget::slotPause);
    connect(stopButton, &QPushButton::clicked, this, &playerWidget::slotStop);
    // volume slider connect
    connect(volumeSlider, &QSlider::valueChanged, this, &playerWidget::slotSetVolume);
    // duration slider connections
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &playerWidget::slotSetDuration);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &playerWidget::slotSetSliderPosition);
    connect(durationSlider, &QSlider::sliderMoved, this, &playerWidget::slotSetMediaPosition);
    connect(currentTime, &QPushButton::clicked, this, &playerWidget::slotChangeDurationInfo);
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
}

playerWidget::~playerWidget()
{
}

void playerWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if(titlebarWidget->underMouse() && playerWindowTitle->underMouse()){
        if( event->buttons().testFlag(Qt::LeftButton) && bIsMovingAvailable) {
            this->move(this->pos() + (event->pos() - lastMousePosition));
          }
      }
}

void playerWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if(titlebarWidget->underMouse() && playerWindowTitle->underMouse()){
            bIsMovingAvailable = true;
            lastMousePosition = event->pos();
      }
}

void playerWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if(titlebarWidget->underMouse() && playerWindowTitle->underMouse()){
        if(event->button() == Qt::LeftButton) {
            bIsMovingAvailable = false;
          }
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
    qDebug() << "Double click";
}

QString playerWidget::msecToTimeString(qint64 duration)
{
    qint64 hours = duration/(60*60*1000);
    qint64 minutes = (duration%(60*60*1000))/(60*1000);
    qint64 seconds = duration%(60*1000)/1000;

    return QTime(hours, minutes, seconds).toString("hh:mm:ss");
}

void playerWidget::setDurationTime(qint64 pos)
{
    if(bIsCurrentTime){
        currentTime->setText(msecToTimeString(pos));
    }
    else{
        currentTime->setText(msecToTimeString(durationSlider->maximum() - pos));
    }
}

void playerWidget::slotMaximized()
{
    if (this->windowState() == Qt::WindowNoState){
        this->setWindowState(Qt::WindowMaximized);
    }
    else {
        this->setWindowState(Qt::WindowNoState);
    }
}

void playerWidget::slotOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");

    if(!fileName.isEmpty()){
        mediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
        // get song name to show
        QStringList nameParse = fileName.split("/");
        fileNameLabel->setText(nameParse[nameParse.length() - 1]);

        playButton->setEnabled(true);
        pauseButton->setEnabled(true);
        stopButton->setEnabled(true);
    }
}

void playerWidget::slotPlay()
{
    switch (mediaPlayer->state()) {
        case QMediaPlayer::PlayingState:
            mediaPlayer->pause();
            break;
        default:
            mediaPlayer->play();
        break;
    }
}

void playerWidget::slotPause()
{
    switch (mediaPlayer->state()) {
        case QMediaPlayer::PlayingState:
            mediaPlayer->pause();
            break;
        default:
            mediaPlayer->play();
        break;
    }
}

void playerWidget::slotStop()
{
    mediaPlayer->stop();
}

void playerWidget::slotSetMediaPosition(qint64 pos)
{
    mediaPlayer->setPosition(pos);
    setDurationTime(pos);
}

void playerWidget::slotSetSliderPosition(qint64 pos)
{
    durationSlider->setValue(pos);
    setDurationTime(pos);
}

void playerWidget::slotSetVolume(qint64 value)
{
    mediaPlayer->setVolume(value);
}

void playerWidget::slotSetDuration(qint64 duration)
{
    durationSlider->setRange(0, duration);
    setDurationTime(0);
}

void playerWidget::slotChangeDurationInfo()
{
    if(bIsCurrentTime){
        bIsCurrentTime = false;
    }
    else{
        bIsCurrentTime = true;
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

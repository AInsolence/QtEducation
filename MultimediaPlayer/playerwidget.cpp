#include "playerwidget.h"
#include <QPushButton>
#include <QToolButton>
#include <QSlider>
#include <QLabel>
#include <QLayout>
#include <QFileDialog>
#include <QTime>

playerWidget::playerWidget(QWidget *parent)
    : QWidget(parent)
{
    mediaPlayer = new QMediaPlayer;
    // player controls init
    playButton = new QPushButton("&Play");
    pauseButton = new QPushButton(" || ");
    stopButton = new QPushButton("&stop");
    openFileButton = new QToolButton();
    openFileButton->setText("^");

    playButton->setEnabled(false);
    pauseButton->setEnabled(false);
    stopButton->setEnabled(false);

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    // info items init
    durationSlider = new QSlider(Qt::Horizontal);
    currentTime = new QPushButton("00:00::00");
    fileNameLabel = new QLabel("");

    QGridLayout* mainLayout = new QGridLayout;

    mainLayout->addWidget(fileNameLabel, 0, 1, 1, 1);
    mainLayout->addWidget(currentTime, 0, 7, 1, 1);
    mainLayout->addWidget(durationSlider, 1, 0, 1, 9);
    mainLayout->addWidget(openFileButton, 1, 10, 1, 1);

    mainLayout->addWidget(playButton, 2, 1, 1, 1);
    mainLayout->addWidget(pauseButton, 2, 2, 1, 1);
    mainLayout->addWidget(stopButton, 2, 3, 1, 1);
    mainLayout->addWidget(volumeSlider, 2, 6, 1, 3);

    // control buttons connects
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
        return;
    }
    else{
        bIsCurrentTime = true;
        return;
    }
}

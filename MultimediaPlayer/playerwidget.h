#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>

class QPushButton;
class QToolButton;
class QLabel;
class QSlider;

class playerWidget : public QWidget
{
    Q_OBJECT

public:
    playerWidget(QWidget *parent = nullptr);
    ~playerWidget();

private:
    QMediaPlayer* mediaPlayer = nullptr;
    // player controls
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
    QPushButton* stopButton = nullptr;
    QToolButton* openFileButton = nullptr;
    QSlider* volumeSlider = nullptr;
    // info items
    QSlider* durationSlider = nullptr;
    QPushButton* currentTime = nullptr;
    QLabel* fileNameLabel = nullptr;
    //
    QString msecToTimeString(qint64);
    void setDurationTime(qint64);
    bool bIsCurrentTime = true;

private slots:
    void slotOpen();
    void slotPlay();
    void slotPause();
    void slotStop();
    void slotSetMediaPosition(qint64);
    void slotSetSliderPosition(qint64);
    void slotSetVolume(qint64);
    void slotSetDuration(qint64);
    void slotChangeDurationInfo();
};
#endif // PLAYERWIDGET_H

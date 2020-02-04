#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QSettings>
#include <QGridLayout>
#include <QLabel>
#include "iplayercommand.h"
#include "icommoncommand.h"
#include "openfilebutton.h"
#include "fullscreenbutton.h"

class QToolButton;
class QLabel;
class QSlider;
class QDial;

class PlayerWidget : public QWidget
{
    Q_OBJECT

    friend IPlayerCommand;
    friend ICommonCommand;

public:
    PlayerWidget(QWidget *parent = nullptr);
    ~PlayerWidget() override;

    inline void setPlaylist(QMediaPlaylist& playlist)
                    {mediaPlayer.setPlaylist(&playlist);}
    inline OpenFileButton* getOpenFileButton(){return openFileButton;}
    inline QMediaPlayer& getMediaPlayer(){return mediaPlayer;}
    inline FullScreenButton* getFullScreenButton(){return  fullScreenButton;}
protected:
    void closeEvent(QCloseEvent* event) override;

private:
    QMediaPlayer mediaPlayer;
    // layouts
    QGridLayout* titleLayout = nullptr;
    QGridLayout* mainLayout = nullptr;
    // top line
    QLabel playerWindowTitle;
    // player controls
    IPlayerCommand* playButton = nullptr;
    IPlayerCommand* pauseButton = nullptr;
    IPlayerCommand* stopButton = nullptr;
    IPlayerCommand* prevButton = nullptr;
    IPlayerCommand* nextButton = nullptr;
    OpenFileButton* openFileButton = nullptr;
    FullScreenButton* fullScreenButton = nullptr;

    // info items
    QDial* volumeSlider = nullptr;
    QSlider* durationSlider = nullptr;
    QToolButton* durationTime = nullptr;
    QLabel* fileNameLabel = nullptr;
    // helper variables
    QPoint dragPosition;
    bool bIsMovingAvailable = false;
    QString msecToTimeString(qint64);
    void setDurationTime(qint64);
    bool bIsDurationTime = true;
    qint64 lastFilePosition = 0.0;

signals:
    void signalNextFilePlay();
public slots:
    void slotPlay();
    void slotSetMediaPosition(qint64);
    void slotSetSliderPosition(qint64);
    void slotSetVolume(qint64);
    void slotSetDuration(qint64);
    void slotChangeDurationInfo();
    void slotReadSettings();
    void slotWriteSettings();
};
#endif // PLAYERWIDGET_H

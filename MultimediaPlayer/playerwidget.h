#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QSettings>

class QPushButton;
class QToolButton;
class QLabel;
class QSlider;
class QVideoWidget;

class playerWidget : public QWidget
{
    Q_OBJECT

public:
    playerWidget(QWidget *parent = nullptr);
    ~playerWidget() override;

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private:
    QMediaPlayer* mediaPlayer = nullptr;
    // top line
    QWidget* titlebarWidget = nullptr;
    QLabel* playerWindowTitle = nullptr;
    // screen
    QVideoWidget* videoScreen = nullptr;
    // player controls
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
    QPushButton* stopButton = nullptr;
    QToolButton* openFileButton = nullptr;
    QToolButton* fullScreenButton = nullptr;
    QSlider* volumeSlider = nullptr;
    // info items
    QSlider* durationSlider = nullptr;
    QToolButton* durationTime = nullptr;
    QLabel* fileNameLabel = nullptr;
    // helper variables
    QPoint dragPosition;
    bool bIsMovingAvailable = false;
    QString msecToTimeString(qint64);
    void setDurationTime(qint64);
    bool bIsDurationTime = true;
    QString lastFileOpened;
    qint64 lastFilePosition;

private slots:
    void slotMaximized();
    void slotOpen();
    void slotPlay();
    void slotPause();
    void slotStop();
    void slotSetMediaPosition(qint64);
    void slotSetSliderPosition(qint64);
    void slotSetVolume(qint64);
    void slotSetDuration(qint64);
    void slotChangeDurationInfo();
    void slotIsVideoAvailable();
    void slotToFullScreen();
    void slotReadSettings();
    void slotWriteSettings();
};
#endif // PLAYERWIDGET_H

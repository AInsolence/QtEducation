#ifndef FULLSCREENBUTTON_H
#define FULLSCREENBUTTON_H

#include <QObject>
#include "icommoncommand.h"
#include <QMediaPlayer>

class FullScreenButton : public ICommonCommand
{
    Q_OBJECT
public:
    explicit FullScreenButton(const QString&& text,
                        QWidget *parent = nullptr);
signals:
    void signalSetFullScreen();
private:
    using ICommonCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() override final;
};

#endif // FULLSCREENBUTTON_H

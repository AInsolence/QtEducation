#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H

#include <QObject>
#include "iplayercommand.h"

class PauseButton : public IPlayerCommand
{
public:
    explicit PauseButton(const QString&& text,
                        QWidget *parent = nullptr);
private:
    using IPlayerCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() const override final;
};

#endif // PAUSEBUTTON_H

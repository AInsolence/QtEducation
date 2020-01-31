#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QObject>
#include "iplayercommand.h"

class PlayButton : public IPlayerCommand
{
public:
    explicit PlayButton(const QString&& text,
                        QWidget *parent = nullptr);
private:
    using IPlayerCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() const override final;
};

#endif // PLAYBUTTON_H

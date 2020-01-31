#ifndef PREVBUTTON_H
#define PREVBUTTON_H

#include <QObject>
#include "iplayercommand.h"

class PrevButton : public IPlayerCommand
{
public:
    explicit PrevButton(const QString&& text,
                        QWidget *parent = nullptr);
private:
    using IPlayerCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() const override final;
};

#endif // PLAYBUTTON_H

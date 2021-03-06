#ifndef STOPBUTTON_H
#define STOPBUTTON_H

#include <QObject>
#include "iplayercommand.h"

class StopButton : public IPlayerCommand
{
public:
    explicit StopButton(const QString&& text,
                        QWidget *parent = nullptr);
private:
    using IPlayerCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() const override final;
};

#endif // STOPBUTTON_H

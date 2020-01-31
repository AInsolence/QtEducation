#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include <QObject>
#include "iplayercommand.h"

class NextButton : public IPlayerCommand
{
public:
    explicit NextButton(const QString&& text,
                        QWidget *parent = nullptr);
private:
    using IPlayerCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() const override final;
};

#endif // PLAYBUTTON_H

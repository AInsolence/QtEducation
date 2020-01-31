#include "iplayercommand.h"
#include "playerwidget.h"

IPlayerCommand::IPlayerCommand(const QString& text,
                               QWidget *parent) :
    QPushButton(text, parent)
{
    _mediaPlayer = &(static_cast<PlayerWidget*>(parent)->mediaPlayer);
    connect(this, &QPushButton::clicked, this, &IPlayerCommand::slotExecute);
}

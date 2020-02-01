#include "iplayercommand.h"
#include "playerwidget.h"

IPlayerCommand::IPlayerCommand(const QString& text,
                               QWidget *parent) :
    QPushButton(text, parent)
{
    _mediaPlayer = &(dynamic_cast<PlayerWidget*>(parent)->mediaPlayer);
    connect(this, &QPushButton::clicked, this, &IPlayerCommand::slotExecute);
}

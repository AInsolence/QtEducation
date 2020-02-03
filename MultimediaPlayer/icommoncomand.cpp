#include "icommoncommand.h"
#include "playerwidget.h"

ICommonCommand::ICommonCommand(const QString& text,
                               QWidget *parent) :
    QToolButton(parent)
{
    setText(text);
    connect(this, &QToolButton::clicked, this, &ICommonCommand::slotExecute);
    _mediaPlayer = &(dynamic_cast<PlayerWidget*>(parent)->mediaPlayer);
    connect(this, &QPushButton::clicked, this, &ICommonCommand::slotExecute);
}

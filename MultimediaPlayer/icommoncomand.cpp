#include "icommoncommand.h"

ICommonCommand::ICommonCommand(const QString& text,
                               QWidget *parent) :
    QToolButton(parent),
    _parent(parent)
{
    setMinimumWidth(40);
    setText(text);
    connect(this, &QToolButton::clicked, this, &ICommonCommand::slotExecute);
}

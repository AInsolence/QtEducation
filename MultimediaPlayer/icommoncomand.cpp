#include "icommoncommand.h"

ICommonCommand::ICommonCommand(const QString& text,
                               QWidget *parent) :
    QToolButton(parent),
    _parent(parent)
{
    setText(text);
    connect(this, &QToolButton::clicked, this, &ICommonCommand::slotExecute);
}

#include "shutdownbutton.h"

ShutDownButton::ShutDownButton(const QString&& text, QWidget *parent)
    : ICommonCommand(text, parent)
{

}

void ShutDownButton::slotExecute()
{
    _parent->close();
}

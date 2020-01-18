#include "minimizebutton.h"

MinimizeButton::MinimizeButton(const QString&& text, QWidget *parent)
    : ICommonCommand(text, parent)
{

}

void MinimizeButton::slotExecute()
{
    _parent->setWindowState(Qt::WindowMinimized);
}

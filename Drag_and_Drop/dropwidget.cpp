#include "dropwidget.h"
#include <QDragEnterEvent>
#include <QMimeData>

DropWidget::DropWidget(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setGeometry(0, 0, 500, 500);
    setAlignment(Qt::AlignCenter);
    // accept drops
    setAcceptDrops(true);
}

DropWidget::~DropWidget()
{

}

void DropWidget::dragEnterEvent(QDragEnterEvent *eventDrag)
{
    // make possible to restrict dropping in some areas
    //eventDrag->accept(this->rect());
    QStringList formats = eventDrag->mimeData()->formats();
    // check dropped MIME object for acceptable formats
    if(!formats.filter("audio/").empty() ||
       !formats.filter("video/").empty() ||
       !formats.filter("text/").empty())
    {
        eventDrag->acceptProposedAction();
    }
}

// get dropped data and do some actions with it
void DropWidget::dropEvent(QDropEvent *eventDrop)
{// get text (or other object) from mimeData object
    QString droppedText = eventDrop->mimeData()->text();
    // make manipulations with dragged object
    setText(this->text() + "\n" + "Dropped: " + droppedText);
}

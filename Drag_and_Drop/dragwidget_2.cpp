#include "dragwidget_2.h"
#include <QMouseEvent>
#include <QApplication>
#include "mimedatawidget.h"
#include "customdragforwidget.h"

DragWidget_2::DragWidget_2(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setMinimumSize(300, 300);
    setAlignment(Qt::AlignCenter);
    setText("You can drag this widget");
}

DragWidget_2::~DragWidget_2()
{

}

void DragWidget_2::mousePressEvent(QMouseEvent *eventPress)
{
    if(eventPress->button() == Qt::LeftButton){
        _dragPos = eventPress->pos();
    }
    QWidget::mousePressEvent(eventPress);
}

void DragWidget_2::mouseMoveEvent(QMouseEvent *eventMove)
{
    if(eventMove->buttons() & Qt::LeftButton){
        int distance = (eventMove->pos() - _dragPos).manhattanLength();
        if(distance > QApplication::startDragDistance()){
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(eventMove);
}

void DragWidget_2::startDrag()
{// create a MIME data to store a draggable object (here "text")
    MimeDataWidget* data = new MimeDataWidget();
    data->setWidget(this);
    // create a drag object with custom image as drag-process indication
    CustomDragForWidget* drag = new CustomDragForWidget(this);// "this" - from where we'll drag
    drag->setMimeData(data);
    drag->setPixmap(QPixmap("://icons8-hand-drag-64.png"));
    drag->exec(Qt::CopyAction);// drag->exec(Qt::LinkAction) - set simple image identifier
}

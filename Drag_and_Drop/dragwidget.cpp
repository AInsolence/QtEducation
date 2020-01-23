#include "dragwidget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>

DragWidget::DragWidget(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setMinimumSize(300, 300);
    setAlignment(Qt::AlignCenter);
}

DragWidget::~DragWidget()
{

}

void DragWidget::mousePressEvent(QMouseEvent *eventPress)
{
    if(eventPress->button() == Qt::LeftButton){
        _dragPos = eventPress->pos();
    }
    QWidget::mousePressEvent(eventPress);
}

void DragWidget::mouseMoveEvent(QMouseEvent *eventMove)
{
    if(eventMove->buttons() & Qt::LeftButton){
        int distance = (eventMove->pos() - _dragPos).manhattanLength();
        if(distance > QApplication::startDragDistance()){
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(eventMove);
}

void DragWidget::startDrag()
{// create a MIME data to store a draggable object (here "text")
    QMimeData* data = new QMimeData();
    data->setText(this->text());
    // create a drag object with custom image as drag-process indication
    QDrag* drag = new QDrag(this);// "this" - from where we'll drag
    drag->setMimeData(data);
    drag->setPixmap(QPixmap("://icons8-hand-drag-64.png"));
    drag->exec();// drag->exec(Qt::LinkAction) - set simple image identifier
}

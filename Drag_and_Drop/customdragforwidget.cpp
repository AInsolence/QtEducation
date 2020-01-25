#include "customdragforwidget.h"
#include <QWidget>
#include "mimedatawidget.h"

CustomDragForWidget::CustomDragForWidget(QWidget* sourceWidget)
    : QDrag(sourceWidget)
{

}

CustomDragForWidget::~CustomDragForWidget()
{

}

void CustomDragForWidget::setWidget(QWidget *wgt)
{
    MimeDataWidget* __mimeData = new MimeDataWidget();
    __mimeData->setWidget(wgt);
    setMimeData(__mimeData);
}

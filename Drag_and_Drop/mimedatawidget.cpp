#include "mimedatawidget.h"

MimeDataWidget::MimeDataWidget()
{

}

MimeDataWidget::~MimeDataWidget()
{

}

QString MimeDataWidget::mimeType()
{
    return "application/widget";
}

void MimeDataWidget::setWidget(QWidget *wgt)
{
    _wgtPointer = std::move(wgt);
    setData(mimeType(), QByteArray());
}

QWidget *MimeDataWidget::widget() const
{
    return _wgtPointer;
}

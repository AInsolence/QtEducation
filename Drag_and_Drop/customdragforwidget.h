#ifndef CUSTOMDRAGFORWIDGET_H
#define CUSTOMDRAGFORWIDGET_H
#include <QDrag>

class CustomDragForWidget : public QDrag
{
public:
    CustomDragForWidget(QWidget* sourceWidget = nullptr);
    virtual ~CustomDragForWidget();
    void setWidget(QWidget* wgt);
};

#endif // CUSTOMDRAGFORWIDGET_H

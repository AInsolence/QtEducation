#ifndef DROPWIDGET_H
#define DROPWIDGET_H

#include <QLabel>

class DropWidget : public QLabel
{
    Q_OBJECT

public:
    DropWidget(const QString& text, QWidget *parent = nullptr);
    ~DropWidget();
protected:
    virtual void dragEnterEvent(QDragEnterEvent* eventDrag);
    virtual void dropEvent(QDropEvent* eventDrop);
};

#endif // DROPWIDGET_H

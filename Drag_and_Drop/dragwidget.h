#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QLabel>

class DragWidget : public QLabel
{
    Q_OBJECT

public:
    DragWidget(const QString& text, QWidget *parent = nullptr);
    ~DragWidget();
protected:
    virtual void mousePressEvent(QMouseEvent* eventPress) override;
    virtual void mouseMoveEvent(QMouseEvent* eventMove) override;
private:
    QPoint _dragPos;
    void startDrag();
};

#endif // DRAGWIDGET_H

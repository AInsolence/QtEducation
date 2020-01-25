#ifndef DRAGWIDGET_2_H
#define DRAGWIDGET_2_H

#include <QLabel>

class DragWidget_2 : public QLabel
{
    Q_OBJECT

public:
    DragWidget_2(const QString& text, QWidget *parent = nullptr);
    ~DragWidget_2();
protected:
    virtual void mousePressEvent(QMouseEvent* eventPress) override;
    virtual void mouseMoveEvent(QMouseEvent* eventMove) override;
private:
    QPoint _dragPos;
    void startDrag();
};

#endif // DRAGWIDGET_H

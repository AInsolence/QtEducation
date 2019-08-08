#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QLabel>

class CustomWidget : public QLabel
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);
protected:
    virtual void mousePressEvent(QMouseEvent* me) override;
    virtual void mouseMoveEvent(QMouseEvent* me) override;
private:
    QPoint m_mouseCursorPosition;
};

#endif // CUSTOMWIDGET_H

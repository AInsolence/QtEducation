#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>

class Widget : public QLabel
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    virtual void keyPressEvent(QKeyEvent* myEvent) override;

    virtual void mousePressEvent(QMouseEvent* myEvent) override;
    virtual void mouseReleaseEvent(QMouseEvent* myEvent) override;
    virtual void mouseMoveEvent(QMouseEvent* myEvent) override;

    virtual void wheelEvent(QWheelEvent* myEvent) override;
    virtual void enterEvent(QEvent* myEvent) override;
    virtual void leaveEvent(QEvent* myEvent) override;

    virtual void resizeEvent(QResizeEvent* myEvent) override;
    virtual void moveEvent(QMoveEvent* myEvent) override;

    void dumpEvent(QMouseEvent* myEvent, const QString msg);
    QString modifiersInfo(QMouseEvent* myEvent);
    QString buttonsInfo(QMouseEvent* myEvent);
};

#endif // WIDGET_H

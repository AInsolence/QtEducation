#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    virtual void paintEvent(QPaintEvent* pEvent) override;
};

#endif // MYLABEL_H

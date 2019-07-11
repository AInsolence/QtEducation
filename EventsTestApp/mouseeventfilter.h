#ifndef MOUSEEVENTFILTER_H
#define MOUSEEVENTFILTER_H

#include <QObject>
#include <QEvent>

class mouseEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit mouseEventFilter(QObject *parent = nullptr);
protected:
    virtual bool eventFilter(QObject* eventOwner,QEvent* myEvent) override;

};

#endif // MOUSEEVENTFILTER_H

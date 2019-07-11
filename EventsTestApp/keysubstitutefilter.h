#ifndef KEYSUBSTITUTEFILTER_H
#define KEYSUBSTITUTEFILTER_H

#include <QObject>

class keySubstituteFilter : public QObject
{
    Q_OBJECT
public:
    explicit keySubstituteFilter(QObject *parent = nullptr);
protected:
    virtual bool eventFilter(QObject* eventOwner,QEvent* myEvent) override;
};

#endif // KEYSUBSTITUTEFILTER_H

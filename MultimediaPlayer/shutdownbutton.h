#ifndef SHUTDOWNBUTTON_H
#define SHUTDOWNBUTTON_H

#include <QObject>
#include "icommoncommand.h"

class ShutDownButton : public ICommonCommand
{
public:
    explicit ShutDownButton(const QString&& text,
                        QWidget *parent = nullptr);
public slots:
    virtual void slotExecute() override final;
};

#endif // SHUTDOWNBUTTON_H

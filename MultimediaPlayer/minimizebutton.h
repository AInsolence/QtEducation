#ifndef MINIMIZEBUTTON_H
#define MINIMIZEBUTTON_H

#include <QObject>
#include "icommoncommand.h"

class MinimizeButton : public ICommonCommand
{
public:
    explicit MinimizeButton(const QString&& text,
                        QWidget *parent = nullptr);
public slots:
    virtual void slotExecute() override final;
};

#endif // MINIMIZEBUTTON_H

#ifndef MAXIMIZEBUTTON_H
#define MAXIMIZEBUTTON_H

#include <QObject>
#include "icommoncommand.h"
#include <QMediaPlayer>

class MaximizeButton : public ICommonCommand
{
public:
    explicit MaximizeButton(const QString&& text,
                            QMediaPlayer& mediaPlayer,
                        QWidget *parent = nullptr);
private:
    QMediaPlayer& _mediaPlayer;
public slots:
    virtual void slotExecute() override final;
};

#endif // MAXIMIZEBUTTON_H

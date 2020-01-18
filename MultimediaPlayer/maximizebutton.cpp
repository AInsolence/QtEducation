#include "maximizebutton.h"
#include <QDebug>

MaximizeButton::MaximizeButton(const QString&& text, QMediaPlayer& mediaPlayer, QWidget *parent)
    : ICommonCommand(text, parent),
      _mediaPlayer(mediaPlayer)
{

}

void MaximizeButton::slotExecute()
{
    qDebug() << "in maximize call";
    if (_parent->windowState() == Qt::WindowNoState){
        if(_mediaPlayer.isVideoAvailable()){
            qDebug() << "maximize call";
            _parent->setWindowState(Qt::WindowMaximized);
        }
    }
    else {
        _parent->setWindowState(Qt::WindowNoState);
    }
}

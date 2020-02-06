#ifndef OPENFILEBUTTON_H
#define OPENFILEBUTTON_H

#include <QObject>
#include "icommoncommand.h"
#include <QMediaPlayer>

class OpenFileButton : public ICommonCommand
{
    Q_OBJECT
public:
    explicit OpenFileButton(const QString&& text,
                        QWidget *parent = nullptr);
signals:
    void signalAddFileToPlaylist(const QString& filePath);
private:
    using ICommonCommand::_mediaPlayer;
public slots:
    virtual void slotExecute() override final;
    void slotOpenFolder();
};

#endif // OPENFILEBUTTON_H

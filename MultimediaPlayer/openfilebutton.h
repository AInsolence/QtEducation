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
                        QMediaPlayer& mediaPlayer,
                        QWidget *parent = nullptr);

    QString getLastFileOpened() const;
    void setLastFileOpened(const QString&);
signals:
    void signalAddFileToPlaylist(const QString& filePath);
private:
    QMediaPlayer& _mediaPlayer;
    QString _lastFileOpened = "";
public slots:
    virtual void slotExecute() override final;
};

#endif // OPENFILEBUTTON_H

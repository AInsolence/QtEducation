#ifndef OPENFILEBUTTON_H
#define OPENFILEBUTTON_H

#include <QObject>
#include "icommoncommand.h"
#include <QLabel>
#include <QMediaPlayer>

class OpenFileButton : public ICommonCommand
{
public:
    explicit OpenFileButton(const QString&& text,
                        QMediaPlayer& mediaPlayer,
                        QLabel& fileNameLabel,
                        QWidget *parent = nullptr);

    QString getLastFileOpened() const;
    void setLastFileOpened(const QString&);
private:
    QMediaPlayer& _mediaPlayer;
    QString _lastFileOpened = "";
    QLabel& _fileNameLabel;
public slots:
    virtual void slotExecute() override final;
};

#endif // OPENFILEBUTTON_H

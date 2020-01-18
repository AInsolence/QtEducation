#ifndef OPENFILEBUTTON_H
#define OPENFILEBUTTON_H

#include <QObject>
#include "iplayercommand.h"
#include <QLabel>

class OpenFileButton : public IPlayerCommand
{
public:
    explicit OpenFileButton(const QString& text,
                        QMediaPlayer& mediaPlayer,
                        QLabel& fileNameLabel,
                        QWidget *parent = nullptr);

    QString getLastFileOpened() const;
    void setLastFileOpened(const QString&);
private:
    using IPlayerCommand::_mediaPlayer;
    QString _lastFileOpened = "";
    QLabel& _fileNameLabel;
    QWidget* _parent;
public slots:
    virtual void slotExecute() override final;
};

#endif // OPENFILEBUTTON_H

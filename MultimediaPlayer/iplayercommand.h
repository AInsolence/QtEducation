#ifndef IPLAYERCOMMAND_H
#define IPLAYERCOMMAND_H

#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>

class IPlayerCommand : public QPushButton
{
    Q_OBJECT
public:
    explicit IPlayerCommand(const QString& text,
                            QWidget *parent = nullptr);
protected:
    QMediaPlayer* _mediaPlayer;
public slots:
    virtual void slotExecute() const = 0;
};

#endif // IPLAYERCOMMAND_H

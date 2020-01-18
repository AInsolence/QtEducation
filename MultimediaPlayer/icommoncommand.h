#ifndef ICOMMONCOMANDCOMMAND_H
#define ICOMMONCOMANDCOMMAND_H

#include <QObject>
#include <QToolButton>

class ICommonCommand : public QToolButton
{
    Q_OBJECT
public:
    explicit ICommonCommand(const QString& text,
                            QWidget *parent = nullptr);
protected:
    QWidget* _parent = nullptr;
public slots:
    virtual void slotExecute() = 0;
};

#endif // ICOMMONCOMANDCOMMAND_H

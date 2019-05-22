#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void NumberChanged(int);
    void StopCounting();

public slots:
    void IncreaseNumber();

private:
    int countingNumber = 0;
};

#endif // CONTROLLER_H

#ifndef UTILITIES_H
#define UTILITIES_H

#include <QObject>

class Utilities : public QObject
{
    Q_OBJECT
public:
    explicit Utilities(QObject *parent = nullptr);

    //Debug helpers and utility functions
    static void messageToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void dummyOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

signals:

public slots:
};

#endif // UTILITIES_H

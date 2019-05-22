#include "utilities.h"
#include <QtGlobal>
#include <QFile>
#include <QTextStream>

Utilities::Utilities(QObject *parent) : QObject(parent)
{

}

void Utilities::messageToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile logFile("protocol.log");
    if(!logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        qDebug("Cannot open protocol.log file!");
        return;
    }

    QTextStream msgText(&logFile);

    switch (type) {
        case QtInfoMsg:
            msgText << "!!!Info: " << msg << context.file << endl;
            break;
        case QtWarningMsg:
            msgText << "!!!Warning: " << msg << context.file << endl;
            break;
        case QtDebugMsg:
            msgText << "!!!Debug: " << msg << context.file << endl;
            break;
        case QtCriticalMsg:
            msgText << "!!!Critial: " << msg << context.file << endl;
            break;
        case QtFatalMsg:
            msgText << "!!!Fatal: " << msg << context.file << endl;
            abort();
    }
}

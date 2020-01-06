#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QSettings>

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    explicit MyApplication(int argc, char** argv,
                           const QString& strOrgName,
                           const QString& strAppName);
    QSettings* settings();

    static MyApplication* getApp();

private:
    QSettings* _settings = nullptr;
};

#endif // MYAPPLICATION_H

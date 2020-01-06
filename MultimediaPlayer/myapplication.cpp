#include "myapplication.h"

MyApplication::MyApplication(int argc, char** argv,
                             const QString& strOrgName,
                             const QString& strAppName)
    : QApplication(argc, argv)
{
    _settings = new QSettings(strOrgName, strAppName, this);
    setOrganizationName(strOrgName);
    setApplicationName(strAppName);
}

QSettings* MyApplication::settings()
{
    return _settings;
}

MyApplication *MyApplication::getApp()
{
    return static_cast<MyApplication*>(QCoreApplication::instance());
}

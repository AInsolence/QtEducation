#include "playerwidget.h"

#include "myapplication.h"

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv, "Anton", "Media Player");
    playerWidget w;
    w.show();
    return a.exec();
}

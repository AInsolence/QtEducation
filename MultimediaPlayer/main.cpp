#include "mediaplayer.h"
#include "playerwidget.h"

#include "myapplication.h"

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv, "Anton", "Media Player");
    MediaPlayer player;
    //PlayerWidget p;
    return a.exec();
}

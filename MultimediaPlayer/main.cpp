#include "mediaplayer.h"
#include "playerwidget.h"

#include "myapplication.h"
#include "videowidget.h"

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv, "Anton", "Media Player");
    MediaPlayer player;
    return MyApplication::exec();
}

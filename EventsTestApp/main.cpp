#include "widget.h"
#include <QApplication>
#include "mouseeventfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QLabel secondWidget;
    secondWidget.setText("Second widget");
    secondWidget.setGeometry(w.pos().x() + w.width(), w.pos().y() + 30,
                             200, 200);
    secondWidget.show();
    // install event filter
    w.installEventFilter(new mouseEventFilter(&w));
    secondWidget.installEventFilter(new mouseEventFilter(&secondWidget));

    return a.exec();
}

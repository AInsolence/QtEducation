#include "widget.h"
#include <QApplication>
#include "mouseeventfilter.h"
#include <QLineEdit>
#include <QKeyEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QLineEdit secondWidget;
    secondWidget.setGeometry(w.pos().x() + w.width(), w.pos().y() + 30,
                             200, 200);
    secondWidget.show();
    // install event filter
    w.installEventFilter(new mouseEventFilter(&w));
    secondWidget.installEventFilter(new mouseEventFilter(&secondWidget));

    for (int i = 0; i < Qt::Key_Z - Qt::Key_A; ++i) {
        QChar inputChar = 65 + i;
        int keyCode = Qt::Key_A + i;
        QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, inputChar);
        QApplication::sendEvent(&secondWidget, &keyPress);
        // NOTE: we need to imitate key release action!
        QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier, inputChar);
        QApplication::sendEvent(&secondWidget, &keyRelease);
    }

    return a.exec();
}

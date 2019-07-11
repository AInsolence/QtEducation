#include "widget.h"
#include <QApplication>
#include "mouseeventfilter.h"
#include "keysubstitutefilter.h"
#include <QLineEdit>
#include <QKeyEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QLineEdit secondWidget;
    QLineEdit thirdWidget;
    secondWidget.setGeometry(w.pos().x() + w.width(), w.pos().y() + 30,
                             200, 200);
    thirdWidget.setGeometry(secondWidget.pos().x() + secondWidget.width(),
                             w.pos().y() + 30,
                             200, 200);
    secondWidget.show();
    thirdWidget.show();
    // install event filter
    w.installEventFilter(new mouseEventFilter(&w));
    secondWidget.installEventFilter(new mouseEventFilter(&secondWidget));
    thirdWidget.installEventFilter(new keySubstituteFilter(&secondWidget));

    for (int i = 0; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        QChar inputChar = 65 + i;
        int keyCode = Qt::Key_A + i;
        QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, inputChar);
        QApplication::sendEvent(&secondWidget, &keyPress);
        QApplication::sendEvent(&thirdWidget, &keyPress);
        // NOTE: we need to imitate key release action!
        QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier, inputChar);
        QApplication::sendEvent(&secondWidget, &keyRelease);
        QApplication::sendEvent(&thirdWidget, &keyRelease);
    }

    return a.exec();
}

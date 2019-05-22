#include <QtWidgets>
#include "utilities.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication MyApplicationInstance(argc, argv);

    // Create label to show results from counter
    QLabel MyLable("Start count, please!");
    MyLable.resize(400, 200);
    MyLable.setWindowTitle("Anton Super Application");
    MyLable.show();
    // Create increase button
    QPushButton CounterIncreaseButton("Counter ++");
    CounterIncreaseButton.resize(200, 200);
    CounterIncreaseButton.move(500, 500);
    CounterIncreaseButton.show();

    Controller* MyController = new Controller();
    // Application connections
    QObject::connect(&CounterIncreaseButton,&QPushButton::clicked, MyController, &Controller::IncreaseNumber);
    QObject::connect(MyController, SIGNAL(NumberChanged(int)), &MyLable, SLOT(setNum(int)));
    QObject::connect(MyController, &Controller::StopCounting, &MyApplicationInstance, &QApplication::quit);

    qDebug("Hello from program");
    qInstallMessageHandler(Utilities::messageToFile);
    qDebug("Hello from program");
    qWarning("This is a warning msg!");

    return MyApplicationInstance.exec();
}

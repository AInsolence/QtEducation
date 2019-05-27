#include <QtWidgets>
#include <QString>
#include "utilities.h"
#include "controller.h"
#include "layoutcustomwidget.h"

int main(int argc, char *argv[])
{
    QApplication MyApplicationInstance(argc, argv);

    // Create label to show results from counter
    QLabel MyLable("Hello from my window", nullptr, Qt::WindowFlags(Qt::WindowStaysOnTopHint));
    MyLable.resize(400, 200);
    MyLable.setWindowTitle("Anton Super Application");
    MyLable.setWindowFlag(Qt::WindowMinMaxButtonsHint);
    MyLable.show();
    //Get position for button from lable pos
    int ButtonXPos = MyLable.x() + MyLable.width();
    // Create increase button
    QPushButton CounterIncreaseButton("Counter ++");
    CounterIncreaseButton.setGeometry(ButtonXPos, MyLable.y(), 300, 100);
    CounterIncreaseButton.setWindowFlag(Qt::FramelessWindowHint);
    CounterIncreaseButton.setParent(nullptr);
    //CounterIncreaseButton.setEnabled(true);

    CounterIncreaseButton.show();

    Controller* MyController = new Controller();
    // Application connections
    QObject::connect(&CounterIncreaseButton,&QPushButton::clicked, MyController, &Controller::IncreaseNumber);
    QObject::connect(MyController, SIGNAL(NumberChanged(int)), &MyLable, SLOT(setNum(int)));
    QObject::connect(MyController, &Controller::StopCounting, &MyApplicationInstance, &QApplication::quit);
    //QLibrary info example
    qDebug("Hello from program");
    qDebug() << QLibraryInfo::location(QLibraryInfo::DataPath);
    //QString methods example
    QString str = "Ringo Star";
    QStringList myList = str.split(" ");
    qDebug() << str << " splitted: " << myList;
    str = myList.join(" ");
    qDebug() << myList << " joined: " << str << endl;
    //QRegExp example
    QRegExp regIP ("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
    QString strWithIP("here we have servers IP: 192.168.0.15");
    qDebug() << strWithIP << " has an IP adress: " << (strWithIP.contains(regIP));

    QRegExp regEmail("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)");
    QString eMail = "Max.Shlee@neonway.com";
    qDebug() << eMail << " has an email adress: " << regEmail.exactMatch(eMail);
    //QVariant
    QVariant variantVar("My string for check");
    qDebug() << variantVar << " type() is: " << variantVar.type();
    qDebug() << variantVar << " typeToName() is: " << QVariant::typeToName(variantVar.type());
    qDebug() << variantVar << " typeName() is: " << variantVar.typeName();
    //Custom msg handler example
    qInstallMessageHandler(Utilities::messageToFile);
    qDebug("Hello from program");
    qWarning("This is a warning msg!");

    //Background settings examples
    QWidget* MyWidget = new QWidget(nullptr, Qt::WindowFlags(Qt::Window));
    MyWidget->setWindowTitle("MyWidget");
    //Create inner widget with palette for background color
    QWidget* InnerWidget_1 = new QWidget(MyWidget);
    InnerWidget_1->setGeometry(25, 25, 100, 100);
    QPalette* Palette_1 = new QPalette(); // create palette
    Palette_1->setColor(InnerWidget_1->backgroundRole(), Qt::blue); // set color to the palette
    InnerWidget_1->setPalette(*Palette_1); //
    InnerWidget_1->setAutoFillBackground(true);
    //Create second inner widget with texture as background
    QWidget* InnerWidget_2 = new QWidget(MyWidget);
    //QPalette* Palette_1 = new QPalette(); // create palette
    QPixmap pix("C:/Users/Anton/QTProjects/ShleeTestApp/BlueTile.jpg");
    Palette_1->setBrush(InnerWidget_2->backgroundRole(), QBrush(pix)); // set color to the palette
    InnerWidget_2->setPalette(*Palette_1); //
    InnerWidget_2->setAutoFillBackground(true);
    //InnerWidget_2->setFixedSize(pix.width(), pix.height());
    InnerWidget_2->resize(500, 500);

    MyWidget->show();

    //Cursor settings examples
    //QGuiApplication::setOverrideCursor(Qt::OpenHandCursor);
    //QGuiApplication::restoreOverrideCursor();
    CounterIncreaseButton.setCursor(Qt::PointingHandCursor);

    //QFrame examples
    QFrame* frame = new QFrame(MyWidget);
    frame->setFrameStyle(QFrame::Box | QFrame::Raised);
    frame->setGeometry(0, 0, 300, 300);
    frame->setLineWidth(10);
    frame->setMidLineWidth(3);
    frame->setContentsMargins(10,10,10,10);
    frame->show();

    //QScrollArea
    QScrollArea scrollArea(MyWidget);
    scrollArea.setWidget(InnerWidget_2);
    scrollArea.setGeometry(100,100,200,200);
    scrollArea.show();

    //Layout examples
    LayoutCustomWidget* MyLayout = new LayoutCustomWidget(nullptr);
    MyLayout->setLayout(MyLayout->layout);
    MyLayout->move(100, 200);
    MyLayout->show();

    return MyApplicationInstance.exec();
}

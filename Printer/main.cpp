#include "printer.h"
#include <QApplication>
#include <QPushButton>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    Printer* printerWgt = new Printer();
    QPushButton* printButton = new QPushButton("&Print");

    QObject::connect(printButton, &QPushButton::clicked, printerWgt, &Printer::slotPrint);

    QVBoxLayout* layout = new QVBoxLayout();
    wgt.setLayout(layout);
    layout->addWidget(printerWgt);
    layout->addWidget(printButton);

    wgt.resize(300, 500);
    wgt.show();
    return a.exec();
}

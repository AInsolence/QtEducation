#include "printer.h"
#include "QPrintDialog"
#include "QPainter"

Printer::Printer(QWidget *parent)
    : QWidget(parent)
{
    myPrinter = new QPrinter();
    myPrinter->setDocName("PrintFileFromQT");
}

Printer::~Printer()
{
    delete myPrinter;
}

void Printer::paintEvent(QPaintEvent *pe)
{
    draw(this);
}

void Printer::draw(QPaintDevice *paintDevice)
{
    QPainter painter(paintDevice);
    QRect areaForPrinting(painter.viewport());

    painter.setBrush(Qt::yellow);
    painter.drawRect(areaForPrinting);
    painter.drawLine(0, 0, areaForPrinting.width(), areaForPrinting.height());
    painter.drawLine(areaForPrinting.width(), 0, 0, areaForPrinting.height());

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::red, 3, Qt::DashLine));
    painter.drawEllipse(areaForPrinting);

    painter.setPen(Qt::blue);
    painter.setFont(QFont("Times", 20, QFont::Normal));
    painter.drawText(areaForPrinting, Qt::AlignCenter, "Printer Test Text");
}

void Printer::slotPrint()
{
    QPrintDialog printDialog(myPrinter, this);
    if(printDialog.exec() == QDialog::Accepted){
        draw(myPrinter);
    }
}

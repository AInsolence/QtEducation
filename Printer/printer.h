#ifndef PRINTER_H
#define PRINTER_H

#include <QWidget>
#include <QPrinter>

class Printer : public QWidget
{
    Q_OBJECT

public:
    Printer(QWidget *parent = nullptr);
    ~Printer();

protected:
    virtual void paintEvent(QPaintEvent* pe) override;
    void draw(QPaintDevice* paintDevice);

private:
    QPrinter* myPrinter = nullptr;

public slots:
    void slotPrint();
};

#endif // PRINTER_H

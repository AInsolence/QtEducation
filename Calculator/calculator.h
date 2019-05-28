#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QStack>
#include <QLCDNumber>
#include <QLayout>
#include <QPushButton>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    QPushButton* createButton(const QString& buttonName);
    void calculate();

private:
    QLCDNumber* lcdDisplay;
    QStack<QString> operationStack;// store all operands & operators from user input
    QString strToDisplay;

public slots:
    void slotButtonClicked();
};

#endif // CALCULATOR_H

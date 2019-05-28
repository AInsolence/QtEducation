#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    constexpr uint displaySize = 12;
    lcdDisplay = new QLCDNumber(displaySize);
    lcdDisplay->setSegmentStyle(QLCDNumber::Flat);
    lcdDisplay->setMinimumSize(160, 50);

    constexpr int buttonRows = 4;
    constexpr int buttonColumns = 4;
    QChar calcButtons [buttonRows][buttonColumns] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'0', '.', '=', '+'}
    };
    // create Layout
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(lcdDisplay, 0, 0, 1, 4);// add display area
    // add buttons
    layout->addWidget(createButton("CE"), 1, 3);

    for (int i = 0; i < buttonRows; ++i) {
        for(int j = 0; j < buttonColumns; ++j){
            layout->addWidget(createButton(calcButtons[i][j]), i + 2, j, 1, 1);
        }
    }

    setLayout(layout);
}

Calculator::~Calculator()
{

}

QPushButton *Calculator::createButton(const QString &buttonName)
{
    QPushButton* button = new QPushButton(buttonName);
    button->setMinimumSize(40, 40);
    button->setCursor(QCursor(Qt::PointingHandCursor));

    connect(button, &QPushButton::clicked, this, &Calculator::slotButtonClicked);

    return button;
}

void Calculator::calculate()
{
    double operand_2 = operationStack.pop().toDouble();
    QString operation = operationStack.pop();
    double operand_1 = operationStack.pop().toDouble();
    double result = 0;

    if(operation == "+"){
        result = operand_1 + operand_2;
    }
    if(operation == "-"){
        result = operand_1 - operand_2;
    }
    if(operation == "*"){
        result = operand_1 * operand_2;
    }
    if(operation == "/"){
        result = operand_1 / operand_2;
    }

    operationStack.clear();
    strToDisplay = "";

    lcdDisplay->display(result);
}

void Calculator::slotButtonClicked()
{
    QString userInput = (dynamic_cast<QPushButton*>(sender())->text());
    // handle user input
    if(userInput == "CE"){
        operationStack.clear();
        strToDisplay = "";
        lcdDisplay->display(0);
        return;
    }
    if(userInput.contains(QRegExp("[0-9]"))){
        strToDisplay += userInput;
        lcdDisplay->display(strToDisplay.toDouble());
    }
    else if(userInput == "."){
        strToDisplay += userInput;
        lcdDisplay->display(strToDisplay);
    }
    else{
        if(operationStack.count() >= 2){// if stack contain number + operator
            operationStack.push(QString::number(lcdDisplay->value()));
            calculate();
            if(userInput != "="){
                operationStack.push(userInput);
            }
        }
        else{// if stack contain only one element or empty
            operationStack.push(QString::number(lcdDisplay->value()));
            operationStack.push(userInput);
            strToDisplay = "";
        }
    }
}

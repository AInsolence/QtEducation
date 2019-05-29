#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    //QLable example NOTE: windows version only underscored with ALT and doesnt work as reference

    QLabel* label = new QLabel("&My name: ", this);
    QLabel* label2 = new QLabel("&My age: ", this);

    QLineEdit* lineEditArea = new QLineEdit("Name", this);
    label->setBuddy(lineEditArea);
    QSpinBox* lineEditArea_2 = new QSpinBox(this);
    lineEditArea_2->setRange(0, LONG_MAX);
    label2->setBuddy(lineEditArea_2);

    QVBoxLayout* labelExamplelayout = new QVBoxLayout();
    labelExamplelayout->addWidget(label);
    labelExamplelayout->addWidget(lineEditArea);
    labelExamplelayout->addWidget(label2);
    labelExamplelayout->addWidget(lineEditArea_2);
    labelExamplelayout->setSpacing(20);
    setLayout(labelExamplelayout);
    show();

    //QProgressBar example
    QHBoxLayout* progressLayout = new QHBoxLayout();
    progressLayout->setSpacing(30);

    progressBar = new QProgressBar();
    QPushButton* stepProgress = new QPushButton("STEP");
    QPushButton* resetProgress = new QPushButton("RESET");

    progressLayout->addWidget(progressBar);
    progressLayout->addWidget(stepProgress);
    progressLayout->addWidget(resetProgress);

    progressBar->setMinimumSize(300, 30);
    progressBar->setRange(0,100);
    labelExamplelayout->addLayout(progressLayout);

    connect(stepProgress, &QPushButton::clicked, this, &Widget::slotStep);
    connect(resetProgress, &QPushButton::clicked, this, &Widget::slotReset);

    //QLCDNumber example
    QLCDNumber* displayLCD = new QLCDNumber(12, this);
    displayLCD->setHexMode();
    displayLCD->setFixedHeight(30);
    connect(lineEditArea_2, qOverload<int>(&QSpinBox::valueChanged), displayLCD, qOverload<int>(&QLCDNumber::display));

    labelExamplelayout->addWidget(displayLCD);
}

Widget::~Widget()
{

}

void Widget::slotStep()
{
    progressValue += 10;
    progressBar->setValue(progressValue);
}

void Widget::slotReset()
{
    progressValue = 0;
    progressBar->reset();
}

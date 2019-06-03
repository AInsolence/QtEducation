#include "mainwidget.h"
#include <QtWidgets>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();

    //Input elements example
    QVBoxLayout* inputLayout = new QVBoxLayout();
    layout->addLayout(inputLayout);

    //QLineEdit example
    QLabel* header = new QLabel("Input your name and password to enter");
    header->setMinimumSize(QSize(200, 80));
    header->setFrameStyle(QFrame::Box | QFrame::Raised);// set frame for whole widget
    header->setLineWidth(3);
    header->setMargin(5);

    QLabel* nameFieldLabel = new QLabel("&Name:");
    QLineEdit* userName = new QLineEdit("Anton");
    nameFieldLabel->setBuddy(userName);
    QLabel* passFieldLabel = new QLabel("&Password:");
    QLineEdit* password = new QLineEdit("ItWasHereBeforeYouStartEdit");
    password->setEchoMode(QLineEdit::Password);
    password->setMaxLength(30);// set max length of string in line
    passFieldLabel->setBuddy(password);

    inputLayout->addWidget(header);
    inputLayout->addWidget(nameFieldLabel);
    inputLayout->addWidget(userName);
    inputLayout->addWidget(passFieldLabel);
    inputLayout->addWidget(password);

    connect(password, &QLineEdit::textEdited, header, &QLabel::setText);
    //connect(userName, &QLineEdit::returnPressed, userName, &QLineEdit::setDisabled);

    //QTextEdit example
    QLabel* header_2 = new QLabel("Text editor example");
    header_2->setMinimumSize(QSize(200, 80));
    header_2->setFrameStyle(QFrame::Box | QFrame::Raised);// set frame for whole widget
    header_2->setAlignment(Qt::AlignCenter);
    header_2->setLineWidth(3);
    header_2->setMargin(5);

    QTextEdit* textEditArea = new QTextEdit();
    textEditArea->setHtml("<!DOCTYPE html>"
                          "<html>"
                          "<head>"
                          "<style>"
                          "body {background-color: powderblue;}"
                          "h1   {color: blue;}"
                          "p    {color: red;}"
                          "</style>"
                          "</head>"
                          "<body>"

                          "<h1>This is a header</h1>"
                          "<p>This is a paragraph</p>"

                          "</body>"
                          "</html>");
    //textEditArea->setReadOnly(true);
    textEditArea->append("New line in the text area field was added with append()");
    QGroupBox* boxForSlider = new QGroupBox("Font size:");
    QHBoxLayout* boxLayout = new QHBoxLayout();
    QSlider* fontSize = new QSlider(Qt::Horizontal);
    QPushButton* increaseFont = new QPushButton("+");
    QPushButton* decreaseFont = new QPushButton("-");
    boxForSlider->setLayout(boxLayout);
    boxLayout->addWidget(fontSize);
    boxLayout->addWidget(increaseFont);
    boxLayout->addWidget(decreaseFont);

    fontSize->setRange(10, 200);
    fontSize->setTickPosition(QSlider::TicksBelow);
    fontSize->setMinimumWidth(100);
    textEditArea->selectAll();
    //change font size with slider
    connect(fontSize, &QSlider::valueChanged, textEditArea, &QTextEdit::selectAll);
    connect(fontSize, &QSlider::valueChanged, textEditArea, &QTextEdit::setFontPointSize);
    //change font size with buttons
    connect(increaseFont, &QPushButton::clicked, this, &MainWidget::callSetRangeIn);
    connect(decreaseFont, &QPushButton::clicked, this, &MainWidget::callSetRangeOut);
    //helper signals call to set range value in zoomIn/zoomOut slots
    connect(this, &MainWidget::setRangeInSignal, textEditArea, &QTextEdit::zoomIn);
    connect(this, &MainWidget::setRangeOutSignal, textEditArea, &QTextEdit::zoomOut);

    inputLayout->addWidget(header_2);
    inputLayout->addWidget(textEditArea);
    inputLayout->addWidget(boxForSlider);

    setLayout(layout);
    show();
}

MainWidget::~MainWidget()
{

}

void MainWidget::callSetRangeIn()
{
    emit setRangeInSignal(2);
}

void MainWidget::callSetRangeOut()
{
    emit setRangeOutSignal(2);
}

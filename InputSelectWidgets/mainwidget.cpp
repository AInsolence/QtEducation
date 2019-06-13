#include "mainwidget.h"
#include <QtWidgets>
#include <QtPrintSupport/QPrinter>
#include <myhighlighter.h>

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

    if(textEditArea->toPlainText().contains("header")){
        textEditArea->append("\"Header finded!\"");
    };

    inputLayout->addWidget(header_2);
    inputLayout->addWidget(textEditArea);
    inputLayout->addWidget(boxForSlider);

    //QTextDocumentWriter example
    QTextDocumentWriter* writer = new QTextDocumentWriter("document.html");
    //writer->setFormat("html");
    //writer->setFileName("document.html");

    QPushButton* save = new QPushButton("Save");
    inputLayout->addWidget(save);
    // try to create signal called lambda function
    //writer->write(textEditArea->document());
    connect(save, &QPushButton::clicked, [=](){writer->write(textEditArea->document());});

    //QPrinter save as pdf file
    QPrinter* printer = new QPrinter(QPrinter::PrinterMode::HighResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("documentFromPrinter.pdf");
    connect(save, &QPushButton::clicked, [=](){textEditArea->document()->print(printer);});

    //QSyntaxHighlighter example
    QVBoxLayout* highlighterLayout = new QVBoxLayout();
    layout->addLayout(highlighterLayout);

    QTextEdit* editorC = new QTextEdit();
    editorC->setMinimumSize(400, 400);
    highlighterLayout->addWidget(editorC);
    //init font
    QFont* editorFont = new QFont("Times", 20, QFont::Thin);
    editorC->setFont(*editorFont);
    //create buttons to set font attributes
    QGroupBox* fontSettings = new QGroupBox("Font settings:");
    QHBoxLayout* fontGroupBox = new QHBoxLayout();
    fontSettings->setLayout(fontGroupBox);
    highlighterLayout->addWidget(fontSettings);

    QRadioButton* thinFontButton = new QRadioButton("Thin");
    thinFontButton->setChecked(true);
    QRadioButton* boldFontButton = new QRadioButton("Bold");
    QCheckBox* italicFontButton = new QCheckBox("Italic");
    fontGroupBox->addWidget(thinFontButton);
    fontGroupBox->addWidget(boldFontButton);
    fontGroupBox->addWidget(italicFontButton);
    //connect buttons
    connect(thinFontButton, &QRadioButton::clicked, [=](){editorC->setFontWeight(QFont::Thin);});
    connect(boldFontButton, &QRadioButton::clicked, [=](){editorC->setFontWeight(QFont::Bold);});
    connect(italicFontButton, &QCheckBox::toggled, editorC, &QTextEdit::setFontItalic);
    //set standart background and text color in pallet and apply it to editor
    QPalette* editorPalette = new QPalette();
    editorPalette->setColor(QPalette::Base, Qt::gray);
    editorPalette->setColor(QPalette::Text, Qt::blue);
    editorC->setPalette(*editorPalette);
    //create highlighter and attach it to editor
    MyHighlighter* highlighter = new MyHighlighter(editorC->document());

    //QDateTimeEdit example
    QDateTimeEdit* dateTimeArea = new QDateTimeEdit(QDateTime::currentDateTime());
    highlighterLayout->addWidget(dateTimeArea);

    /**************** Selection widgets **********************/
    QVBoxLayout* selectionLayout = new QVBoxLayout();
    layout->addLayout(selectionLayout);

    //QListWidget
    QListWidget* osList = new QListWidget();
    selectionLayout->addWidget(osList);
    osList->setIconSize(QSize(40, 40));

    QStringList osStrList;
    osStrList << "Windows" << "MacOS" << "Linux" << "Android";

    for(QString os : osStrList){
        QListWidgetItem* item = new QListWidgetItem(os, osList);
        item->setIcon(QPixmap(":/images/" + os + ".png"));
    }
    // sort AFTER all elements in list
    osList->sortItems(Qt::AscendingOrder);
    osList->setSelectionMode(QAbstractItemView::MultiSelection);// set selection MODE

    connect(osList,&QListWidget::clicked, [=] () {//take pointer by value cause by ref ->> runtime error
        for(auto msg : osList->selectedItems()){// get list of selected items
            editorC->append(msg->text());
        }
        qDebug() << osList->currentItem()->text();// get ONE selected item
    });
    connect(osList, &QListWidget::itemClicked, [=](QListWidgetItem* item){
        qDebug() << item->text() << " item clicked";
    });
    connect(osList, &QListWidget::itemDoubleClicked, [=](QListWidgetItem* item){
        qDebug() << item->text() << " item double clicked";
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable
                       | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    });

    //Pictogram mode
    osList->setViewMode(QListView::IconMode);
    //Set view flow
    osList->setFlow(QListView::TopToBottom);
    // clone() method example
    QListWidget* osList_2 = new QListWidget();
    selectionLayout->addWidget(osList_2);
    osList_2->setIconSize(QSize(40, 40));

    osList_2->addItem(osList->item(0)->clone());//clone from first list

    //QTreeWidget example

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

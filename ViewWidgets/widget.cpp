#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* label = new QLabel("&My name: ", this);
    QLabel* label2 = new QLabel("&My age: ", this);

    QLineEdit* lineEditArea = new QLineEdit("Name", this);
    //QLable example NOTE: windows version only underscored with ALT and doesnt work as reference
    label->setBuddy(lineEditArea);
    QSpinBox* lineEditArea_2 = new QSpinBox(this);
    lineEditArea_2->setRange(0, LONG_MAX);
    lineEditArea_2->setPrefix("Num: ");
    lineEditArea_2->setSuffix(" (DEC)");
    lineEditArea_2->setMinimumHeight(30);
    lineEditArea_2->setButtonSymbols(QSpinBox::PlusMinus);// do not work on win10(why??)
    label2->setBuddy(lineEditArea_2);

    QVBoxLayout* wrapperLayoutLevel_2 = new QVBoxLayout();
    wrapperLayoutLevel_2->setMargin(10);
    wrapperLayoutLevel_2->setSpacing(50);
    setLayout(wrapperLayoutLevel_2);

    QHBoxLayout* wrapperLayoutLevel_1 = new QHBoxLayout();
    wrapperLayoutLevel_2->addLayout(wrapperLayoutLevel_1);
    wrapperLayoutLevel_1->setMargin(10);
    wrapperLayoutLevel_1->setSpacing(30);

    QVBoxLayout* labelExamplelayout = new QVBoxLayout();
    wrapperLayoutLevel_1->addLayout(labelExamplelayout);
    labelExamplelayout->addWidget(label);
    labelExamplelayout->addWidget(lineEditArea);
    labelExamplelayout->addWidget(label2);
    labelExamplelayout->addWidget(lineEditArea_2);
    labelExamplelayout->setSpacing(20);

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

    //Buttons examples
    QVBoxLayout* buttonsExamplelayout = new QVBoxLayout();
    buttonsExamplelayout->setAlignment(Qt::AlignCenter);
    buttonsExamplelayout->setMargin(10);
    buttonsExamplelayout->setSpacing(20);
    wrapperLayoutLevel_1->addLayout(buttonsExamplelayout);

    QPushButton* normalButton = new QPushButton("&Normal button");
    QPushButton* toggledButton = new QPushButton("Toggled button");
    toggledButton->setCheckable(true);//make toggle button
    toggledButton->setChecked(true);//make "on" by default
    QPushButton* flatButton = new QPushButton("Flat button");
    flatButton->setFlat(true);
    QPushButton* pixmapButton = new QPushButton("Pixmap button");
    QPixmap trooper(":/images/calculator.png");
    pixmapButton->setIcon(trooper);
    pixmapButton->setIconSize(QSize(30, 30));
    normalButton->setDefault(true);

    buttonsExamplelayout->addWidget(normalButton);
    buttonsExamplelayout->addWidget(toggledButton);
    buttonsExamplelayout->addWidget(flatButton);
    buttonsExamplelayout->addWidget(pixmapButton);

    QMenu* dropDownMenu = new QMenu (pixmapButton);
    dropDownMenu->addAction("Push me first");
    dropDownMenu->addAction("Push me second");
    dropDownMenu->addAction("Exit", &QApplication::quit);
    pixmapButton->setMenu(dropDownMenu);

    //Checkbox examples
    QCheckBox* normalCheckBox = new QCheckBox("&Filled segments");
    QCheckBox* tristateCheckbox = new QCheckBox("&Triple state box");

    tristateCheckbox->setTristate(true);//allows using third "undefined" state
    tristateCheckbox->setCheckState(Qt::PartiallyChecked);

    buttonsExamplelayout->addWidget(normalCheckBox);
    buttonsExamplelayout->addWidget(tristateCheckbox);

    //Radio buttons and GroupBox example
    QGroupBox* radioBox = new QGroupBox("&Choose your color:");
    buttonsExamplelayout->addWidget(radioBox);
    radioBox->setLayout(new QHBoxLayout());

    QRadioButton* redRadio = new QRadioButton("&Red");// use Alt+R shortcut
    QRadioButton* blueRadio = new QRadioButton("&Blue");
    QRadioButton* greenRadio = new QRadioButton("&Green");

    radioBox->layout()->addWidget(redRadio);
    radioBox->layout()->addWidget(blueRadio);
    radioBox->layout()->addWidget(greenRadio);
    redRadio->setChecked(true);
    blueRadio->setFocus();// set TAB focus on button

    QPushButton* exit = new QPushButton("Exit");
    radioBox->layout()->addWidget(exit);
    connect(exit, &QPushButton::clicked, &QApplication::quit);

    //Slider examples
    QHBoxLayout* wrapperLayoutLevel_1_2 = new QHBoxLayout();
    wrapperLayoutLevel_2->addLayout(wrapperLayoutLevel_1_2);
    wrapperLayoutLevel_1_2->setMargin(10);
    wrapperLayoutLevel_1_2->setSpacing(50);
    wrapperLayoutLevel_1_2->setAlignment(Qt::AlignLeft);
    //QSlider
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,30);
    slider->setMinimumSize(QSize(50, 10));
    slider->setSingleStep(2);// arrow buttons pressed interval
    slider->setValue(3);// init default value
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setTickInterval(3);// ticks paint interval
    slider->setPageStep(10);// PgUp-PgDown pressed interval
    wrapperLayoutLevel_1_2->addWidget(slider);

    QLabel* slideLable = new QLabel("3");
    slideLable->setMinimumSize(QSize(20, 20));
    wrapperLayoutLevel_1_2->addWidget(slideLable);
    connect(slider, &QSlider::valueChanged, slideLable, qOverload<int>(&QLabel::setNum));

    //QScrollBar
    QScrollBar* scroll = new QScrollBar();
    wrapperLayoutLevel_1_2->addWidget(scroll);
    scroll->setOrientation(Qt::Horizontal);
    scroll->setRange(0, 100);
    //scroll->setSingleStep(2);
    //scroll->setPageStep(5);
    scroll->setMinimumSize(QSize(250, 5));
    connect(scroll, &QScrollBar::valueChanged, lineEditArea_2, &QSpinBox::setValue);

    //QDial
    QDial* dial = new QDial();
    dial->setNotchTarget(2);// ticks paint interval
    dial->setNotchesVisible(true);
    dial->setRange(0, 100);
    dial->setWrapping(true);// make loop form min to max, false by default
    wrapperLayoutLevel_1_2->addWidget(dial);
    connect(dial, &QDial::valueChanged, progressBar, &QProgressBar::setValue);

    show();
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

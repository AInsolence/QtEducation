#include "qsswidget.h"

#include "QPushButton"
#include "QLayout"
#include "QFile"
#include "QDebug"

QSSWidget::QSSWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* button_1 = new QPushButton("Button 1");
    QPushButton* button_2 = new QPushButton("Button 2");
    QPushButton* button_3 = new QPushButton("Button 3");

    layout->addWidget(button_1);
    layout->addWidget(button_2);
    layout->addWidget(button_3);

    setLayout(layout);
    resize(500, 300);

    QFile styleFile(":/style.qss");
    if(styleFile.open(QFile::ReadOnly)){
        QString style (styleFile.readAll());
        setStyleSheet(style);
    }
    else {
        qDebug() << "Cannot open style.qss file";
    }

    ensurePolished();
}

QSSWidget::~QSSWidget()
{

}

void QSSWidget::paintEvent(QPaintEvent *event)
{

}

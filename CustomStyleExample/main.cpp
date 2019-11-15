#include "customstyle.h"
#include <QApplication>
#include "mylabel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;
    MyLabel label;

    wgt.resize(1000, 1000);

    QVBoxLayout* layout = new QVBoxLayout();
    QPushButton* btn_1 = new QPushButton("button 1");
    QPushButton* btn_2 = new QPushButton("button 2");
    QPushButton* btn_3 = new QPushButton("button 3");

    btn_1->setMinimumSize(100, 100);
    QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    policy.setHeightForWidth(true);
    btn_1->setSizePolicy(policy);

    layout->addWidget(btn_1);
    layout->addWidget(btn_2);
    layout->addWidget(btn_3);
    layout->addWidget(&label);

    wgt.setLayout(layout);
    app.setStyle(new CustomStyle);

    wgt.show();

    return app.exec();
}

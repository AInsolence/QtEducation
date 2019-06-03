#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void callSetRangeIn();
    void callSetRangeOut();

signals:
    void setRangeInSignal(int scale);
    void setRangeOutSignal(int scale);
};

#endif // MAINWIDGET_H

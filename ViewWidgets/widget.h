#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QProgressBar* progressBar = nullptr;
    int progressValue = 0;

private slots:
    void slotStep();
    void slotReset();
};

#endif // WIDGET_H

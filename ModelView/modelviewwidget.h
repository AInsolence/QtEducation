#ifndef MODELVIEWWIDGET_H
#define MODELVIEWWIDGET_H

#include <QWidget>

class ModelViewWidget : public QWidget
{
    Q_OBJECT

public:
    ModelViewWidget(QWidget *parent = nullptr);
    ~ModelViewWidget();
protected:
    virtual void keyPressEvent(QKeyEvent* myEvent) override;
};

#endif // MODELVIEWWIDGET_H

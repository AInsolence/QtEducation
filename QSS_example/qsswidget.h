#ifndef QSSWIDGET_H
#define QSSWIDGET_H

#include <QWidget>

class QSSWidget : public QWidget
{
    Q_OBJECT

public:
    QSSWidget(QWidget *parent = nullptr);
    ~QSSWidget();
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // QSSWIDGET_H

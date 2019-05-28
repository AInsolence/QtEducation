#ifndef LAYOUTCUSTOMWIDGET_H
#define LAYOUTCUSTOMWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QVector>

class LayoutCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayoutCustomWidget(QWidget *parent = nullptr);
    QBoxLayout* layout = nullptr;

signals:

public slots:

private:
    QVector<QBoxLayout*> rows;
};

#endif // LAYOUTCUSTOMWIDGET_H

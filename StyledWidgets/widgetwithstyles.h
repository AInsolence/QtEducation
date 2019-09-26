#ifndef WIDGETWITHSTYLES_H
#define WIDGETWITHSTYLES_H

#include <QWidget>

class WidgetWithStyles : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetWithStyles(QWidget *parent = nullptr);
public slots:
    void slotSetStyle(const QString& styleName);
};

#endif // WIDGETWITHSTYLES_H

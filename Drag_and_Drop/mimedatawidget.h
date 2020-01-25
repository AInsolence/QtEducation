#ifndef MIMEDATAWIDGET_H
#define MIMEDATAWIDGET_H

#include <QMimeData>

class MimeDataWidget : public QMimeData
{
public:
    MimeDataWidget();
    virtual ~MimeDataWidget();

    static QString mimeType();
    void setWidget(QWidget* wgt);
    QWidget *widget() const;

private:
    QWidget* _wgtPointer = nullptr;
};

#endif // MIMEDATAWIDGET_H

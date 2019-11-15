#ifndef CUSTOMSTYLE_H
#define CUSTOMSTYLE_H

#include <QCommonStyle>
#include <QtWidgets>

class QPainter;

class CustomStyle : public QCommonStyle
{
public:
    virtual void polish(QWidget* wgt) override;
    virtual void unpolish(QWidget* wgt) override;

    virtual void drawPrimitive( PrimitiveElement elem,
                                const QStyleOption* option,
                                QPainter* painter,
                                const QWidget* wgt = nullptr
                                ) const override;
};

#endif // CUSTOMSTYLE_H

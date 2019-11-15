#include "customstyle.h"

class QPushButton;

void CustomStyle::polish(QWidget *wgt)
{
    if(qobject_cast<QPushButton*>(wgt)){
        wgt->setAttribute(Qt::WA_Hover, true);
    }
}

void CustomStyle::unpolish(QWidget *wgt)
{
    if(qobject_cast<QPushButton*>(wgt)){
        wgt->setAttribute(Qt::WA_Hover, false);
    }
}

void CustomStyle::drawPrimitive(QStyle::PrimitiveElement elem,
                                const QStyleOption *option,
                                QPainter *painter,
                                const QWidget *wgt) const
{
    switch (elem) {
        case PE_PanelButtonCommand:
            {
                const QStyleOptionButton* pOptionButton =
                        qstyleoption_cast<const QStyleOptionButton*>(option);
                if(pOptionButton){// if the element is a button
                    // check is it pressed
                    bool bDown = (pOptionButton->state & State_Sunken) ||
                                (pOptionButton->state & State_On);
                    // set an appropriate picture
                    QPixmap buttonPix = bDown ? QPixmap(":/button/button-on.png") :
                                                QPixmap(":/button/button-off.png");

                    painter->drawPixmap(pOptionButton->rect, buttonPix);
                    // check is it on hover
                    bool bHover = (pOptionButton->state & State_Enabled) &&
                            (pOptionButton->state & State_MouseOver);
                    if(bHover){// draw translucent rect on hover
                        painter->fillRect(pOptionButton->rect, QColor(25, 97, 45, 83));
                    }
                }
            }
            break;

        default:
            QCommonStyle::drawPrimitive(elem, option, painter, wgt);
            break;
    }
    return;
}

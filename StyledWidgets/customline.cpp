#include "customline.h"
#include <QRegExpValidator>

CustomLine::CustomLine(QWidget *parent) : QLineEdit(parent)
{
    QRegExp hexExp("[0-9a-fA-F]+");
    setValidator(new QRegExpValidator(hexExp, this));
}

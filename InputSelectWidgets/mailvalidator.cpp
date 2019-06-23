#include "mailvalidator.h"

MailValidator::MailValidator(QObject* parent)
{

}

QValidator::State MailValidator::validate(QString &input, int &pos) const
{
    QRegExp emailRegExp(QRegExp("\\+7\\([0-9]{3}\\)[0-9]{0,7}"));
    if(input.contains(emailRegExp)){
        return Acceptable;
    }
    return Invalid;
}

#ifndef MAILVALIDATOR_H
#define MAILVALIDATOR_H

#include <QObject>
#include <QValidator>

class MailValidator : public QValidator
{
    Q_OBJECT
public:
    MailValidator(QObject* parent = nullptr);
    virtual State validate(QString &input, int &pos) const override;

signals:

public slots:
};

#endif // MAILVALIDATOR_H

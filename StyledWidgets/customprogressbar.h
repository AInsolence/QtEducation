#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QFrame>

class CustomProgressBar : public QFrame
{
    Q_OBJECT
public:
    explicit CustomProgressBar(QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *) override;
    virtual QSize sizeHint() const override;
private:
    int _progressInPercentage = 0;

signals:
    void progressChanged(int);
public slots:
    void slotSetProgress(int percentage);
};

#endif // CUSTOMPROGRESSBAR_H

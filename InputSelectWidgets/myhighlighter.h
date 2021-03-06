#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class QTextDocument;

class MyHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    MyHighlighter(QTextDocument* parent = nullptr);
    virtual void highlightBlock(const QString& str);

private:
    QStringList keyWordList;
    QStringList keySymbolsList;

    QString isStringKeyWord(int ipos, const QString &str);
    QString isStringKeySymbol(int ipos, const QString &str);
};

#endif // MYHIGHLIGHTER_H

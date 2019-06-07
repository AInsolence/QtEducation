#include "myhighlighter.h"
#include <QFile>
#include <QDebug>

MyHighlighter::MyHighlighter(QTextDocument* parent):
    QSyntaxHighlighter (parent)
{
    QFile keyWordsFile(":/data/keyWords.txt");
    QFile keySymbolsFile(":/data/keySymbols.txt");

    if(!keyWordsFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Key words data file is not open";
    }
    // read whole key words content
    QString wordsContent = keyWordsFile.readAll();
    // extract words
    keyWordList = wordsContent.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);

    if(!keySymbolsFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Key symbols data file is not open";
    }
    // read whole symbols content
    QString symbolsContent = keySymbolsFile.readAll();
    // extract symbols
    keySymbolsList = symbolsContent.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);

    keyWordsFile.close();
    keySymbolsFile.close();
}

void MyHighlighter::highlightBlock(const QString &str)
{
    int i = 0;
    while(i < str.length()){
        if(str.at(i).isDigit()){
            setFormat(i, 1, Qt::darkMagenta);
            ++i;
        }
        else if(!isStringKeySymbol(i, str).isEmpty()){// is special symbol
            setFormat(i, isStringKeySymbol(i, str).length(), Qt::darkBlue);
            i += isStringKeySymbol(i, str).length();
        }
        else if(!isStringKeyWord(i, str).isEmpty()){// is key word
            setFormat(i, isStringKeyWord(i, str).length(), Qt::darkGreen);
            i += isStringKeyWord(i, str).length();
        }
        else{
            ++i;
        }
    }
}

QString MyHighlighter::isStringKeyWord(int ipos, const QString &str)
{
    for(QString word : keyWordList){
        if(str.mid(ipos, word.length()) == word){
            return word;
        }
    }
    return "";
}

QString MyHighlighter::isStringKeySymbol(int ipos, const QString &str)
{
    for(QString symbol : keySymbolsList){
        if(str.mid(ipos, symbol.length()) == symbol){
            return symbol;
        }
    }
    return "";
}

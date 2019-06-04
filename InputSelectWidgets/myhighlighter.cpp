#include "myhighlighter.h"

MyHighlighter::MyHighlighter(QTextDocument* parent):
    QSyntaxHighlighter (parent)
{

}

void MyHighlighter::highlightBlock(const QString &str)
{
    for(int i = 0; i < str.length(); ++i){
        if(str.at(i).isDigit()){
            setFormat(i, 1, Qt::darkMagenta);
        }
    }
}

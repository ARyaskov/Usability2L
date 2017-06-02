#ifndef IVLHIGHLIGHTER_H
#define IVLHIGHLIGHTER_H

#include "../includes/pch.h"

class IVLHighlighter: public QSyntaxHighlighter
{

  public:
    IVLHighlighter(QTextDocument* document);
    ~IVLHighlighter();


    void highlightBlock(const QString &text);


};

#endif // IVLHIGHLIGHTER_H

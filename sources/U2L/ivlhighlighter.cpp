#include "../../includes/U2L/ivlhighlighter.h"


IVLHighlighter::IVLHighlighter(QTextDocument* document): QSyntaxHighlighter(document)
{

}

IVLHighlighter::~IVLHighlighter()
{

}


void IVLHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat myClassFormat;
    QString pattern;
    QRegExp expression;
    int index;

    enum block_state{NormalState=-1,
                     SQuotesState = 0,
                     DQuotesState=1,
                     InsideCStyleComment=2};



    /* Normal */
    myClassFormat.setForeground(QColor("Black"));
    myClassFormat.setFontWeight(QFont::Normal);
    myClassFormat.setFontUnderline(false);
    myClassFormat.setFontItalic(false);

    pattern = "[A-Za-z0-9]+";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {

        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }



    /* Properties*/
    myClassFormat.setFontWeight(QFont::Bold);
    //
    myClassFormat.setForeground(QColor(0x7b,0x9e,0x00));


    pattern = "\\B@[A-Za-z0-9]+";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }


    /* Predicate squares*/
    myClassFormat.setForeground(QColor(0x08,0x6C,0xA2));
    myClassFormat.setFontWeight(QFont::Bold);

    pattern = "[\\[\\]]";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }


    /* . */
    myClassFormat.setForeground(QColor(0x08,0x6C,0xA2));
    myClassFormat.setFontWeight(QFont::Bold);
    myClassFormat.setFontFamily("Comic Sans");

    pattern = "[\\.]";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }

    /* Signs */
    myClassFormat.setForeground(QColor(0x00,0x00,0x00));
    myClassFormat.setFontWeight(QFont::Black);
    //myClassFormat.setFontItalic(true);

    pattern = "[!=:-><]";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }


    /* Keywords */
    myClassFormat.setForeground(QColor(0x7b,0x9e,0x00));
    myClassFormat.setFontWeight(QFont::Bold);
    myClassFormat.setFontUnderline(true);

    pattern = "meta|app|beh|warnings|errors|global";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }


    // Strings
    myClassFormat.setForeground(QColor(0x1b,0x1b,0xb3));
    myClassFormat.setFontUnderline(false);

    pattern = "\\B\".+\"\\B";

    expression = QRegExp(pattern);
    index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }


    // Comments
    int state = previousBlockState();
    int start = 0;

    for (int i = 0; i < text.length(); ++i) {

        if (state == InsideCStyleComment) {
            if (text.mid(i, 2) == "*/") {
                state = NormalState;
                setFormat(start, i - start + 2, Qt::blue);
            }
        }else {
                if (text.mid(i, 2) == "//") {
                    setFormat(i, text.length() - i, Qt::red);
                    break;
                } else if (text.mid(i, 2) == "/*") {
                    start = i;
                    state = InsideCStyleComment;
                }

        }
        if (state == InsideCStyleComment)
            setFormat(start, text.length() - start, Qt::blue);



    }
    setCurrentBlockState(state);
}

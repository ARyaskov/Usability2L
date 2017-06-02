/**
* @file ivllexer.h
* @brief описание класса подсветки синтаксиса для IVL редактора
*
* @author Андрей Рясков
* @date

*/



#ifndef IVLLEXER_H
#define IVLLEXER_H
#ifndef Q_MOC_RUN

#include "../../includes/pch.h"


class IVLLexer : public QsciLexerCustom
{

public:

    IVLLexer(QObject * parent = 0);

    ~IVLLexer();


    const char * language() const;
    QColor defaultColor(int style) const;
    QFont defaultFont(int style) const;
    QColor defaultPaper(int style) const;
    void styleText (int start, int end);
    QString description (int style) const;
    bool commentStyling(const QString & line, int start, int end);
    bool defaultStyling(const QString & line, int start, int end);
    bool propertiesStyling(const QString & line, int start, int end);
    bool metaPropertiesStyling(const QString & line, int start, int end);
    bool bracketsStyling(const QString & line, int start, int end);
    bool sign1Styling(const QString & line, int start, int end);
    bool stringStyling(const QString & line, int start, int end);


    enum Style
    {
        Default = 0,
        Comment,
        Property,
        MetaProperty,
        Bracket,
        Sign1,
        Sign2,
        String,
        Keyword1,
        Const
    };

private:
    IVLLexer(const IVLLexer &);
    IVLLexer &operator=(const IVLLexer &);
};


#endif
#endif // IVLLEXER_H

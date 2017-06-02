#include "../../includes/U2L/ivllexer.h"

IVLLexer::IVLLexer(QObject * parent){
    Q_UNUSED(parent)
}

IVLLexer::~IVLLexer(){

}

const char * IVLLexer::language() const
{
    return "IVL";
}

QString IVLLexer::description(int style) const
{
    switch (style)
    {
    case Comment:
        return "Comment";
    case Default:
        return "Default";
    case Property:
        return "Property";
    case MetaProperty:
        return "MetaProperty";
    }

    return QString(style);
}

QColor IVLLexer::defaultColor(int style) const
{
    if (style == Comment)
    {
        // Зелёный, как комментарии в VS
        return QColor("#0C7502");
    }else if (style == Property)
    {
        // Сиреневый
        return QColor("#9709D4");
    }else if (style == MetaProperty){
        // Синий, как ключевые слова в VS
        return QColor(0x07, 0x07, 0xFF);
    }else if (style == Bracket)
    {
        // Синий #081d8c
        return QColor("#081d8c");
    }else if (style == Sign1){
        // Зелёный #228A32
        return QColor("#228A32");
    }else if (style == String)
    {
        return QColor("#FF0000");
    }
    return QColor("#000000"); //QsciLexer::defaultColor(style);
}

QColor IVLLexer::defaultPaper(int style) const
{
    if (style == Comment)
    {
        //return QColor(0x79,0xB7,0x2E);
    }
    return QsciLexer::defaultPaper(style);
}

QFont IVLLexer::defaultFont(int style) const
{
    QFont f("Courier New");
    f.setPointSize(10);

    if (style == Comment)
    {
        // f.setFamily("Comic Sans");

    }
    else if(style == Property)
    {
        //f.setWeight(QFont::Bold);
    }else if(style == MetaProperty)
    {
        //f.setWeight(QFont::Bold);
    }else if (style == Bracket){
        //f.setWeight(QFont::Black);
    }else if (style == Sign1){
        //f.setWeight(QFont::Bold);
    }else if (style == String){
        //f.setWeight(QFont::Bold);
    }else
    {
        //f = QsciLexer::defaultFont(style);
    }

    return f;
}

void IVLLexer::styleText(int start, int end)
{

    if (!this->editor())
        return;


    char * chars = new char[end - start + 1];

    //this->editor()->SendScintilla(QsciScintilla::SCI_GETTEXTRANGE,
    //                              start, end, chars);

    this->editor()->SendScintilla(QsciScintilla::SCI_GETTEXT, end-start+1, chars);

    QString source(chars);
    delete [] chars;

    /*   if (source == cache)
        return;
    else
        cache = source;*/

    if (source.isEmpty())
        return;

    //qDebug() << qPrintable("Here we are: ");
    //qDebug() << qPrintable(source);

    defaultStyling(source, start, end);
    propertiesStyling(source, start, end);
    metaPropertiesStyling(source, start, end);
    bracketsStyling(source, start, end);

    sign1Styling(source, start, end);

    stringStyling(source, start, end);
    commentStyling(source, start, end);
}

bool IVLLexer::stringStyling(const QString &line, int start, int end)
{
    Q_UNUSED(end)
    int style = String;
    int idxStart = 0;
    int idxEnd = idxStart;
    int count = line.count("\"");


    if (count > 1)
        count/=2;

    for (int i = 0; i < count; i++)
    {

        idxStart = line.indexOf("\"", idxStart);

        idxEnd = line.indexOf("\"", idxStart+1);

        //if (start + idxStart > 0){
            startStyling(start + idxStart);
        //}

        //if (idxEnd-idxStart+1 > 0){
            setStyling(idxEnd-idxStart+1, style);
        //}
        //startStyling(start + idxStart);
        //startStyling(start + idxEnd);

        idxStart = idxEnd;
    }

    return true;
}

bool IVLLexer::sign1Styling(const QString &line, int start, int end)
{
    Q_UNUSED(end)
    // ! != == = < > <= >= + -
    int style = Sign1;
    int idxStart = 0;
    int idxEnd = idxStart;
    int count = line.count(QRegExp("[!\\<\\>=\\+-]"));

    for (int i = 0; i < count; i++)
    {

        idxStart = line.indexOf(QRegExp("[!\\<\\>=\\+-]"), idxStart);
        if (idxStart == -1)
            break;

        idxEnd = idxStart+1;

        startStyling(start + idxStart);

        setStyling(1, style);

        startStyling(start + idxEnd);

        idxStart = idxEnd;
    }
    return true;
}

bool IVLLexer::bracketsStyling(const QString &line, int start, int end)
{
    Q_UNUSED(end)
    // [ ] ( ) { }
    int style = Bracket;
    int idxStart = 0;
    int idxEnd = idxStart;
    int count = line.count(QRegExp("[\\[\\]\\(\\)\\{\\}]"));


    for (int i = 0; i < count; i++)
    {

        idxStart = line.indexOf(QRegExp("[\\[\\]\\(\\)\\{\\}]"), idxStart);
        if (idxStart == -1)
            break;
        //int pos = line.indexOf(QRegExp("[\\. ]"), idxStart);

        idxEnd = idxStart+1;


        startStyling(start + idxStart);

        setStyling(1, style);

        startStyling(start + idxEnd);

        idxStart = idxEnd;
    }
    return true;
}

bool IVLLexer::propertiesStyling(const QString &line, int start, int end)
{
    Q_UNUSED(end)
    int style = Property;
    int idxStart = 0;
    int idxEnd = idxStart;
    int count = line.count(QRegExp("@[A-Za-z0-9]*"));

    for (int i = 0; i < count; i++)
    {

        idxStart = line.indexOf(QRegExp("@[A-Za-z0-9]*"), idxStart);
        if (idxStart == -1)
            break;
        int pos = line.indexOf(QRegExp("[\\. ]"), idxStart);
        if (pos != -1)
        {
            idxEnd = pos;
        }
        else
        {
            idxEnd  = idxStart + line.mid(idxStart).size();
        }

        startStyling(start + idxStart);
        int len = idxEnd - idxStart;

        setStyling(len, style);

        startStyling(start + idxEnd);

        idxStart = idxEnd;
    }
    return true;
}

bool IVLLexer::metaPropertiesStyling(const QString &line, int start, int end){
    Q_UNUSED(end)
    int style = MetaProperty;
    int idxStart = 0;
    int idxEnd = idxStart;
    int count = line.count(QRegExp("@(app|beh|global|meta)"));

    for (int i = 0; i < count; i++)
    {

        idxStart = line.indexOf(QRegExp("@(app|beh|global|meta)"), idxStart);
        if (idxStart == -1)
            break;
        int pos = line.indexOf(QRegExp("[\\. ]"), idxStart);
        if (pos != -1)
        {
            idxEnd = pos;
        }
        else
        {
            idxEnd  = idxStart + line.mid(idxStart).size();
        }

        startStyling(start + idxStart);
        int len = idxEnd - idxStart;

        setStyling(len, style);

        startStyling(start + idxEnd);

        idxStart = idxEnd;
    }
    return true;
}

bool IVLLexer::defaultStyling(const QString& line, int start, int end)
{
    Q_UNUSED(end)
    int style = Default;
    int idxStart = start;
    int idxEnd = idxStart;


    if (idxStart == -1)
        return false;
    int pos = line.indexOf("\r", idxStart);
    if (pos != -1)
    {
        idxEnd = pos;
    }
    else
    {
        idxEnd  = idxStart + line.mid(idxStart).size();
    }

    startStyling(start + idxStart);
    int len = idxEnd - idxStart;

    setStyling(len, style);

    startStyling(start + idxEnd);

    idxStart = idxEnd;
    return true;
}

bool IVLLexer::commentStyling(const QString & line, int start, int end)
{
    Q_UNUSED(end)
    //Если в строке вообще нет символов комментария, то ничего не делать
    if (!line.contains("//"))
        return false;
    int count = line.count("//");
    int style = Comment;
    int idxStart = 0;
    int idxEnd = idxStart;

    for (int i = 0; i < count; i++)
    {
        idxStart = line.indexOf("//", idxStart);
        if (idxStart == -1)
            break;
        int pos = line.indexOf("\r", idxStart);
        if (pos != -1)
        {
            idxEnd = pos;
        }
        else
        {
            idxEnd  = idxStart + line.mid(idxStart).size();
        }
        //Здесь мы сообщаем, что начинаем новый стиль
        //с позиции start + idxStart
        startStyling(start + idxStart);
        int len = idxEnd - idxStart;
        //А здесь мы сообщаем, что начиная от текущей позиции, определенной startStyling,
        //дальше последуют len символов стиля style == Comment
        setStyling(len, style);
        //Заканчиваем отрисовку стиля
        startStyling(start + idxEnd);

        idxStart = idxEnd;
    }

    return true;
}

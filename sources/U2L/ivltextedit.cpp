#include "../../includes/U2L/ivltextedit.h"

IVLTextEdit::IVLTextEdit(QWidget *parent) :
    QTextEdit(parent)
{
    setEditor(this);
}


void IVLTextEdit::paintEvent(QPaintEvent *e)
{
   // QTextEdit::paintEvent(e);
    QRect region = e->rect();
    QPainter painter(this);
    QPen pen(Qt::red); //Note: set line colour like this

    //(Brush line removed; not necessary when drawing a line)
    int x = 0; //Note changed
    int y = height() /2; //Note changed
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawLine(x,y,x+100,y);


}

void IVLTextEdit::setEditor( QTextEdit * editor )
{
    m_editor = editor;
    connect((QObject*)(editor->verticalScrollBar()), SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect((QObject*)(editor->document()->documentLayout()), SIGNAL(update(const QRectF&)), this, SLOT(update()));
}

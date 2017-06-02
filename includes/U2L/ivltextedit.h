#ifndef IVLTEXTEDIT_H
#define IVLTEXTEDIT_H

#include "../includes/pch.h"


class IVLTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit IVLTextEdit(QWidget *parent = 0);
    void setEditor( QTextEdit * editor );
    QTextEdit *m_editor;
protected:
    void paintEvent(QPaintEvent *e);
    
signals:
    
public slots:
    
};

#endif // IVLTEXTEDIT_H

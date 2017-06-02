/**
* @file metaextensions.h
* @brief описание класса расширения метавозможностей Qt/C++
*

*/

#ifndef METAEXTENSIONS_H
#define METAEXTENSIONS_H

#include "../../includes/pch.h"





class MetaExtension : public QObject
{

public:
    explicit MetaExtension(QObject *parent = 0);



    static bool isDescOf(QObject *obj, const char* className);
    static bool isChildOf(QWidget *obj, QString objectName);
    static bool isChildOf(const char* child, const char* objectName);

signals:
    
public slots:
    
};

#endif // METAEXTENSIONS_H

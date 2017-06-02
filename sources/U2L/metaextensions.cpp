#include "metaextensions.h"

MetaExtension::MetaExtension(QObject *parent) :
    QObject(parent)
{
}


bool MetaExtension::isDescOf(QObject* obj, const char* className)
{
    bool res = false;

    const QMetaObject* cur = obj->metaObject();

    if (QString(className) == QString(cur->className()))
        return true;

    while(cur){
        cur = cur->superClass();
        if (QString(className) == QString(cur->className()))
        {
            res = true;
            cur = NULL;
        }

    }

    return res;
}

bool MetaExtension::isChildOf(QWidget* obj, QString objectName)
{
    bool res = false;

    QWidget* cur = obj;

    if (QString(cur->objectName()) == objectName)
        return true;

    while(cur){
        cur = cur->parentWidget();
        if (cur!=nullptr)
            if (QString(cur->objectName()) == objectName)
            {
                res = true;
                cur = nullptr;
            }

    }

    return res;
}

bool MetaExtension::isChildOf(const char* child, const char* objectName)
{
    bool res = false;
    Q_UNUSED(objectName)
    Q_UNUSED(child)
    /*  QWidget* cur = obj;

    if (QString(cur->objectName()) == QString(objectName))
        return true;

    while(cur){
        cur = cur->parentWidget();
        if (QString(cur->objectName()) == QString(objectName))
        {
            res = true;
            cur = NULL;
        }

    }
*/
    return res;
}


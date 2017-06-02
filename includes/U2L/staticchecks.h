#ifndef STATICCHECKS_H
#define STATICCHECKS_H

#include "../../includes/pch.h"
#include "usabilitycheck.h"
#include "metaextensions.h"
#include "settingsmanager.h"

extern QHash<QObject*, QStringList> errors;
extern QHash<QObject*, QStringList> warnings;




void addError(QObject* obj, QStringList listOfErrors);
void addError(QObject* obj, QString error);
void addWarning(QObject* obj, QStringList listOfWarnings);
void addWarning(QObject* obj, QString warning);


template<class T>
QList<T> getChildrenExceptU2L(QWidget* root)
{
    QStringList forbiddenNames;

    QList<T> list = root->findChildren<T>();
    QMutableListIterator<T> it(list);
    while(it.hasNext())
    {
        T widget = it.next();
        const QMetaObject* meta = widget->metaObject();
        qDebug() << "getChildrenExceptU2L::ClassName: " << meta->className();
        if (meta->className() == "U2LWidget" ||
                MetaExtension::isChildOf(widget, GlobalSM::instance().u2lWidgetName) ||
                   /*widget->objectName().isEmpty() ||*/
                      forbiddenNames.contains(widget->objectName()) ||
                           widget->objectName().startsWith("qt_"))
        {
            it.remove();
            continue;
        }

    }
    return list;
}

class StaticChecks
{
    QList<UsabilityCheck> m_checks;
    QMainWindow* m_mw;
    int m_groupCount;

    StaticChecks(){buildCheckList();}
    StaticChecks(StaticChecks&){}
    StaticChecks& operator=(StaticChecks&){}
    void buildCheckList();
public:
    void setMainWindow(QMainWindow* mw){m_mw = mw;}
    QMainWindow* getMainWindow(){return m_mw;}
    static StaticChecks &instance();
    void runChecks(const QStringList &neededChecks);
    void runChecks(const QList<QTreeWidgetItem *> &neededChecks);

    void addCheck(const QString& in_name, const QString& in_desc,
                  const std::function<void()>& lambda);

    void addCheck(const QString& in_name, const QString& in_desc,
                  const QString& parentGroup, const std::function<void()>& in_lambda);

    void addCheckList(QList<UsabilityCheck>& list);
    QList<UsabilityCheck>& getChecks(){return m_checks;}
    QList<UsabilityCheck> getChecksByGroup(const QString& in_group);
    int getGroupCount(){return m_groupCount;}
    void setGroupCount(int val){m_groupCount = val;}
};

#endif // STATICCHECKS_H

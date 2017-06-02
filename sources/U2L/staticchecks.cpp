#include "staticchecks.h"
#include "../../sources/U2L/guichecks/pushbutton.cpp"
#include "../../sources/U2L/guichecks/combobox.cpp"
#include "../../sources/U2L/guichecks/spinner.cpp"
#include "../../sources/U2L/guichecks/timeedit.cpp"
#include "../../sources/U2L/guichecks/dateedit.cpp"
#include "../../sources/U2L/guichecks/datetimeedit.cpp"
#include "../../sources/U2L/guichecks/lineedit.cpp"
#include "../../sources/U2L/guichecks/groupbox.cpp"
#include "../../sources/U2L/guichecks/tabwidget.cpp"
#include "../../sources/U2L/guichecks/label.cpp"
#include "../../sources/U2L/guichecks/layout.cpp"
#include "../../sources/U2L/guichecks/common.cpp"


void addError(QObject* obj, QStringList listOfErrors)
{
    if (errors.contains(obj))
    {
        QStringList prevList = errors.value(obj);
        prevList.append(listOfErrors);
        errors.insert(obj, prevList);
    }else
    {
        errors.insert(obj, listOfErrors);
    }
}

void addError(QObject* obj, QString error)
{
    addError(obj,QStringList(error));
}

void addWarning(QObject* obj, QStringList listOfWarnings)
{

        if (warnings.contains(obj))
        {
            QStringList prevList = warnings.value(obj);
            prevList.append(listOfWarnings);
            warnings.insert(obj, prevList);
        }else
        {
            warnings.insert(obj, listOfWarnings);
        }

}

void addWarning(QObject* obj, QString warning)
{
    addWarning(obj, QStringList(warning));
}



void StaticChecks::runChecks(const QStringList& neededChecks)
{


    for(int i=0;i<m_checks.size();i++)
    {
        QString curName = m_checks[i].getName();
        // QString curDesc = m_checks.at(i).getDescription();

        if (neededChecks.contains(curName))
        {
            std::function<void()> curLambda = m_checks[i].getCode();
            curLambda();
        }
    }
}

void StaticChecks::runChecks(const QList<QTreeWidgetItem *>& neededChecks)
{


    for(int i=0;i<m_checks.size();i++)
    {
        QString curName = m_checks[i].getName();
        // QString curDesc = m_checks.at(i).getDescription();
        QListIterator<QTreeWidgetItem*> it(neededChecks);
        while(it.hasNext())
        {
            QTreeWidgetItem* curTreeItem = it.next();

            if (!curTreeItem->text(0).compare(curName))
            {
                std::function<void()> curLambda = m_checks[i].getCode();
                curLambda();
                break;
            }
        }

    }

}


StaticChecks& StaticChecks::instance()
{
    static StaticChecks singleton;
    return singleton;

}

void StaticChecks::addCheck(const QString& in_name, const QString& in_desc,const std::function<void()>& in_lambda)
{
    UsabilityCheck check;
    m_checks.append(check);

    m_checks.last().setName(in_name);
    m_checks.last().setDescription(in_desc);
    m_checks.last().setCode(in_lambda);
}

void StaticChecks::addCheck(const QString& in_name, const QString& in_desc, const QString& parentGroup, const std::function<void()>& in_lambda)
{
    UsabilityCheck check;
    m_checks.append(check);

    m_checks.last().setName(in_name);
    m_checks.last().setDescription(in_desc);
    m_checks.last().setParentGroup(parentGroup);
    m_checks.last().setCode(in_lambda);
}



void StaticChecks::addCheckList(QList<UsabilityCheck>& list)
{
    m_checks.append(list);
}

void StaticChecks::buildCheckList()
{


    pushbutton_exec();
    combobox_exec();
    spinner_exec();
    timeedit_exec();
    dateedit_exec();
    datetimeedit_exec();
    lineedit_exec();
    groupbox_exec();
    tabwidget_exec();
    label_exec();
    layout_exec();
    common_exec();
}

QList<UsabilityCheck> StaticChecks::getChecksByGroup(const QString& in_group)
{
    QList<UsabilityCheck> res;

    QListIterator<UsabilityCheck> it(m_checks);
    while(it.hasNext())
    {
        UsabilityCheck curCheck = it.next();
        QString parentGroup = curCheck.getParentGroup();
        if (!parentGroup.compare(in_group))
        {
            res.append(curCheck);
        }
    }
    return res;
}


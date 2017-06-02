
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"

auto layout_exec =
[&]{


StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);

StaticChecks::instance().addCheck(
            QObject::tr("Layout1"),
            QObject::tr("Элемент не связан ни с одним менеджером компоновки"),
            QObject::tr("Менеджеры компоновки (Layouts)"),
            [&]
{

        QList<QWidget*> list = getChildrenExceptU2L<QWidget*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QWidget*> it(list);
           while(it.hasNext())
           {
              QWidget* cur = it.next();

              if (cur->layout() == nullptr)
              {
                  QString str;
str="Элемент не связан ни с одним менеджером компоновки.\
 Менеджеры компоновки позволяют не заботиться о поведении виджетов,\
 при изменении параметров их соседей/окна. Адекватная реакция приложения\
 на изменение размера окна считается хорошим тоном.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }

});

/*
StaticChecks::instance().addCheck(
            QObject::tr("Layout2"),
            QObject::tr("На форме не найдено ни одного Spacer’а"),
            QObject::tr("Менеджеры компоновки (Layouts)"),
            [&]
{

        QList<QSpacerItem*> list = getChildrenExceptU2L<QSpacerItem*>(StaticChecks::instance().getMainWindow());

        if (list.isEmpty())
        {
    QString str;
str="На форме не найдено ни одного Spacer’а.\
 Spacer – это прозрачный виджет, служащий для заполнения места между виджетами,\
 если необходимо оставить некоторый промежуток.\
 Обратите внимание на класс QSpacerItem. Spacer’ы присутствуют на панели виджетов QtDesigner.";
 addWarning(new QObject(), QObject::tr(qPrintable(str)));
        }

});
*/

};


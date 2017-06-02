#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"


auto common_exec =
[&]{

StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);

StaticChecks::instance().addCheck(
            QObject::tr("Common1"),
            QObject::tr("На форме более 7 цветов"),
            QObject::tr("Общие проверки"),
            [&]
{

        QList<QWidget*> list = getChildrenExceptU2L<QWidget*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QList<QColor> colors;
           QListIterator<QWidget*> it(list);
           bool overFlag = false;
           while(it.hasNext())
           {
              QWidget* cur = it.next();
              QColor backColor = cur->palette().color(QPalette::Window);
              QColor foreColor = cur->palette().color(QPalette::WindowText);
              colors.contains(backColor) ? (void(0)) : colors.append(backColor);
              colors.contains(foreColor) ? (void(0)) : colors.append(foreColor);
              if (colors.size() > 7)
              {
                overFlag=true;
                it.toBack();
              }

           }
           if (!overFlag)
           {
           QString str;
str="Цвет делает поиск нужных элементов более удобным. Но не стоит злоупотреблять.\
Как и с количеством элементов в группе, рекомендуется использовать не более 7 цветов на форме.";
addWarning(new QObject(), QObject::tr(qPrintable(str)));
           }

        }
});

};

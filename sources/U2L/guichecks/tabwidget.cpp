
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"




auto tabwidget_exec =
        [&]{
      StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);

StaticChecks::instance().addCheck(
            QObject::tr("TabWidget1"),
            QObject::tr("На вкладках есть элемент, не управляемый менеджером компоновки"),
            QObject::tr("Вкладки TabWidget"),
            [&]
{

        QList<QTabWidget*> list = getChildrenExceptU2L<QTabWidget*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
            QListIterator<QTabWidget*> it(list);
            while(it.hasNext())
            {
                QTabWidget* cur = it.next();
                int j=0;
                int count = cur->count();
                while(j<count)
                {
                    QWidget* curTab = cur->widget(j);

                    QWidgetList widList = getChildrenExceptU2L<QWidget*>(curTab);
                    QListIterator<QWidget*> it2(widList);
                    while(it2.hasNext())
                    {
                      QWidget* w = it2.next();

                      if (w->layout() == nullptr)
                      {
                       QString str;
str="Виджет не включён ни в один менеджер компоновки. Виджет QTabWidget представляет собой\
 такой же контейнер для элементов как и окно, поэтому следует позаботиться о правильной раскладке\
 элементов на каждой вкладке при изменении размера контейнера.";
                       addError(cur, QObject::tr(qPrintable(str)));
                      }
                    }
                    j++;

              }
       }
       }
}
);


};


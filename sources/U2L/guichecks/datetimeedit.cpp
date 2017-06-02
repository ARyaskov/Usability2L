
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"


auto datetimeedit_exec =
        [&]{
  /*      StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);


StaticChecks::instance().addCheck(
            QObject::tr("DateTimeEdit1"),
            QObject::tr("При выборе даты желательно предоставлять календарь"),
            QObject::tr("Виджет DateTimeEdit"),
            [&]
{

        QList<QDateTimeEdit*> list = getChildrenExceptU2L<QDateTimeEdit*>(StaticChecks::instance().getMainWindow());

            if (list.size())
        {
           QListIterator<QDateTimeEdit*> it(list);
           while(it.hasNext())
           {
              QDateTimeEdit* cur = it.next();

              if (cur->calendarPopup() == false)
              {
                  QString str;
str="Рекомендуется предоставлять пользователю календарь, для более удобного выбора даты.\
 Календарь можно включить с помощью метода QDateTimeEdit::setCalendarPopup(bool).";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);*/

};


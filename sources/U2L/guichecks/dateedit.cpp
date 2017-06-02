
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"


auto dateedit_exec =
        [&]{
        StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);


StaticChecks::instance().addCheck(
            QObject::tr("DateEdit1"),
            QObject::tr("При выборе даты желательно предоставлять календарь"),
            QObject::tr("Виджет DateEdit"),
            [&]
{

        QList<QDateEdit*> list = getChildrenExceptU2L<QDateEdit*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
            if (list.size())
        {
           QListIterator<QDateEdit*> it(list);
           while(it.hasNext())
           {
              QDateEdit* cur = it.next();

              if (cur->calendarPopup() == false)
              {
                  QString str;
str="Рекомендуется предоставлять пользователю календарь, для более удобного ввода даты.\
 Календарь можно включить с помощью метода QDateEdit::setCalendarPopup(bool).";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

};

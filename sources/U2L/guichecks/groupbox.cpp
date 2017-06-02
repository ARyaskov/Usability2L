

#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"


auto groupbox_exec =
        [&]{
       StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);



/*StaticChecks::instance().addCheck(
            QObject::tr("GroupBox1"),
            QObject::tr("В группе больше 5 элементов"),
            QObject::tr("Виджет GroupBox"),
            [&]
{
        QStringList containerWidgetNames;
        containerWidgetNames.append("QFrame");
        containerWidgetNames.append("QTabWidget");
        containerWidgetNames.append("QGroupBox");
        QList<QGroupBox*> list = getChildrenExceptU2L<QGroupBox*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QGroupBox*> it(list);
           while(it.hasNext())
           {
              QGroupBox* cur = it.next();
              QList<QWidget*> children = getChildrenExceptU2L<QWidget*>(cur);
              QListIterator<QWidget*> it2(children);
              int count=0;
              while (it2.hasNext())
              {
                  QWidget* curWidget = it2.next();
                  QString className = curWidget->metaObject()->className();

                  if (!containerWidgetNames.contains(className)){
                      MetaExtensions::isChildOf(curWidget, )
                  }
              }
              if (count > 5)
              {
                  QString str;
str="Пользователь на ментальном уровне обычно не запоминает больше 5-7 элементов.\
 Если есть возможность – перегруппируйте.";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);



StaticChecks::instance().addCheck(
            QObject::tr("GroupBox2"),
            QObject::tr("В группе больше 7 элементов"),
            QObject::tr("Виджет GroupBox"),
            [&]
{

        QList<QGroupBox*> list = getChildrenExceptU2L<QGroupBox*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QGroupBox*> it(list);
           while(it.hasNext())
           {
              QGroupBox* cur = it.next();
              QList<QWidget*> children = getChildrenExceptU2L<QWidget*>(cur);
              if (children.size() > 7)
              {
                  QString str;
str="Пользователь на ментальном уровне обычно не запоминает больше 5-7 элементов.\
 Перегруппируйте.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);
*/
StaticChecks::instance().addCheck(
            QObject::tr("GroupBox3"),
            QObject::tr("Группа не имеет заголовка"),
            QObject::tr("Виджет GroupBox"),
            [&]
{

        QList<QGroupBox*> list = getChildrenExceptU2L<QGroupBox*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QGroupBox*> it(list);
           while(it.hasNext())
           {
              QGroupBox* cur = it.next();

              if (cur->title().isEmpty())
              {
                  QString str;
str="Группа должна иметь название, чтобы пользователь мог как-то идентифицировать функции,\
 которая она содержит.\
 Название можно задать с помощью QGroupBox::setTitle(const QString& title).";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("GroupBox4"),
            QObject::tr("В группе есть элементы, не управляемые менеджером компоновки"),
            QObject::tr("Виджет GroupBox"),
            [&]
{

        QList<QGroupBox*> list = getChildrenExceptU2L<QGroupBox*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QGroupBox*> it(list);
           while(it.hasNext())
           {
              QGroupBox* cur = it.next();
              bool exists = false;
              QWidgetList widList = getChildrenExceptU2L<QWidget*>(cur);
              QListIterator<QWidget*> it2(widList);
              while(it2.hasNext())
              {
                  QWidget* w = it2.next();
                  if (w->layout() == nullptr)
                  {
                      QString str;
    str="Виджет не включён ни в один менеджер компоновки. Виджет QGroupBox представляет собой\
 такой же контейнер для элементов как и окно, поэтому следует позаботиться о правильной раскладке\
 элементов при изменении размера контейнера.";
                      addError(w, QObject::tr(qPrintable(str)));
                  }
              }


           }

        }
}
);



};





#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"




auto pushbutton_exec =
        [&]{
        StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);

StaticChecks::instance().addCheck(
            QObject::tr("PushButton1"),
            QObject::tr("Наличие опознавательных знаков у кнопки"),
            QObject::tr("Кнопка PushButton"),
            [&]
{

        QList<QPushButton*> list = getChildrenExceptU2L<QPushButton*>(StaticChecks::instance().getMainWindow());

            if (list.size())
        {
           QListIterator<QPushButton*> it(list);
           while(it.hasNext())
           {
              QPushButton* cur = it.next();
              QString text = cur->text();
              QString str;
              if (text.isEmpty())
              {
                  if (cur->toolTip().isEmpty())
                  {

                      if (cur->icon().isNull()){
                              str+= "Кнопка без надписи, всплывающей подсказки, иконки неприемлема."
                                       "Часто её назначение непонятно, она незаметна.";
                      }else{
                          str+="На кнопке установлена иконка, но не все пользователи смогут понять, что на ней"
                                  "изображено. Снабдите кнопку всплывающей подсказкой (ToolTip, WhatsThis). ";
                      }
                      addError((QObject*)cur,
                               QObject::tr( qPrintable(str) ));
                  }
                  else
                  {
                      str+="Желательно сделать надпись на кнопке.";
                      addWarning((QObject*)cur,
                                 QObject::tr( qPrintable(str) ));
                  }
              }

           }

        }
}
);


StaticChecks::instance().addCheck(
            QObject::tr("PushButton2"),
            QObject::tr("Текст на кнопке написан в несколько строк"),
            QObject::tr("Кнопка PushButton"),
            [&]
{

        QList<QPushButton*> list = getChildrenExceptU2L<QPushButton*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QPushButton*> it(list);
           while(it.hasNext())
           {
              QPushButton* cur = it.next();
              QString text = cur->text();

              QStringList strList = text.split("\n");
              if (strList.size() > 1)
              {
                  QString str;
str = "Не стоит делать надпись на кнопке в несколько строк.\
 Кнопка должна сообщать о своём действии, а не описывать его.";
                  addError(cur,
                           QObject::tr( qPrintable(str) ));
              }

           }

        }
}
);

};



#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"


auto lineedit_exec =
[&]{


StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);

StaticChecks::instance().addCheck(
            QObject::tr("LineEdit1"),
            QObject::tr("Желательно, чтобы текст умещался в поле"),
            QObject::tr("Поле ввода LineEdit"),
            [&]
{

        QList<QLineEdit*> list = getChildrenExceptU2L<QLineEdit*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLineEdit*> it(list);
           while(it.hasNext())
           {
              QLineEdit* cur = it.next();
              qreal wWidth = cur->fontMetrics().width('W');
              qreal iWidth = cur->fontMetrics().width('i');
              qreal width =(wWidth + iWidth) / 2;
              int pxLen = cur->maxLength();
              qreal pxWidth = width*pxLen;
              int lineEditWidth = cur->width();
              if (pxWidth >= lineEditWidth)
              {
                  QString str;
str="Рекомендуется делать так, чтобы текст в поле ввода был виден полностью.\
 Это избавит пользователя от многих лишних действий, позволяющих увидеть скрытый границами поля текст.\
 Установить максимальное количество символов в поле можно с помощью QLineEdit::setMaxLength(int)";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }

});


StaticChecks::instance().addCheck(
            QObject::tr("LineEdit2"),
            QObject::tr("Вводимые данные проверяются по мере ввода?"),
            QObject::tr("Поле ввода LineEdit"),
            [&]
{

        QList<QLineEdit*> list = getChildrenExceptU2L<QLineEdit*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLineEdit*> it(list);
           while(it.hasNext())
           {
              QLineEdit* cur = it.next();

              if (cur->validator() == nullptr)
              {
                  QString str;
str="Рекомендуется проверять ввод пользователя \"на лету\", чтобы не отвлекать его после нажатия Enter\
 сообщениями об ошибке. Воспользуйтесь концепцией валидаторов (QValidator, QLineEdit::setValidator(const QValidator*)";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }

});

};

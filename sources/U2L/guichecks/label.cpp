
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"



auto label_exec =
        [&]{

        StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);


StaticChecks::instance().addCheck(
            QObject::tr("Label1"),
            QObject::tr("Надпись сделана прописными буквами"),
            QObject::tr("Метка QLabel"),
            [&]
{

        QList<QLabel*> list = getChildrenExceptU2L<QLabel*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLabel*> it(list);
           while(it.hasNext())
           {
              QLabel* cur = it.next();

              QString text = cur->text();
              bool isUpperCase = true;
              int j=0;
              while (j<text.length())
              {
                  if (text.at(j).isLower())
                      isUpperCase = false;

                  ++j;
              }
              if (isUpperCase)
              {
                  QString str;
str="Текст, написанный заглавными буквами утомляет глаза, его сложнее читать.\
 Если нужно подчеркнуть значимость надписи, лучше упомяните его в справке,\
 после нескольких сеансов использования программы, пользователь поймет посыл и будет только\
 отвлекаться на прописные буквы в дальнейшем.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);
/*
StaticChecks::instance().addCheck(
            QObject::tr("Label2"),
            QObject::tr("Надпись контрастирует с фоном менее чем на 80%"),
            QObject::tr("Метка QLabel"),
            [&]
{

        QList<QLabel*> list = getChildrenExceptU2L<QLabel*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLabel*> it(list);
           while(it.hasNext())
           {
              QLabel* cur = it.next();

              QPalette palette = cur->palette();
              QColor f = palette.color(QPalette::WindowText);
              QColor b = palette.color(QPalette::Window);
              // http://www.had2know.com/technology/color-contrast-calculator-web-design.html
              qDebug() << f.red() << " " << f.green() << " " << b.blue();
              int indice1 = (299*f.red() + 587*f.green() + 114*f.blue())/1000;
              int indice2 = (299*b.red() + 587*b.green() + 114*b.blue())/1000;
              int contrastIndice = indice1 - indice2;
              qDebug() << "indice1:" << indice1 << "indice2:" << indice2;

              if (contrastIndice < 125)
              {
                  QString str;
str="Рекомендуется стремиться к 80% контраста.\
 Не утомляйте пользователей. В монопольном приложении (т.е. с которым пользователь работает\
 бОльшую часть рабочего дня) это становится крайне важным фактором.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);
*/



StaticChecks::instance().addCheck(
            QObject::tr("Label3"),
            QObject::tr("Надпись сделана шрифтом с засечками (например, Times New Roman)"),
            QObject::tr("Метка QLabel"),
            [&]
{
        QStringList serifFontFamilies;
        serifFontFamilies.append("Times New Roman");
        serifFontFamilies.append("Georgia");


        QList<QLabel*> list = getChildrenExceptU2L<QLabel*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLabel*> it(list);
           while(it.hasNext())
           {
              QLabel* cur = it.next();

              QString family = cur->font().family();

              if (serifFontFamilies.contains(family))
              {
                  QString str;
str="Рекомендуется применять в надписях шрифты без засечек, такие как Verdana или Tahoma.";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("Label4"),
            QObject::tr("Надпись сделана шрифтом с засечками (например, Times New Roman) с кеглем меньше 10"),
            QObject::tr("Метка QLabel"),
            [&]
{
        QStringList serifFontFamilies;
        serifFontFamilies.append("Times New Roman");
        serifFontFamilies.append("Georgia");
        QList<QLabel*> list = getChildrenExceptU2L<QLabel*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLabel*> it(list);
           while(it.hasNext())
           {
              QLabel* cur = it.next();

              QString family = cur->font().family();
              int pt = cur->font().pixelSize();
              if (serifFontFamilies.contains(family) && pt < 10)
              {
                  QString str;
str="Поскольку у шрифтов с засечками и сглаживанием наблюдаются проблемы с отображением для малых кеглей,\
 не рекомендуется использовать их для этой цели. Если возникла необходимость сделать миниатюрный текст\
 – воспользуйтесь, к примеру, Verdana.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("Label5"),
            QObject::tr("Часть надписи не видно"),
            QObject::tr("Метка QLabel"),
            [&]
{

        QList<QLabel*> list = getChildrenExceptU2L<QLabel*>(StaticChecks::instance().getMainWindow());

        if (list.size())
        {
           QListIterator<QLabel*> it(list);
           while(it.hasNext())
           {
              QLabel* cur = it.next();

              int widthOfChars = cur->fontMetrics().width(cur->text());
              int widthOfLabel = cur->width();
              if (widthOfLabel < widthOfChars)
              {
                  QString str;
str="Необходимо увеличить размеры метки, чтобы в ней поместились все символы её текста.";
                  addError(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

};

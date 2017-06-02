

#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"

class MySpinBox : public QSpinBox
{
    public:
        QValidator::State validate ( QString & input, int & pos ) const
         {return this->validate(input,pos);}
};

auto spinner_exec =
        [&]{
        StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);


StaticChecks::instance().addCheck(
            QObject::tr("Spinner1"),
            QObject::tr("Можно ли ввести неподходящее значение в счётчик (например, текст)"),
            QObject::tr("Счётчик SpinBox"),
            [&]
{

        QList<QSpinBox*> list = getChildrenExceptU2L<QSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QSpinBox*> it(list);
           while(it.hasNext())
           {
              QSpinBox* cur = it.next();
              QString text = "T";
              int pos = 0;
              MySpinBox* box = reinterpret_cast<MySpinBox*>(cur);
              QValidator::State state = box->validate(text,pos);

              if (state == QValidator::Acceptable){
                  QString str;
str="В данный счётчик можно записать текстовое значение - это было предусмотрено?\
 Для проверки введенного значения пользуйтесь валидаторами (QValidator)";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);


StaticChecks::instance().addCheck(
            QObject::tr("Spinner2"),
            QObject::tr("Не забыли выставить границы?"),
            QObject::tr("Счётчик SpinBox"),
            [&]
{

        QList<QSpinBox*> list = getChildrenExceptU2L<QSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QSpinBox*> it(list);
           while(it.hasNext())
           {
              QSpinBox* cur = it.next();
              int min = cur->minimum();
              int max = cur->maximum();
              if (min == 0 && max == 99)
              {
                  QString str;
str = "Диапазон значений счётчика совпадает с диапазоном по-умолчанию для QSpinBox.\
 Возможно забыли прописать требуемые по заданию границы. Это можно сделать при помощи\
 QSpinBox::setMinimum(int) и QSpinBox::setMaximum(int).";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("Spinner3"),
            QObject::tr("Префиксы и суффиксы значения в счётчике"),
            QObject::tr("Счётчик SpinBox"),
            [&]
{

        QList<QSpinBox*> list = getChildrenExceptU2L<QSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QSpinBox*> it(list);
           while(it.hasNext())
           {
              QSpinBox* cur = it.next();
              QString suffix = cur->suffix();
              QString prefix = cur->prefix();
              if (suffix.isEmpty() && prefix.isEmpty())
              {
                  QString str;
str = "Возможно повышение информативности счётчика, путём задания префикса или суффикса значения.\
 К примеру, количество дней отпуска можно более наглядно отображать, используя суффикс \"дн.\" - \"10 дн.\" вместо \"10\".";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);



StaticChecks::instance().addCheck(
            QObject::tr("Spinner4"),
            QObject::tr("Использование кнопок плюс-минус вместо стрелок"),
            QObject::tr("Счётчик SpinBox"),
            [&]
{

        QList<QSpinBox*> list = getChildrenExceptU2L<QSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QSpinBox*> it(list);
           while(it.hasNext())
           {
              QSpinBox* cur = it.next();
              QAbstractSpinBox::ButtonSymbols butsyms = cur->buttonSymbols();
              if (butsyms == QAbstractSpinBox::PlusMinus)
              {
                  QString str;
str = "Выбранный тип кнопок (PlusMinus) может не поддерживаться на некоторых платформах.\
 К примеру, Windows XP может отображать только стрелки.";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);


StaticChecks::instance().addCheck(
            QObject::tr("DoubleSpinner1"),
            QObject::tr("Не забыли выставить границы?"),
            QObject::tr("Счётчик DoubleSpinBox"),
            [&]
{

        QList<QDoubleSpinBox*> list = getChildrenExceptU2L<QDoubleSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QDoubleSpinBox*> it(list);
           while(it.hasNext())
           {
              QDoubleSpinBox* cur = it.next();
              double min = cur->minimum();
              double max = cur->maximum();
              if (min == 0. && max == 99.)
              {
                  QString str;
str = "Диапазон значений счётчика совпадает с диапазоном по-умолчанию для QDoubleSpinBox.\
 Возможно забыли прописать требуемые по заданию границы. Это возможно сделать при помощи\
 QDoubleSpinBox::setMinimum(int) и QDoubleSpinBox::setMaximum(int)";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);


StaticChecks::instance().addCheck(
            QObject::tr("DoubleSpinner2"),
            QObject::tr("Префиксы и суффиксы значения в счётчике"),
            QObject::tr("Счётчик DoubleSpinBox"),
            [&]
{

        QList<QDoubleSpinBox*> list = getChildrenExceptU2L<QDoubleSpinBox*>(StaticChecks::instance().getMainWindow());
        //QList<QPushButton*> list = StaticChecks::instance().getMainWindow()->findChildren<QPushButton*>();
         if (list.size())
        {
           QListIterator<QDoubleSpinBox*> it(list);
           while(it.hasNext())
           {
              QDoubleSpinBox* cur = it.next();
              QString suffix = cur->suffix();
              QString prefix = cur->prefix();
              if (suffix.isEmpty() && prefix.isEmpty())
              {
                  QString str;
str = "Возможно повышение информативности счётчика, путём задания префикса или суффикса значения.\
К примеру, количество литров жидкости можно более наглядно отображать, используя суффикс\
 \'л\' - \'2,5 л\' вместо \'2,5\'.";
                  addWarning(cur, QObject::tr(qPrintable(str)));
              }

           }

        }
}
);
};

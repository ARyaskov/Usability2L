
#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/usabilitycheck.h"
#include "../../includes/U2L/staticchecks.h"




auto combobox_exec =
        [&]{

        StaticChecks::instance().setGroupCount(StaticChecks::instance().getGroupCount()+1);



StaticChecks::instance().addCheck(
            QObject::tr("Combobox1"),
            QObject::tr("Меньше 3 элементов в списке"),
            QObject::tr("Выпадающий список ComboBox"),
            [&]
{
        QList<QComboBox*> list = getChildrenExceptU2L<QComboBox*>(StaticChecks::instance().getMainWindow());
        QListIterator<QComboBox*> it(list);
        while(it.hasNext())
        {
            QComboBox* cur = it.next();
            int count = cur->count();
            if (count < 3)
            {
                QString str;
str="Списки вида ComboBox созданы для хранения 3 и более элементов. \
Если же элементов меньше 3, стоит задуматься о применении радиокнопок (QRadioButton)";
                addError(cur, QObject::tr(qPrintable(str)));
            }
        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("Combobox2"),
            QObject::tr("Больше 10 элементов в списке"),
            QObject::tr("Выпадающий список ComboBox"),
            [&]
{
        QList<QComboBox*> list = getChildrenExceptU2L<QComboBox*>(StaticChecks::instance().getMainWindow());
        QListIterator<QComboBox*> it(list);
        while(it.hasNext())
        {
            QComboBox* cur = it.next();
            int count = cur->count();
            if (count > 10)
            {
                QString str;
str="Не рекомендуется использовать виджет ComboBox c более чем 10 вариантами\
выбора. Во-первых, пользователям-новичкам будет трудно держать в голове все\
варианты выбора (психологами рекомендовано до 5-7 вариантов, для лучшего запоминания).\
Во-вторых, если приложение используется достаточно часто, человека будет утомлять поиск варианта.\
Попробуйте отсечь схожие варианты, классифицируйте выбор по другому критерию, разбейте выбор на несколько этапов.";

                addWarning(cur, QObject::tr(qPrintable(str)));
            }
        }
}
);

StaticChecks::instance().addCheck(
            QObject::tr("Combobox3"),
            QObject::tr("Рекомендация сделать заголовок списка редактируемым (>5 элементов)."),
            QObject::tr("Выпадающий список ComboBox"),
            [&]
{
        QList<QComboBox*> list = getChildrenExceptU2L<QComboBox*>(StaticChecks::instance().getMainWindow());
        QListIterator<QComboBox*> it(list);
        while(it.hasNext())
        {
            QComboBox* cur = it.next();

            if (!cur->isEditable())
            {
                QString str;
str="Для лучшего взаимодействия рекомендуется делать заголовок списка редактируемым \
(при наличии 5 и более элементов). Это позволит не тратить время на поиск \
элемента, а сразу же вводить нужный вариант (возможна реализация автодополнения). \
В Qt это можно выполнить с помощью QComboBox::setEditable(bool editable).";

                addWarning(cur, QObject::tr(qPrintable(str)));
            }
        }
}
);

};


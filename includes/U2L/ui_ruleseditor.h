/********************************************************************************
** Form generated from reading UI file 'ruleseditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESEDITOR_H
#define UI_RULESEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RulesEditor
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bRun;
    QPushButton *bClose;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RulesEditor)
    {
        if (RulesEditor->objectName().isEmpty())
            RulesEditor->setObjectName(QString::fromUtf8("RulesEditor"));
        RulesEditor->setWindowModality(Qt::ApplicationModal);
        RulesEditor->resize(753, 546);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/E_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        RulesEditor->setWindowIcon(icon);
        RulesEditor->setModal(true);
        verticalLayout = new QVBoxLayout(RulesEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bRun = new QPushButton(RulesEditor);
        bRun->setObjectName(QString::fromUtf8("bRun"));

        horizontalLayout->addWidget(bRun);

        bClose = new QPushButton(RulesEditor);
        bClose->setObjectName(QString::fromUtf8("bClose"));
        bClose->setDefault(true);

        horizontalLayout->addWidget(bClose);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(1, 278, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(1, 278, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(558, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(RulesEditor);

        QMetaObject::connectSlotsByName(RulesEditor);
    } // setupUi

    void retranslateUi(QDialog *RulesEditor)
    {
        RulesEditor->setWindowTitle(QApplication::translate("RulesEditor", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\277\321\200\320\260\320\262\320\270\320\273", 0, QApplication::UnicodeUTF8));
        bRun->setText(QApplication::translate("RulesEditor", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        bClose->setText(QApplication::translate("RulesEditor", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RulesEditor: public Ui_RulesEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESEDITOR_H

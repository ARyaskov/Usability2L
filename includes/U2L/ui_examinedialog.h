/********************************************************************************
** Form generated from reading UI file 'examinedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMINEDIALOG_H
#define UI_EXAMINEDIALOG_H

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

class Ui_ExamineDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bRunChecks;
    QPushButton *bCancelChecks;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ExamineDialog)
    {
        if (ExamineDialog->objectName().isEmpty())
            ExamineDialog->setObjectName(QString::fromUtf8("ExamineDialog"));
        ExamineDialog->setWindowModality(Qt::ApplicationModal);
        ExamineDialog->resize(590, 342);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/R_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExamineDialog->setWindowIcon(icon);
        ExamineDialog->setModal(true);
        verticalLayout = new QVBoxLayout(ExamineDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bRunChecks = new QPushButton(ExamineDialog);
        bRunChecks->setObjectName(QString::fromUtf8("bRunChecks"));

        horizontalLayout->addWidget(bRunChecks);

        bCancelChecks = new QPushButton(ExamineDialog);
        bCancelChecks->setObjectName(QString::fromUtf8("bCancelChecks"));
        bCancelChecks->setDefault(true);

        horizontalLayout->addWidget(bCancelChecks);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(1, 278, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(1, 278, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(558, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ExamineDialog);

        QMetaObject::connectSlotsByName(ExamineDialog);
    } // setupUi

    void retranslateUi(QDialog *ExamineDialog)
    {
        ExamineDialog->setWindowTitle(QApplication::translate("ExamineDialog", "\320\227\320\260\320\277\321\203\321\201\320\272 \320\277\321\200\320\276\320\262\320\265\321\200\320\276\320\272 \320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260", 0, QApplication::UnicodeUTF8));
        bRunChecks->setText(QApplication::translate("ExamineDialog", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        bCancelChecks->setText(QApplication::translate("ExamineDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExamineDialog: public Ui_ExamineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMINEDIALOG_H

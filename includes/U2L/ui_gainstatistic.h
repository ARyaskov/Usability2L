/********************************************************************************
** Form generated from reading UI file 'gainstatistic.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAINSTATISTIC_H
#define UI_GAINSTATISTIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GainStatistic
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_3;
    QTreeWidget *widsTree;
    QWidget *tab2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupXML;
    QGroupBox *groupText;
    QGroupBox *groupSQLite;
    QPushButton *bExportXML;
    QSpacerItem *horizontalSpacer;
    QPushButton *bExportText;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bExportDB;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *GainStatistic)
    {
        if (GainStatistic->objectName().isEmpty())
            GainStatistic->setObjectName(QString::fromUtf8("GainStatistic"));
        GainStatistic->setWindowModality(Qt::ApplicationModal);
        GainStatistic->resize(701, 474);
        gridLayout_2 = new QGridLayout(GainStatistic);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(GainStatistic);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout_3 = new QGridLayout(tab1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widsTree = new QTreeWidget(tab1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Name"));
        widsTree->setHeaderItem(__qtreewidgetitem);
        widsTree->setObjectName(QString::fromUtf8("widsTree"));
        widsTree->setAnimated(true);
        widsTree->setColumnCount(2);
        widsTree->header()->setVisible(true);
        widsTree->header()->setDefaultSectionSize(250);
        widsTree->header()->setHighlightSections(false);
        widsTree->header()->setStretchLastSection(true);

        gridLayout_3->addWidget(widsTree, 0, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_4 = new QGridLayout(tab2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupXML = new QGroupBox(tab2);
        groupXML->setObjectName(QString::fromUtf8("groupXML"));

        verticalLayout->addWidget(groupXML);

        groupText = new QGroupBox(tab2);
        groupText->setObjectName(QString::fromUtf8("groupText"));

        verticalLayout->addWidget(groupText);

        groupSQLite = new QGroupBox(tab2);
        groupSQLite->setObjectName(QString::fromUtf8("groupSQLite"));

        verticalLayout->addWidget(groupSQLite);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 6);

        bExportXML = new QPushButton(GainStatistic);
        bExportXML->setObjectName(QString::fromUtf8("bExportXML"));

        gridLayout->addWidget(bExportXML, 1, 1, 3, 1);

        horizontalSpacer = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        bExportText = new QPushButton(GainStatistic);
        bExportText->setObjectName(QString::fromUtf8("bExportText"));
        bExportText->setDefault(true);
        bExportText->setFlat(false);

        gridLayout->addWidget(bExportText, 1, 3, 3, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 3, 1);

        bExportDB = new QPushButton(GainStatistic);
        bExportDB->setObjectName(QString::fromUtf8("bExportDB"));

        gridLayout->addWidget(bExportDB, 1, 6, 3, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 7, 3, 1);

        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 3, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(GainStatistic);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GainStatistic);
    } // setupUi

    void retranslateUi(QDialog *GainStatistic)
    {
        GainStatistic->setWindowTitle(QApplication::translate("GainStatistic", "Gain Statistic", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = widsTree->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("GainStatistic", "Value", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("GainStatistic", "Widgets in current app", 0, QApplication::UnicodeUTF8));
        groupXML->setTitle(QApplication::translate("GainStatistic", "XML", 0, QApplication::UnicodeUTF8));
        groupText->setTitle(QApplication::translate("GainStatistic", "Text", 0, QApplication::UnicodeUTF8));
        groupSQLite->setTitle(QApplication::translate("GainStatistic", "SQLite", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("GainStatistic", "Preferences", 0, QApplication::UnicodeUTF8));
        bExportXML->setText(QApplication::translate("GainStatistic", "Statistic in XML...", 0, QApplication::UnicodeUTF8));
        bExportText->setText(QApplication::translate("GainStatistic", "Statistic in text...", 0, QApplication::UnicodeUTF8));
        bExportDB->setText(QApplication::translate("GainStatistic", "Statistic in DB (SQLITE)...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GainStatistic: public Ui_GainStatistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAINSTATISTIC_H

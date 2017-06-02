/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../U2L/u2lwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QTableWidget *Table;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *trainNumber;
    QCheckBox *isRapid;
    QHBoxLayout *hboxLayout1;
    QLabel *label_7;
    QDoubleSpinBox *duration;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout2;
    QLabel *label_2;
    QLineEdit *from_city;
    QHBoxLayout *hboxLayout3;
    QLabel *label_3;
    QTimeEdit *from_time;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout2;
    QVBoxLayout *_2;
    QHBoxLayout *hboxLayout4;
    QLabel *label_4;
    QLineEdit *to_city;
    QHBoxLayout *_3;
    QLabel *label_5;
    QTimeEdit *to_time;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout3;
    QVBoxLayout *vboxLayout3;
    QLabel *label_6;
    QComboBox *periodicType;
    QVBoxLayout *vboxLayout4;
    QStackedWidget *stcWid;
    QWidget *page0;
    QGroupBox *weekDays;
    QGridLayout *gridLayout4;
    QHBoxLayout *hboxLayout5;
    QCheckBox *mon;
    QCheckBox *tue;
    QCheckBox *wed;
    QCheckBox *thur;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout6;
    QCheckBox *fri;
    QCheckBox *sat;
    QCheckBox *sun;
    QSpacerItem *spacerItem1;
    QWidget *page1;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hboxLayout7;
    QCheckBox *cb1;
    QDateEdit *de1;
    QHBoxLayout *hboxLayout8;
    QCheckBox *cb2;
    QDateEdit *de2;
    QHBoxLayout *hboxLayout9;
    QCheckBox *cb3;
    QDateEdit *de3;
    QHBoxLayout *hboxLayout10;
    QCheckBox *cb4;
    QDateEdit *de4;
    QGroupBox *manageButs;
    QGridLayout *gridLayout5;
    QPushButton *butCreate;
    QPushButton *butDelete;
    U2LWidget *u2lwidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(723, 593);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Table = new QTableWidget(centralWidget);
        if (Table->columnCount() < 3)
            Table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setFocusPolicy(Qt::WheelFocus);
        Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table->setTabKeyNavigation(false);
        Table->setSelectionMode(QAbstractItemView::SingleSelection);
        Table->setSelectionBehavior(QAbstractItemView::SelectRows);
        Table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        Table->setCornerButtonEnabled(false);
        Table->setColumnCount(3);

        gridLayout1->addWidget(Table, 0, 0, 2, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(362, 2000));
        groupBox->setFocusPolicy(Qt::NoFocus);
        gridLayout2 = new QGridLayout(groupBox);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        trainNumber = new QLineEdit(groupBox);
        trainNumber->setObjectName(QString::fromUtf8("trainNumber"));
        trainNumber->setMaxLength(10);

        hboxLayout->addWidget(trainNumber);


        gridLayout2->addLayout(hboxLayout, 0, 0, 1, 1);

        isRapid = new QCheckBox(groupBox);
        isRapid->setObjectName(QString::fromUtf8("isRapid"));

        gridLayout2->addWidget(isRapid, 0, 1, 1, 2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        hboxLayout1->addWidget(label_7);

        duration = new QDoubleSpinBox(groupBox);
        duration->setObjectName(QString::fromUtf8("duration"));
        duration->setMinimum(1);
        duration->setMaximum(10);
        duration->setValue(1);

        hboxLayout1->addWidget(duration);


        gridLayout2->addLayout(hboxLayout1, 0, 3, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(169, 0));
        groupBox_2->setMaximumSize(QSize(169, 16777215));
        vboxLayout = new QVBoxLayout(groupBox_2);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout2->addWidget(label_2);

        from_city = new QLineEdit(groupBox_2);
        from_city->setObjectName(QString::fromUtf8("from_city"));
        from_city->setMaxLength(30);

        hboxLayout2->addWidget(from_city);


        vboxLayout1->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        hboxLayout3->addWidget(label_3);

        from_time = new QTimeEdit(groupBox_2);
        from_time->setObjectName(QString::fromUtf8("from_time"));

        hboxLayout3->addWidget(from_time);


        vboxLayout1->addLayout(hboxLayout3);


        vboxLayout->addLayout(vboxLayout1);


        gridLayout2->addWidget(groupBox_2, 1, 0, 1, 2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(169, 0));
        groupBox_3->setMaximumSize(QSize(169, 16777215));
        vboxLayout2 = new QVBoxLayout(groupBox_3);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(11, 11, 11, 11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        _2 = new QVBoxLayout();
        _2->setSpacing(6);
        _2->setObjectName(QString::fromUtf8("_2"));
        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        hboxLayout4->addWidget(label_4);

        to_city = new QLineEdit(groupBox_3);
        to_city->setObjectName(QString::fromUtf8("to_city"));
        to_city->setMaxLength(30);

        hboxLayout4->addWidget(to_city);


        _2->addLayout(hboxLayout4);

        _3 = new QHBoxLayout();
        _3->setSpacing(6);
        _3->setObjectName(QString::fromUtf8("_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        _3->addWidget(label_5);

        to_time = new QTimeEdit(groupBox_3);
        to_time->setObjectName(QString::fromUtf8("to_time"));

        _3->addWidget(to_time);


        _2->addLayout(_3);


        vboxLayout2->addLayout(_2);


        gridLayout2->addWidget(groupBox_3, 1, 2, 1, 2);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout3 = new QGridLayout(groupBox_4);
        gridLayout3->setSpacing(6);
        gridLayout3->setContentsMargins(11, 11, 11, 11);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        vboxLayout3->addWidget(label_6);

        periodicType = new QComboBox(groupBox_4);
        periodicType->setObjectName(QString::fromUtf8("periodicType"));

        vboxLayout3->addWidget(periodicType);

        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        stcWid = new QStackedWidget(groupBox_4);
        stcWid->setObjectName(QString::fromUtf8("stcWid"));
        page0 = new QWidget();
        page0->setObjectName(QString::fromUtf8("page0"));
        weekDays = new QGroupBox(page0);
        weekDays->setObjectName(QString::fromUtf8("weekDays"));
        weekDays->setGeometry(QRect(70, 40, 188, 151));
        gridLayout4 = new QGridLayout(weekDays);
        gridLayout4->setSpacing(6);
        gridLayout4->setContentsMargins(11, 11, 11, 11);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        mon = new QCheckBox(weekDays);
        mon->setObjectName(QString::fromUtf8("mon"));

        hboxLayout5->addWidget(mon);

        tue = new QCheckBox(weekDays);
        tue->setObjectName(QString::fromUtf8("tue"));

        hboxLayout5->addWidget(tue);

        wed = new QCheckBox(weekDays);
        wed->setObjectName(QString::fromUtf8("wed"));

        hboxLayout5->addWidget(wed);

        thur = new QCheckBox(weekDays);
        thur->setObjectName(QString::fromUtf8("thur"));

        hboxLayout5->addWidget(thur);


        gridLayout4->addLayout(hboxLayout5, 0, 0, 1, 3);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout4->addItem(spacerItem, 1, 0, 1, 1);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        fri = new QCheckBox(weekDays);
        fri->setObjectName(QString::fromUtf8("fri"));

        hboxLayout6->addWidget(fri);

        sat = new QCheckBox(weekDays);
        sat->setObjectName(QString::fromUtf8("sat"));

        hboxLayout6->addWidget(sat);

        sun = new QCheckBox(weekDays);
        sun->setObjectName(QString::fromUtf8("sun"));

        hboxLayout6->addWidget(sun);


        gridLayout4->addLayout(hboxLayout6, 1, 1, 1, 1);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout4->addItem(spacerItem1, 1, 2, 1, 1);

        stcWid->addWidget(page0);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        vboxLayout5 = new QVBoxLayout(page1);
        vboxLayout5->setSpacing(6);
        vboxLayout5->setContentsMargins(11, 11, 11, 11);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        cb1 = new QCheckBox(page1);
        cb1->setObjectName(QString::fromUtf8("cb1"));

        hboxLayout7->addWidget(cb1);

        de1 = new QDateEdit(page1);
        de1->setObjectName(QString::fromUtf8("de1"));
        de1->setEnabled(false);

        hboxLayout7->addWidget(de1);


        vboxLayout5->addLayout(hboxLayout7);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setSpacing(6);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        cb2 = new QCheckBox(page1);
        cb2->setObjectName(QString::fromUtf8("cb2"));

        hboxLayout8->addWidget(cb2);

        de2 = new QDateEdit(page1);
        de2->setObjectName(QString::fromUtf8("de2"));
        de2->setEnabled(false);

        hboxLayout8->addWidget(de2);


        vboxLayout5->addLayout(hboxLayout8);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setSpacing(6);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        cb3 = new QCheckBox(page1);
        cb3->setObjectName(QString::fromUtf8("cb3"));

        hboxLayout9->addWidget(cb3);

        de3 = new QDateEdit(page1);
        de3->setObjectName(QString::fromUtf8("de3"));
        de3->setEnabled(false);

        hboxLayout9->addWidget(de3);


        vboxLayout5->addLayout(hboxLayout9);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setSpacing(6);
        hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
        cb4 = new QCheckBox(page1);
        cb4->setObjectName(QString::fromUtf8("cb4"));

        hboxLayout10->addWidget(cb4);

        de4 = new QDateEdit(page1);
        de4->setObjectName(QString::fromUtf8("de4"));
        de4->setEnabled(false);

        hboxLayout10->addWidget(de4);


        vboxLayout5->addLayout(hboxLayout10);

        stcWid->addWidget(page1);

        vboxLayout4->addWidget(stcWid);


        vboxLayout3->addLayout(vboxLayout4);


        gridLayout3->addLayout(vboxLayout3, 0, 0, 1, 1);


        gridLayout2->addWidget(groupBox_4, 2, 0, 1, 4);


        gridLayout1->addWidget(groupBox, 0, 1, 1, 1);

        manageButs = new QGroupBox(centralWidget);
        manageButs->setObjectName(QString::fromUtf8("manageButs"));
        gridLayout5 = new QGridLayout(manageButs);
        gridLayout5->setSpacing(6);
        gridLayout5->setContentsMargins(11, 11, 11, 11);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        butCreate = new QPushButton(manageButs);
        butCreate->setObjectName(QString::fromUtf8("butCreate"));

        gridLayout5->addWidget(butCreate, 0, 0, 1, 1);

        butDelete = new QPushButton(manageButs);
        butDelete->setObjectName(QString::fromUtf8("butDelete"));

        gridLayout5->addWidget(butDelete, 0, 1, 1, 1);


        gridLayout1->addWidget(manageButs, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout1, 1, 0, 1, 1);

        u2lwidget = new U2LWidget(centralWidget);
        u2lwidget->setObjectName(QString::fromUtf8("u2lwidget"));

        gridLayout->addWidget(u2lwidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(Table, trainNumber);
        QWidget::setTabOrder(trainNumber, isRapid);
        QWidget::setTabOrder(isRapid, duration);
        QWidget::setTabOrder(duration, from_city);
        QWidget::setTabOrder(from_city, from_time);
        QWidget::setTabOrder(from_time, to_city);
        QWidget::setTabOrder(to_city, to_time);
        QWidget::setTabOrder(to_time, periodicType);
        QWidget::setTabOrder(periodicType, mon);
        QWidget::setTabOrder(mon, tue);
        QWidget::setTabOrder(tue, wed);
        QWidget::setTabOrder(wed, thur);
        QWidget::setTabOrder(thur, fri);
        QWidget::setTabOrder(fri, sat);
        QWidget::setTabOrder(sat, sun);
        QWidget::setTabOrder(sun, butCreate);
        QWidget::setTabOrder(butCreate, butDelete);

        retranslateUi(MainWindow);
        QObject::connect(trainNumber, SIGNAL(returnPressed()), isRapid, SLOT(setFocus()));
        QObject::connect(from_city, SIGNAL(returnPressed()), from_time, SLOT(setFocus()));
        QObject::connect(from_time, SIGNAL(editingFinished()), to_city, SLOT(setFocus()));
        QObject::connect(to_city, SIGNAL(returnPressed()), to_time, SLOT(setFocus()));
        QObject::connect(to_time, SIGNAL(editingFinished()), periodicType, SLOT(setFocus()));
        QObject::connect(butCreate, SIGNAL(clicked()), trainNumber, SLOT(setFocus()));
        QObject::connect(periodicType, SIGNAL(currentIndexChanged(int)), mon, SLOT(setFocus()));
        QObject::connect(mon, SIGNAL(stateChanged(int)), tue, SLOT(setFocus()));
        QObject::connect(tue, SIGNAL(stateChanged(int)), wed, SLOT(setFocus()));
        QObject::connect(wed, SIGNAL(stateChanged(int)), thur, SLOT(setFocus()));
        QObject::connect(thur, SIGNAL(stateChanged(int)), fri, SLOT(setFocus()));
        QObject::connect(fri, SIGNAL(stateChanged(int)), sat, SLOT(setFocus()));
        QObject::connect(sat, SIGNAL(stateChanged(int)), sun, SLOT(setFocus()));

        stcWid->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\320\276\320\265\320\267\320\264\320\276\320\262 ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\342\204\226 \320\277\320\276\320\265\320\267\320\264\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = Table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\277\320\276\320\265\320\267\320\264\320\265", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\342\204\226 \320\277\320\276\320\265\320\267\320\264\320\260", 0, QApplication::UnicodeUTF8));
        isRapid->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\321\213\320\271", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\321\213\321\202\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277", 0, QApplication::UnicodeUTF8));
        periodicType->clear();
        periodicType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\272\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\277\320\276 \321\207\320\265\321\202\320\275\321\213\320\274 \320\264\320\275\321\217\320\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\277\320\276 \320\275\320\265\321\207\320\265\321\202\320\275\321\213\320\274 \320\264\320\275\321\217\320\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\277\320\276 \320\264\320\275\321\217\320\274 \320\275\320\265\320\264\320\265\320\273\320\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\273\321\214\320\275\320\276", 0, QApplication::UnicodeUTF8)
        );
        weekDays->setTitle(QApplication::translate("MainWindow", "\320\224\320\275\320\270 \320\275\320\265\320\264\320\265\320\273\320\270", 0, QApplication::UnicodeUTF8));
        mon->setText(QApplication::translate("MainWindow", "\320\237\320\235", 0, QApplication::UnicodeUTF8));
        tue->setText(QApplication::translate("MainWindow", "\320\222\320\242", 0, QApplication::UnicodeUTF8));
        wed->setText(QApplication::translate("MainWindow", "\320\241\320\240", 0, QApplication::UnicodeUTF8));
        thur->setText(QApplication::translate("MainWindow", "\320\247\320\242", 0, QApplication::UnicodeUTF8));
        fri->setText(QApplication::translate("MainWindow", "\320\237\320\242", 0, QApplication::UnicodeUTF8));
        sat->setText(QApplication::translate("MainWindow", "\320\241\320\221", 0, QApplication::UnicodeUTF8));
        sun->setText(QApplication::translate("MainWindow", "\320\222\320\241", 0, QApplication::UnicodeUTF8));
        cb1->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\2601", 0, QApplication::UnicodeUTF8));
        cb2->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\2602", 0, QApplication::UnicodeUTF8));
        cb3->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\2603", 0, QApplication::UnicodeUTF8));
        cb4->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\2604", 0, QApplication::UnicodeUTF8));
        manageButs->setTitle(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        butCreate->setText(QString());
        butDelete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

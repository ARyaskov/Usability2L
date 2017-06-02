
#include "../../includes/U2L/u2lwidget.h"



//#define qApp2 (static_cast<QApplication *>(QCoreApplication::instance()))



QWidgetList widgetsList;


U2LWidget::U2LWidget(QWidget *parent) :
    QWidget(parent)
{
    QResource::registerResource("../../misc/u2lres.qrc");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

  /*  QTranslator translator;
    translator.load("u2l_ru");
    QApplication::instance()->installTranslator(&translator);*/

}

U2LWidget::~U2LWidget(){

    //delete rulesEditor;
    /*delete gainStatistic;*/
    //delete examineDialog;
}



void U2LWidget::setMainWindow(QMainWindow* new_mw)
{
    m_mainwindow = new_mw;
}

QMainWindow* U2LWidget::getMainWindow()
{
    return m_mainwindow;
}

void U2LWidget::setup(QMainWindow* parent)
{

    QTextCodec::setCodecForTr(QTextCodec::codecForName("windows-1251"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("windows-1251"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("windows-1251"));
    setMainWindow(parent);
    StaticChecks::instance().setMainWindow(parent);
    QMenuBar* menubar;
    QMenu* u2lmenu;
    QAction* actionExamine;
    QAction* actionRulesEditor;
    QAction* actionGainStatistic ;

    menubar = parent->menuBar();
    u2lmenu = new QMenu(GlobalSM::instance().menuName);

    actionExamine = new QAction("Запуск проверок...", 0);
    // QAction* actionTaskForTime = new QAction(tr("TimeForTask mode"), 0);
    actionRulesEditor = new QAction("Редактор правил...", 0);
    /*actionGainStatistic = new QAction(tr("Gain statistic..."), 0);*/
    // QAction* actionSettings = new QAction(tr("Settings..."), 0);
    // QAction* actionAboutU2L = new QAction(tr("About U2L"), 0);

    u2lmenu->addAction(actionExamine);
    // u2lmenu->addAction(actionTaskForTime);
    u2lmenu->addAction(actionRulesEditor);
    /*u2lmenu->addAction(actionGainStatistic);*/
    // u2lmenu->addAction(actionSettings);
    // u2lmenu->addSeparator();
    // u2lmenu->addAction(actionAboutU2L);

    menubar->addMenu(u2lmenu);

    connect(actionExamine, SIGNAL(triggered()), this, SLOT(on_actionExamine_triggered()));
    connect(actionRulesEditor, SIGNAL(triggered()), this, SLOT(on_actionRulesEditor_triggered()));
  /*  connect(actionGainStatistic, SIGNAL(triggered()), this, SLOT(on_actionGainStatistic_triggered()));
*/

    widgetsList = getChildrenExceptU2L<QWidget*>(parent);
    for (int i=0;i<widgetsList.size();i++)
    {

        qDebug() << widgetsList.at(i)->objectName();
        qDebug() << widgetsList.at(i)->metaObject()->className();
    }
    rulesEditor = new RulesEditor(parent);
   /* gainStatistic = new GainStatistic(parent);*/
    examineDialog = new ExamineDialog(parent);


    QList<U2LWidget*> list = getMainWindow()->findChildren<U2LWidget*>();
    if (list.size())
    {
        GlobalSM::instance().u2lWidgetName = list[0]->objectName();
        GlobalSM::instance().u2lwidget = list[0];
    }

}


void U2LWidget::on_actionRulesEditor_triggered(){
    rulesEditor->exec();
}

void U2LWidget::on_actionGainStatistic_triggered()
{
    gainStatistic->exec();
}

void U2LWidget::on_actionExamine_triggered()
{
    examineDialog->exec();
}

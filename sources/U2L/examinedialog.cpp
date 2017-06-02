#include "../../includes/U2L/examinedialog.h"
#include "ui_examinedialog.h"





ExamineDialog::ExamineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExamineDialog)
{
    ui->setupUi(this);

    m_listNotes = new QListWidget();
    m_listNotes->addItem(tr("Пока нет ни ошибок, ни предупреждений"));
    ui->verticalLayout->addWidget(m_listNotes);



    m_checksTree = new QTreeWidget(this);
    QStringList headersList;
    headersList << QObject::tr("Название проверки") << QObject::tr("Описание проверки");
    m_checksTree->setColumnCount(2);
    m_checksTree->setHeaderLabels(headersList);
    m_checksTree->header()->resizeSection(0,180);
    ui->gridLayout->addWidget(m_checksTree, 1, 0);

    m_checksTree->setFocus();

    connect(ui->bRunChecks,SIGNAL(clicked()), this, SLOT(on_bRunChecks_clicked()),Qt::UniqueConnection);
    connect(ui->bCancelChecks,SIGNAL(clicked()), this, SLOT(reject()),Qt::UniqueConnection);
    connect(m_checksTree,SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(on_item_change_state(QTreeWidgetItem* , int )),Qt::UniqueConnection);
    connect(m_listNotes,SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem *)), this, SLOT(on_current_item_changed(QTreeWidgetItem* , QTreeWidgetItem* )),Qt::UniqueConnection);

    floodChecksTree();

}

ExamineDialog::~ExamineDialog()
{
    delete ui;
}


void ExamineDialog::on_current_item_changed(QListWidgetItem* curItem, QListWidgetItem* prevItem)
{

    /* QWidget* wid = qvariant_cast<QWidget*>(curItem->data(Qt::UserRole));
    QPalette palette = wid->palette();
    QPalette newPalette = wid->palette();
    newPalette.setColor(QPalette::Base,QColor(0,255,17,150));
    wid->setPalette(newPalette);
    wid->update();*/

}

void ExamineDialog::on_item_change_state(QTreeWidgetItem* item, int column)
{
    Q_UNUSED(column)
    if (m_checkedList.contains(item))
        m_checkedList.removeOne(item);
    else
        m_checkedList << item;




}

void ExamineDialog::floodChecksTree()
{
    QList<UsabilityCheck> listChecks = StaticChecks::instance().getChecks();

    auto isGroupExistsInTree = [&](QString group) -> bool
    {
            bool res=false;
    for( int i = 0; i < m_checksTree->topLevelItemCount(); i++ )
    {
        QTreeWidgetItem* item = m_checksTree->topLevelItem( i );
        if (!item->text(0).compare(group))
        {
            res = true;
            break;
        }

    }
    return res;
};

int count = listChecks.size();
for (int i=0;i<count;i++)
{

    QString parentGroup = listChecks[i].getParentGroup();

    if (isGroupExistsInTree(parentGroup) == false){

        QStringList tempList;
        tempList << parentGroup << "";
        QTreeWidgetItem* ptrGroup = new QTreeWidgetItem(m_checksTree,tempList);
        tempList.clear();
        m_checksTree->addTopLevelItem(ptrGroup);

        QList<UsabilityCheck> list = StaticChecks::instance().getChecksByGroup(parentGroup);
        QListIterator<UsabilityCheck> it(list);
        while(it.hasNext())
        {
            UsabilityCheck curCheck = it.next();
            QString name = curCheck.getName();
            QString desc = curCheck.getDescription();
            tempList << name << desc;
            QTreeWidgetItem* ptrCheck = new QTreeWidgetItem(m_checksTree,tempList);
            ptrCheck->setFlags(ptrCheck->flags() | Qt::ItemIsUserCheckable);
            ptrCheck->setCheckState(0, Qt::Unchecked);

            //m_checkedList << ptrCheck;
            ptrGroup->addChild(ptrCheck);
            tempList.clear();

        }
    }
}
}

void ExamineDialog::on_bRunChecks_clicked()
{
    qDebug() << GlobalSM::instance().u2lWidgetName;
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("windows-1251"));
    StaticChecks::instance().runChecks(m_checkedList);

    //============================================


    bool notesExists = false;
    m_listNotes->clear();

    if (!errors.isEmpty())
    {

        QHashIterator<QObject*, QStringList> it(errors);
        int index = 1;
        int counter = 1;
        QStringList alreadyList;
        while(it.hasNext())
        {

            QStringList curList = it.next().value();
            QWidget* curWidget = (QWidget*)it.key();
            QStringListIterator itStrings(curList);
            while(itStrings.hasNext())
            {
                QString curError = itStrings.next();

                if (curWidget->objectName().size() && curWidget->objectName() != "bRunChecks" &&
                        curWidget->objectName() != "bCancelChecks")
                {
                    notesExists = true;
                    QString curListString =
                            QString(tr("Ошибка %1 в %2: %3")).arg(QString::number(counter)).arg(curWidget->objectName()).arg(curError);
                    QListWidgetItem* listItem = new QListWidgetItem(QIcon(":/icons/error.png"), curListString);
                    QString alreadyString;
                    alreadyString = QString("%1: %2").arg(curWidget->objectName()).arg(curError);
                    if (!alreadyList.contains(alreadyString))
                    {
                        m_listNotes->addItem(listItem);
                        listItem->setData(Qt::UserRole, QVariant::fromValue(curWidget));
                        listItem->setToolTip(curError.split("\.").join(".\n"));
                        alreadyList.append(alreadyString);
                        counter++;
                    }
                    index++;

                }else
                {
                    index++;
                }
            }
        }
        errors.clear();
    }


    if (!warnings.isEmpty())
    {

        QHashIterator<QObject*, QStringList> it(warnings);
        int index = 1;
        int counter = 1;
        QStringList alreadyList;
        while(it.hasNext())
        {

            QStringList curList = it.next().value();
            QWidget* curWidget = (QWidget*)it.key();
            QStringListIterator itStrings(curList);
            while(itStrings.hasNext())
            {
                QString curWarning = itStrings.next();
                if (curWidget->objectName().size() && curWidget->objectName() != "bRunChecks" &&
                        curWidget->objectName() != "bCancelChecks")
                {
                    notesExists = true;
                    QString curListString =
                            QString(tr("Предупреждение %1 в %2: %3")).arg(QString::number(counter)).arg(curWidget->objectName()).arg(curWarning);
                    QListWidgetItem* listItem = new QListWidgetItem(QIcon(":/icons/warning.png"), curListString);
                    QString alreadyString;
                    alreadyString = QString("%1: %2").arg(curWidget->objectName()).arg(curWarning);
                    if (!alreadyList.contains(alreadyString))
                    {
                        m_listNotes->addItem(listItem);
                        listItem->setData(Qt::UserRole, QVariant::fromValue(curWidget));
                        listItem->setToolTip(curWarning.split("\.").join(".\n"));
                        counter++;
                        alreadyList.append(alreadyString);
                    }
                    index++;
                }else
                {
                    index++;
                }
            }
        }
        warnings.clear();
    }

    if (!notesExists)
        m_listNotes->addItem(tr("Пока нет ни ошибок, ни предупреждений"));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
}

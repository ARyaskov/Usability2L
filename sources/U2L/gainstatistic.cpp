#include "gainstatistic.h"
#include "ui_gainstatistic.h"

GainStatistic::GainStatistic(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::GainStatistic)
{
    ui->setupUi(this);

    m_mw = parent;


    GainStatisticSM& sm = GainStatisticSM::instance();

    takeAllWidgets(m_mw, (QTreeWidgetItem*)NULL);

    int count = ui->widsTree->topLevelItemCount();
    Q_UNUSED(count)
    Q_UNUSED(sm)
}


void GainStatistic::takeAllWidgets(QWidget* widget, QTreeWidgetItem* parent)
{
    QWidgetList list;
    if (widget){
        list =  widget->findChildren<QWidget*>();
        if (list.isEmpty())
        {
            return;
        }
    }else
    {
        return;
    }

    int listSize = list.size();
    QTreeWidgetItem* newItem;
    QString parentName;
    QString className;
    QString objectName;
    const QMetaObject* curMetaObj;

    for (int j=0;j<listSize;j++)
    {
        QObject* current = list.at(j);
        if (current == (QObject*)0xabababab || !current)
            continue;

        curMetaObj = current->metaObject();
        if (curMetaObj->className() == "U2LWidget")
            continue;
        if (/*(MetaExtensions::isDescOf(current, "QWidget") ||
             MetaExtensions::isDescOf(current, "QLayout") ||
             curMetaObj->className() == QString("QWidget") )*/
                curMetaObj->className() == QString("QWidget") &&
                !QString(curMetaObj->className()).startsWith("Q") ){
            parentName = curMetaObj->superClass()->className();
            className = curMetaObj->className();
            objectName = current->property("objectName").toString();
            newItem = new QTreeWidgetItem(parent,
                                          QStringList(QString("Class: %1, Parent: %2 :: %3").arg(className).arg(parentName).arg(objectName)));
        }else if (/*(MetaExtensions::isDescOf(current, "QWidget") ||
                   MetaExtensions::isDescOf(current, "QLayout") ||
                   curMetaObj->className() == QString("QWidget") )*/
                  curMetaObj->className() == QString("QWidget") &&
                  QString(curMetaObj->className()).startsWith("Q") ){
            className = curMetaObj->className();
            objectName = current->property("objectName").toString();
            newItem = new QTreeWidgetItem(parent,
                                          QStringList(QString("Class: %1 :: %2").arg(className).arg(objectName)));
        }else {
            continue;
        }


        int countProps = curMetaObj->propertyCount();
        QMetaProperty currentProperty;
        QString curPropName;
        QString curPropValue;
        QList<QTreeWidgetItem*> propertiesList;

        for(int i=0;i<countProps;i++)
        {
            currentProperty = curMetaObj->property(i);
            curPropName = currentProperty.name();

            curPropValue = dispatchVariantType(current->property(qPrintable(curPropName)));
            if (currentProperty.isDesignable())
            {
                QTreeWidgetItem* tmpItem = new QTreeWidgetItem(QStringList() << curPropName << curPropValue);

                propertiesList.append(tmpItem);
            }
        }
        newItem->addChildren(propertiesList);
        ui->widsTree->insertTopLevelItem(ui->widsTree->topLevelItemCount(),newItem);
        takeAllWidgets((QWidget*)(current), newItem);

    }

}

// Function converts QVariant into QString in smart manner
QString GainStatistic::dispatchVariantType(QVariant _union)
{
    QString res;

    switch (_union.type())
    {
    case QVariant::Rect:{
        QRect r = _union.toRect();
        res = QString("[(%1, %2), %3 x %4]").arg(r.x()).arg(r.y()).arg(r.width()).arg(r.height());
    }break;
    default:{
        res = _union.toString();
        res = res.isEmpty() ? " " : res;
    }
    }
    return res;
}

GainStatistic::~GainStatistic()
{
    /*   ui->widsTree->blockSignals(true);
    int count = ui->widsTree->topLevelItemCount();
    for (int i=0;i<count;i++)
    {
        QTreeWidgetItem* item = ui->widsTree->takeTopLevelItem(i);
        fullTreeItemDestruct(item);
        delete item;
    }
    ui->widsTree->blockSignals(false);*/
    delete ui;
}

void GainStatistic::fullTreeItemDestruct(QTreeWidgetItem* item)
{
    if (item){
        QList<QTreeWidgetItem *> list = item->takeChildren();
        if (list.isEmpty())
            return;
        int count = list.size();
        for (int i=0;i<count;i++)
        {
            fullTreeItemDestruct(list.at(i));
            delete list.at(i);
        }
    }
}


void GainStatistic::on_bExportXML_clicked()
{
    QMessageBox::warning(this,"Title","not implemented yet :)");

    /* QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save report as"), "./", tr("XML files (*.xml)"));

    if (!fileName.isEmpty())
    {
        saveToFileAsText(fileName);
    }*/
}

void GainStatistic::on_bExportText_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save report as"), "./", tr("Text files (*.txt)"));

    if (!fileName.isEmpty())
    {
        saveToFileAsText(fileName);
    }
}

void GainStatistic::on_bExportDB_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save report as"), "./", tr("SQLite DB files (*.sqlite)"));

    if (!fileName.isEmpty())
    {
        saveToFileAsDB(fileName);
    }



}

void GainStatistic::saveToFileAsDB(QString fileName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");



    db.setDatabaseName(fileName);


    if (db.open()) {

        QSqlQuery query("CREATE DATABASE widgets_db;");

        QList<QWidget*> widList = m_mw->findChildren<QWidget*>();
        QString queryString;

        QString paramsString;

        QSqlQuery curQuery;
        QListIterator<QWidget*> it(widList);
        while(it.hasNext())
        {
            QObject* curObject = it.next();
            QString curClassName = curObject->metaObject()->className();

            QString objName = curObject->objectName();
            QString paramsString;

            int propCount = curObject->metaObject()->propertyCount();
            QMetaProperty curProp;
            const QMetaObject* curMetaObject = curObject->metaObject();
            if (curMetaObject->className())
                continue;
            QList<QString> existed;
            for (int i=0;i<propCount;i++)
            {
                curProp = curMetaObject->property(i);
                if (curProp.isDesignable()){

                    QString curName = curProp.name();

                    paramsString+= QString("\n%1 %2,\n").arg(curName).arg(QString("varchar(64)"));
                    existed.append(curName);
                }

            }
            paramsString.remove(paramsString.size() - 2, 1);
            QString curQueryString = QString("CREATE TABLE IF NOT EXISTS %1_table (id INT PRIMARY KEY, %2);").arg(curClassName).arg(paramsString);
            curQuery.prepare(curQueryString);
            curQuery.exec();

        }


        it.toFront();

        queryString.clear();

        curQuery.clear();

        int index = 0;
        while(it.hasNext())
        {
            QObject* curObject = it.next();
            int propCount = curObject->metaObject()->propertyCount();
            QMetaProperty curProp;
            const QMetaObject* curMetaObject = curObject->metaObject();
            QList<QString> paramsList;
            int parIndex = 0;
            paramsString.clear();
            for (int i=0;i<propCount;i++)
            {
                curProp = curMetaObject->property(i);
                if (curProp.isDesignable()){
                    QString curVal = dispatchVariantType( curProp.read(curObject) );

                    paramsString += QString(":p%1,").arg(parIndex);
                    parIndex++;
                    paramsList << curVal;
                }

            }
            QString curClassName = curMetaObject->className();
            paramsString.remove(paramsString.size() - 1, 1);
            QString curQueryString = QString("INSERT INTO %1_table VALUES (%2, %3);").arg(curClassName).arg(index).arg(paramsString);
            index++;
            curQuery.prepare(curQueryString);

            for (int j=0;j<parIndex;j++)
            {
                curQuery.bindValue(QString(":p%1").arg(j), paramsList.at(j));
            }
            curQuery.exec();
            qDebug() << db.lastError().text();
        }

        db.close();
    }


}


void GainStatistic::saveToFileAsText(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){

        QList<QWidget *> widList =  m_mw->findChildren<QWidget*>();

        QTextStream stream(&file);
        QStringList lines;

        QDateTime nowDate(QDateTime::currentDateTime());

        QString infoString(tr("Report generated at "));

        stream << infoString << nowDate.toString() << endl << endl;


        lines << tr("Widgets list:\n");


        QListIterator<QWidget*> it(widList);
        int count=1;
        while(it.hasNext())
        {
            QObject* cur = it.next();
            QString className = cur->metaObject()->className();
            QString objectName = cur->property("objectName").toString();
            if (className ==  "U2LWidget")
                continue;
            if (objectName.isEmpty())
                objectName = tr("<empty>");
            lines << QString("%1. %2 :: %3").arg(count++).arg(className).arg(objectName);
        }


        lines <<  tr("\n <== Widgets and their properties: ==>\n\n");

        QStringList formatLineList = getWidgetAndProps(m_mw,0);
        lines.append(formatLineList);

        QListIterator<QString> it2(lines);
        while(it2.hasNext())
        {
            stream << it2.next() << endl;
        }



        file.close();
    }

}

QStringList GainStatistic::getWidgetAndProps(QObject * obj, int level)
{
    QStringList res;

    if (obj)
    {
        const QWidgetList widList = m_mw->findChildren<QWidget*>();

        QObject* curItem;
        QListIterator<QWidget*> itObj(widList);
        QString className;
        QString objectName;


        while(itObj.hasNext())
        {
            curItem = itObj.next();
            if (MetaExtension::isDescOf(curItem, "QWidget"))
            {
                className = curItem->metaObject()->className();
                objectName = curItem->property("objectName").toString();
                auto lambdaSpaces =
                            [level] () -> QString {QString s;for(int i=0;i++<level;s.append(" "));return s;};

            QString str = lambdaSpaces();
            objectName = objectName.isEmpty() ? "<empty objectName>" : objectName;
            className = className.isEmpty() ? "<empty className>" : className;

            str.append(QString("%1 :: %2").arg(objectName).arg(className));

            res.append(str);



            QStringList listPropVal;
            int propertyCount = curItem->metaObject()->propertyCount();
            if (propertyCount > 0)
            {
                str = lambdaSpaces();
                res << QString("\n" + str.append("== Properties start ==\n"));
            }
            QString propertyName;
            QString propertyValue;
            for (int i=0;i<propertyCount;i++)
            {
                if (curItem->metaObject()->property(i).isDesignable()){
                    propertyName = curItem->metaObject()->property(i).name();
                    QVariant tmpVar = curItem->property(propertyName.toAscii().constData());
                    propertyValue = dispatchVariantType(tmpVar);
                    propertyValue = propertyValue == QString() ? QString("<empty>") : propertyValue;

                    QString tmpStr = lambdaSpaces();
                    tmpStr.append(QString("%1 :: %2 :: %3").arg(propertyName).arg(tmpVar.typeName()).arg(propertyValue));
                    listPropVal << tmpStr;
                }
            }

            res.append(listPropVal);
            if (propertyCount > 0)
            {
                str = [level] () -> QString {QString s;for(int i=0;i++<level;s.append(" "));return s;}();
            res << QString("\n" + str.append("== Properties end ==\n"));
        }
        if (curItem == obj)
            return QStringList();
        res.append(getWidgetAndProps(curItem, level+4));


        // QListIterator<QMetaProperty*> itProp(curItem->metaObject())
    }
}

}


return res;
}



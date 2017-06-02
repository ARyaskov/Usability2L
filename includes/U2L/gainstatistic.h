#ifndef GAINSTATISTIC_H
#define GAINSTATISTIC_H

#include "../../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/settingsmanager.h"


namespace Ui {
class GainStatistic;
}

class GainStatistic : public QDialog
{
    Q_OBJECT
    
public:
    explicit GainStatistic(QMainWindow *parent);
    ~GainStatistic();
    QString dispatchVariantType(QVariant _union);
    void takeAllWidgets(QWidget* widget, QTreeWidgetItem *parent);
    void fullTreeItemDestruct(QTreeWidgetItem *item);
    void saveToFileAsText(QString filename);
    void saveToFileAsDB(QString fileName);

    QStringList getWidgetAndProps(QObject * obj, int level);
private:
    QMainWindow* m_mw;
    Ui::GainStatistic *ui;

private slots:
    void on_bExportText_clicked();
    void on_bExportDB_clicked();
    void on_bExportXML_clicked();
};



#endif // GAINSTATISTIC_H

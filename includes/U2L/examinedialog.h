#ifndef EXAMINEDIALOG_H
#define EXAMINEDIALOG_H

#include "../../includes/pch.h"
#include "staticchecks.h"

namespace Ui {
class ExamineDialog;
}



class ExamineDialog : public QDialog
{
    Q_OBJECT
    
    QListWidget* m_listNotes;
    QTreeWidget* m_checksTree;
    QList<QTreeWidgetItem*> m_checkedList;
public:
    void floodChecksTree();
    explicit ExamineDialog(QWidget *parent = 0);
    ~ExamineDialog();
    
private:
    Ui::ExamineDialog *ui;

private slots:
    void on_bRunChecks_clicked();
    void on_current_item_changed(QListWidgetItem*, QListWidgetItem*);
    void on_item_change_state(QTreeWidgetItem * item, int column);
};

#endif // EXAMINEDIALOG_H

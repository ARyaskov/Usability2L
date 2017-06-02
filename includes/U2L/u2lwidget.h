/**
* @file u2lwidget.h
* @brief описание класса виджета Usability2L для QtDesigner
*
* @author Андрей Рясков
* @date 16 апреля 2012 г.

*/

#ifndef U2LWIDGET_H
#define U2LWIDGET_H

#include "../includes/pch.h"
#include "../../includes/U2L/metaextensions.h"
#include "../../includes/U2L/ruleseditor.h"
#include "../../includes/U2L/gainstatistic.h"
#include "../../includes/U2L/examinedialog.h"
#include "../../includes/U2L/settingsmanager.h"
#include "../../includes/U2L/staticchecks.h"


class QDESIGNER_WIDGET_EXPORT U2LWidget : public QWidget
{
    Q_OBJECT
private:
    QMainWindow * m_mainwindow;
    RulesEditor* rulesEditor;
    GainStatistic* gainStatistic;
    ExamineDialog* examineDialog;

public:
    explicit U2LWidget(QWidget *parent = 0);
    ~U2LWidget();

#ifdef _MSC_VER
    QMainWindow* getMainWindow();

    void setMainWindow(QMainWindow* new_mw);

    void setup(QMainWindow* parent);
#endif

#if !defined(_MSC_VER)
    Q_DECL_EXPORT QMainWindow* getMainWindow();

    Q_DECL_EXPORT void setMainWindow(QMainWindow* new_mw);

    Q_DECL_EXPORT void setup(QMainWindow* parent);
#endif


 private slots:
    void on_actionExamine_triggered();
    void on_actionRulesEditor_triggered();
    void on_actionGainStatistic_triggered();


};

#endif // U2LWIDGET_H

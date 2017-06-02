/**
* @file ruleseditor.h
* @brief описание класса диалога редактора IVL
*

*/

#ifndef RULESEDITOR_H
#define RULESEDITOR_H

#include "../includes/pch.h"
#include "../../includes/U2L/flex.h"
#include "../../includes/U2L/bison.h"
#include "settingsmanager.h"


namespace Ui {
  class RulesEditor;
}




class RulesEditor : public QDialog
{
  Q_OBJECT


public:
  explicit RulesEditor(QMainWindow *parent);
  ~RulesEditor();



  QsciScintilla* m_sourceEdit;
  QMainWindow* m_mw;
  QListWidget* m_listNotes;
private:
  QAction* m_actOpen;
  QAction* m_actSave;
  QAction* m_actSaveAs;
  QAction* m_actCloseFile;
  QAction* m_actSettings;
  QMenu* m_fileMenu;
  QMenu* m_miscMenu;
  QString m_prevTextHash;
  QMenuBar* m_menubar;
  QString m_openedFilePath;
  Ui::RulesEditor *ui;

private slots:
  void on_bClose_triggered();
  void on_actOpen_triggered();
  void on_actSave_triggered();
  void on_actSaveAs_triggered();
  void on_actCloseFile_triggered();
  void on_bRun_clicked();
  void on_documentWasModified();
  void on_fileMenu_aboutToShow();
};

#endif // RULESEDITOR_H

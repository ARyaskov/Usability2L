#ifndef PCH_H
#define PCH_H



#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <cmath>
#include <cfloat>
#include <functional>

#include <QObject>
#include <QtGlobal>
#include <QCoreApplication>
#include <QApplication>

#ifdef D_SHARED_LIB
    #define D_SHARED Q_DECL_EXPORT
#else
    #define D_SHARED Q_DECL_IMPORT
#endif



#include <QtDesigner/QDesignerCustomWidgetInterface>
#include <QtDesigner/QDesignerExportWidget>
#include <QtDesigner/QDesignerFormEditorInterface>

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QIcon>
#include <QFont>



// for Q_EXPORT_PLUGIN2
#include <QtCore/QtPlugin>

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QResource>
#include <QMessageBox>
#include <QSyntaxHighlighter>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

#include <QPainter>
#include <QPaintEvent>
#include <QPaintEngine>


#include <QHash>
#include <QMap>
#include <QMetaClassInfo>
#include <QHashIterator>

#include "../QScintillaQt4/Qt4Qt5/Qsci/qscilexercustom.h"
#include "../QScintillaQt4/Qt4Qt5/Qsci/qsciscintilla.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QMetaObject>
#include <QScopedPointer>
#include <QPointer>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include <QDateTime>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSQLiteDriver>
#include <QtSql/QSQLiteResult>
#include <QtSql/qsql_sqlite.h>

#include <QListWidget>
#include <QDebug>

#include <QTextCodec>
#include <QTimer>
#include <QTranslator>

#include <QCryptographicHash>
#include <QComboBox>
#include <QSpinBox>
#include <QValidator>
#include <QTimeEdit>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QSpacerItem>


#endif // PCH_H

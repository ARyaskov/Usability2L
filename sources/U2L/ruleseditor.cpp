
#include "../../includes/U2L/ivllexer.h"
#include "../../includes/U2L/ruleseditor.h"

#include "../../includes/U2L/ui_ruleseditor.h"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996 4102)
#include "../../includes/U2L/lex.yy.hpp"
#pragma warning(pop)
#else
#include "../../includes/U2L/lex.yy.hpp"
#endif

#define SCRIPT_MAX_LEN 8192


QHash<QObject*, QStringList> errors;
QHash<QObject*, QStringList> warnings;

RulesEditor::RulesEditor(QMainWindow* parent) :
    QDialog(parent),
    ui(new Ui::RulesEditor)
{
    ui->setupUi(this);



    //IVLHighlighter *highlighter = new IVLHighlighter(ui->teSourceEdit->document());
    m_menubar = new QMenuBar();
    m_mw = parent;


    m_fileMenu = m_menubar->addMenu(QObject::tr("Файл"));
    //m_miscMenu = m_menubar->addMenu(QObject::tr("Другое"));

    m_actOpen = new QAction(QObject::tr("Открыть файл правил..."), m_fileMenu);
    m_fileMenu->addAction(m_actOpen);

    m_actSave = new QAction(QObject::tr("Сохранить файл правил"), m_fileMenu);
    m_fileMenu->addAction(m_actSave);
    m_actSave->setDisabled(true);

    m_actSaveAs = new QAction(QObject::tr("Сохранить файл правил как..."), m_fileMenu);
    m_fileMenu->addAction(m_actSaveAs);
    m_actSaveAs->setDisabled(true);

    m_fileMenu->addSeparator();

    m_actCloseFile = new QAction(QObject::tr("Закрыть файл правил"), m_fileMenu);
    m_fileMenu->addAction(m_actCloseFile);
    m_actCloseFile->setDisabled(true);


    //m_actSettings = new QAction(QObject::tr("Настройки"), m_miscMenu);
    //m_miscMenu->addAction(m_actSettings);
    //m_actSettings->setDisabled(true);

    ui->verticalLayout->setMenuBar(m_menubar);

    m_listNotes = new QListWidget();
    m_listNotes->addItem(tr("Пока нет ни ошибок, ни предупреждений"));
    ui->verticalLayout->addWidget(m_listNotes);


    connect(ui->bClose,SIGNAL(clicked()), this, SLOT(on_bClose_triggered()),Qt::UniqueConnection);
    connect(ui->bRun,SIGNAL(clicked()), this, SLOT(on_bRun_clicked()),Qt::UniqueConnection);

    connect(m_actOpen, SIGNAL(triggered()),this, SLOT(on_actOpen_triggered()), Qt::UniqueConnection);
    connect(m_actSave, SIGNAL(triggered()),this, SLOT(on_actSave_triggered()), Qt::UniqueConnection);
    connect(m_actSaveAs, SIGNAL(triggered()),this, SLOT(on_actSaveAs_triggered()), Qt::UniqueConnection);
    connect(m_actCloseFile, SIGNAL(triggered()),this, SLOT(on_actCloseFile_triggered()), Qt::UniqueConnection);

    connect(m_fileMenu, SIGNAL(aboutToShow()),this, SLOT(on_fileMenu_aboutToShow()), Qt::UniqueConnection);

    /*QScintilla setup*/

    m_sourceEdit = new QsciScintilla(this);

    ui->gridLayout->addWidget(m_sourceEdit, 1, 0);


    IVLLexer * lexIVL = new IVLLexer(this);
    m_sourceEdit->setLexer(lexIVL);

    m_sourceEdit->setUtf8(true);
    //m_sourceEdit->SendScintilla(QsciScintilla::SCI_SETCODEPAGE, 65001);
    //m_sourceEdit->setLocale(QLocale(QLocale::Russian));
    m_sourceEdit->setCaretLineVisible(true);
    m_sourceEdit->setCaretLineBackgroundColor(QColor("lightGray"));


    m_sourceEdit->setAutoIndent(true);
    m_sourceEdit->setIndentationGuides(true);

    m_sourceEdit->setIndentationsUseTabs(false);

    m_sourceEdit->setIndentationWidth(2);


#if defined Q_WS_X11
    m_sourceEdit->setEolMode(QsciScintilla::EolUnix);
#elif defined Q_WS_WIN
    m_sourceEdit->setEolMode(QsciScintilla::EolWindows);
#endif


    m_sourceEdit->setMarginsBackgroundColor(QColor(0xE3,0xDA,0xDE));

    m_sourceEdit->setMarginLineNumbers(1, true);

    m_sourceEdit->setMarginWidth(1, QString("10"));

    //Автозавершение лексем
    m_sourceEdit->setAutoCompletionSource(QsciScintilla::AcsAll);
    m_sourceEdit->setAutoCompletionCaseSensitivity(true);
    m_sourceEdit->setAutoCompletionReplaceWord(true);
    m_sourceEdit->setAutoCompletionShowSingle(true);
    m_sourceEdit->setAutoCompletionThreshold(3);


    m_sourceEdit->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    m_sourceEdit->setMatchedBraceBackgroundColor(QColor(0x39,0xE6,0x39));
    m_sourceEdit->setUnmatchedBraceForegroundColor(QColor(0x6C,0x8C,0xD5));

    m_sourceEdit->setWrapMode(QsciScintilla::WrapWord);

    connect(m_sourceEdit, SIGNAL(textChanged()),
            this, SLOT(on_documentWasModified()));

    connect(m_sourceEdit, SIGNAL(cursorPositionChanged(int, int)),
            this, SLOT(cursorMoved(int, int)));


    m_sourceEdit->setFocus();

    QCryptographicHash hash(QCryptographicHash::Md5);
    QString text = m_sourceEdit->text();
    hash.addData(text.toAscii());
    m_prevTextHash = hash.result().toHex().data();

}


void RulesEditor::on_bClose_triggered()
{
    m_sourceEdit->clear();
    warnings.clear();
    errors.clear();
    m_listNotes->clear();
    reject();
}

void RulesEditor::on_fileMenu_aboutToShow()
{
    QString text = m_sourceEdit->text();
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(text.toAscii());
    QString nowHash = hash.result().toHex().data();
    if (!nowHash.compare(m_prevTextHash))
    {
        this->m_actSave->setDisabled(true);
        this->m_actSaveAs->setDisabled(true);
    }else
    {
        this->m_actSave->setEnabled(true);
        this->m_actSaveAs->setEnabled(true);
    }


}

void RulesEditor::on_actOpen_triggered()
{
    QString pathToFile = QFileDialog::getOpenFileName(this,
                                                      QObject::tr("Open .IVL file"),
                                                      GlobalSM::instance().recentIVLOpenFileDialogPath,
                                                      QObject::tr("Interface verification files (*.ivl)"));
    QDir fileDir(pathToFile);
    int numChars = fileDir.absolutePath().split("/").last().size();
    QString pathDir = fileDir.absolutePath();
    pathDir.chop(numChars);
    GlobalSM::instance().recentIVLOpenFileDialogPath = pathDir;

    QFile ivlfile(pathToFile);
    if (ivlfile.open(QFile::ReadOnly)) {
        QTextStream in(&ivlfile);


        QStringList list;
        while(!in.atEnd())
        {
            list << in.readLine();
        }
        m_sourceEdit->setText(list.join("\n"));
        ivlfile.close();
        m_openedFilePath = pathToFile;

        m_actSave->setDisabled(true);
        m_actSaveAs->setEnabled(true);
        m_actCloseFile->setEnabled(true);

        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(m_sourceEdit->text().toAscii());
        m_prevTextHash = hash.result().toHex().data();
    }else
    {
        qWarning() << QObject::tr("IVL file %1 not open").arg(pathToFile);
    }

}

void RulesEditor::on_actSave_triggered()
{
    QFile ivlfile(m_openedFilePath);
    if (ivlfile.open(QFile::WriteOnly)) {
        QString text = m_sourceEdit->text();
        QTextStream out(&ivlfile);

        out << text;

        ivlfile.close();
        m_actSave->setDisabled(true);

        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(text.toAscii());
        m_prevTextHash = hash.result().toHex().data();
    }else
    {
        qWarning() << QObject::tr("IVL file %1 not saved").arg(m_openedFilePath);
    }
}

void RulesEditor::on_actSaveAs_triggered()
{
    QString pathToFile = QFileDialog::getSaveFileName(this,
                                                      QObject::tr("Open .IVL file"),
                                                      GlobalSM::instance().recentIVLOpenFileDialogPath,
                                                      QObject::tr("Interface verification files (*.ivl)"));
    QDir fileDir(pathToFile);
    int numChars = fileDir.absolutePath().split("/").last().size();
    QString pathDir = fileDir.absolutePath();
    pathDir.chop(numChars);
    GlobalSM::instance().recentIVLSaveAsFileDialogPath = pathDir;

    QFile ivlfile(pathToFile);
    if (ivlfile.open(QFile::WriteOnly)) {
        QString text = m_sourceEdit->text();
        QTextStream out(&ivlfile);

        out << text;

        ivlfile.close();
        m_actSave->setDisabled(true);
        m_actCloseFile->setEnabled(true);

        m_openedFilePath = pathToFile;
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(m_sourceEdit->text().toAscii());
        m_prevTextHash = hash.result().toHex().data();
    }else
    {
        qWarning() << QObject::tr("IVL file %1 not saved").arg(pathToFile);
    }

}

void RulesEditor::on_actCloseFile_triggered()
{
    m_openedFilePath = "";
    m_actSave->setDisabled(true);
    m_actSaveAs->setDisabled(true);
    m_actCloseFile->setDisabled(true);
    m_sourceEdit->setText(QString());

    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(m_sourceEdit->text().toAscii());
    m_prevTextHash = hash.result().toHex().data();

}


void RulesEditor::on_documentWasModified()
{
    m_sourceEdit->recolor(0,-1);


}

RulesEditor::~RulesEditor()
{
    delete ui;
    delete m_sourceEdit;
}



void RulesEditor::on_bRun_clicked()
{


    int len = m_sourceEdit->SendScintilla(QsciScintilla::SCI_GETLENGTH);
    char* buf = new char[SCRIPT_MAX_LEN];
    memset (buf,'-',SCRIPT_MAX_LEN);

    m_sourceEdit->SendScintilla(QsciScintilla::SCI_GETTEXT,len+1,buf);
    YY_BUFFER_STATE bufState = yy_scan_string((const char*)buf);
    setlocale(LC_CTYPE, "russian");

    logfile = fopen("log.txt", "w");

    if (errno)
    {
        qWarning() << QObject::tr("Log file is not be opened!");
    }

    errfile = freopen("err.txt","w",stderr);
    if (errno)
    {
        qWarning() << QObject::tr("stderr is not be redirected!");
    }

    yy_switch_to_buffer(bufState);

    yyparse();



    yy_delete_buffer(bufState);
    fclose(errfile);
    fclose(logfile);

    delete[] buf;


    m_listNotes->clear();

    bool notesExists = false;

    if (!errors.isEmpty())
    {
        notesExists = true;
        QHashIterator<QObject*, QStringList> it(errors);
        int index = 1;
        while(it.hasNext())
        {

            QStringList curList = it.next().value();
            QWidget* curWidget = (QWidget*)it.key();
            QStringListIterator itStrings(curList);
            while(itStrings.hasNext())
            {
                QString curError = itStrings.next();
                QString curListString =
                        QString(tr("Error %1 at %2: %3")).arg(QString::number(index)).arg(curWidget->objectName()).arg(curError);
                QListWidgetItem* listItem = new QListWidgetItem(QIcon(":/icons/error.png"), curListString);
                m_listNotes->addItem(listItem);
                index++;
            }
        }
        errors.clear();
    }


    if (!warnings.isEmpty())
    {
        notesExists = true;
        QHashIterator<QObject*, QStringList> it(warnings);
        int index = 1;
        while(it.hasNext())
        {

            QStringList curList = it.next().value();
            QWidget* curWidget = (QWidget*)it.key();
            QStringListIterator itStrings(curList);
            while(itStrings.hasNext())
            {
                QString curWarning = itStrings.next();
                QString curListString =
                        QString(tr("Warning %1 at %2: %3")).arg(QString::number(index)).arg(curWidget->objectName()).arg(curWarning);
                QListWidgetItem* listItem = new QListWidgetItem(QIcon(":/icons/warning.png"), curListString);
                m_listNotes->addItem(listItem);
                index++;
            }
        }
        warnings.clear();
    }

    if (!notesExists)
        m_listNotes->addItem(tr("No errors or warnings yet"));

}




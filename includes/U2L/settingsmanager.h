/**
* @file settingsmanager.h
* @brief описание класса хранителя настроек
*
* @author Андрей Рясков
* @date 7 мая 2012 г.

*/

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "../../includes/pch.h"

class GlobalSM
{

public:
    static GlobalSM& instance()
    {
        static GlobalSM theSingleInstance;
        return theSingleInstance;
    }

    QString u2lWidgetName;
    QPointer<QWidget> u2lwidget;
    QString menuName;
    QString recentIVLOpenFileDialogPath;
    QString recentIVLSaveFileDialogPath;
    QString recentIVLSaveAsFileDialogPath;
private:
    GlobalSM(GlobalSM& root){Q_UNUSED(root);}
    GlobalSM& operator=(GlobalSM&){}

    GlobalSM()
    {
        u2lWidgetName = "u2lwidget";
        u2lwidget = new QWidget();
        menuName = "Usability2L";
        recentIVLOpenFileDialogPath = QCoreApplication::applicationDirPath();
        qDebug() << "Current IVLOpenFileDialog path : " << recentIVLOpenFileDialogPath;
        recentIVLSaveAsFileDialogPath = QCoreApplication::applicationDirPath();

    }
};

class RulesEditorSM
{


};

class GainStatisticSM
{

public:
    static GainStatisticSM& instance()
    {
        static GainStatisticSM theSingleInstance;
        return theSingleInstance;
    }

    int textPropertiesIndent;
    int textWidgetsIndent;

private:
    GainStatisticSM(GainStatisticSM& root){Q_UNUSED(root);}
    GainStatisticSM& operator=(GainStatisticSM&){}

    GainStatisticSM()
    {
        GainStatisticSM::textPropertiesIndent = 2;
        GainStatisticSM::textWidgetsIndent = 4;
    }
};

#endif // SETTINGSMANAGER_H

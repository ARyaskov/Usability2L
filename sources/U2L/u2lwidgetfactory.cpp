#include "../../includes/U2L/u2lwidgetfactory.h"

#include "../../includes/U2L/u2lwidget.h"


U2LWidgetFactory::U2LWidgetFactory( QObject* parent ) : QObject( parent )
{

    m_initialized = false;
}


QWidget* U2LWidgetFactory::createWidget( QWidget* parent )
{
    U2LWidget* widget = new U2LWidget( parent );

    return widget;
}


QString U2LWidgetFactory::group() const
{
    return QString::fromLatin1("[Usability Testing]");
}


QIcon U2LWidgetFactory::icon() const
{
    return QIcon(":/icons/U2L_64.png");
}

QString U2LWidgetFactory::includeFile() const
{
    return QString::fromLatin1("../U2L/u2lwidget.h");
}

QString U2LWidgetFactory::toolTip() const
{
    return QString::fromLatin1("Useful things for usablity testing");
}

QString U2LWidgetFactory::whatsThis() const
{
    return QString::fromLatin1("U2L - usability testing tools for GUI");
}

bool U2LWidgetFactory::isContainer() const
{
    return false;
}

QString U2LWidgetFactory::name() const
{
    return QString::fromLatin1("U2LWidget");
}

QString U2LWidgetFactory::domXml() const
{
    return "<ui language=\"c++\">\n"
           "<widget class=\"U2LWidget\" name=\"u2lwidget\">\n"
           "</widget>\n"
           "</ui>\n";
}

void U2LWidgetFactory::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core)

    if (m_initialized)
        return;


    m_initialized = true;
}

 bool U2LWidgetFactory::isInitialized() const
 {
     return m_initialized;
 }


Q_EXPORT_PLUGIN2( u2lplugin, U2LWidgetFactory )

#ifndef U2LWIDGETFACTORY_H
#define U2LWIDGETFACTORY_H

#include "../includes/pch.h"



class U2LWidgetFactory : public QObject,
        public QDesignerCustomWidgetInterface
{

    Q_OBJECT
    Q_INTERFACES( QDesignerCustomWidgetInterface )


    bool m_initialized;
    QMainWindow* m_parentWindow;

public:
    explicit U2LWidgetFactory( QObject* parent = 0 );

public:

    QWidget* createWidget( QWidget* parent );
    QString group() const;
    QIcon icon() const;
    QString includeFile() const;
    bool isContainer() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QString domXml()const;
    bool isInitialized() const;
    void initialize(QDesignerFormEditorInterface *core);



};


#endif  //U2LWIDGETFACTORY_H

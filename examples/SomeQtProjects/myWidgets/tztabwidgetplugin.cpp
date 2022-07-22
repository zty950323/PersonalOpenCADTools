#include "tztabwidget.h"
#include "tztabwidgetplugin.h"

#include <QtPlugin>

TzTabWidgetPlugin::TzTabWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TzTabWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TzTabWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TzTabWidgetPlugin::createWidget(QWidget *parent)
{
    return new TzTabWidget(parent);
}

QString TzTabWidgetPlugin::name() const
{
    return QLatin1String("TzTabWidget");
}

QString TzTabWidgetPlugin::group() const
{
    return QLatin1String("");
}

QIcon TzTabWidgetPlugin::icon() const
{
    return QIcon();
}

QString TzTabWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TzTabWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TzTabWidgetPlugin::isContainer() const
{
    return false;
}

QString TzTabWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TzTabWidget\" name=\"tzTabWidget\">\n</widget>\n");
}

QString TzTabWidgetPlugin::includeFile() const
{
    return QLatin1String("tztabwidget.h");
}


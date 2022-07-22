#include "tzswitchwidget.h"
#include "tzswitchwidgetplugin.h"

#include <QtPlugin>

TzSwitchWidgetPlugin::TzSwitchWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TzSwitchWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TzSwitchWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TzSwitchWidgetPlugin::createWidget(QWidget *parent)
{
    return new TzSwitchWidget(parent);
}

QString TzSwitchWidgetPlugin::name() const
{
    return QLatin1String("TzSwitchWidget");
}

QString TzSwitchWidgetPlugin::group() const
{
    return QLatin1String("");
}

QIcon TzSwitchWidgetPlugin::icon() const
{
    return QIcon();
}

QString TzSwitchWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TzSwitchWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TzSwitchWidgetPlugin::isContainer() const
{
    return false;
}

QString TzSwitchWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TzSwitchWidget\" name=\"tzSwitchWidget\">\n</widget>\n");
}

QString TzSwitchWidgetPlugin::includeFile() const
{
    return QLatin1String("tzswitchwidget.h");
}


#include "tzbutton.h"
#include "tzbuttonplugin.h"

#include <QtPlugin>

TzButtonPlugin::TzButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TzButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TzButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TzButtonPlugin::createWidget(QWidget *parent)
{
    return new TzButton(parent);
}

QString TzButtonPlugin::name() const
{
    return QLatin1String("TzButton");
}

QString TzButtonPlugin::group() const
{
    return QLatin1String("");
}

QIcon TzButtonPlugin::icon() const
{
    return QIcon();
}

QString TzButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TzButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TzButtonPlugin::isContainer() const
{
    return false;
}

QString TzButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TzButton\" name=\"tzButton\">\n</widget>\n");
}

QString TzButtonPlugin::includeFile() const
{
    return QLatin1String("tzbutton.h");
}


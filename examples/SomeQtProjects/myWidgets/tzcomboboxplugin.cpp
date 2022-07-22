#include "tzcombobox.h"
#include "tzcomboboxplugin.h"

#include <QtPlugin>

TzComBoBoxPlugin::TzComBoBoxPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TzComBoBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TzComBoBoxPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TzComBoBoxPlugin::createWidget(QWidget *parent)
{
    return new TzComBoBox(parent);
}

QString TzComBoBoxPlugin::name() const
{
    return QLatin1String("TzComBoBox");
}

QString TzComBoBoxPlugin::group() const
{
    return QLatin1String("");
}

QIcon TzComBoBoxPlugin::icon() const
{
    return QIcon();
}

QString TzComBoBoxPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TzComBoBoxPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TzComBoBoxPlugin::isContainer() const
{
    return false;
}

QString TzComBoBoxPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TzComBoBox\" name=\"tzComBoBox\">\n</widget>\n");
}

QString TzComBoBoxPlugin::includeFile() const
{
    return QLatin1String("tzcombobox.h");
}


#include "tz_widgets.h"
#include "tz_widgetsplugin.h"

#include <QtCore/QtPlugin>

TZ_WidgetsPlugin::TZ_WidgetsPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void TZ_WidgetsPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool TZ_WidgetsPlugin::isInitialized() const
{
    return initialized;
}

QWidget *TZ_WidgetsPlugin::createWidget(QWidget *parent)
{
    return new TZ_Widgets(parent);
}

QString TZ_WidgetsPlugin::name() const
{
    return "TZ_Widgets";
}

QString TZ_WidgetsPlugin::group() const
{
    return "My Plugins";
}

QIcon TZ_WidgetsPlugin::icon() const
{
    return QIcon();
}

QString TZ_WidgetsPlugin::toolTip() const
{
    return QString();
}

QString TZ_WidgetsPlugin::whatsThis() const
{
    return QString();
}

bool TZ_WidgetsPlugin::isContainer() const
{
    return false;
}

QString TZ_WidgetsPlugin::domXml() const
{
    return "<widget class=\"TZ_Widgets\" name=\"TZ_Widgets\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString TZ_WidgetsPlugin::includeFile() const
{
    return "tz_widgets.h";
}

#include "SepSomeWidgets.h"
#include "SepSomeWidgetsPlugin.h"

#include <QtCore/QtPlugin>

SepSomeWidgetsPlugin::SepSomeWidgetsPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void SepSomeWidgetsPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool SepSomeWidgetsPlugin::isInitialized() const
{
    return initialized;
}

QWidget *SepSomeWidgetsPlugin::createWidget(QWidget *parent)
{
    return new SepSomeWidgets(parent);
}

QString SepSomeWidgetsPlugin::name() const
{
    return "SepSomeWidgets";
}

QString SepSomeWidgetsPlugin::group() const
{
    return "Sep Widgets";
}

QIcon SepSomeWidgetsPlugin::icon() const
{
    return QIcon();
}

QString SepSomeWidgetsPlugin::toolTip() const
{
    return QString("a switchable widget.");
}

QString SepSomeWidgetsPlugin::whatsThis() const
{
    return QString("This is a test for my thoughts about use QStackWidget.");
}

bool SepSomeWidgetsPlugin::isContainer() const
{
    return false;
}

QString SepSomeWidgetsPlugin::domXml() const
{
    return "<widget class=\"SepSomeWidgets\" name=\"SepSomeWidgets\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width> 640 </width>\n"
        "   <height> 480 </height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString SepSomeWidgetsPlugin::includeFile() const
{
    return "SepSomeWidgets.h";
}

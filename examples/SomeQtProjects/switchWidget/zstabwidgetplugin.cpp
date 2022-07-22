#include "zstabwidget.h"
#include "zstabwidgetplugin.h"

#include <QtPlugin>
#include <QFile>
#include <QDomDocument>

ZsTabWidgetPlugin::ZsTabWidgetPlugin(QObject *parent) : QObject(parent)
{
    m_initialized = false;
}

bool ZsTabWidgetPlugin::isContainer() const
{
    return true;
}

bool ZsTabWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QIcon ZsTabWidgetPlugin::icon() const
{
    return QIcon();
}

QString ZsTabWidgetPlugin::domXml() const
{
    QFile dom(":/ui_files/zstabwidget.ui");
    if(!dom.open(QFile::ReadOnly | QFile::Text))
    {
        return QLatin1String("<widget class=\"ZsTabWidget\" name=\"ZsTabWidget\">\n</widget>\n");
    }
    QDomDocument doc;
    if (!doc.setContent(&dom, true)) {
        dom.close();
        return QLatin1String("<widget class=\"ZsTabWidget\" name=\"ZsTabWidget\">\n</widget>\n");
    }
    return doc.toString();
}

QString ZsTabWidgetPlugin::group() const
{
    return QLatin1String("myWidgets");
}

QString ZsTabWidgetPlugin::includeFile() const
{
    return QLatin1String("zstabwidget.h");
}

QString ZsTabWidgetPlugin::name() const
{
    return QLatin1String("zstabwidget");
}

QString ZsTabWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ZsTabWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

QWidget *ZsTabWidgetPlugin::createWidget(QWidget *parent)
{
    return new ZsTabWidget(parent);
}

void ZsTabWidgetPlugin::initialize(QDesignerFormEditorInterface *)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

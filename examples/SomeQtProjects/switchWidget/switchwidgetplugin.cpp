#include "switchwidget.h"
#include "switchwidgetplugin.h"

#include <QtPlugin>
#include <QFile>
#include <QDomDocument>

switchWidgetPlugin::switchWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void switchWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool switchWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *switchWidgetPlugin::createWidget(QWidget *parent)
{
    return new switchWidget(parent);
}

QString switchWidgetPlugin::name() const
{
    return QLatin1String("switchWidget");
}

QString switchWidgetPlugin::group() const
{
    return QLatin1String("myWidgets");
}

QIcon switchWidgetPlugin::icon() const
{
    return QIcon();
}

QString switchWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString switchWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool switchWidgetPlugin::isContainer() const
{
    return false;
}

QString switchWidgetPlugin::domXml() const
{
    return QString::fromUtf8(
R"(
<ui>
 <class>switchWidget</class>
 <widget class="QWidget" name="switchWidget">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>683</width>
    <height>652</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>switchWidget</string>
  </property>
  <layout class="QVBoxLayout" name="verticalLayout">
   <item>
    <widget class="QWidget" name="widget" native="true">
     <property name="minimumSize">
      <size>
       <width>200</width>
       <height>30</height>
      </size>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QWidget" name="widget_2" native="true">
     <layout class="QHBoxLayout" name="horizontalLayout_2">
      <item>
       <spacer name="horizontalSpacer_3">
        <property name="orientation">
         <enum>Qt::Horizontal</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>338</width>
          <height>20</height>
         </size>
        </property>
       </spacer>
      </item>
      <item>
       <widget class="QComboBox" name="comboBox">
        <property name="minimumSize">
         <size>
          <width>300</width>
          <height>20</height>
         </size>
        </property>
       </widget>
      </item>
     </layout>
    </widget>
   </item>
   <item>
    <widget class="ZsStackedWidget" name="stackedWidget">
     <property name="minimumSize">
      <size>
       <width>200</width>
       <height>320</height>
      </size>
     </property>
     <property name="lineWidth">
      <number>5</number>
     </property>
     <property name="currentIndex">
      <number>0</number>
     </property>
     <widget class="QWidget" name="page">
      <property name="toolTip">
       <string>Page_0</string>
      </property>
     </widget>
     <widget class="QWidget" name="page_2">
      <property name="toolTip">
       <string>Page_1</string>
      </property>
     </widget>
     <widget class="QWidget" name="page_3">
      <property name="toolTip">
       <string>Page_2</string>
      </property>
     </widget>
     <widget class="QWidget" name="page_4">
      <property name="toolTip">
       <string>Page_3</string>
      </property>
     </widget>
    </widget>
   </item>
  </layout>
 </widget>
 <customwidgets>
  <customwidget>
   <class>ZsStackedWidget</class>
   <extends>QStackedWidget</extends>
   <header>zsstackedwidget.h</header>
   <container>1</container>
  </customwidget>
 </customwidgets>
 <resources/>
 <connections/>
</ui>
)"
);

    QFile dom(":/ui_files/switchwidgetinner.ui");
    if(!dom.open(QFile::ReadOnly | QFile::Text))
    {
        return QLatin1String("<widget class=\"switchWidget\" name=\"switchWidget\">\n</widget>\n");
    }
    QDomDocument doc;
    if (!doc.setContent(&dom, true)) {
        dom.close();
        return QLatin1String("<widget class=\"switchWidget\" name=\"switchWidget\">\n</widget>\n");
    }
    return doc.toString();
}

QString switchWidgetPlugin::includeFile() const
{
    return QLatin1String("switchwidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(switchwidgetplugin, switchWidgetPlugin)
#endif // QT_VERSION < 0x050000

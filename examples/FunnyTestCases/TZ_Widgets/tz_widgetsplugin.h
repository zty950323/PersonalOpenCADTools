#pragma once

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class TZ_WidgetsPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface" FILE "tz_widgetsplugin.json")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    TZ_WidgetsPlugin(QObject *parent = Q_NULLPTR);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized;
};

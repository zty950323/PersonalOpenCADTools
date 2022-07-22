// widgets headers
#include "tztabwidgetplugin.h"
#include "tzbuttonplugin.h"
#include "tzcomboboxplugin.h"
#include "multipagewidgetplugin.h"
#include "tzswitchwidgetplugin.h"
#include "zstabwidgetplugin.h"
#include "tictactoeplugin.h"

// connections headers.
#include "tzcollections.h"

TzCollections::TzCollections(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new TzTabWidgetPlugin(this));
    m_widgets.append(new TzSwitchWidgetPlugin(this));
    m_widgets.append(new TzComBoBoxPlugin(this));
    m_widgets.append(new TzButtonPlugin(this));
    m_widgets.append(new ZsTabWidgetPlugin(this));
    m_widgets.append(new TicTacToePlugin(this));
    m_widgets.append(new MultiPageWidgetPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> TzCollections::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(tzcollectionsplugin, TzCollections)
#endif // QT_VERSION < 0x050000

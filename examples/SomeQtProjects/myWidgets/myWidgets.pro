CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(tzcollectionsplugin)
TEMPLATE    = lib

HEADERS     = tztabwidgetplugin.h tzswitchwidgetplugin.h tzcomboboxplugin.h tzbuttonplugin.h tzcollections.h \
    zstabwidgetplugin.h
SOURCES     = tztabwidgetplugin.cpp tzswitchwidgetplugin.cpp tzcomboboxplugin.cpp tzbuttonplugin.cpp tzcollections.cpp \
    zstabwidgetplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(tzswitchwidget.pri)
include(tzcombobox.pri)
include(tzbutton.pri)
include(tztabwidget.pri)
include(taskMenuextension.pri)
include(multipagewidget.pri)

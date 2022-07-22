greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    QT += xml
    CONFIG += designer
}

CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(switchwidgetplugin)
TEMPLATE    = lib
CONFIG      += qt plugin warn_off
HEADERS     += switchwidgetplugin.h \
    zstabwidgetplugin.h
SOURCES     += switchwidgetplugin.cpp \
    zstabwidgetplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(switchwidget.pri)

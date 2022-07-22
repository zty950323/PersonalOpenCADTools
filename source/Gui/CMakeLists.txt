#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_GUI_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("TZ_GUI_SOURCE_DIR=${TZ_GUI_SOURCE_DIR}")
SET(TZ_GUI_INCLUDE_DIR ${TZ_GUI_SOURCE_DIR}/include)
MESSAGE("TZ_GUI_INCLUDE_DIR=${TZ_GUI_INCLUDE_DIR}")

IF(TZ_QT_ROOT)
    ADD_SUBDIRECTORY(GuiCore)
    ADD_SUBDIRECTORY(GuiTools)
    ADD_SUBDIRECTORY(Widgets)
ENDIF(TZ_QT_ROOT)

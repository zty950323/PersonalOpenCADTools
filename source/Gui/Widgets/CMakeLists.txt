#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZ_SOFT_WIDGETS_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "Widgets not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME Widgets)

SET(TZ_GUI_WIDGETS_PATH ${TZ_SDK_INCLUDE_DIR}/Widgets)
SET(TZ_GUI_WIDGETS_CONTROLS_PATH ${TZ_GUI_WIDGETS_PATH}/Controls)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_GUI_WIDGETS_PATH}/widgets_basic_color_enum_map.h
    ${TZ_GUI_WIDGETS_PATH}/widgets_common_utils.h
    ${TZ_GUI_WIDGETS_PATH}/widgets_defines.h
    ${TZ_GUI_WIDGETS_PATH}/widgets_export.h
    ${TZ_GUI_WIDGETS_PATH}/widgets_keep_menu.h
)

SET(_LIBRARAY_SDK_CONTROLS_INCLUDE
    ${TZ_GUI_WIDGETS_CONTROLS_PATH}/widgets_alarm_button.h
)

SET(_LIBRIRAY_GUI_INCLUDE
    # TODO: future add more file
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
    ${_LIBRARAY_SDK_CONTROLS_INCLUDE}
    ${_LIBRIRAY_GUI_INCLUDE}
)

SET(TZ_LIBRARY_MOC_SRCS
    ${TZ_GUI_WIDGETS_CONTROLS_PATH}/widgets_alarm_button.h
)

SET(TZ_LIBRARY_INC
    inc/widgets_private.h
)

IF(TZ_WINDOWS)
    SET(_TZ_WIDGETS_SRC
        src/dllmain.cpp
        src/widgets.def
    )
ENDIF()

SET(_LIBRARY_WIDGETS_SRC
    src/widgets_private.cpp
)

SET(_LIBRARY_WIDGETS_CONTROLS_SRC
    src/Controls/widgets_alarm_button.cpp
)

SET(_LIBRARY_WIDGETS_COMMON_SRC
    src/Common/widgets_basic_color_enum_map.cpp
)

SET(TZ_LIBRARY_SRC
    ${_TZ_WIDGETS_SRC}
    ${_LIBRARY_WIDGETS_SRC}
    ${_LIBRARY_WIDGETS_COMMON_SRC}
    ${_LIBRARY_WIDGETS_CONTROLS_SRC}
)

SET(TZ_LIBRARY_CUSTOM_GROUP ON)

SET(TZ_LIBRARY_FOLDER "Gui")

#   COMPILE_OPTIONS

SET(TZ_LIBRARY_GENERAL_OPTIONS
    ${__TZ_PLATFORM_COMPILE_OPTIONS}
)

SET(TZ_LIBRARY_GENERAL_OPTIONS_DEBUG
    ${__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG}
)

SET(TZ_LIBRARY_GENERAL_OPTIONS_RELEASE
    ${__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE}
)

#   LINK FLAGS

SET(TZ_LIBRARY_GENERAL_LINK_FLAGS
    ${__TZ_PLATFORM_LINK_FLAGS}
)

SET(TZ_LIBRARY_GENERAL_LINK_FLAGS_DEBUG
    ${__TZ_PLATFORM_LINK_FLAGS_DEBUG}
)

SET(TZ_LIBRARY_GENERAL_LINK_FLAGS_RELEASE
    ${__TZ_PLATFORM_LINK_FLAGS_RELEASE}
)

SET(TZ_LIBRARY_INCLUDE_DIRECTORIES_PRIVATE
    ${TZ_BASIC_INCLUDE_DIR}
    ${TZ_SDK_INCLUDE_DIR}
    ${TZ_THIRDPARTY_ROOT}/boost_1_76_0
    inc
)

SET(TZ_LIBRARY_LINK_LIBRARIES_PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)

SET(TZ_LIBRARY_USE_MODULES_PRIVATE
    Platform
    BasicTools
    GuiCore
    GuiTools
)

SET(TZ_LIBRARY_INSTALL_HEADERS
    ${_LIBRARY_SDK_INCLUDE}
    ${_LIBRARAY_SDK_CONTROLS_INCLUDE}
)

TZ_SETUP_LIBRARY()

IF(TZ_WINDOWS)
    # header file group
    SOURCE_GROUP("include\\Common"
        FILES
        ${_LIBRARY_SDK_INCLUDE}
    )
    SOURCE_GROUP("include\\Controls"
        FILES
        ${_LIBRARAY_SDK_CONTROLS_INCLUDE}
    )
    SOURCE_GROUP("inc"
        FILES
        ${TZ_LIBRARY_INC}
    )
    # source file group
    SOURCE_GROUP("src"
        FILES
        ${_LIBRARY_WIDGETS_SRC}
    )
    SOURCE_GROUP("src\\Platform"
        FILES
        ${_TZ_WIDGETS_SRC}
    )
    SOURCE_GROUP("src\\Controls"
        FILES
        ${_LIBRARY_WIDGETS_CONTROLS_SRC}
    )
    SOURCE_GROUP("src\\Common"
        FILES
        ${_LIBRARY_WIDGETS_COMMON_SRC}
    )
ENDIF()
#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZ_SOFT_GUI_TOOLS_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "GuiTools not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME GuiTools)

SET(TZ_GUI_TOOLS_PATH ${TZ_SDK_INCLUDE_DIR}/GuiTools)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_GUI_TOOLS_PATH}/gui_tools_common_utils.h
    ${TZ_GUI_TOOLS_PATH}/gui_tools_defines.h
    ${TZ_GUI_TOOLS_PATH}/gui_tools_export.h
)

SET(_LIBRIRAY_GUI_INCLUDE
    ${TZ_GUI_INCLUDE_DIR}/gui_tools_drawhelpers.h
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
    ${_LIBRIRAY_GUI_INCLUDE}
)

SET(TZ_LIBRARY_INC
    inc/gui_tools_private.h
    inc/gui_tools_dpi_helper_p.h
)

IF(TZ_WINDOWS)
    SET(_TZ_GUI_TOOLS_SRC
        src/dllmain.cpp
        src/gui_tools.def
    )
ENDIF()

SET(_LIBRARY_GUI_TOOLS_SRC
    src/gui_tools_private.cpp
    src/gui_tools_drawhelpers.cpp
)

SET(TZ_LIBRARY_SRC
    ${_TZ_GUI_TOOLS_SRC}
    ${_LIBRARY_GUI_TOOLS_SRC}
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
    ${TZ_GUI_INCLUDE_DIR}
    inc
)

SET(TZ_LIBRARY_LINK_LIBRARIES_PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)

SET(TZ_LIBRARY_USE_MODULES_PRIVATE
    Platform
    BasicTools
    GuiCore
)

SET(TZ_LIBRARY_INSTALL_HEADERS
    ${_LIBRARY_SDK_INCLUDE}
)

TZ_SETUP_LIBRARY()

IF(TZ_WINDOWS)
    # header file group
    SOURCE_GROUP("include\\Common"
        FILES
        ${TZ_LIBRARY_INCLUDE}
    )
    SOURCE_GROUP("inc"
        FILES
        ${TZ_LIBRARY_INC}
    )
    # source file group
    SOURCE_GROUP("src"
        FILES
        ${_LIBRARY_GUI_TOOLS_SRC}
    )
    SOURCE_GROUP("src\\Platform"
        FILES
        ${_TZ_GUI_TOOLS_SRC}
    )
ENDIF()
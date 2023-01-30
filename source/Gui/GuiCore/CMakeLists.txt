#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZ_SOFT_GUI_CORE_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "GuiCore not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME GuiCore)

SET(TZ_GUI_CORE_PATH ${TZ_SDK_INCLUDE_DIR}/GuiCore)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_GUI_CORE_PATH}/gui_core_common_utils.h
    ${TZ_GUI_CORE_PATH}/gui_core_defines.h
    ${TZ_GUI_CORE_PATH}/gui_core_export.h
)

SET(_LIBRIRAY_GUI_INCLUDE
    # TODO: future add more file.
    ${TZ_GUI_CORE_INCLUDE_DIR}/gui_core_object.h
    ${TZ_GUI_CORE_INCLUDE_DIR}/gui_core_error_unit.h
    ${TZ_GUI_CORE_INCLUDE_DIR}/gui_core_expected_tools.h
    ${TZ_GUI_CORE_INCLUDE_DIR}/gui_core_singleton.h
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
    ${_LIBRIRAY_GUI_INCLUDE}
)

SET(TZ_LIBRARY_INC
    inc/gui_core_private.h
    inc/gui_core_object_p.h
)

IF(TZ_WINDOWS)
    SET(_TZ_CORE_SRC
        src/dllmain.cpp
        src/core.def
    )
ENDIF()

SET(_LIBRARY_CORE_SRC
    src/gui_core_private.cpp
    src/gui_core_object.cpp
)

SET(TZ_LIBRARY_SRC
    ${_TZ_CORE_SRC}
    ${_LIBRARY_CORE_SRC}
)

SET(TZ_LIBRARY_CUSTOM_GROUP ON)

SET(TZ_LIBRARY_FOLDER "Gui")

# COMPILE_OPTIONS

SET(TZ_LIBRARY_GENERAL_OPTIONS
    ${__TZ_PLATFORM_COMPILE_OPTIONS}
)

SET(TZ_LIBRARY_GENERAL_OPTIONS_DEBUG
    ${__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG}
)

SET(TZ_LIBRARY_GENERAL_OPTIONS_RELEASE
    ${__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE}
)

# LINK FLAGS

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
    ${TZ_GUI_CORE_PATH}
    ${TZ_GUI_CORE_INCLUDE_DIR}
    ${TZ_THIRDPARTY_ROOT}/boost_1_79_0
    inc
)

SET(TZ_LIBRARY_LINK_LIBRARIES_PRIVATE
    Qt5::Core
)

SET(TZ_LIBRARY_USE_MODULES_PRIVATE
    Platform
    BasicTools
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
        ${_LIBRARY_CORE_SRC}
    )
    SOURCE_GROUP("src\\Platform"
        FILES
        ${_TZ_CORE_SRC}
    )
ENDIF()
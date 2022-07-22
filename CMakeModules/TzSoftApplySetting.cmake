#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_SET_CONFIGUATION_TYPES()

TZ_SET_OUTPUT_DIRECTORY()

TZ_SET_POSTFIX()

TZ_SET_LIBRARY_LINKING()

TZ_SET_FOLDERS_ENABLE()

IF(TZ_QT_ROOT)
    TZ_SET_QT()
ENDIF()

TZ_SET_INCLUDE_CURRENT_DIR()

TZ_SET_GLOBAL_COMPILE_DEFINITIONS()

TZ_SET_GLOBAL_COMPILE_OPTIONS()

TZ_SET_GLOBAL_LINK_FLAGS()
#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZSOFT_PLATFORM_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "Platform not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME Platform)

IF(TZ_WINDOWS)
    SET(__TZ_PLATFORM_INCLUDE
        ${TZ_SDK_INCLUDE_DIR}/zsofts_windows_ver.h
    )
ENDIF()

SET(TZ_LIBRARY_SRC
    ${_TZ_PLATFORM_SRC}
    ${TZ_SOURCE_COMMON_DIR}/target_winver.cpp
)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_SDK_INCLUDE_DIR}/platform_export.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_assert.h
    ${TZ_SDK_INCLUDE_DIR}/zsofts_compiler_specific.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_debug_utils.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_lock.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_math.h
    ${TZ_SDK_INCLUDE_DIR}/zsofts_platform.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_platform_utils.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_ref_counter.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_str_operations.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_trace_util.h
    ${TZ_SDK_INCLUDE_DIR}/zsofts_types.h
    ${__TZ_PLATFORM_INCLUDE}
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
)

SET(TZ_LIBRARY_INC

)

IF(TZ_WINDOWS)
    SET(__TZ_PLATFORM_SRC
        src/platform_dllmain.cpp
    )
ENDIF()

SET(TZ_LIBRARY_SRC
    src/tzsofts_assert.cpp
    src/tzsofts_platform_utils.cpp
    src/tzsofts_lock.cpp
    src/tzsofts_trace_util.cpp
    ${__TZ_PLATFORM_SRC}
    ${TZ_SOURCE_COMMON_DIR}/target_winver.cpp
)

SET(TZ_LIBRARY_FOLDER "Basic")

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
    inc
)

SET(TZ_LIBRARY_USE_MODULES_PRIVATE

)

SET(TZ_LIBRARY_INSTALL_HEADERS
    ${_LIBRARY_SDK_INCLUDE}
)

TZ_SETUP_LIBRARY()
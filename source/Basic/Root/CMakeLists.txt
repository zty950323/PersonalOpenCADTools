#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZSOFT_ROOT_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "Root not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME Root)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_SDK_INCLUDE_DIR}/root_export.h
    ${TZ_SDK_INCLUDE_DIR}/tzsofts_mem_heap.h
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
    ${TZ_BASIC_INCLUDE_DIR}/root_mem_heap.h
    ${TZ_BASIC_INCLUDE_DIR}/root_mem_heap_dbg.h
    ${TZ_BASIC_INCLUDE_DIR}/root_mem_malloc.h
)

IF(TZ_WINDOWS)
    IF(TZ_WINDOWS_BUILD_32)
        SET(__TZ_PLATFORM_INC_ARCH
            inc/root_win32_mem_pool.h
        )
    ENDIF()

    IF(TZ_WINDOWS_BUILD_64)
        SET(__TZ_PLATFORM_INC_ARCH
            inc/root_win64_mem_pool.h
        )
    ENDIF()

    SET(__TZ_PLATFORM_INC
        ${__TZ_PLATFORM_INC_ARCH}
    )
ENDIF()

SET(TZ_LIBRARY_INC
    ${__TZ_PLATFORM_INC}
)

IF(TZ_WINDOWS)
    IF(TZ_WINDOWS_BUILD_32)
        SET(__TZ_PLATFORM_SRC_ARCH
            src/root_win32_mem_pool.cpp
        )
    ENDIF()

    IF(TZ_WINDOWS_BUILD_64)
        SET(__TZ_PLATFORM_SRC_ARCH
            src/root_win64_mem_pool.cpp
        )
    ENDIF()

    SET(__TZ_PLATFORM_SRC
        src/dllmain.cpp
        ${__TZ_PLATFORM_SRC_ARCH}
    )
ENDIF()

SET(TZ_LIBRARY_SRC
    src/root_mem_heap.cpp
    src/root_mem_malloc.cpp
    src/tzsofts_mem_heap.cpp
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
    Platform
)

SET(TZ_LIBRARY_INSTALL_HEADERS
    ${_LIBRARY_SDK_INCLUDE}
)

TZ_SETUP_LIBRARY()
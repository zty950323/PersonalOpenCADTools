#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZ_SOFT_BASIC_TOOL_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "BasicTools not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME BasicTools)

SET(TZ_BASIC_DP_PATH ${TZ_SDK_INCLUDE_DIR}/DesignPatternTools)
SET(TZ_BASIC_OCTOOLS_PATH ${TZ_SDK_INCLUDE_DIR}/OCTools)
SET(TZ_BASIC_DS_PATH ${TZ_SDK_INCLUDE_DIR}/DataStructure)
SET(TZ_BASIC_UTIL_PATH ${TZ_SDK_INCLUDE_DIR}/Utility)
SET(TZ_BASIC_TEST_PATH ${TZ_SDK_INCLUDE_DIR}/TestCommon)
SET(TZ_BASIC_TOOLS_PATH ${TZ_SDK_INCLUDE_DIR}/BasicTools)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_SDK_INCLUDE_DIR}/basic_array.h
    ${TZ_SDK_INCLUDE_DIR}/basic_open_array.h
    ${TZ_SDK_INCLUDE_DIR}/basic_open_array_stl.h
    ${TZ_SDK_INCLUDE_DIR}/basic_bit_flags.h
    ${TZ_SDK_INCLUDE_DIR}/basic_open_bit_flags.h
    ${TZ_SDK_INCLUDE_DIR}/basic_char_map.h
    ${TZ_SDK_INCLUDE_DIR}/basic_export.h
    ${TZ_SDK_INCLUDE_DIR}/basic_open_math.h
    ${TZ_SDK_INCLUDE_DIR}/basic_open_no_copyable_class.h
    ${TZ_BASIC_TOOLS_PATH}/basic_64_coder.h
    ${TZ_BASIC_DP_PATH}/basic_open_singleTon.h
    ${TZ_BASIC_OCTOOLS_PATH}/basic_yvals_core.h
    ${TZ_BASIC_DS_PATH}/basic_RBTree.h
    ${TZ_BASIC_TEST_PATH}/basic_test_common_class.h
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
    # TODO: future add more file
)

SET(TZ_LIBRARY_INC
    # TODO: future add more file
)

IF(TZ_WINDOWS)
    SET(_TZ_PLATFORM_SRC
        src/dllmain.cpp
        src/basicTools.def
    )
ENDIF()

SET(TZ_LIBRARY_SRC
    ${_TZ_PLATFORM_SRC}
    ${TZ_SOURCE_COMMON_DIR}/target_winver.cpp
    src/basic_64_coder.cpp
)

SET(TZ_LIBRARY_CUSTOM_GROUP ON)

SET(TZ_LIBRARY_FOLDER "Basic")

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
    ${TZ_THIRDPARTY_ROOT}/boost_1_79_0
    inc
)

SET(TZ_LIBRARY_USE_MODULES_PRIVATE
    Platform
    Root
)

SET(TZ_LIBRARY_INSTALL_HEADERS
    ${_LIBRARY_SDK_INCLUDE}
)

TZ_SETUP_LIBRARY()

IF(TZ_WINDOWS)

    SOURCE_GROUP("include\\Common"
        FILES
        ${TZ_SDK_INCLUDE_DIR}/basic_array.h
        ${TZ_SDK_INCLUDE_DIR}/basic_open_array.h
        ${TZ_SDK_INCLUDE_DIR}/basic_open_array_stl.h
        ${TZ_SDK_INCLUDE_DIR}/basic_bit_flags.h
        ${TZ_SDK_INCLUDE_DIR}/basic_open_bit_flags.h
        ${TZ_SDK_INCLUDE_DIR}/basic_char_map.h
        ${TZ_SDK_INCLUDE_DIR}/basic_export.h
        ${TZ_SDK_INCLUDE_DIR}/basic_open_math.h
        ${TZ_SDK_INCLUDE_DIR}/basic_open_no_copyable_class.h
        ${TZ_BASIC_TOOLS_PATH}/basic_64_coder.h
    )

    SOURCE_GROUP("include\\DesignPattern"
        FILES
        ${TZ_BASIC_DP_PATH}/basic_open_singleTon.h
    )

    SOURCE_GROUP("include\\OCTools"
        FILES
        ${TZ_BASIC_OCTOOLS_PATH}/basic_yvals_core.h
    )

    SOURCE_GROUP("include\\DataSturcture"
        FILES
        ${TZ_BASIC_DS_PATH}/basic_RBTree.h
    )

    SOURCE_GROUP("include\\Test"
        FILES
        ${TZ_BASIC_TEST_PATH}/basic_test_common_class.h
    )

    SOURCE_GROUP("src\\Common"
        FILES
        src/basic_64_coder.cpp
    )

ENDIF()
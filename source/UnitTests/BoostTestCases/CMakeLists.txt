#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

TZ_CHECK_LIBRARY_LINKING()

IF(TZ_RESULT_LIBRARY_LINK_DYNAMIC)
    ADD_DEFINITIONS(-DTZ_SOFT_BOOST_TEST_CASES_MODULE)
ELSE()
    MESSAGE(FATAL_ERROR "BoostTestCases not support static lib yet!")
ENDIF()

SET(TZ_LIBRARY_NAME BoostTestCases)

SET(TZ_BOOST_TEST_CASES_PATH ${TZ_SDK_INCLUDE_DIR}/BoostTestCases)

SET(_LIBRARY_SDK_INCLUDE
    ${TZ_BOOST_TEST_CASES_PATH}/boost_test_cases_export.h
)

SET(_LIBRIRAY_UNIT_TESTS_INCLUDE
    # TODO: future add more file
)

SET(TZ_LIBRARY_INCLUDE
    ${_LIBRARY_SDK_INCLUDE}
)

SET(TZ_LIBRARY_INC
    inc/boost_test_cases_private.h
)

IF(TZ_WINDOWS)
    SET(_TZ_BOOST_TEST_CASES_SRC
        src/dllmain.cpp
        src/boostTestCases.def
    )
ENDIF()

SET(_LIBRARY_BOOST_TEST_CASES_SRC
    src/boost_test_cases_private.cpp
)

SET(TZ_LIBRARY_SRC
    ${_TZ_BOOST_TEST_CASES_SRC}
    ${_LIBRARY_BOOST_TEST_CASES_SRC}
)

SET(TZ_LIBRARY_CUSTOM_GROUP ON)

SET(TZ_LIBRARY_FOLDER "UnitTests")

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
        ${_LIBRARY_SDK_INCLUDE}
    )
    SOURCE_GROUP("inc"
        FILES
        ${TZ_LIBRARY_INC}
    )
    # source file group
    SOURCE_GROUP("src"
        FILES
        ${_LIBRARY_BOOST_TEST_CASES_SRC}
    )
    SOURCE_GROUP("src\\Platform"
        FILES
        ${_TZ_BOOST_TEST_CASES_SRC}
    )
ENDIF()
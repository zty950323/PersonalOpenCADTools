#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_BASIC_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("TZ_BASIC_SOURCE_DIR=${TZ_BASIC_SOURCE_DIR}")
SET(TZ_BASIC_INCLUDE_DIR ${TZ_BASIC_SOURCE_DIR}/include)
MESSAGE("TZ_BASIC_INCLUDE_DIR=${TZ_BASIC_INCLUDE_DIR}")

IF(TZ_QT_ROOT)
    ADD_SUBDIRECTORY(BasicTests)
ENDIF(TZ_QT_ROOT)
ADD_SUBDIRECTORY(BasicTools)
ADD_SUBDIRECTORY(Platform)
ADD_SUBDIRECTORY(Root)
IF(TZ_CMAKE_TOOLCHAIN_FILE)
    ADD_SUBDIRECTORY(BasicTestCases)
ENDIF(TZ_CMAKE_TOOLCHAIN_FILE)
#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_BASIC_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("TZ_BASIC_SOURCE_DIR=${TZ_BASIC_SOURCE_DIR}")
SET(TZ_BASIC_INCLUDE_DIR ${TZ_BASIC_SOURCE_DIR}/include)
MESSAGE("TZ_BASIC_INCLUDE_DIR=${TZ_BASIC_INCLUDE_DIR}")

# Define some basic tools path prefix
SET(TZ_BASIC_DP_PATH ${TZ_SDK_INCLUDE_DIR}/DesignPatternTools)
SET(TZ_BASIC_OCTOOLS_PATH ${TZ_SDK_INCLUDE_DIR}/OCTools)
SET(TZ_BASIC_DS_PATH ${TZ_SDK_INCLUDE_DIR}/DataStructure)
SET(TZ_BASIC_UTIL_PATH ${TZ_SDK_INCLUDE_DIR}/Utility)
SET(TZ_BASIC_TEST_PATH ${TZ_SDK_INCLUDE_DIR}/TestCommon)
SET(TZ_BASIC_TOOLS_PATH ${TZ_SDK_INCLUDE_DIR}/BasicTools)

# Define some platform path prefix.
SET(TZ_PLATFORM_PATH ${TZ_SDK_INCLUDE_DIR}/Platform)

IF(TZ_QT_ROOT)
    ADD_SUBDIRECTORY(BasicTests)
ENDIF(TZ_QT_ROOT)
ADD_SUBDIRECTORY(BasicTools)
ADD_SUBDIRECTORY(Platform)
ADD_SUBDIRECTORY(Root)
#[[
IF(TZ_CMAKE_TOOLCHAIN_FILE)
    ADD_SUBDIRECTORY(BasicTestCases)
ENDIF(TZ_CMAKE_TOOLCHAIN_FILE)
]]#
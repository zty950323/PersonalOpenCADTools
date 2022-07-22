#[================================================================[.rst:
    Copyright (c)2022, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_UNIT_TESTS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("TZ_UNIT_TESTS_SOURCE_DIR=${TZ_UNIT_TESTS_SOURCE_DIR}")
SET(TZ_UNIT_TESTS_INCLUDE_DIR ${TZ_GUI_SOURCE_DIR}/include)
MESSAGE("TZ_UNIT_TESTS_INCLUDE_DIR=${TZ_UNIT_TESTS_INCLUDE_DIR}")

ADD_SUBDIRECTORY(BoostTestCases)

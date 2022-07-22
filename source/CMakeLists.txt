#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_SOURCE_COMMON_DIR ${TZ_SOURCE_DIR}/common)
MESSAGE("TZ_SOURCE_COMMON_DIR=${TZ_SOURCE_COMMON_DIR}")

ADD_SUBDIRECTORY(Basic)
ADD_SUBDIRECTORY(Deploy)
ADD_SUBDIRECTORY(Gui)
ADD_SUBDIRECTORY(UnitTests)
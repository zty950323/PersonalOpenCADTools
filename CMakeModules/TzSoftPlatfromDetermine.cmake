#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:

    TZ_WINDOWS
    TZ_WINDOWS_BUILD_32
    TZ_WINDOWS_BUILD_64

    TZ_MAC
    TZ_MAC_BUILD_XX

    TZ_UNIX
    TZ_UNIX_BUILD_XX

#]================================================================]

SET(TZ_WINDOWS 0)
SET(TZ_WINDOWS_BUILD_32 0)
SET(TZ_WINDOWS_BUILD_64 0)

SET(TZ_MAC 0)
SET(TZ_MAC_BUILD_XX 0)

SET(TZ_UNIX 0)
SET(TZ_UNIX_BUILD_XX 0)

IF(WIN32)
    SET(ZS_WINDOWS 1)

    IF(CMAKE_CL_64)
        SET(ZS_WINDOWS_BUILD_64 1)
    ELSE()
        SET(ZS_WINDOWS_BUILD_32 1)
    ENDIF(CMAKE_CL_64)

    IF(MSVC_VERSION LESS 1900)
        MESSAGE(FATAL_ERROR "TzSoft not support comiler")
    ELSEIF(MSVC_VERSION LESS 1910)
        SET(TZ_MSVC_140 1)
    ELSE()
        SET(TZ_MSVC_141 1)
    ENDIF()
ENDIF(WIN32)

IF(APPLE)
    SET(TZ_MAC 1)
    SET(TZ_MAC_BUILD_XX 1)
ENDIF(APPLE)

IF(UNIX)
    SET(TZ_UNIX 1)
    SET(TZ_UNIX_BUILD_XX 1)
ENDIF(UNIX)

IF(TZ_WINDOWS_BUILD_32)
    MESSAGE("TzSoft build windows 32")
ELSEIF(TZ_WINDOWS_BUILD_64)
    MESSAGE("TzSoft build windows 64")
ELSEIF(TZ_MAC_BUILD_XX)
    MESSAGE("TzSoft build mac xx")
ELSEIF(TZ_UNIX_BUILD)
    MESSAGE("TzSoft build unix xx")
ELSE()
    MESSAGE(FATAL_ERROR "TzSoft build unknow!")
ENDIF()
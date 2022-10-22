#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_GLOBAL_CONFIGUATION_TYPES "")

IF(TZ_WINDOWS)
    #   COMPILE_DEFINITIONS
    SET(TZ_GLOBAL_COMPILE_DEFINITIONS
        OS_WIN32
        WINVER=0X0601
        _WIN32_WINNT=0X0601
        PSAPI_VERSION=1
        _AFXDLL
        _WINDOWS
        _WINDLL
        _USRDLL
        _WINSOCK_DEPERCATED_NO_WARNINGS
        _CRT_SECURE_NO_WARNINGS
        _CRT_NONSTDC_NO_WARNINGS
        WIN32_LEAN_AND_MEAN
        NO_WARN_MBCS_MFC_DEPERCATON
        LI_FLOAT_IS_DOUBLE
        LI_MACROS
        LI_NO_COMPILER_CHECK
        _TOOLKIT_IN_DLL_
        _SILENCE_STDEXT_HASH_DEPERCATION_WARNINGS
        DUMMY_TZ_PLATFORM_WINDOWS
        UNICODE
        _UNICODE
        TZ_NO_USE_QT
        QT_DLL
        QT_CORE_LIB
        QT_GUI_LIB
        QT_NO_CAST_FROM_ASCII
        QT_NO_CAST_TO_ASCII
        QT_NO_CAST_FROM_BYTEARRAY
    )

    SET(TZ_GLOBAL_COMPILE_DEFINITIONS_DEBUG
        _DEBUG
    )

    SET(TZ_GLOBAL_COMPILE_DEFINITIONS_RELEASE
        NDEBUG
        MEM_DEBUG
        QT_NO_DEBUG
    )

    #   COMPILE_OPTIONS
    SET(TZ_GLOBAL_COMPILE_OPTIONS
        /MP
        /permissive-
        /std:c++latest
        /FC
        "/wd 4290"
        "/wd 4996"
        "/wd 4812"
        "/wd 4819"
        "/we 4715"
        #"/we 4244"
        "/we 4553"
        "/we 4002"
        "/we 4090"
        "/we 4554"
        "/we 4700"
        "/we 4150"
        "/we 4805"
        "/wd 4005"
    )

    SET(TZ_GLOBAL_COMPILE_OPTIONS_DEBUG
        /ZI
        /JMC
        /W4
        /GT
        /GF-
        /fp:except-
    )

    SET(TZ_GLOBAL_COMPILE_OPTIONS_RELEASE
        /Zi
        /W3
        /Ob1
        /Oi
        /Ot
        /GL
        /GF
        /Gy
    )

    #   LINK_FLAGS
    SET(TZ_GLOABL_LINK_FLAGS
        /SUBSYSTEM:WINDOWS
        /LARGEADDRESWARE
    )

    SET(TZ_GLOABL_LINK_FLAGS_DEBUG
        /INCREMENTAL
        /MAP
        /MAPINFO:EXPORTS
        /SAFESEH:NO
    )

IF(TZ_WINDOWS_BUILD_32)
    SET(__TZ_PLAGFORM_GLOBAL_LINK_RELEASE
        /SAFESEH
    )
ENDIF()

IF(TZ_WINDOWS_BUILD_64)
    SET(__TZ_PLAGFORM_GLOBAL_LINK_RELEASE
    )
ENDIF()

    SET(TZ_GLOBAL_LINK_FLAGS_RELEASE
        /INCREMENTAL:NO
        /LTCG:incremental
        /OPT:ICF
        /OPT:REF
        ${__TZ_PLATFORM_GLOBAL_LINK_RELEASE}
    )

ENDIF(TZ_WINDOWS)

IF(TZ_MAC)

    SET(TZ_GLOBAL_COMPILE_DEFINITIONS
        DUMMY_TZ_PLATFORM_MAC
    )

    TZ_TODO()

ENDIF(TZ_MAC)

IF(TZ_UNIX)

    SET(TZ_GLOBAL_COMPILE_DEFINITIONS
        DUMMY_TZ_PLATFORM_UNIX
    )

    TZ_TODO()

ENDIF(TZ_UNIX)

TZ_ADD_CONFIG("Debug" "")
TZ_ADD_CONFIG("Release" "")
TZ_ADD_CONFIG("MiniSizeReL" "s")
TZ_ADD_CONFIG("RelWithDebInfo" "rd")
TZ_ADD_CONFIG("AlphaTest" "at")

SET(TZ_GLOBAL_OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/Out/$<CONFIG>/bin)
SET(TZ_GLOBAL_OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/Out/$<CONFIG>/lib)

SET(TZ_GLOBAL_INSTALL_INCDIR include)
SET(TZ_GLOBAL_INSTALL_BINDIR bin)

IF(TZ_WINDOWS)
    SET(TZ_GLOBAL_INSTALL_LIBDIR bin)
    SET(TZ_GLOBAL_INSTALL_ARCHIVEDIR lib)
ELSE(TZ_WINDOWS)
    SET(TZ_GLOBAL_INSTALL_LIBDIR lib)
    SET(TZ_GLOBAL_INSTALL_ARCHIVEDIR lib)
ENDIF(TZ_WINDOWS)

OPTION(TZ_GLOBAL_DYNAMIC "Set to on to build all library for dynamic linking. Use OFF for static linking" ON)
OPTION(TZ_BUILD_EXAMPLES "Set to build some examples in our project" ON)
OPTION(TZ_BUILD_GEOM_WITH_CGAL "Set to build some geometry with CGAL as the third party" ON)
OPTION(TZ_LIBRARY_INSTALL "Install the library or not when called with 'cmake --install' command" ON)
OPTION(TZ_APPLICATION_INSTALL "Install the application or not when called with 'cmake --install' command" ON)
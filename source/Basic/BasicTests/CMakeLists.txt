#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_APPLICATION_NAME BasicTests)

SET(TZ_APPLICATION_INCLUDE
    ${TZ_BASIC_INCLUDE_DIR}/basic_test_common_defines.h
)

SET(TZ_APPLICATION_INC
    inc/basic_array_test_tab_widget.h
    inc/basic_array_tests.h
    inc/basic_bit_flags_test_tab_widget.h
    inc/basic_bit_flags_test.h
    inc/BasicTests.h
)

SET(TZ_APPLICATION_SRC
    src/main.cpp
    src/basic_array_test_tab_widget.cpp
    src/basic_array_tests.cpp
    src/basic_bit_flags_test.cpp
    src/basic_bit_flags_test_tab_widget.cpp
    src/BasicTests.cpp
    ${TZ_ADD_RESOURCES}
)

SET(TZ_APPLICATION_UI_FORMS
    res/BasicTests.ui
)

SET(TZ_APPLICATION_MOC_SRCS
    inc/basic_array_test_tab_widget.h
    inc/basic_bit_flags_test_tab_widget.h
    inc/BasicTests.h
)

SET(TZ_APPLICATION_RESOURCES
    res/BasicTests.qrc
)

SET(TZ_APPLICATION_FOLDER "Basic")

#SET(TZ_APPLICATION_GENERAL_DEFINITIONS "")
#SET(TZ_APPLICATION_DEFINITIONS_<CONFIG> "")

IF(TZ_WINDOWS)
    SET(__TZ_PLATFORM_COMPILE_OPTIONS
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS
        /SUBSYSTEM:CONSOLE
    )

    SET(__TZ_PLATFORM_LINK_FLAGS_DEBUG
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS_RELEASE
    
    )

ELSEIF(TZ_MAC)
    SET(__TZ_PLATFORM_COMPILE_OPTIONS
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS

    )

    SET(__TZ_PLATFORM_LINK_FLAGS_DEBUG
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS_RELEASE
    
    )
ELSEIF(TZ_UNIX)
    SET(__TZ_PLATFORM_COMPILE_OPTIONS
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG
    
    )

    SET(__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS_DEBUG
    
    )

    SET(__TZ_PLATFORM_LINK_FLAGS_RELEASE
    
    )

ELSE()
    MESSAGE(FATAL_ERROR "TzSoft not support platform")
ENDIF(TZ_WINDOWS)

#   COMPILE_OPTIONS

SET(TZ_APPLICATION_GENERAL_OPTIONS
    ${__TZ_PLATFORM_COMPILE_OPTIONS}
)

SET(TZ_APPLICATION_GENERAL_OPTIONS_DEBUG
    ${__TZ_PLATFORM_COMPILE_OPTIONS_DEBUG}
)

SET(TZ_APPLICATION_GENERAL_OPTIONS_RELEASE
    ${__TZ_PLATFORM_COMPILE_OPTIONS_RELEASE}
)

SET(TZ_APPLICATION_INCLUDE_DIRECTORIES_PRIVATE
    ${TZ_BASIC_INCLUDE_DIR}
    ${TZ_SDK_INCLUDE_DIR}
    ${TZ_THIRDPARTY_ROOT}/boost_1_76_0
    inc
)

SET(TZ_APPLICATION_LINK_LIBRARIES_PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)

SET(TZ_APPLICATION_LINK_LIBRARIES_PRIVATE_DEUBG
    ${TZ_QT_ROOT}/lib/qtmaind.lib
)

SET(TZ_APPLICATION_LINK_LIBRARIES_PRIVATE_RELEASE
    ${TZ_QT_ROOT}/lib/qtmain.lib
)

SET(TZ_APPLICATION_USE_MODULES_PRIVATE
    Platform
    BasicTools
    Widgets
    BoostTestCases
)

SET(TZ_APPLICATION_DEPENDENCIES

)

SET(TZ_APPILCATION_INSTALL ON)

TZ_SETUP_APPLICATION()
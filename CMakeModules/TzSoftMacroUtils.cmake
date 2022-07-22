#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

MACRO(TZ_BUILDER_VERSION_GREATER MAJOR_VER MINOR_VER PATCH_VER)
    SET(TZ_VAILD_BUILDER_VERSION OFF)
    IF(CMAKE_MAJOR_VERSION GREATER ${MAJOR_VER})
        SET(TZ_VALID_BUILDER_VERSION ON)
    ELSEIF(CMAKE_MAJOR_VERSION EQUAL ${MAJOR_VER})
        IF(CMAKE_MINOR_VERSION GREATER ${MINOR_VER})
            SET(TZ_VALID_BUILDER_VERSION ON)
        ELSEIF(CMAKE_MINOR_VERSION EQUAL ${MINOR_VER})
            IF(CMAKE_PATCH_VERSION GREATER ${PATCH_VER})
                SET(TZ_VALID_BUILDER_VERSION ON)
            ENDIF(CMAKE_PATCH_VERSION GREATER ${PATCH_VER})
        ENDIF(CMAKE_MINOR_VERSION EQUAL ${MINOR_VER})
    ENDIF(CMAKE_MAJOR_VERSION GREATER ${MAJOR_VER})
ENDMACRO(TZ_BUILDER_VERSION_GREATER MAJOR_VER MINOR_VER PATCH_VER)

MACRO(TZ_SETUP_TARGET_CONFIG_DEFINITIONS _TZ_TARGET_NAME _TARGET_TYPE)
    SET(_TZ_CONFIG_DEFINITIONS_GENERATOR "$<1:${TZ_${_TARGET_TYPE}_GENERAL_DEFINITIONS}>")
    LIST(LENGTH TZ_GLOBAL_CONFIGUATION_TYPES _TZ_LIST_LEN)
    FOREACH(i RANGE ${_TZ_LIST_LEN})
        IF(${i} EQUAL ${_TZ_LIST_LEN})
            BREAK()
        ENDIF()
        LIST(GET TZ_GLOBAL_CONFIGUATION_TYPES ${i} _TZ_CONF)
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        SET(_TZ_ITEM "$<$<CONFIG:${_TZ_CONF}>:${TZ_${_TARGET_TYPE}_DEFINITIONS_${_TZ_CONF}}>")
        SET(_TZ_CONFIG_DEFINITIONS_GENERATOR "${_TZ_CONFIG_DEFINITIONS_GENERATOR};${_TZ_ITEM}")
    ENDFOREACH()
    SET_PROPERTY(TARGET ${_TZ_TARGET_NAME} APPEND PROPERTY COMPILE_DEFINITIONS ${_TZ_CONFIG_DEFINITIONS_GENERATOR})
ENDMACRO(TZ_SETUP_TARGET_CONFIG_DEFINITIONS _TZ_TARGET_NAME _TARGET_TYPE)

MACRO(TZ_SETUP_TARGET_CONFIG_COMPILE_OPTIONS _TZ_TARGET_NAME _TARGET_TYPE)
    SET(_TZ_CONFIG_COMPILE_OPTIONS_GENERATOR "$<1:${ZS_${_TARGET_TYPE}_GENERAL_COMPILE_OPTIONS}>")
    LIST(LENGTH TZ_GLOBAL_CONFIGUATION_TYPES _TZ_LIST_LEN)
    FOREACH(i RANGE ${_TZ_LIST_LEN})
        IF(${i} EQUAL ${_TZ_LIST_LEN})
            BREAK()
        ENDIF()
        LIST(GET TZ_GLOBAL_CONFIGUATION_TYPES ${i} _TZ_CONF)
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        SET(_TZ_ITEM "$<$<CONFIG:${_TZ_CONF}>:${TZ_${_TARGET_TYPE}_COMPILE_OPTIONS_${_TZ_CONF}}>")
        SET(_TZ_CONFIG_COMPILE_OPTIONS_GENERATOR "${_TZ_CONFIG_COMPILE_OPTIONS_GENERATOR};${_TZ_ITEM}")
    ENDFOREACH()
    SET_PROPERTY(TARGET ${_TZ_TARGET_NAME} APPEND PROPERTY COMPILE_OPTIONS ${_TZ_CONFIG_COMPILE_OPTIONS_GENERATOR})
ENDMACRO(TZ_SETUP_TARGET_CONFIG_COMPILE_OPTIONS _TZ_TARGET_NAME _TARGET_TYPE)

MACRO(TZ_SETUP_TARGET_CONFIG_LINK_FLAGS _TZ_TARGET_NAME _TARGET_TYPE)

    SET(_TZ_LINK_FLAGS)

    FOREACH(_TZ_ITEM ${TZ_GLOBAL_LINK_FLAGS})
        SET(_TZ_LINK_FLAGS "${_TZ_LINK_FLAGS}${_TZ_ITEM} ")
    ENDFOREACH()

    FOREACH(_TZ_ITEM ${TZ_${_TARGET_TYPE}_GENERAL_LINK_FLAGS})
        SET(_TZ_LINK_FLAGS "${_TZ_LINK_FLAGS}${_TZ_ITEM}")
    ENDFOREACH()

    SET_PROPERTY(TARGET ${_TA_TARGET_NAME} PROPERTY LINK_FLAGS ${_TZ_LINK_FLAGS})

    FOREACH(_TZ_CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        SET(_TZ_LINK_FLAGS_${_TZ_CONF})

        FOREACH(_TZ_ITEM ${TZ_GLOBAL_LINK_FLAGS_${_TZ_CONF}})
            SET(_TZ_LINK_FLAGS_${_ZS_CONF} "${_TZ_LINK_FLAGS_${_TZ_CONF}}${_TZ_ITEM}")
        ENDFOREACH()

        FOREACH(_TZ_ITEM ${TZ_${_TARGET_TYPE}_LINK_FLAGS_${_TZ_CONF}})
            SET(_TZ_LINK_FLAGS_${_TZ_CONF} "${_TZ_LINK_FLAGS_${_TZ_CONF}}${_TZ_ITEM}")
        ENDFOREACH()

        SET_PROPERTY(TARGET ${_TZ_TARGET_NAME} PROPERTY LINK_FLAGS_${_TZCONF} ${_TZ_LINK_FLAGS_${_TZ_CONF}})

    ENDFOREACH()

    #SET_PROPERTY(TARGET ${_TZ_TARGET_NAME} PROPERTY LINK_FLAGS ${TZ_${_TARGET_TYPE}_GENERAL_LINK_FLAGS})
    #FOREACH(_TZ_CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
    #    STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
    #    SET_PROPERTY(TARGET ${_TZ_TARGET_NAME} PROPERTY LINK_FLAGS_${_TZ_CONF} ${TZ_${_TARGET_TYPE}_LINK_FLAGS_${_TZ_CONF}})
    #ENDFOREACH()

ENDMACRO(TZ_SETUP_TARGET_CONFIG_LINK_FLAGS _TZ_TARGET_NAME _TARGET_TYPE)

MACRO(TZ_VAR_CONFIG_GENERATOR_EXPRESSION _TZ_INPUT_VAR_NAME _TZ_OUTPUT_VAR_NAME)
    SET(${_TZ_OUTPUT_VAR_NAME} "")
    LIST(LENGTH TZ_GLOBAL_CONFIGUATION_TYPES _TZ_LIST_LEN)
    FOREACH(i RANGE ${_TZ_LIST_LEN})
        IF(${i} EQUAL ${_TZ_LIST_LEN})
            BREAK()
        ENDIF()
        LIST(GET TZ_GLOBAL_CONFIGUATION_TYPES ${i} _TZ_CONF)
        STRING(TOUUPER ${_TZ_CONF} _TZ_CONF)
        SET(_TZ_ITEM "$<$<CONFIG:${_TZ_CONF}>:${${_TZ_INPUT_VAR_NAME}_${_TZ_CONF}}>")
        SET(${_TZ_OUTPUT_VAR_NAME} "${${_TZ_OUTPUT_VAR_NAME}};${_TZ_ITEM}")
    ENDFOREACH()
ENDMACRO(TZ_VAR_CONFIG_GENERATOR_EXPRESSION _TZ_INPUT_VAR_NAME _TZ_OUTPUT_VAR_NAME)

MACRO(TZ_SETUP_APPLICATION)
    IF(TZ_APPLICATION_MOC_SRCS)
        INCLUDE_DIRECTORIES(
            ${TZ_QT_ROOT}/include
            ${TZ_APPLICATION_MOC_INCLUDE_DIRECTORIES}
        )
        FOREACH(moc_src ${TZ_APPLICATION_MOC_SRCS})
            QT5_WRAP_CPP(_TZ_APPLICATION_MOC_CPP ${moc_src} OPTIONS -f${moc_src} OPTIONS -DHAVE_QT5)
        ENDFOREACH()
    ENDIF()

    IF(TZ_QT_ROOT)
        QT5_WRAP_UI(_TZ_APPLICATION_UI_CPP ${TZ_APPLICATION_UI_FORMS})
    ENDIF()

    IF(DEFINED TZ_APPLICATION_RESOURCES)
        QT5_ADD_RESOURCES(_TZ_APPLICATION_QRC_SRCS ${TZ_APPLICATION_RESOURCES})
    ENDIF()

    ADD_EXECUTABLE(${TZ_APPLICATION_NAME}
        ${TZ_APPLICATION_INCLUDE}
        ${TZ_APPLICATION_INC}
        ${TZ_APPLICATION_SRC}
        ${_TZ_APPLICATION_MOC_CPP}
        ${_TZ_APPLICATION_UI_CPP}
        ${_TZ_APPLICATION_QRC_SRCS}
    )

    IF(NOT TZ_APPLICATION_CUSTOM_GROUP)
        SOURCE_GROUP("include" FILES ${TZ_APPLICATION_INCLUDE})
        SOURCE_GROUP("inc" FILES ${TZ_APPLICATION_INC})
        SOURCE_GROUP("src" FILES ${TZ_APPLICATION_SRC})
    ENDIF()

    SOURCE_GROUP("Resources"
        FILES
        ${TZ_APPLICATION_RESOURCES}
        ${TZ_APPLICATION_UI_FORMS}
    )

    SOURCE_GROUP("Generated"
        FILES
        ${_TZ_APPLICATION_MOC_CPP}
        ${_TZ_APPLICATION_UI_CPP}
        ${_TZ_APPLICATION_QRC_SRCS}
    )

    IF(TZ_APPLICATION_PCH_ENABLE)
        IF(TZ_WINDOWS)
            SET_TARGET_PROPERTIES(${TZ_APPLICATION_NAME} PROPERTIES COMPILE_FLAGS
            "/Yu${TZ_APPLICATION_PCH_HEADER_FILE} /FI${TZ_APPLICATION_PCH_HEADER_FILE}"
            )

            SET_SOURCE_FILES_PROPERTIES(${TZ_APPLICATION_PCH_SOURCE_FILE} PROPERTIES COMPILE_FLAGS
                "/Yc${TZ_APPLICATION_PCH_HERADER_FILE}"    
            )
        ELSE()
            MESSAGE(FATAL_ERROR "tzsoft not support pch yet")
        ENDIF()
    ENDIF()

    FOREACH(_TZ_CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        SET_TARGET_PROPERTIES(${TZ_APPLICATION_NAME} PROPERTIES "OUTPUT_NAME_${_TZ_CONF}" "${TZ_APPLICATION_NAME}${CMAKE_${_TZ_CONF}_POSTFIX}")
    ENDFOREACH()

    SET_TARGET_PROPERTIES(${TZ_APPLICATION_NAME} PROPERTIES FOLDER "${TZ_APPLICATION_FOLDER}")
    SET_TARGET_PROPERTIES(${TZ_APPLICATION_NAME} PROPERTIES PUBLIC_HEADER "${TZ_APPLICATION_INCLUDE}")
    TZ_SETUP_TARGET_CONFIG_DEFINITIONS(${TZ_APPLICATION_NAME} "APPLICATION")
    TZ_SETUP_TARGET_CONFIG_COMPILE_OPTIONS(${TZ_APPLICATION_NAME} "APPLICATION")
    TZ_SETUP_TARGET_CONFIG_LINK_FLAGS(${TZ_APPLICATION_NAME} "APPLICATION")

    TARGET_INCLUDE_DIRECTORIES(${TZ_APPLICATION_NAME} PUBLIC
        ${TZ_APPLICATION_INCLUDE_DIRECTORIES_PUBLIC}
    )

    TARGET_INCLUDE_DIRECTORIES(${TZ_APPLICATION_NAME} INTERFACE
        ${TZ_APPLICATION_INCLUDE_DIRECTORIES_INTERFACE}
    )

    TARGET_INCLUDE_DIRECTORIES(${TZ_APPLICATION_NAME} PRIVATE
        ${TZ_APPLICATION_INCLUDE_DIRECTORIES_PRIVATE}
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} PUBLIC
        general
        "${TZ_APPLICATION_LINK_LIBARIES_PUBLIC}"
        debug
        "${TZ_APPLICATION_LINK_LIBRARIES_PUBLIC_DEBUG}"
        optimized
        "${TZ_APPLICATION_LINK_LIBRARIES_PUBLIC_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} INTERFACE
        general
        "${TZ_APPLICATION_LINK_LIBRARIES_INTERFACE}"
        debug
        "${TZ_APPLICATION_LINK_LIBRARIES_INTERFACE_DEBUG}"
        optimized
        "${TZ_APPLICATION_LINK_LIBRARIES_INTERFACE_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} PRIVATE
        general
        "${TZ_APPLICATION_LINK_LIBRARIES_PRIVATE}"
        debug
        "${TZ_APPLICATION_LINK_LIBRARIES_PRIVATE_DEBUG}"
        optimized
        "${TZ_APPLICATION_LINK_LIBRARIES_PRIVATE_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} PUBLIC
        ${TZ_APPLICATION_USE_MODULES_PUBLIC}
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} INTERFACE
        ${TZ_APPLICATION_USE_MODULES_INTERFACE}
    )

    TARGET_LINK_LIBRARIES(${TZ_APPLICATION_NAME} PRIVATE
        ${TZ_APPLICATION_USE_MODULES_PRIVATE}
    )

    FOREACH(_TZ_DEPEND ${TZ_APPLICATION_DEPENDENCIES})
        ADD_DEPENDENCIES(${TZ_APPLICATION_NAME} ${_TZ_DEPEND})
    ENDFOREACH()

    IF(TZ_APPLICATION_INSTALL)
        INSTALL(
            TARGETS ${TZ_APPLICATION_NAME}
            RUNTIME DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
        )
    ENDIF(TZ_APPLICATION_INSTALL)

    # INSTALL(
    #    TARGETS ${TZ_APPLICATION_NAME}
    #    RUNTIME DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
    #    LIBRARY DESTINATION ${TZ_GLOBAL_INSTALL_LIBDIR}
    #    ARCHIVE DESTINATION ${TZ_GLOBAL_INSTALL_ARCHIVEDIR}
    #    PUBLIC_HEADER DESTINATION ${TZ_GLOBAL_INSTALL_INCDIR}
    #)

ENDMACRO(TZ_SETUP_APPLICATION)

MACRO(TZ_SETUP_LIBRARY)
    IF(TZ_LIBRARY_MOC_SRCS)
        INCLUDE_DIRECTORIES(
            ${TZ_QT_RROT}/include
            ${TZ_LIBRARY_MOC_INCLUDE_DIRECTORIES}
        )

        FOREACH(moc_src ${TZ_LIBRARY_MOC_SRCS})
            QT5_WRAP_CPP(_TZ_LIBRARY_MOC_CPP ${moc_src} OPTIONS -f${moc_src} OPTIONS -DHAVE_QT5)
        ENDFOREACH()
    ENDIF()
    
    IF(${TZ_QT_RROT})
        QT5_WRAP_UI(_TZ_LIBRARY_UI_CPP ${TZ_LIBRARY_UI_FORMS})
    ENDIF()

    IF(DEFINED TZ_LIBRARY_RESOURCES)
        QT5_ADD_RESOURCES(_TZ_LIBRARY_QRC_SRCS ${TZ_LIBRARY_RESOURCES})
    ENDIF()

    ADD_LIBRARY(${TZ_LIBRARY_NAME}
        ${TZ_LIBRARY_LINKING}
        ${TZ_LIBRARY_INCLUDE}
        ${TZ_LIBRARY_INC}
        ${TZ_LIBRARY_SRC}
        ${_TZ_LIBRARY_MOC_CPP}
        ${_TZ_LIBRARY_UI_CPP}
        ${_TZ_LIBRARY_QRC_SRCS}
    )

    IF(NOT TZ_LIBRARY_CUSTOM_GROUP)
        SOURCE_GROUP("include" FILES ${TZ_LIBRARY_INCLUDE})
        SOURCE_GROUP("inc" FILES ${TZ_LIBRARY_INC})
        SOURCE_GROUP("src" FILES ${TZ_LIBRARY_SRC})
    ENDIF()

    SOURCE_GROUP("Resources"
        FILES
        ${TZ_LIBRARY_RESOURCES}
        ${TZ_LIBRARY_UI_FORMS}
    )

    SOURCE_GROUP("Generated"
        FILES
        ${_TZ_LIBRARY_MOC_CPP}
        ${_TZ_LIBRARY_UI_CPP}
        ${_TZ_LIBRARY_QRC_SRCS}
    )

    IF(TZ_LIBRARY_PCH_ENABLE)
        IF(TZ_WINDOWS)
            SET_TARGET_PROPERTIES(${TZ_LIBRARY_NAME} PROPERTIES COMPILE_FLAGS
                "/Yu${TZ_LIBRARY_PCH_HEADER_FILE} /FI${TZ_LIBRARY_PCH_HEADER_FILE}"
            )

            SET_SOURCE_FILES_PROPERTIES(${TZ_LIBRARY_PCH_SOURCE_FILE} PROPERTIES COMPILE_FLAGS
                "/Yc${TZ_LIBRARY_PCH_HERADER_FILE}"    
            )
        ELSE()
            MESSAGE(FATAL_ERROR "tzsoft not support pch yet")
        ENDIF()
    ENDIF()

    SET_TARGET_PROPERTIES(${TZ_LIBRARY_NAME} PROPERTIES FOLDER "${TZ_LIBRARY_FOLDER}")
    SET_TARGET_PROPERTIES(${TZ_LIBRARY_NAME} PROPERTIES PUBLIC_HEADER "${TZ_LIBRARY_INCLUDE}")
    TZ_SETUP_TARGET_CONFIG_DEFINITIONS(${TZ_LIBRARY_NAME} "LIBRARY")
    TZ_SETUP_TARGET_CONFIG_COMPILE_OPTIONS(${TZ_LIBRARY_NAME} "LIBRARY")
    TZ_SETUP_TARGET_CONFIG_LINK_FLAGS(${TZ_LIBRARY_NAME} "LIBRARY")

    TARGET_INCLUDE_DIRECTORIES(${TZ_LIBRARY_NAME} PUBLIC
        ${TZ_LIBRARY_INCLUDE_DIRECTORIES_PUBLIC}
    )

    TARGET_INCLUDE_DIRECTORIES(${TZ_LIBRARY_NAME} INTERFACE
        ${TZ_LIBRARY_INCLUDE_DIRECTORIES_INTERFACE}
    )

    TARGET_INCLUDE_DIRECTORIES(${TZ_LIBRARY_NAME} PRIVATE
        ${TZ_LIBRARY_INCLUDE_DIRECTORIES_PRIVATE}
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} PUBLIC
        general
        "${TZ_LIBRARY_LINK_LIBRARIES_PUBLIC}"
        debug
        "${TZ_LIBRARY_LINK_LIBRARIES_PUBLIC_DEBUG}"
        optimized
        "${TZ_LIBRARY_LINK_LIBRARIES_PUBLIC_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} INTERFACE
        general
        "${TZ_LIBRARY_LINK_LIBRARIES_INTERFACE}"
        debug
        "${TZ_LIBRARY_LINK_LIBRARIES_INTERFACE_DEBUG}"
        optimized
        "${TZ_LIBRARY_LINK_LIBRARIES_INTERFACE_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} PRIVATE
        general
        "${TZ_LIBRARY_LINK_LIBRARIES_PRIVATE}"
        debug
        "${TZ_LIBRARY_LINK_LIBRARIES_PRIVATE_DEBUG}"
        optimized
        "${TZ_LIBRARY_LINK_LIBRARIES_PRIVATE_OPTIMIZED}"
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} PUBLIC
        ${TZ_LIBRARY_USE_MODULES_PUBLIC}
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} INTERFACE
        ${TZ_LIBRARY_USE_MODULES_INTERFACE}
    )

    TARGET_LINK_LIBRARIES(${TZ_LIBRARY_NAME} PRIVATE
        ${TZ_LIBRARY_USE_MODULES_PRIVATE}
    )

    FOREACH(_TZ_DEPEND ${TZ_LIBRARY_DEPENDENCIES})
        ADD_DEPENDENCIES(${TZ_LIBRARY_NAME} ${_TZ_DEPEND})
    ENDFOREACH()

    IF(TZ_LIBRARY_INSTALL)
        INSTALL(
            TARGETS ${TZ_LIBRARY_NAME}
            RUNTIME DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
            LIBRARY DESTINATION ${TZ_GLOBAL_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${TZ_GLOBAL_INSTALL_ARCHIVEDIR}
            PUBLIC_HEADER DESTINATION ${TZ_GLOBAL_INSTALL_INCDIR}
        )
    ENDIF(TZ_LIBRARY_INSTALL)

ENDMACRO(TZ_SETUP_LIBRARY)

MACRO(TZ_SET_CONFIGUATION_TYPES)
    SET(CMAKE_CONFIGURATION_TYPES ${TZ_GLOBAL_CONFIGUATION_TYPES})
ENDMACRO(TZ_SET_CONFIGUATION_TYPES)

MACRO(TZ_SET_OUTPUT_DIRECTORY)
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TZ_GLOBAL_OUTPUT_LIBDIR})
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TZ_GLOBAL_OUTPUT_BINDIR})
    IF(TZ_WINDOWS)
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TZ_GLOBAL_OUTPUT_BINDIR})
    ELSE(TZ_WINDOWS)
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TZ_GLOBAL_OUTPUT_LIBDIR})
    ENDIF(TZ_WINDOWS)

    TZ_BUILDER_VERSION_GREATER(2 8 0)

    IF(TZ_VALID_BUILDER_VERSION)
        FOREACH(CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
            STRING(TOUPPER "${CONF}" CONF)
            SET("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF}" ${TZ_GLOBAL_OUTPUT_LIBDIR})
            SET("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF}" ${TZ_GLOBAL_OUTPUT_BINDIR})
            IF(TZ_WINDOWS)
                SET("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" ${TZ_GLOBAL_OUTPUT_BINDIR})
            ELSE()
                SET("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONF}" ${TZ_GLOBAL_OUTPUT_LIBDIR})
            ENDIF()
        ENDFOREACH()
    ENDIF(TZ_VALID_BUILDER_VERSION)

ENDMACRO(TZ_SET_OUTPUT_DIRECTORY)

MACRO(TZ_SET_POSTFIX)
    FOREACH(CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
        STRING(TOUPPER "${CONF}" CONF)
        SET("CMAKE_&{CONF}_POSTFIX" "${TZ_GLOBAL_POSTFIX_${CONF}}")
    ENDFOREACH()
ENDMACRO(TZ_SET_POSTFIX)

MACRO(TZ_SET_LIBRARY_LINKING)
    IF(TZ_GLOBAL_DYNAMIC)
        SET(TZ_LIBRARY_LINKING "SHARED")
    ELSE()
        SET(TZ_LIBRARY_LINKING "STATIC")
    ENDIF()
ENDMACRO(TZ_SET_LIBRARY_LINKING)

MACRO(TZ_SET_FOLDERS_ENABLE)
    SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
ENDMACRO(TZ_SET_FOLDERS_ENABLE)

MACRO(TZ_CHECK_LIBRARY_LINKING)
    IF(TZ_LIBRARY_LINKING MATCHES "SHARED")
        SET(TZ_RESULT_LIBRARY_LINK_DYNAMIC ON)
    ELSEIF(TZ_LIBRARY_LINKING MATCHES "STATIC")
        SET(TZ_RESULT_LIBRARY_LINK_DYNAMIC OFF)
    ELSE()
        MESSAGE(FATAL_ERROR "TZ_LIBRARY_LINKING INVALID, TZ_LIBRARY_LINKING=${TZ_LIBRARY_LINKING}")
    ENDIF()
ENDMACRO(TZ_CHECK_LIBRARY_LINKING)

MACRO(TZ_FIND_MODULE __MODULE_NAME)
    #MESSAGE("Finding ${__MODULE_NAME}" __MODULE_NAME_UPPER)
    STRING(TOUPPER "${__MODULE_NAME}" __MODULE_NAME_UPPER)
    SET("TZ_${__MODULE_NAME_UPPER}_FOUND" "YES")
    #MESSAGE("TZ_${__MODULE_NAME_UPPER}_FOUND=${TZ_${__MODULE_NAME_UPPER}_FOUND}")
    FOREACH(CONF ${TZ_GLOBAL_CONFIGUATION_TYPES})
        STRING(TOUPPER "${CONF}" CONF)
        SET("TZ_${__MODULE_NAME_UPPER}_LIBRARIES_${CONF}"
            "${TZ_GLOBAL_OUTPUT_LIBDIR}/${__MODULE_NAME}${TZ_GLOBAL_POSTFIX_${CONF}}.lib"
        )

        FIND_LIBRARY("_TZ_LIBNAME_${CONF}"
            NAMES "${__MODULE_NAME}${TZ_GLOBAL_POSTFIX_${CONF}}"
            PATHS
            ${TZ_GLOABL_OUTPUT_LIBDIR}
            NO_DEFAULT_PATH
        )

        MESSAGE("_TZ_LIBNAME_${CONF}=${_TZ_LIBNAME_${CONF}}")

        #MESSAGE("TZ_${MODULE_NAME_UPPER}")
    ENDFOREACH()

    TZ_VAR_CONFIG_GENERATOR_EXPRESSION("TZ_${__MODULE_NAME_UPPER}_LIBRARIES" "TZ_${__MODULE_NAME_UPPER}_LIBRARIES_CONFIG_GENERATOR")
    #MESSAGE("TZ_${__MODULE_NAME_UPPER}_LIBRARIES_CONFIG_GENERATOR=${tZ_${__MODULE_NAME_UPPER}_LIBRARIES_CONFIG_GENERATOR}")
    #MESSAGE("Finding ${__MODULE_NAME} end ........")

ENDMACRO(TZ_FIND_MODULE __MODULE_NAME)

MACRO(TZ_ADD_CONFIG _TZ_CONFIG_NAME _TZ_CONFIG_POSTFIX)
    IF(NOT TZ_GLOBAL_CONFIGUATION_TYPES)
        SET(TZ_GLOBAL_CONFIGUATION_TYPES "${_TZ_CONFIG_NAME}")
    ELSE()
        SET(TZ_GLOBAL_CONFIGUATION_TYPES "${TZ_GLOBAL_CONFIGUATION_TYPES};${_TZ_CONFIG_NAME}")
    ENDIF()
    STRING(TOUPPER "${_TZ_CONFIG_NAME}" _TZ_CONFIG_NAME_UPPER)
    SET("TZ_GLOBAL_POSTFIX_${_TZ_CONFIG_NAME_UPPER}" ${_TZ_CONFIG_POSTFIX})

    IF(NOT DEFINED CMAKE_CXX_FLAGS_${_TZ_CONFIG_NAME_UPPER})
        SET(CMAKE_EXE_LINKER_FLAGS_${_TZ_CONFIG_NAME_UPPER} "")
    ENDIF()

    IF(NOT DEFINED CMAKE_EXE_LINKER_FLAGS_${_TZ_CONFIG_NAME_UPPER})
        SET(CMAKE_EXE_LINKER_FLAGS_${_TZ_CONFIG_NAME_UPPER} "")
    ENDIF()

    IF(NOT DEFINED CMAKE_SHARED_LINKER_FLAGS_${_TZ_CONFIG_NAME_UPPER})
        SET(CMAKE_SHARED_LINKER_FLAGS_${_TZ_CONFIG_NAME_UPPER} "")
    ENDIF()

ENDMACRO(TZ_ADD_CONFIG _TZ_CONFIG_NAME _TZ_CONFIG_POSTFIX)

MACRO(TZ_SET_QT)
    FIND_PACKAGE(Qt5 REQUIRED Widgets Designer Network UiPlugin)

    MESSAGE("Qt5Widgets_FOUND=${Qt5Widgets_FOUND}")
    MESSAGE("Qt5Widgets_INCLUDE_DIRS=${Qt5Widgets_INCLUDE_DIRS}")
    MESSAGE("Qt5Widgets_LIBRARIES=${Qt5Widgets_LIBRARIES}")

    MESSAGE("Qt5Designer_FOUND=${Qt5Designer_FOUND}")
    MESSAGE("Qt5Designer_INCLUDE_DIRS=${Qt5Designer_INCLUDE_DIRS}")
    MESSAGE("Qt5Designer_LIBRARIES=${Qt5Designer_LIBRARIES}")

ENDMACRO(TZ_SET_QT)

MACRO(TZ_SET_INCLUDE_CURRENT_DIR)
    SET(CMAKE_INCLUDE_CURRENT_DIR ON)
ENDMACRO(TZ_SET_INCLUDE_CURRENT_DIR)

MACRO(TZ_SET_GLOBAL_COMPILE_DEFINITIONS)
    SET(_TZ_GENERATOR "$<1:${TZ_GLOBAL_COMPILE_DEFINITIONS}>")
    LIST(LENGTH TZ_GLOBAL_CONFIGUATION_TYPES _TZ_LIST_LEN)
    FOREACH(i RANGE ${_TZ_LIST_LEN})
        IF(${i} EQUAL ${_TZ_LIST_LEN})
            BREAK()
        ENDIF()
        LIST(GET TZ_GLOBAL_CONFIGUATION_TYPES ${i} _TZ_CONF)
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        SET(_TZ_ITEM "$<$<CONFIG:${_TZ_CONF}>:${TZ_GLOBAL_COMPILE_DEFINITIONS_${_TZ_CONF}}>")
        SET(_TZ_GENERATOR "${_TZ_GENERATOR};${_TZ_ITEM}")
    ENDFOREACH()

    SET_PROPERTY(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS "${_TZ_GENERATOR}")

ENDMACRO(TZ_SET_GLOBAL_COMPILE_DEFINITIONS)

MACRO(TZ_SET_GLOBAL_COMPILE_OPTIONS)
    SET(_TZ_GENERATOR "$<1:${TZ_GLOBAL_COMPILE_OPTIONS}>")
    LIST(LENGTH TZ_GLOBAL_CONFIGUATION_TYPES _TZ_LIST_LEN)
    FOREACH(i RANGE ${_TZ_LIST_LEN})
        IF(${i} EQUAL ${_TZ_LIST_LEN})
            BREAK()
        ENDIF()
        LIST(GET TZ_GLOABL_CONFIGUATION_TYPES ${i} _TZ_CONF)
        STRING(TOUPPER ${_TZ_CONF} _TZ_CONF)
        MESSAGE(${_TZ_CONF})
        IF(${_TZ_CONF} EQUAL "NOTFOUND")
            MESSAGE("Right set!.")
            SET(_TZ_ITEM "$<$<CONFIG:${_TZ_CONF}>:${TZ_GLOBAL_COMPILE_OPTIONS_${_TZ_CONF}}")
            # MESSAGE(${_TZ_ITEM})
            SET(_TZ_GENERATOR "${_TZ_GENERATOR};${_TZ_ITEM}")
            # MESSAGE(${_TZ_GENERATOR})
        ELSE()
            MESSAGE(${_TZ_CONF} " is not found ")
        ENDIF()
    ENDFOREACH()

    SET_PROPERTY(DIRECTORY APPEND PROPERTY COMPILE_OPTIONS "${_TZ_GENERATOR}")

ENDMACRO(TZ_SET_GLOBAL_COMPILE_OPTIONS)

MACRO(TZ_SET_GLOBAL_LINK_FLAGS)
# DO NOTHING HERE
ENDMACRO(TZ_SET_GLOBAL_LINK_FLAGS)

MACRO(TZ_GET_BUILD_PLATFORMNAME __TZ_NAME)
    IF(TZ_WINDOWS)
        IF(TZ_WINDOWS_BUILD_32)
            SET(__TZ_BUILD Win32)
        ENDIF()

        IF(TZ_WINDOWS_BUILD_64)
            SET(__TZ_BUILD x64)
        ENDIF()

        IF(TZ_MSVC_140)
            SET(__TZ_VC v140)
        ENDIF()

        IF(TZ_MSVC_141)
            SET(__TZ_VC v141)
        ENDIF()

        SET(${__TZ_NAME} ${__TZ_BUILD}_${__TZ_VC})
    ENDIF()
ENDMACRO(TZ_GET_BUILD_PLATFORMNAME __TZ_NAME)

MACRO(TZ_TODO)
    MESSAGE(WARNING "TZ_TODO!!!")
ENDMACRO(TZ_TODO)
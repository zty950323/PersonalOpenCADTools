#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

IF(TZ_WINDOWS_BUILD_32)
    SET(__PLATFORMNAME Win32)
ENDIF()

IF(TZ_WINDOWS_BUILD_64)
    SET(__PLATFORMNAME x64)
ENDIF()

SET(__TZ_PLUGINS ${TZ_QT_ROOT}/plugins)
SET(__TZ_PLG_IMG ${__TZ_PLUGINS}/imageformats)
SET(__TZ_PLG_PLT ${__TZ_PLUGINS}/platforms)
SET(__POST $<$<CONFIG:DEBUG>:d>)
SET(__DST ${TZ_GLOBAL_OUTPUT_BINDIR})

#SET(__DESIGNER_SRC $<$<CONFIG:DEBUG>:${TZ_THIRDPARTY_ROOT}/other/QtDesigner/Qt5.12.10/${__PLATFORMNAME}_V140>$<$CONFIG:RELEASE>:${TZ_QT_ROOT}/bin>/designer.exe)
#SET(__DESIGNER_DST ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/designer.exe)

ADD_CUSTOM_TARGET(
    DeployQt
    # COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__DESIGNER_SRC} ${__DESIGNER_DST}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/d3dcompiler_47.dll                      ${__DST}/d3dcompiler_47.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/libEGL${__POST}.dll                     ${__DST}/libEGL${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/libGLESv2${__POST}.dll                  ${__DST}/libGLESv2${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Core${__POST}.dll                    ${__DST}/Qt5Core${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Designer${__POST}.dll                ${__DST}/Qt5Designer${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5DesignerComponents${__POST}.dll      ${__DST}/Qt5DesignerComponents${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Gui${__POST}.dll                     ${__DST}/Qt5Gui${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Network${__POST}.dll                 ${__DST}/Qt5Network${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5OpenGL${__POST}.dll                  ${__DST}/Qt5OpenGL${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5PrintSupport${__POST}.dll            ${__DST}/Qt5PrintSupport${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Widgets${__POST}.dll                 ${__DST}/Qt5Widgets${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TZ_QT_ROOT}/bin/Qt5Xml${__POST}.dll                     ${__DST}/Qt5Xml${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qgif${__POST}.dll                         ${__DST}/plugins/imageformats/qgif${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qicns${__POST}.dll                        ${__DST}/plugins/imageformats/qicns${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qico${__POST}.dll                         ${__DST}/plugins/imageformats/qico${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qjpeg${__POST}.dll                        ${__DST}/plugins/imageformats/qjpeg${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qsvg${__POST}.dll                         ${__DST}/plugins/imageformats/qsvg${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qtga${__POST}.dll                         ${__DST}/plugins/imageformats/qtga${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qtiff${__POST}.dll                        ${__DST}/plugins/imageformats/qtiff${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qwbmp${__POST}.dll                        ${__DST}/plugins/imageformats/qwbmp${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_IMG}/qwebp${__POST}.dll                        ${__DST}/plugins/imageformats/qwebp${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_PLT}/qdirect2d${__POST}.dll                    ${__DST}/plugins/platforms/qdirect2d${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_PLT}/qminimal${__POST}.dll                     ${__DST}/plugins/platforms/qminimal${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_PLT}/qoffscreen${__POST}.dll                   ${__DST}/plugins/platforms/qoffscreen${__POST}.dll
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__TZ_PLG_PLT}/qwindows${__POST}.dll                     ${__DST}/plugins/platforms/qwindows${__POST}.dll
)

SET_TARGET_PROPERTIES(DeployQt PROPERTIES FOLDER ${TZ_DEPLOY_GROUP})

#[[
INSTALL(
    FILES ${__DESIGNER_SRC}
    DESTINATON ${TZ_GLOBAL_INSTALL_BINDIR}
)
#]]

INSTALL(
    FILES
        ${TZ_QT_ROOT}/bin/d3dcompiler_47.dll
        ${TZ_QT_ROOT}/bin/libEGL${__POST}.dll
        ${TZ_QT_ROOT}/bin/libGLESv2${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Core${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Designer${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5DesignerComponents${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Gui${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Network${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5OpenGL${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5PrintSupport${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Widgets${__POST}.dll
        ${TZ_QT_ROOT}/bin/Qt5Xml${__POST}.dll
    DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
)

INSTALL(
    FILES
        ${__TZ_PLG_IMG}/qgif${__POST}.dll
        ${__TZ_PLG_IMG}/qicns${__POST}.dll
        ${__TZ_PLG_IMG}/qico${__POST}.dll
        ${__TZ_PLG_IMG}/qjpeg${__POST}.dll
        ${__TZ_PLG_IMG}/qsvg${__POST}.dll
        ${__TZ_PLG_IMG}/qtga${__POST}.dll
        ${__TZ_PLG_IMG}/qtiff${__POST}.dll
        ${__TZ_PLG_IMG}/qwbmp${__POST}.dll
        ${__TZ_PLG_IMG}/qwebp${__POST}.dll
    DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
)

INSTALL(
    FILES
        ${__TZ_PLG_PLT}/qdirect2d${__POST}.dll
        ${__TZ_PLG_PLT}/qminimal${__POST}.dll
        ${__TZ_PLG_PLT}/qoffscreen${__POST}.dll
        ${__TZ_PLG_PLT}/qwindows${__POST}.dll
    DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
)
#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(__SRC ${TZ_SOURCE_DIR}/support/TzMsBuild/QtMsBuild/qt.conf)
SET(__DST ${TZ_GLOBAL_OUTPUT_BINDIR}/qt.conf)

ADD_CUSTOM_TARGET(
    DeployQtConfig
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${__SRC} ${__DST}
)

SET_TARGET_PROPERTIES(DeployQtConfig PROPERTIES FOLDER ${TZ_DEPLOY_GROUP})

INSTALL(
    FILES ${__SRC}
    DESTINATION ${TZ_GLOBAL_INSTALL_BINDIR}
)
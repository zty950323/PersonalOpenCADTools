#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(TZ_DEPLOY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("TZ_DEPLOY_SOURCE_DIR=${TZ_DEPLOY_SOURCE_DIR}")

SET(TZ_DEPLOY_GROUP "deploy")

ADD_SUBDIRECTORY(DeployEnv)
ADD_SUBDIRECTORY(DeployThirdparty)
ADD_CUSTOM_TARGET(DeployAll ALL DEPENDS DeployEnv DeployThirdparty)

SET_TARGET_PROPERTIES(DeployAll PROPERTIES FOLDER ${TZ_DEPLOY_GROUP})
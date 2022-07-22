#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(__TZ_FOLDER ${TZ_DEPLOY_GROUP})
SET(TZ_DEPLOY_GROUP "${TZ_DEPLOY_GROUP}")

#ADD_SUBDIRECTORY(DeployMemoryLeak)
#ADD_SUBDIRECTORY(DeployResource)
#ADD_SUBDIRECTORY(DeployQtConfig)
#ADD_SUBDIRECTORY(DeployWkConfig)
#ADD_SUBDIRECTORY(DeployZW3DRuntime)

ADD_CUSTOM_TARGET(DeployEnv
    DEPENDS
    #DeployMemoryLeak
    #DeployResource
    #DeployQtConfig
    #DeployWkConfig
    #DeployZW3DRuntime
    )

SET_TARGET_PROPERTIES(DeployEnv PROPERTIES FOLDER ${__TZ_FOLDER})
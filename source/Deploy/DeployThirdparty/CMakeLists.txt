#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

SET(__TZ_FOLDER ${TZ_DEPLOY_GROUP})
SET(TZ_DEPLOY_GROUP "${TZ_DEPLOY_GROUP}/Thirdparty")

#ADD_SUBDIRECTORY(DeployOSG)
ADD_SUBDIRECTORY(DeployQt)
#ADD_SUBDIRECTORY(DeployZW3D)
#ADD_SUBDIRECTORY(DeployZW3rd)
#ADD_SUBDIRECTORY(DeployZwIfc)

IF(EXISTS "${TZ_WKAPI_ROOT}")
    ADD_SUBDIRECTORY(DeployWKAPI)
ENDIF()

IF(EXISTS "${TZ_WKAPI_ROOT}")
    ADD_CUSTOM_TARGET(DeployThirdparty
        DEPENDS
        #DeployOSG
        IF(TZ_QT_ROOT)
            # DeployQt
        ENDIF()
        #DeployZW3D
        #DeployZW3rd
        #DeployZwIfc
        #DeployWKAPI
    )
ELSE()
    ADD_CUSTOM_TARGET(DeployThirdparty
        DEPENDS
        #DeployOSG
        IF(TZ_QT_ROOT)
            # DeployQt
        ENDIF()
        #DeployZW3D
        #DeployZW3rd
        #DeployZwIfc
        #DeployWKAPI
    )
ENDIF()

SET_TARGET_PROPERTIES(DeployThirdparty PROPERTIES FOLDER ${__TZ_FOLDER})
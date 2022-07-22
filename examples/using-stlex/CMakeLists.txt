#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(TZ_USING_STL_NAME UsingSTLProject)

set(TZ_USING_STL_INCLUDE
    include
)

SET(TZ_ROOT_DIR ${CMAKE_SOURCE_DIR})
SET(TZ_SDK_INCLUDE_DIR ${TZ_ROOT_DIR}/include)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(${TZ_USING_STL_NAME})

add_definitions(
    -wd4819
)

add_compile_options(
    /std:c++latest
)

add_subdirectory(UsingString)
add_subdirectory(UsingVector)
add_subdirectory(UsingDeque)
add_subdirectory(UsingStack)
add_subdirectory(UsingQueue)
add_subdirectory(UsingLists)
add_subdirectory(UsingSet)
add_subdirectory(UsingPtr)
add_subdirectory(CppLearningBase)
add_subdirectory(TheModernCppChallenge)
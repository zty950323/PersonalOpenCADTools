cmake_minimum_required(VERSION 3.1)

set(TZ_CMAKE_TOOLCHAIN_FILE "${TZ_CMAKE_TOOLCHAIN_FILE}" CACHE PATH "Please select the matched vcpkg toolchain path root dir!")

if(EXISTS "${TZ_CMAKE_TOOLCHAIN_FILE}")
    set(CMAKE_TOOLCHAIN_FILE ${TZ_CMAKE_TOOLCHAIN_FILE})
    message("Set Up the vcpkg's package")
else()
    message(FATAL_ERROR "Please specify the TZ_CMAKE_TOOLCHAIN_FILE")
endif()

set(TZ_MAIN_NAME FollyUse)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC
	inc/FollyArenaTest.h
)

set(TZ_MAIN_SRC
	src/FollyArenaTest.cpp
	src/main.cpp
)

project(${TZ_MAIN_NAME})

find_package(folly CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_executable(${TZ_MAIN_NAME}
	${TZ_MAIN_INCLUDE}
	${TZ_MAIN_INC}
	${TZ_MAIN_SRC}
)

target_link_libraries(${TZ_MAIN_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util)
target_link_libraries(${TZ_MAIN_NAME} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

target_include_directories(${TZ_MAIN_NAME} PRIVATE 
	inc
)
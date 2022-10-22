#[================================================================[.rst:
    Copyright (c)2022, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME AABBCachedBBoxEx)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC

)

set(TZ_MAIN_SRC
    AABB_cached_bbox_example.cpp
)

find_package(CGAL REQUIRED)

# create a target per cppfile
file(
  GLOB cppfiles
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
foreach(cppfile ${cppfiles})
  create_single_source_cgal_program("${cppfile}")
endforeach()
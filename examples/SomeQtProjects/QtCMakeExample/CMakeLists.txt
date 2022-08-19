# Qt对cmake版本的最小要求（但测试发现低一点的版本似乎也没问题）
cmake_minimum_required(VERSION 3.16.0)

# 项目命名
# VERSION 1.0.0 LANGUAGES CXX: 是可选的
project(QtCMakeExample VERSION 1.0.0 LANGUAGES CXX)

# 如果采用非Qt Creator开发，需要通过告知Qt的安装路径，建议把Qt的安装路径设置到环境变量
# 例如：QT_DIR=D:\Qt\6.1.2\msvc2019_64
set(CMAKE_PREFIX_PATH $ENV{QT_DIR})

# 有些项目会动态生成头文件，项目中需要引入它，因此需要将output目录也include进来
# 等同于INCLUDE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt6 对C++版本推荐至少17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt特有的编译器需要打开，默认是关闭的
set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTORCC ON) # Resource Compiler
set(CMAKE_AUTOUIC ON) # User Interface Compiler

# 寻找Qt的库
# Qt6 COMPONENTS Widgets：寻找Qt库中的Widget模块
# REQUIRED： 意味着找不到报错并不会继续下去
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# 集成源码以及资源并打包
aux_source_directory(src SRC_LIST)
set(PROJECT_SOURCES ${SRC_LIST})
set(INNER_PROJECT_NAME QtCMakeExample)

# 这里如果不加WIN32，会导致编译的可执行文件运行时候会同时弹出一个命令行终端
# 这是Windows的特性，对于其它平台得去掉WIN32
add_executable(${INNER_PROJECT_NAME} WIN32 ${PROJECT_SOURCES})

# cmake本身有四种编译模式：`Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`
# 此操作将`Debug`和`RelWithDebInfo`归类于QML的debug，即这两种模式下QML运行会保留debug信息
target_compile_definitions(${INNER_PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

# 链接库到当前项目
# PRIVATE：项目私有内部链接，只有在开发Library对外公开时候才会使用PUBLIC
target_link_libraries(${INNER_PROJECT_NAME} PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets)
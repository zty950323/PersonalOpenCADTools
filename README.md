# TZOpenTools

# 介绍

&ensp;&ensp;&ensp;&ensp; 这是一个，我个人用来记录一些平时编写的demo和记录一些代码技巧的项目，用作平时积累，主要会有一些：

1.  用于记录一些自己编写的文章的文件，主要是markdown的文件。
2.  自己从零开始编写的一些小工具和小框架。
3.  一部分自己试验性的Qt的案例 ——  主要针对自己Gui开发方向的一些小实验。
4.  平时看到的一些代码的技巧。
5.  整体从零开始写的一个工业软件原型框架，增加自己对于某些方向的理解和对全局的把握。
6.  记录一些平时用到的网站和链接，作为一个资料的整理和收集。

&ensp;&ensp;&ensp;&ensp; 这个项目来讲，主要是用来培养自己平时的一些习惯，做好良好的工作，学习过程中的记录，如有幸被人看到，那就与君共勉，普通人一个，做一个长久而坚定的人。

## 怎么利用CMake编译这个项目

&ensp;&ensp;&ensp;&ensp; 我希望你的文件结构跟下面的类似：

### 在 Windows 平台上

TzOpenTools
TzOpenTools/CMakeModules
TzOpenTools/ThirdParty
TzOpenToolsBuilds

- win32
- win64

&ensp;&ensp;&ensp;&ensp; 如果你想编译32位的程序：

```shell
cd TzOpenToolsBuilds_win32
cmake ../../TzOpenTools -DTZ_QT_ROOT=D:\Library\Qt\5.12.10\msvc2017(your qt dir) -DTZ_THIRDPARTY_ROOT=../../TzOpenTools/ThirdParty -DTZ_CMAKEMODULES_ROOT=../../TzOpenTools/CMakeModules
```

&ensp;&ensp;&ensp;&ensp; 如果你想编译64位的程序：

```shell
cd TzOpenToolsBuilds_win64
cmake ../../TzOpenTools -DTZ_QT_ROOT=D:\Library\Qt\5.12.10\msvc2017_64(your qt dir) -DTZ_THIRDPARTY_ROOT=../../TzOpenTools/ThirdParty -DTZ_CMAKEMODULES_ROOT=../../TzOpenTools/CMakeModules
```

### 在 Mac 平台上:

TODO: 需要有空补一下如何在mac上编译。

### 在 Linux 平台上：

TODO: 需要有空补一下如何在linux上编译。
# TZOpenTools

## Introduction

&ensp;&ensp;&ensp;&ensp; This is a project that I personally use to record some demos I usually write and record some code skills. It is used as a daily accumulation. There are mainly some:
   1. Files used to record some self-written articles, mainly markdown files.
   2. Some small tools and small frameworks I wrote from scratch.
   3. Part of my own experimental Qt cases-mainly for some small experiments in the direction of my own Gui development.
   4. Some code skills that you usually see.
   5. An industrial software prototype framework written from scratch as a whole to increase my understanding of certain directions and grasp of the overall situation.
   6. Record some of the websites and links that are used in daily life, as a data sorting and collection.

&ensp;&ensp;&ensp;&ensp; In terms of this project, it is mainly used to cultivate some of your usual habits, do a good job, and record in the learning process. If you are lucky enough to be seen by others, then share with you, an ordinary person, and be a long and firm one. People.

## How to build this project by cmake

&ensp;&ensp;&ensp;&ensp; I think you should assume that your directory just like this:

### On Windows:

TzOpenTools
TzOpenTools/CMakeModules
TzOpenTools/ThirdParty
TzOpenToolsBuilds

- win32
- win64

&ensp;&ensp;&ensp;&ensp; if you want to build 32 on windows:

```shell
cd TzOpenToolsBuilds_win32
cmake ../../TzOpenTools -DTZ_QT_ROOT=D:\Library\Qt\5.12.10\msvc2017(your qt dir) -DTZ_THIRDPARTY_ROOT=../../TzOpenTools/ThirdParty -DTZ_CMAKEMODULES_ROOT=../../TzOpenTools/CMakeModules
```

&ensp;&ensp;&ensp;&ensp; if you want to build 64 on windows:

```shell
cd TzOpenToolsBuilds_win64
cmake ../../TzOpenTools -DTZ_QT_ROOT=D:\Library\Qt\5.12.10\msvc2017_64(your qt dir) -DTZ_THIRDPARTY_ROOT=../../TzOpenTools/ThirdParty -DTZ_CMAKEMODULES_ROOT=../../TzOpenTools/CMakeModules
```

### On Mac:

TODO: need to write how use this on mac.

### On Linux:

TODO: need to write how use this on linux.
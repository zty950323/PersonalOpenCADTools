///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TZ_SOFTS_WINDOWS_VER_H_H_
#define __TZ_SOFTS_WINDOWS_VER_H_H_

#include "zsofts_platform.h"

// this will report an error if the building platform is wrong.
#if !defined(TZ_WINDOWS)
#error \
    "When building for platform that other than windows should not include zsofts_windows_ver.h!\n"
#endif

#include <sdkddkver.h>

// TODO: Put the target windows version and windows SDK version here.

//#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#endif
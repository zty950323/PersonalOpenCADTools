/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef __TZ_SOFTS_COMPILER_SPECIFIC_H_INCLUDE__
#define __TZ_SOFTS_COMPILER_SPECIFIC_H_INCLUDE__

#include "zsofts_platform.h"

// Building configurations macros
#define TZ_BUILD_DEBUG 1
#define TZ_BUILD_RELEASE 2
#define TZ_CHARACTERS_MBCS 1
#define TZ_CHARACTERS_UNICODE 2
#define TZ_DEBUG_PHASE 0    // Developing
#define TZ_UNITT_PHASE 1    // Unit testing
#define TZ_ALPHA_PHASE 2    // Alpha released
#define TZ_BETA_PHASE 3     // Beta released
#define TZ_RELEASE_PHASE 4  // Official released

// Put predefine macros in your project building
// configurations to determine which phase your project is in.
#if defined(_DEBUG)
#define TZ_PHASE TZ_DEBUG_PHASE
#elif defined(TZ_UNIT_TESTS)
#define TZ_PHASE TZ_UNITT_PHASE
#elif defined(TZ_ALPHA_RELEASE)
#define TZ_PHASE TZ_ALPHA_PHASE
#elif defined(TZ_BETA_REALSE)
#define TZ_PHASE TZ_BETA_PHASE
#else
#define TZ_PHASE TZ_RELEASE_PHASE
#endif

// Unicode & ANSI configurations
#if TZ_COMPILER != TZ_COMPILER_MSVC
#ifndef _UNICODE
#define _UNICODE
#endif
#endif

#ifdef _UNICODE

#ifndef TZ_DEF_UNICODE
#define TZ_DEF_UNICODE
#endif

#endif

#if (TZ_COMPILER == TZ_COMPILER_MSVC) || (TZ_COMPILER == TZ_COMPILER_GUNC)
#if defined(_DEBUG) || defined(DEBUG)
#define TZ_BUILD_MODE TZ_BUILD_DEBUG
#else
#define TZ_BUILD_MODE TZ_BUILD_RELEASE
#endif
#if defined(_UNICODE) || defined(UNICODE)
#define TZ_BUILD_CHARACTERS TZ_CHARACTERS_UNICODE
#else
#define TZ_BUILD_CHARACTERS TZ_CHARACTERS_MBCS
#endif
#elif TZ_COMPILER == TZ_COMPILER_WINSCW
#error "TZ_BUILD_CHARACTERS solution is missing for this platform!\n"
#elif TZ_COMPILER == TZ_COMPILER_BORL
#error "TZ_BUILD_CHARACTERS solution is missing for this platform!\n"
#elif TZ_COMPILER == TZ_COMPILER_GCCE
#error "TZ_BUILD_CHARACTERS solution is missing for this platform!\n"
#else
#error "Unsupported compiler!!! \n"
#endif

// Compiler stuff
#if TZ_COMPILER == TZ_COMPILER_MSVC
#define TZ_ABSTRACT __declspec(novtable)
#define TZ_DEPRECATED __declspec(deprecated)
#if defined TZ_MAKE_STATIC_LIB
#define TZ_EXPORT
#define TZ_C_EXPORT extern "C"
#define TZ_IMPORT
#define TZ_C_IMPORT extern "C"
#else
#if defined __cplusplus
#define TZ_C_EXPORT extern "C" __declspec(dllexport)
#define TZ_C_IMPORT extern "C"
#else
#define TZ_C_EXPORT __declspec(dllexport)
#define TZ_C_IMPORT
#endif
#define TZ_EXPORT __declspec(dllexport)
#define TZ_IMPORT __declspec(dllimport)
#endif
#define TZ_REGISTER register
#define TZ_THISCALL __thiscall
#define TZ_STDCALL __stdcall
#define TZ_CDECL __cdecl
#define TZ_FASTCALL __fastcall
#define TZ_PASCAL __pascal
#define TZ_CALLBACK __stdcall
#else
#define TZ_ABSTRACT
#define TZ_DEPRECATED
#define TZ_EXPORT __attribute__((visibility("default")))
#define TZ_IMPORT __attribute__((visibility("default")))
#define TZ_REGISTER
#define TZ_THISCALL __attribute__((thiscall))
#define TZ_STDCALL __attribute__((stdcall))
#define TZ_CDECL __attribute__((cdecl))
#define TZ_FASTCALL __attribute__((fastcall))
#define TZ_PASCAL __attribute__((pascal))
#define TZ_CALLBACK _attribute__((stdcall))
#endif

#if TZ_COMPILER == TZ_COMPILER_MSVC && TZ_COMPILER_VER >= TZ_COMPILER_MSVC_6_0
#define TZ_FORCEINLINE __forceinline
#else
#define TZ_FORCEINLINE inline
#endif

#if TZ_BUILD_MODE == TZ_BUILD_DEBUG
// Any debug function to include?
#else
#include <stdlib.h>
#ifdef TZ_WINDOWS
#include <malloc.h>
#endif
#endif

#ifdef _MSC_EXTENSIONS
#define TZ_OVERRIDE override
#define TZ_SEALED sealed
#else
#define TZ_OVERRIDE
#define TZ_SEALED
#endif

#define MIGRATION_ERRORS
#if defined(_MSC_VER) && defined(MIGRATION_ERRORS)
#define TZ_SEALED_VIRTUAL virtual
#ifndef TZ_SEALED
#define TZ_SEALED sealed
#endif
#else
#define TZ_SEALED_VIRTUAL
#endif

#ifdef __cplusplus
#define COMPILE_WITH_CTYPE_BEGIN extern "C" {
#define COMPILE_WITH_CTYPE_END }
#else
#define COMPILE_WITH_CTYPE_BEGIN
#define COMPILE_WITH_CTYPE_END
#endif

#define TZ_NAMESPACE_BEGIN(name) namespace name {
#define TZ_NAMESPACE_END(name) }
#define TZ_USINGNAMESPACE(name) using namespace name

#define _USE_TZPRINTER

// Treat these dangerous warnings as error.
#if (TZ_COMPILER == TZ_COMPILER_MSVC)

// Treat warning that implicitly convert an integer to a byte as an error.
#pragma warning(error : 4244)
// Treat warning that implicitly convert an 64
// bits integer to a 32 bits integer
// or convert an 32 bits integer to a 16 bits integer as an error.
#pragma warning(error : 4267)
// You should always check your source code where has cause these two errors.
// and try to use another type for your variable or
// change the implicit conversion
// to an explicit one.

#pragma warning(error : 4553)
#pragma warning(error : 4002)
#pragma warning(error : 4090)
#pragma warning(error : 4554)
#pragma warning(error : 4700)
#pragma warning(error : 4150)
#pragma warning(error : 4805)

#endif  // # if (TZ_COMPILER == TZ_COMPILER_MSVC)

#endif

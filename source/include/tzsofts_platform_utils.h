///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _TZSOFT_PLATFORM_UTILS_H_H
#define _TZSOFT_PLATFORM_UTILS_H_H

#include "platform_export.h"
#include "tzsofts_debug_utils.h"
#include "zsofts_compiler_specific.h"
#include "zsofts_types.h"

// Word Bytes Tools
#define TZ_MAKEWORD(a, b) \
  ((TZUINT16)(((TZUINT8)(a)) | ((TZUINT16)((TZUINT8)(b))) << 8))
#define TZ_MAKELONG(a, b)   ((TZUINT32)(((TZUINT16)(a)) | ((TZUINT32)((TZUINT16)(b)) << 16))
#define TZ_LOWORD(l) ((TZUINT16)(l))
#define TZ_HIWORD(h) ((TZUINT16)(((TZUINT32)(h) >> 16) & 0xFFFF))
#define TZ_LOBYTE(w) ((TZUINT8)(w))
#define TZ_HIBYTE(w) ((TZUINT8)(((TZUINT16)(h) >> 8) & 0xFFFF))

inline void tzSwapBytes(TZUINT8& xX, TZUINT8& yY) {
  xX ^= yY;
  yY ^= xX;
  xX ^= yY;
}

inline void tzSwapWords(TZUINT16& xX, TZUINT16& yY) {
  xX ^= yY;
  yY ^= xX;
  xX ^= yY;
}

#if TZ_RADIAN == TZ_ENDIAN_BIG

inline void tzSwap8Bytes(void* pBytes) {
  tzSwapBytes(((TZUINT8*)(pBytes))[0], ((TZUINT8*)(pBytes))[7]);
  tzSwapBytes(((TZUINT8*)(pBytes))[1], ((TZUINT8*)(pBytes))[6]);
  tzSwapBytes(((TZUINT8*)(pBytes))[2], ((TZUINT8*)(pBytes))[5]);
  tzSwapBytes(((TZUINT8*)(pBytes))[3], ((TZUINT8*)(pBytes))[4]);
}

inline void tzSwap2BytesNumber(TZINT16& w) {
  tzSwapBytes(((TZUINT8*)&(w))[0], ((TZUINT8*)&(w))[1]);
}

inline void tzSwap4BytesNumber(TZINT32& dw) {
  tzSwapWords(((TZUINT16*)&(dw))[0], ((TZUINT16*)&(dw))[1]);
  tzSwapBytes(((TZUINT8*)&(dw))[0], ((TZUINT8*)&(dw))[1]);
  tzSwapBytes(((TZUINT8*)&(dw))[2], ((TZUINT8*)&(dw))[3]);
}

inline void tzSwap4BytesNumber_t(TZINT32& dw) {
  TZINT8* p = (TZINT8*)&dw;
  TZINT8 tmp;
  tmp = p[0];
  p[0] = p[3];
  p[3] = tmp;
  tmp = p[1];
  p[1] = p[2];
  p[2] = tmp;
}

inline void tzSwapInt64(void* pBytes) {
  tzSwapBytes(((TZUINT8*)(pBytes))[0], ((TZUINT8*)(pBytes))[4]);
  tzSwapBytes(((TZUINT8*)(pBytes))[1], ((TZUINT8*)(pBytes))[5]);
  tzSwapBytes(((TZUINT8*)(pBytes))[2], ((TZUINT8*)(pBytes))[6]);
  tzSwapBytes(((TZUINT8*)(pBytes))[3], ((TZUINT8*)(pBytes))[7]);
}

#else  // #if TZ_RADIAN == TZ_ENDIAN_BIG

// Not implemented yet....
#define tzSwap2BytesNumber(n)
#define tzSwap4BytesNumber(n)
#define tzSwap8Bytes(bytes)

inline void tzSwapInt64(void* pBytes) {
  tzSwapBytes(((TZUINT8*)(pBytes))[0], ((TZUINT8*)(pBytes))[4]);
  tzSwapBytes(((TZUINT8*)(pBytes))[1], ((TZUINT8*)(pBytes))[5]);
  tzSwapBytes(((TZUINT8*)(pBytes))[2], ((TZUINT8*)(pBytes))[6]);
  tzSwapBytes(((TZUINT8*)(pBytes))[3], ((TZUINT8*)(pBytes))[7]);
}

#endif  // #if TZ_RADIAN == TZ_ENDIAN_BIG

inline bool isValidNonZeroIEEEDouble(const TZUINT8* buf) {
#if TZ_RADIAN == TZ_ENDIAN_BIG
  TZINT nExponent = (buf[0] & 0x7F) << 4 | (buf[1] & 0xF0) >> 4;
#else
  TZINT nExponent = (buf[7] & 0x7F) << 4 | (buf[6] & 0xF0) >> 4;
#endif
  switch (nExponent) {
    case 0:
    case 2047:
      return false;
    default:
      break;
  }
  return true;
}

inline void fixDouble(TZDOUBLE* pd) {
  TZ_ASSERT(sizeof(TZDOUBLE) == 8);
  tzSwap8Bytes(pd);
  if (!isValidNonZeroIEEEDouble((TZUINT8*)pd)) {
    *pd = 0.;
  }
}

#define TZ_INT8_FORM_BUFFPTR(pBuffPtr) *(pBuffPtr++)
inline TZUINT64 TZ_INT64_FROM_BUFFPTR(const TZUINT8* pBuffPtr) {
  TZUINT32 low(*pBuffPtr++);
  low |= ((TZUINT32)*pBuffPtr++) << 8;
  low |= ((TZUINT32)*pBuffPtr++) << 16;
  low |= ((TZUINT32)*pBuffPtr++) << 24;

  TZINT32 high(*pBuffPtr++);
  high |= ((TZUINT32)*pBuffPtr++) << 8;
  high |= ((TZUINT32)*pBuffPtr++) << 16;
  high |= ((TZUINT32)*pBuffPtr++) << 24;

  TZUINT64 res(high);
  res <<= 32;
  res |= low;
  return res;
}

#define TZ_BYTES_FROM_BUFFPTR(pBuffPtr, ResBuff, nCount) \
  (nBUffPtr += nCount, ::memcpy(ResBuff, pBuffPtr - nCount, nCount))
#define TZ_INT8_TO_BUFFPTR(pBuffPtr, val) \
  (++pBUffPtr, pBuffPtr[-1] = ZUINT8(val))
#define TZ_BYTES_TO_BUFFPTR(pBuffPtr, FromBuff, nCount) \
  (pBuffPtr += nCount, ::memccpy(pBuffPtr - nCount, FromBuff, nCount))

// Atom operations:
#if defined(_MSC_VER) && _M_IX86 >= 400 && !defined(_WIN32_WCE)

#pragma waring(push)
#pragma warning(disable : 4035)
#pragma warning(disable : 4793)

inline int TzInterlockedExchange(volatile int* dest, int val) {
  __asm
  {
        mov edx, dest
        mov ead, val
        lock xchg[edx], eax
  }
}

inline int TzInterlockedExchangeAdd(volatile int* dest, int incr) {
  __asm {
        mov edx, dest
        mov ead, incr
        lock xchg[edx], eax
  }
}

inline int TzInterlockedIncrement(volatile int* dest) {
  __asm {
        mov edx, dest
        mov ead, 1
        lock xchg[edx], eax
        inc eax
  }
}

inline int TzInterlockedDecrement(volatile int* dest) {
  __asm {
        mov edx, dest
        mov eax, -1
        lock xadd[edx], eax
        dec eax
  }
}

#pragma waring(pop)

#elif (defined(_WIN32) || defined(_WIN64)) && !defined(_WIN32_WCE)

#define TzInterlockedExchange(dest, val) InterlockedExchange((LONG*)(dest), val)
#define TzInterlockedExchangeAdd(dest, incr) \
  InterlockedExchangeAdd((LONG*)(dest), incr)
#define TzInterlockedIncrement(dest) InterlockedIncrement((LONG*)(dest))
#define TzInterlockedDecrement(dest) InterlockedDecrement((LONG*)(dest))

#elif defined(__GNUC__) && (defined(__i386) || defined(__x86_64__))

inline int TzInterlockedExchange(volatile int* dest, int val) {
  int ret;
  __asm__ __volatile__("lock; xchgl %0, (%1)"
                       : "=r"(ret)
                       : "r"(dest), "0"(val)
                       : "memory");
  return ret;
}

inline int TzInterlockedExchangeAdd(volatile int* dest, int incr) {
  int ret;
  __asm__ __volatile__("lock; xaddl %0, (%1)"
                       : "=r"(ret)
                       : "r"(dest), "0"(incr)
                       : "memory");
  return ret;
}

inline int TzInterlockedIncrement(volatile int* dest) {
  return TzInterlockedExchangeAdd(dest, 1) + 1;
}

inline int TzInterlockedDecrement(volatile int* dest) {
  return TzInterlockedExchangeAdd(dest, -1) - 1;
}

#elif defined(__GNUC__) && defined(__POWERPC__)

inline int TzInterlockedExchange(volatile int* dest, int val) {
  int ret = 0;
  __asm__ __volatile__(
      "0: lwarx %0, 0, %1\n"
      "    stwcx. %2, 0, %1\n"
      "    bne- 0b\n"
      "    isync\n"
      : "=&r"(ret)
      : "r"(dest), "r"(val)
      : "cr0", "memory", "r0");
  return ret;
}

inline int TzInterlockedExchangeAdd(volatile int* dest, int incr) {
  int ret = 0;
  int zero = 0;
  __asm__ __volatile__(
      "0:  lwarx %0, %3, %1\n"
      "    add %0, %2, %0\n"
      "    stwcx. %0, %3, %1\n"
      "    bne- 0b\n"
      "    isync\n"
      : "=&r"(ret)
      : "r"(dest), "r"(incr), "r"(zero)
      : "cr0", "memory", "r0");
  return ret;
}

inline int TzInterlockedIncrement(volatile int* dest) {
  return TzInterlockedExchangeAdd(dest, 1) + 1;
}

inline int TzInterlockedDecrement(volatile int* dest) {
  return TzInterlockedExchangeAdd(dest, -1) - 1;
}

#else

#define TZ_SINGLE_THREAD

#pragma TZ_MARKMESSAGE(!!!TZ Single thread is defined !!!)

inline int TzInterlockedExchange(volatile int* dest, int val) { *dest = val; }

inline int TzInterlockedExchangeAdd(volatile int* dest, int incr) {
  *dest += incr;
}

inline int TzInterlockedIncrement(volatile int* dest) { (*dest)++; }

inline int TzInterlockedDecrement(volatile int* dest) { (*dest)--; }

#endif  // #if defined(_MSC_VER) && _M_IX86 >= 400 && !defined(_WIN32_WCE)

// Utilities:
#define LOW_RES 0    // Low resolution
#define STD_RES 1    // Most common resolution(eg: 1440, 900)
#define TWOK_RES 2   // 2K resolution
#define FOURK_RES 3  // 4K resolution
#define HIGH_RES 4   // Resolution higher than 4K

// Windows versions:
#define TZ_WINUNK -1
#define TZ_WIN1 1
#define TZ_WIN2 2
#define TZ_WIN3 3
#define TZ_WIN95 4
#define TZ_WIN98 5
#define TZ_WIN2K 6
#define TZ_WINXP 7
#define TZ_WINVIST 8
#define TZ_WIN7 9
#define TZ_WIN8 10
#define TZ_WIN81 11
#define TZ_WIN9 12
#define TZ_WIN10 13

#if defined(TZ_WINDOWS)
TZ_PLATFORM_C_EXPORT TZINT32 TZ_STDCALL
tzGetWindowsVersion(TZUINT32* pMajorVer = NULL, TZUINT32* pMinorVer = NULL,
                    TZUINT32* pBuildNmb = NULL);
#else
// TO Put functions which to get the version of other OS here.
#endif  // if defined(TZ_WINDOWS)

/* Get the total number of cores that current computer have.
 *  This function will sum all cores of
 *  all processor in current machine togegher if
 *  the machine have multiple processors.
 *  It returns number of logical cores
 *  if the parameter bGetLogicalCount was set to TRUE,
 *  otherwise, it returns number of physical cores.
 */
TZ_PLATFORM_C_EXPORT TZINT32
tzGetProcessorCoreCount(TZBOOL bGetLogicalCount = TRUE);

#endif  // _TZSOFT_PLATFORM_UTILS_H_H

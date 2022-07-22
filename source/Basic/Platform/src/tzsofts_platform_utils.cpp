///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "tzsofts_platform_utils.h"

#include <malloc.h>

#if defined(TZ_WINDOWS)

static TZINT32 _g_WindowsVersion = TZ_WINUNK;
static TZUINT32 _g_WinMajorVersion = -1;
static TZUINT32 _g_WinMinorVersion = -1;
static TZUINT32 _g_WinBuildNumber = -1;
static TZINT32 _g_LogicalProcCoreCount = -1;
static TZINT32 _g_PhysicalProcCoreCount = -1;

TZ_FORCEINLINE
TZBOOL _getWindowVer(TZUINT32& majorV, TZUINT32& minorV, TZUINT32& buildNmb) {
  TZBOOL bRet = FALSE;
  HMODULE hModNtDll = NULL;
  majorV = -1;
  minorV = -1;
  if (hModNtDll = ::LoadLibrary(TZ_T("ntdll.dll"))) {
    typedef void(WINAPI * pFRTLGETNTVERSIONNUMBERS)(DWORD*, DWORD*, DWORD*);
    pFRTLGETNTVERSIONNUMBERS pfGetOSVerCallBack =
        (pFRTLGETNTVERSIONNUMBERS)::GetProcAddress(hModNtDll,
                                                   "RtlGetNtVersionNumbers");
    if (NULL != pfGetOSVerCallBack) {
      DWORD dwMajor = 0;
      DWORD dwMinor = 0;
      DWORD dwBuildNmb = 0;
      pfGetOSVerCallBack(&dwMajor, &dwMinor, &dwBuildNmb);
      dwBuildNmb &= 0xFFFF;
      majorV = dwMajor;
      minorV = dwMinor;
      buildNmb = dwBuildNmb;
      bRet = TRUE;
    }

    ::FreeLibrary(hModNtDll);
    hModNtDll = 0;
  }
  return bRet;
}

TZ_PLATFORM_C_EXPORT TZINT32 TZ_STDCALL tzGetWindowsVersion(
    TZUINT32* pMajorVer, TZUINT32* pMinorVer, TZUINT32* pBuildNmb) {
  if (TZ_WINUNK != _g_WindowsVersion) {
    if (pMajorVer != NULL) {
      *pMajorVer = _g_WinMajorVersion;
    }
    if (pMinorVer != NULL) {
      *pMinorVer = _g_WinMinorVersion;
    }
    if (pBuildNmb != NULL) {
      *pBuildNmb = _g_WinBuildNumber;
    }
    return _g_WindowsVersion;
  }

  _g_WinMajorVersion = -1;
  _g_WinMinorVersion = -1;
  _g_WinBuildNumber = -1;

  if (!_getWindowVer(_g_WinMinorVersion, _g_WinMinorVersion,
                     _g_WinBuildNumber)) {
    OSVERSIONINFO osv;
    ZeroMemory(&osv, sizeof(OSVERSIONINFO));
    osv.dwOSVersionInfoSize = sizeof(osv);
    if (!GetVersionEx(&osv)) {
      if (pMajorVer != NULL) {
        *pMajorVer = _g_WinMajorVersion;
      }
      if (pMinorVer != NULL) {
        *pMinorVer = _g_WinMinorVersion;
      }
      if (pBuildNmb != NULL) {
        *pBuildNmb = _g_WinBuildNumber;
      }
      return _g_WindowsVersion = TZ_WINUNK;
    }

    _g_WinMajorVersion = osv.dwMajorVersion;
    _g_WinMinorVersion = osv.dwMinorVersion;
    _g_WinBuildNumber = osv.dwBuildNumber;
  }

  if (_g_WinMajorVersion < 1) {
    if (pMajorVer != NULL) {
      *pMajorVer = _g_WinMajorVersion;
    }
    if (pMinorVer != NULL) {
      *pMinorVer = _g_WinMinorVersion;
    }
    if (pBuildNmb != NULL) {
      *pBuildNmb = _g_WinBuildNumber;
    }
    return _g_WindowsVersion = TZ_WINUNK;
  }

  switch (_g_WinMajorVersion) {
    case 1: {
      _g_WindowsVersion = TZ_WIN1;
    } break;
    case 2: {
      _g_WindowsVersion = TZ_WIN2;
    } break;
    case 3: {
      _g_WindowsVersion = TZ_WIN3;
    } break;
    case 4: {
      if (0 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WIN95;
      } else {
        _g_WindowsVersion = TZ_WIN98;
      }
    } break;
    case 5: {
      if (0 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WINVIST;
      } else if (1 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WIN7;
      } else if (2 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WIN8;
      } else if (3 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WIN81;
      } else if (4 == _g_WinMinorVersion) {
        _g_WindowsVersion = TZ_WIN9;
      }
    } break;
    case 10: {
      _g_WindowsVersion = TZ_WIN10;
    } break;
    default: {
      _g_WindowsVersion = TZ_WINUNK;
    } break;
  }

  if (pMajorVer != NULL) {
    *pMajorVer = _g_WinMajorVersion;
  }
  if (pMinorVer != NULL) {
    *pMinorVer = _g_WinMinorVersion;
  }
  if (pBuildNmb != NULL) {
    *pBuildNmb = _g_WinBuildNumber;
  }
  return _g_WindowsVersion;
}

TZ_FORCEINLINE
DWORD _CountSetBits(ULONG_PTR bitMask) {
  DWORD LSHIFT = sizeof(ULONG_PTR) * 8 - 1;
  DWORD bitSetCount = 0;
  ULONG_PTR bitTest = (ULONG_PTR)1 << LSHIFT;
  for (DWORD i = 0; i <= LSHIFT; ++i) {
    bitSetCount += ((bitMask & bitTest) ? 1 : 0);
    bitTest /= 2;
  }
  return bitSetCount;
}

typedef BOOL(WINAPI* LPFN_GLPI)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD);

TZ_FORCEINLINE
TZBOOL _GetLogicalCoreCount(void) {
  LPFN_GLPI glpi = (LPFN_GLPI)::GetProcAddress(
      ::GetModuleHandle(TZ_T("kernel32")), "GetLogicalProcessorInformation");
  if (NULL == glpi) {
    return FALSE;
  }

  PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = NULL;
  PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
  DWORD returnLength = 0;

  TZBOOL bDone = FALSE;
  while (!bDone) {
    DWORD rc = glpi(buffer, &returnLength);

    if (FALSE == rc) {
      if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
        if (buffer) {
          ::free(buffer);
        }

        buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)::malloc(returnLength);

        if (NULL == buffer) {
          return FALSE;
        }
      } else {
        return FALSE;
      }
    } else {
      bDone = TRUE;
    }
  }

  ptr = buffer;
  DWORD byteOffset = 0;

  while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <=
         returnLength) {
    switch (ptr->Relationship) {
      case RelationNumaNode:
      case RelationCache:
      case RelationProcessorPackage:
        break;
      case RelationProcessorCore:
        ++_g_PhysicalProcCoreCount;

        // A hyper threaded core supplies more than one logical processor.
        _g_LogicalProcCoreCount += _CountSetBits(ptr->ProcessorMask);
        break;
      default:
        return FALSE;
    }
    byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
    ++ptr;
  }

  ::free(buffer);
  return TRUE;
}

TZ_PLATFORM_C_EXPORT TZINT32 tzGetProcessorCoreCount(TZBOOL bGetLogicalCount) {
  if (bGetLogicalCount) {
    if (_g_LogicalProcCoreCount > 0) {
      return _g_LogicalProcCoreCount;
    }
  } else {
    if (_g_PhysicalProcCoreCount > 0) {
      return _g_PhysicalProcCoreCount;
    }
  }

  TZINT32 nRetCount = 0;
  _g_LogicalProcCoreCount = _g_PhysicalProcCoreCount = 0;
  if (!_GetLogicalCoreCount()) {
    SYSTEM_INFO sysInfo;
    sysInfo.dwNumberOfProcessors;
    ::GetSystemInfo(&sysInfo);
    _g_LogicalProcCoreCount = _g_PhysicalProcCoreCount =
        (TZINT32)sysInfo.dwNumberOfProcessors;
    TZ_ASSERT(_g_PhysicalProcCoreCount > 0);
  }
  return bGetLogicalCount ? _g_LogicalProcCoreCount : _g_PhysicalProcCoreCount;
}

#else  // #if defined (TZ_WINDOWS)

#endif  // #if defined (TZ_WINDOWS)

// LastError:

TZUINT32 _u_tzsoft_last_error_code = 0;

TZ_PLATFORM_C_EXPORT void tzSetLastError(TZUINT32 uError) {
  _u_tzsoft_last_error_code = uError;
#if defined(TZ_WINDOWS)
  ::SetLastError(uError);
#endif
}

TZ_PLATFORM_C_EXPORT TZUINT32 tzGetLastError(void) {
#if defined(TZ_WINDOWS)
  return ::GetLastError();
#endif
  return _u_tzsoft_last_error_code;
}
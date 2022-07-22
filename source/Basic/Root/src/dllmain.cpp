﻿/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This is a dll export file for windows.
 */

#include "zsofts_windows_ver.h"

#ifdef TZ_WINDOWS

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  return TRUE;
}

#endif

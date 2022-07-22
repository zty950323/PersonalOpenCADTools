///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "tzsofts_lock.h"

#include "zsofts_platform.h"

#if defined(TZ_WINDOWS)
class TzImpLock_windows : public TzSoft::Lock {
 public:
  TzImpLock_windows() { InitializeCriticalSection(&m_CS); }
  virtual ~TzImpLock_windows() { DeleteCriticalSection(&m_CS); }

  virtual void lock() { EnterCriticalSection(&m_CS); }
  virtual void unlock() { LeaveCriticalSection(&m_CS); }

 private:
  CRITICAL_SECTION m_CS;
};

TZ_PLATFORM_C_EXPORT TzSoft::Lock* createTzLock() {
  return new TzImpLock_windows;
}

#else

// TODO: Put lock class here for the platform that other windows.

TZ_PLATFORM_C_EXPORT TzSoft::Lock* createTzLock() { return nullptr; }

#endif
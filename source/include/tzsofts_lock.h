/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_LOCK_H_H_
#define _TZSOFTS_LOCK_H_H_

#include "platform_export.h"
#include "tzsofts_debug_utils.h"
#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TZ_ABSTRACT Lock
{
public:
  virtual ~Lock() {}
  virtual void lock() = 0;
  virtual void unlock() = 0;
};

TZ_PLATFORM_C_EXPORT Lock *createTzLock();
#if defined(TZ_WINDOWS)
class TzImpLock_Windows : public TzSoft::Lock
{
public:
  TzImpLock_Windows() { InitializeCriticalSection(&m_CS); }
  virtual ~TzImpLock_Windows() { DeleteCriticalSection(&m_CS); }

  virtual void lock() { EnterCriticalSection(&m_CS); }
  virtual void unlock() { LeaveCriticalSection(&m_CS); }

private:
  CRITICAL_SECTION m_CS;
};

#endif

#pragma pack(push, 8)

class Locker
{
public:
  Locker(void);
  ~Locker(void);

  void lock() const;
  void unlock() const;

protected:
#if defined(TZ_WINDOWS)
  Lock *createLock();
#endif

private:
  Lock *m_pLock;
};

#pragma pack(pop)

#if defined(TZ_WINDOWS)

TZ_FORCEINLINE
Locker::Locker(void) { m_pLock = createLock(); }

#endif

TZ_FORCEINLINE
Locker::~Locker(void)
{
  if (m_pLock)
  {
    delete m_pLock;
    m_pLock = nullptr;
  }
}

TZ_FORCEINLINE
void Locker::lock(void) const { m_pLock->lock(); }

TZ_FORCEINLINE
void Locker::unlock(void) const { m_pLock->unlock(); }

TZ_FORCEINLINE
Lock *Locker::createLock() { return new TzImpLock_Windows; }

class AutoLocker
{
public:
  explicit AutoLocker(const Locker *pLocker);
  ~AutoLocker();

private:
  const Locker *m_pLocker;
};

TZ_FORCEINLINE
AutoLocker::AutoLocker(const Locker *pLocker)
{
  TZ_ASSERT(m_pLocker);
  m_pLocker->lock();
}

TZ_FORCEINLINE
AutoLocker::~AutoLocker()
{
  TZ_ASSERT(m_pLocker);
  m_pLocker->unlock();
}

TZ_NAMESPACE_END(TzSoft)

#define TZ_AUTOLOCK(pLocker) TzSoft::AutoLocker autoLocker(pLocker)

#endif

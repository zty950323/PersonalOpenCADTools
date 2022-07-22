/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_REF_COUNTER_H_H_
#define _TZSOFTS_REF_COUNTER_H_H_

#include "tzsofts_platform_utils.h"

#pragma pack(push, 8)

TZ_NAMESPACE_BEGIN(TzSoft)

using RefCounterType = int;

class RefCounter {
 public:
  inline RefCounter() : m_refs(0) {}
  inline explicit RefCounter(RefCounterType n) : m_refs(0) {}
  ~RefCounter() {}

  inline RefCounter& operator=(RefCounterType n) {
    m_refs = 0;
    TzInterlockedExchange(&m_refs, n);
  }

  inline operator RefCounterType() const {
    return TzInterlockedExchangeAdd(const_cast<RefCounterType*>(&m_refs), 0);
  }

  inline RefCounterType operator++() { return TzInterlockedIncrement(&m_refs); }

  inline bool operator==(const RefCounter& other) const {
    return m_refs == other.m_refs;
  }

  inline bool operator==(RefCounterType n) const { return (m_refs == n); }

  friend inline bool operator==(RefCounterType a, const RefCounter& b) {
    return a == b.m_refs;
  }

  inline bool operator!=(const RefCounter& other) const {
    return m_refs != other.m_refs;
  }

  inline bool operator!=(RefCounterType n) const { return (m_refs != n); }

  friend inline bool operator!=(RefCounterType a, const RefCounter& b) {
    return a != b.m_refs;
  }

  inline bool operator>(const RefCounter& other) const {
    return m_refs > other.m_refs;
  }

  inline bool operator>(RefCounterType n) const { return (m_refs > n); }

  friend inline bool operator>(RefCounterType a, const RefCounter& b) {
    return a > b.m_refs;
  }

  inline bool operator>=(const RefCounter& other) const {
    return m_refs >= other.m_refs;
  }

  inline bool operator>=(RefCounterType n) const { return (m_refs >= n); }

  friend inline bool operator>=(RefCounterType a, const RefCounter& b) {
    return a >= b.m_refs;
  }

  inline bool operator<(const RefCounter& other) const {
    return m_refs < other.m_refs;
  }

  inline bool operator<(RefCounterType n) const { return (m_refs < n); }

  friend inline bool operator<(RefCounterType a, const RefCounter& b) {
    return a < b.m_refs;
  }

  inline bool operator<=(const RefCounter& other) const {
    return m_refs <= other.m_refs;
  }

  inline bool operator<=(RefCounterType n) const { return (m_refs <= n); }

  friend inline bool operator<=(RefCounterType a, const RefCounter& b) {
    return a <= b.m_refs;
  }

 private:
  volatile RefCounterType m_refs;
};

TZ_NAMESPACE_END(TzSoft)

#pragma pack(pop)

#endif

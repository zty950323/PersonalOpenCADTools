/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _BASIC_TEST_COMMON_DEFINES_H_H_
#define _BASIC_TEST_COMMON_DEFINES_H_H_

#include <vector>

#include "zsofts_compiler_specific.h"

class QProgressBar;
class QTextEdit;

using std::vector;

TZ_NAMESPACE_BEGIN(TzSoftTest)

class TestCommonBase {
 public:
  TestCommonBase() = default;
  virtual ~TestCommonBase() = default;

  virtual void initProfile() {
    // Subclass will finished this.
  }
  virtual void initData() {
    // Subclass will finished this.
  }
  virtual void unloadProfile() {
    // Subclass will finished this.
  }
  virtual void unloadData() {
    // Subclass will finished this.
  }
};

class TestCommon : public TestCommonBase {
 public:
  virtual bool startAllTest() { return false; }
  virtual bool startOneTest(int testId) { return false; }
  virtual bool startSomeTest(int startId, int endId) { return false; }
  virtual bool startSomeTest(const vector<int>& ids) { return false; }
  virtual void showTestLog() {
    // Subclass will finished this.
  }

  inline void setEdit(QTextEdit* edit) {
    if (nullptr != edit) {
      m_edit = edit;
    }
  }

  void setProgressBar(QProgressBar* bar) {
    if (nullptr != bar) {
      m_prograssBar = bar;
    }
  }

 protected:
  virtual bool commonTests() { return false; }

  QTextEdit* m_edit = nullptr;
  QProgressBar* m_prograssBar = nullptr;
};

TZ_NAMESPACE_END(TzSoftTest)

#endif  // _BASIC_TEST_COMMON_DEFINES_H_H_

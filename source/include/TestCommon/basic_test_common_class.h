/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_TESTCOMMON_BASIC_TEST_COMMON_CLASS_H_
#define SOURCE_INCLUDE_TESTCOMMON_BASIC_TEST_COMMON_CLASS_H_

#include <string>

namespace Basic {
class TzTestCommonClass {
 public:
  TzTestCommonClass() {}
  ~TzTestCommonClass() {}

 protected:
  inline virtual bool initData() { return true; }
  inline virtual bool initCommonData() { return true; }
  inline virtual bool initRandomData() { return true; }
  inline virtual bool clearAllData() { return true; }
  inline virtual bool checkAllData() { return true; }
  inline virtual bool runAllTest() {
    bool ret = true;
    ret = initData();
    ret = checkAllData();
    ret = runCommonTest();
    ret = clearAllData();
    return ret;
  }
  inline virtual bool runCommonTest() {
    bool ret = true;
    return ret;
  }
  inline virtual std::string printAllData() const { return std::string(); }
};
}  // namespace Basic

#endif  // SOURCE_INCLUDE_TESTCOMMON_BASIC_TEST_COMMON_CLASS_H_

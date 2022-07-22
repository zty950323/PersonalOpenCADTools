///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef F94B3332_C137_41BC_9AE3_03D70A01C16C
#define F94B3332_C137_41BC_9AE3_03D70A01C16C

#include "DesignPatternTools/basic_open_singleTon.h"

namespace Basic {
class TzBoostAlgorithmTestCases
    : public TzSingleTon<TzBoostAlgorithmTestCases> {
  friend class TzSingleTon<TzBoostAlgorithmTestCases>;

 public:
  void runAllTestCases();

 private:
  void useFunc_all_of_case_01(void);
  void useTimerCase_01();
};
}  // namespace Basic

#endif /* F94B3332_C137_41BC_9AE3_03D70A01C16C */
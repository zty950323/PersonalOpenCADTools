///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef C74B295E_DCCC_42E7_B5C2_FB00F632755D
#define C74B295E_DCCC_42E7_B5C2_FB00F632755D

#include <string>

#include "basic_test_RBTree_cases.h"
#include "basic_test_basicArray_cases.h"
#include "basic_test_bitflag_cases.h"

namespace Basic {
class TzBasicToolsTestCases : public TzSingleTon<TzBasicToolsTestCases> {
  friend class TzSingleTon<TzBasicToolsTestCases>;

 public:
  bool runAllTestCases(int argc, char* argv[]);
};
}  // namespace Basic

#endif /* C74B295E_DCCC_42E7_B5C2_FB00F632755D */
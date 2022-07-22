///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef D40F1ECA_4D6B_490F_91FA_E15B85EC4B14
#define D40F1ECA_4D6B_490F_91FA_E15B85EC4B14

#include "DesignPatternTools/basic_open_singleTon.h"

namespace Basic {
class TzBasicAllTestCases : public TzSingleTon<TzBasicAllTestCases> {
  friend TzSingleTon<TzBasicAllTestCases>;

 public:
  int runAllTestCase(int argc, char* argv[]);
};
}  // namespace Basic

#endif /* D40F1ECA_4D6B_490F_91FA_E15B85EC4B14 */
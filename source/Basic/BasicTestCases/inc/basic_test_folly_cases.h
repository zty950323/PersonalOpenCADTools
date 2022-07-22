///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef CC5F9840_30E9_4FEB_9638_18EB0D5FE922
#define CC5F9840_30E9_4FEB_9638_18EB0D5FE922

#include "DesignPatternTools/basic_open_singleTon.h"
#include "TestCommon/basic_test_common_class.h"

namespace Basic {

class TzFollyArenaTestCase : public TzSingleTon<TzFollyArenaTestCase>,
                             TzTestCommonClass {
  friend class TzSingleTon<TzFollyArenaTestCase>;

 public:
  int runAllCases(int argc, char* argv[]);
};
}  // namespace Basic

#endif /* CC5F9840_30E9_4FEB_9638_18EB0D5FE922 */

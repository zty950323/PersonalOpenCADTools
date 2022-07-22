///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef A7B1D9E5_4467_4873_9B1C_92313BC45D59
#define A7B1D9E5_4467_4873_9B1C_92313BC45D59

#include "DesignPatternTools/basic_open_singleTon.h"

namespace Basic {
class TzBasicBoostAccExample : public TzSingleTon<TzBasicBoostAccExample> {
  friend TzSingleTon<TzBasicBoostAccExample>;

 public:
  int runAllTestCase(int argc, char* argv[]);

 private:
  void exampleForSetByForEach();
  void exampleForStatics();
  void exampleForWeightedStatistics();
};
}  // namespace Basic

#endif /* A7B1D9E5_4467_4873_9B1C_92313BC45D59 */

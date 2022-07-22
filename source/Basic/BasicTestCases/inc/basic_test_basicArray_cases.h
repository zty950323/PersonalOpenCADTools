///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef CB275143_51DB_40B9_9CC5_F07246DA8D71
#define CB275143_51DB_40B9_9CC5_F07246DA8D71

#include <string>

#include "DesignPatternTools/basic_open_singleTon.h"
#include "basic_open_array.h"

namespace Basic {
class TzBasicArrayTestCases : public TzSingleTon<TzBasicArrayTestCases> {
  friend TzSingleTon<TzBasicArrayTestCases>;

 public:
  TzBasicArrayTestCases();
  ~TzBasicArrayTestCases();

  bool runAllTestCases();
  bool runAllCommonTests();
  bool runSomeCertainTests();
  std::string printArrays(void) const;

 private:
  void initRandomData();
  void initCertainData();
  void clearData();

 private:
  Array<float> m_floatArray;
  Array<double> m_doubleArray;
  Array<short> m_shortArray;
  Array<int> m_intArray;
  Array<unsigned int> m_uintArray;
  Array<long> m_longArray;
};
}  // namespace Basic

#endif /* CB275143_51DB_40B9_9CC5_F07246DA8D71 */

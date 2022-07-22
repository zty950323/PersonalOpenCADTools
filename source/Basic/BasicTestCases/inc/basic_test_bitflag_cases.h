///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef CA8A55C0_1374_4E1F_A3AA_58278644ED09
#define CA8A55C0_1374_4E1F_A3AA_58278644ED09

#include "DesignPatternTools/basic_open_singleTon.h"
#include "TestCommon/basic_test_common_class.h"
#include "basic_bit_flags.h"

namespace Basic {
class TzBasicBitFlagTestCases : public TzSingleTon<TzBasicBitFlagTestCases>,
                                TzTestCommonClass {
  friend class TzSingleTon<TzBasicBitFlagTestCases>;

 public:
  TzBasicBitFlagTestCases();
  ~TzBasicBitFlagTestCases();

  virtual bool initData() override;
  virtual bool initRandomData() override;

  virtual bool runAllTest() override;
  virtual bool runCommonTest() override;

  enum TestIntBit {
    TOne = 1,
    TTwo = 2,
    TThree = 4,
    TFour = 8,
    TFive = 16,
  };

  enum TestUIntBit {
    UOne = 0xFFFFFFF1,
    UTwo = 0xFFFFFFF2,
    UThree = 0xFFFFFFF4,
    UFour = 0xFFFFFFF8,
  };

 private:
  TzBitFlags<int> m_intFlags;
  TzBitFlags<unsigned int> m_uint32Flags;
};
}  // namespace Basic

#endif /* CA8A55C0_1374_4E1F_A3AA_58278644ED09 */

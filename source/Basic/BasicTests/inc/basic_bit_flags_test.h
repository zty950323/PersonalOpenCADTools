///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_bit_flags.h"
#include "basic_test_common_defines.h"

TZ_NAMESPACE_BEGIN(TzSoftTest)

class TzBitFlagsTests final : public TestCommon {
 public:
  TzBitFlagsTests() = default;
  ~TzBitFlagsTests() override = default;
  bool startAllTest() override;
  bool startOneTest(int testId) override;
  bool startSomeTest(int startId, int endId) override;
  bool startSomeTest(const std::vector<int>& ids) override;
  void showTestLog() override;

 private:
  void initProfile() override;
  void initData() override;
  void unloadProfile() override;
  void unloadData() override;
  bool commonTests() override;

  Basic::TzBitFlags<uint8_t> m_flags;
};

TZ_NAMESPACE_END(TzSoftTest)

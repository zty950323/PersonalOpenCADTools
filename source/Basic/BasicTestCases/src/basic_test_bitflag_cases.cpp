///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_test_bitflag_cases.h"

namespace Basic {

TzBasicBitFlagTestCases::TzBasicBitFlagTestCases() {}

TzBasicBitFlagTestCases::~TzBasicBitFlagTestCases() {}

bool TzBasicBitFlagTestCases::initData() {
  bool ret = true;

  bool uFlag = false;
  for (int i = 1; i <= 16; i = i << 1) {
    if (!uFlag) {
      m_intFlags.setBit(i, false);
      uFlag = true;
    } else {
      m_intFlags.setBit(i, true);
      uFlag = false;
    }
  }

  unsigned int uBit = 0xFFFFFFF0;
  unsigned int i = 1;

  uFlag = false;

  for (unsigned int j = uBit + i; j <= 0xFFFFFFF8; j += (i << 1)) {
    if (!uFlag) {
      m_uint32Flags.setBit(j, false);
      uFlag = true;
    } else {
      m_uint32Flags.setBit(j, true);
      uFlag = false;
    }
  }

  return ret;
}

bool TzBasicBitFlagTestCases::initRandomData() { return false; }

bool TzBasicBitFlagTestCases::runAllTest() {
  bool ret = true;
  ret = TzTestCommonClass::runAllTest();
  return ret;
}

bool TzBasicBitFlagTestCases::runCommonTest() { return false; }
}  // namespace Basic
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <string>

#include "basic_array.h"
#include "basic_open_array.h"
#include "basic_test_common_defines.h"

using std::string;

TZ_NAMESPACE_BEGIN(TzSoftTest)

class ArrayTestCommon : public TestCommon {
 public:
  string printRetString() const { return m_printRetString; }

 protected:
  virtual string printArrays(void) { return m_printRetString; }
  string m_printRetString;
};

using TzSoft::TzArray;

class TzArrayTests final : public ArrayTestCommon {
 public:
  TzArrayTests();
  ~TzArrayTests() override;
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
  string printArrays(void) override;

  TzArray<float> m_floatArray;
  TzArray<double> m_doubleArray;
  TzArray<short> m_shortArray;
  TzArray<int> m_intArray;
  TzArray<unsigned int> m_uintArray;
  TzArray<long> m_longArray;
};

using Basic::Array;
using std::vector;

class TzOpenArrayTests final : public ArrayTestCommon {
 public:
  TzOpenArrayTests();
  ~TzOpenArrayTests() final;
  bool startAllTest() override;
  bool startOneTest(int testId) override;
  bool startSomeTest(int startId, int endId) override;
  bool startSomeTest(const vector<int>& ids) override;
  void showTestLog() override;

 private:
  void initProfile() override;
  void initData() override;
  void unloadProfile() override;
  void unloadData() override;
  string printArrays(void) override;
  bool commonTests() override;

  Array<float> m_floatArray;
  Array<double> m_doubleArray;
  Array<short> m_shortArray;
  Array<int> m_intArray;
  Array<unsigned int> m_uintArray;
  Array<long> m_longArray;
};

TZ_NAMESPACE_END(TzSoftTest)

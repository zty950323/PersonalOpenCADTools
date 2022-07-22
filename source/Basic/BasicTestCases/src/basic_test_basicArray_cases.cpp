///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_test_basicArray_cases.h"

#include <iostream>
#include <limits>
#include <random>
#include <sstream>

namespace Basic {
constexpr unsigned int MaxNumOfRandomTestItems = 100;

template <typename T>
class ArrayTestUtils {
 public:
  // some generate data methods.
  static void generateRealData(Basic::Array<T>& array);
  static void generateIntData(Basic::Array<T>& array);
  static void generateCertainData(Basic::Array<T>& array, const T& down,
                                  const T& up, const T& step);
  static std::string printArray(const Basic::Array<T>& array);

  static bool commonInterfaceTests(const Basic::Array<T>& array);
};

template <typename T>
void ArrayTestUtils<T>::generateRealData(Basic::Array<T>& array) {
  std::default_random_engine e;
  for (int i = 0; i < MaxNumOfRandomTestItems; ++i) {
    std::uniform_real_distribution<T> u(std::numeric_limits<T>::min(),
                                        std::numeric_limits<T>::max());
    array.append(u(e));
  }
}

template <typename T>
void ArrayTestUtils<T>::generateIntData(Basic::Array<T>& array) {
  std::default_random_engine e;
  for (int i = 0; i < MaxNumOfRandomTestItems; ++i) {
    std::uniform_int_distribution<T> u(std::numeric_limits<T>::min(),
                                       std::numeric_limits<T>::max());
    array.append(u(e));
  }
}

template <typename T>
void ArrayTestUtils<T>::generateCertainData(Basic::Array<T>& array,
                                            const T& down, const T& up,
                                            const T& step) {
  for (T i = down; i < up; i += step) {
    array.append(i);
  }
}

template <typename T>
std::string ArrayTestUtils<T>::printArray(const Basic::Array<T>& array) {
  std::ostringstream oss;
  for (decltype(array.length()) i = 0; i < array.length(); ++i) {
    oss << array.at(i) << '\t';

    if (0 == i % 8) {
      oss << '\n';
    }
  }

  return oss.str();
}

template <typename T>
bool ArrayTestUtils<T>::commonInterfaceTests(const Basic::Array<T>& array) {
  assert(!array.isEmpty());
  assert(MaxNumOfRandomTestItems == array.length());
  assert(array.at(0) == array.first());
  assert(array.last() == array.at(array.length() - 1));
  assert(array.last() == array[array.length() - 1]);
  assert(array.length() == array.logicalLength());
  Basic::Array<T> tmp = array;
  assert(tmp == array);
  int count = 0;
  for (auto it = array.begin(); it != array.end(); ++it) {
    assert(nullptr != it);
    assert(*it == array.at(count));
    assert(*it == array[count]);
    assert(array.at(count) == array[count]);
    count++;
  }
  return true;
}

TzBasicArrayTestCases::TzBasicArrayTestCases() { initRandomData(); }

TzBasicArrayTestCases::~TzBasicArrayTestCases() {}

bool TzBasicArrayTestCases::runAllTestCases() {
  bool ret = true;
  ret = runAllCommonTests();
  ret = runSomeCertainTests();
  return ret;
}

bool TzBasicArrayTestCases::runAllCommonTests() {
  bool ret = true;
  ret = std::move(ArrayTestUtils<float>::commonInterfaceTests(m_floatArray));
  ret = std::move(ArrayTestUtils<double>::commonInterfaceTests(m_doubleArray));
  ret = std::move(
      ArrayTestUtils<unsigned int>::commonInterfaceTests(m_uintArray));
  ret = std::move(ArrayTestUtils<int>::commonInterfaceTests(m_intArray));
  ret = std::move(ArrayTestUtils<short>::commonInterfaceTests(m_shortArray));
  ret = std::move(ArrayTestUtils<long>::commonInterfaceTests(m_longArray));
  std::cout << std::move(printArrays()) << std::endl;
  return ret;
}

bool TzBasicArrayTestCases::runSomeCertainTests() {
  bool ret = true;
  // for test case one
  clearData();
  initCertainData();
  ret = runAllCommonTests();
  std::cout << std::move(printArrays()) << std::endl;
  return ret;
}

std::string TzBasicArrayTestCases::printArrays(void) const {
  std::string retStr;
  retStr += std::move(ArrayTestUtils<float>::printArray(m_floatArray));
  retStr += std::move(ArrayTestUtils<double>::printArray(m_doubleArray));
  retStr += std::move(ArrayTestUtils<unsigned int>::printArray(m_uintArray));
  retStr += std::move(ArrayTestUtils<int>::printArray(m_intArray));
  retStr += std::move(ArrayTestUtils<short>::printArray(m_shortArray));
  retStr += std::move(ArrayTestUtils<long>::printArray(m_longArray));
  return retStr;
}

void TzBasicArrayTestCases::initRandomData() {
  ArrayTestUtils<float>::generateRealData(m_floatArray);
  ArrayTestUtils<double>::generateRealData(m_doubleArray);
  ArrayTestUtils<unsigned int>::generateIntData(m_uintArray);
  ArrayTestUtils<int>::generateIntData(m_intArray);
  ArrayTestUtils<short>::generateIntData(m_shortArray);
  ArrayTestUtils<long>::generateIntData(m_longArray);
}

void TzBasicArrayTestCases::initCertainData() {
  ArrayTestUtils<float>::generateCertainData(m_floatArray, 0.0f, 200.0f, 0.5f);
  ArrayTestUtils<double>::generateCertainData(m_doubleArray, -200.0, 200.0,
                                              0.05);
  ArrayTestUtils<unsigned int>::generateCertainData(m_uintArray, 0, 400, 1);
  ArrayTestUtils<int>::generateCertainData(m_intArray, -200, 200, 1);
  ArrayTestUtils<short>::generateCertainData(m_shortArray, -100, 100, 1);
  ArrayTestUtils<long>::generateCertainData(m_longArray, -2000, 2000, 5);
}

void TzBasicArrayTestCases::clearData() {
  m_floatArray.removeAll();
  m_doubleArray.removeAll();
  m_intArray.removeAll();
  m_longArray.removeAll();
  m_shortArray.removeAll();
  m_uintArray.removeAll();
}
}  // namespace Basic
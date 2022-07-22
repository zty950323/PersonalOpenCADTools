///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#define NOMINMAX

#include "basic_array_tests.h"

#include <assert.h>

#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <limits>
#include <random>
#include <sstream>

TZ_NAMESPACE_BEGIN(TzSoftTest)

constexpr unsigned int MaxNumOfRandomTestItems = 2000;

template <typename T>
class ArrayTestUtils {
 public:
  // some generate data methods.
  static void generateRealData(TzSoft::TzArray<T>& array);
  static void generateRealData(Basic::Array<T>& array);
  static void generateIntData(TzSoft::TzArray<T>& array);
  static void generateIntData(Basic::Array<T>& array);

  static bool commonInterfaceTests(const TzSoft::TzArray<T>& array);
  static bool commonInterfaceTests(const Basic::Array<T>& array);
};

template <typename T>
void ArrayTestUtils<T>::generateRealData(TzSoft::TzArray<T>& array) {
  std::default_random_engine e;
  for (int i = 0; i < MaxNumOfRandomTestItems; ++i) {
    std::uniform_real_distribution<T> u(std::numeric_limits<T>::min(),
                                        std::numeric_limits<T>::max());
    array.append(u(e));
  }
}

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
void ArrayTestUtils<T>::generateIntData(TzSoft::TzArray<T>& array) {
  std::default_random_engine e;
  for (int i = 0; i < MaxNumOfRandomTestItems; ++i) {
    std::uniform_int_distribution<T> u(std::numeric_limits<T>::min(),
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
bool ArrayTestUtils<T>::commonInterfaceTests(const TzSoft::TzArray<T>& array) {
  assert(!array.isEmpty());
  assert(MaxNumOfRandomTestItems == array.length());
  assert(array.at(0) == array.first());
  assert(array.last() == array.at(array.length() - 1));
  TzSoft::TzArray<T> tmp = array;
  assert(tmp == array);
  int count = 0;
  for (auto it = array.begin(); it != array.end(); it++) {
    assert(nullptr != it);
    assert(*it == array.at(count));
    assert(*it == array[count]);
    assert(array.at(count) == array[count]);
    count++;
  }
  return true;
}

template <typename T>
bool ArrayTestUtils<T>::commonInterfaceTests(const Basic::Array<T>& array) {
  assert(!array.isEmpty());
  assert(MaxNumOfRandomTestItems == array.length());
  assert(array.at(0) == array.first());
  assert(array.last() == array.at(array.length() - 1));
  Basic::Array<T> tmp = array;
  assert(tmp == array);
  int count = 0;
  for (auto it = array.begin(); it != array.end(); it++) {
    assert(nullptr != it);
    assert(*it == array.at(count));
    assert(*it == array[count]);
    assert(array.at(count) == array[count]);
    count++;
  }
  return true;
}

//////////////////////////////////////////////////////////////////////////

TzArrayTests::TzArrayTests() {
  initProfile();
  initData();
}

TzArrayTests::~TzArrayTests() {
  unloadData();
  unloadProfile();
}

bool TzArrayTests::startAllTest() {
  // TODO
  printArrays();
  commonTests();
  return false;
}

bool TzArrayTests::startOneTest(int testId) {
  // TODO
  printArrays();
  return false;
}

bool TzArrayTests::startSomeTest(int startId, int endId) {
  // TODO
  printArrays();
  return false;
}

bool TzArrayTests::startSomeTest(const std::vector<int>& ids) {
  // TODO
  printArrays();
  return false;
}

void TzArrayTests::showTestLog() {
  // TODO
}

void TzArrayTests::initProfile() {
  // TODO
}

void TzArrayTests::initData() {
  ArrayTestUtils<float>::generateRealData(m_floatArray);
  ArrayTestUtils<double>::generateRealData(m_doubleArray);
  ArrayTestUtils<unsigned int>::generateIntData(m_uintArray);
  ArrayTestUtils<int>::generateIntData(m_intArray);
  ArrayTestUtils<short>::generateIntData(m_shortArray);
  ArrayTestUtils<long>::generateIntData(m_longArray);
}

void TzArrayTests::unloadProfile() {
  // TODO
}

void TzArrayTests::unloadData() {
  // TODO
}

bool TzArrayTests::commonTests() {
  ArrayTestUtils<float>::commonInterfaceTests(m_floatArray);
  ArrayTestUtils<double>::commonInterfaceTests(m_doubleArray);
  ArrayTestUtils<unsigned int>::commonInterfaceTests(m_uintArray);
  ArrayTestUtils<int>::commonInterfaceTests(m_intArray);
  ArrayTestUtils<short>::commonInterfaceTests(m_shortArray);
  ArrayTestUtils<long>::commonInterfaceTests(m_longArray);
  return true;
}

std::string TzArrayTests::printArrays(void) {
  m_prograssBar->setValue(0);
  m_edit->append(QStringLiteral("This is a float random array's output: "));
  QString str;
  // deal with the float array.
  for (decltype(m_floatArray.length()) i = 0; i < m_floatArray.length(); ++i) {
    str += QString::number(m_floatArray.at(i)) + QLatin1Char('\t');

    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 1);

  // deal with the double array.
  m_edit->append(QStringLiteral("This is a double random array's output:"));
  for (decltype(m_doubleArray.length()) i = 0; i < m_doubleArray.length();
       ++i) {
    str += QString::number(m_doubleArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 2);

  // deal with the int array.
  m_edit->append(QStringLiteral("This is a int random array's output:"));
  for (decltype(m_intArray.length()) i = 0; i < m_intArray.length(); ++i) {
    str += QString::number(m_intArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 3);

  // deal with the short array.
  m_edit->append(QStringLiteral("This is a short random array's output:"));
  for (decltype(m_shortArray.length()) i = 0; i < m_shortArray.length(); ++i) {
    str += QString::number(m_shortArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 4);

  // deal with the uint array.
  m_edit->append(QStringLiteral("This is a uint random array's output:"));
  for (decltype(m_uintArray.length()) i = 0; i < m_uintArray.length(); ++i) {
    str += QString::number(m_uintArray.at(i)) + QLatin1Char('\t');

    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 5);

  // deal with the long array.
  m_edit->append(QStringLiteral("This is a long random array's output:"));
  for (decltype(m_longArray.length()) i = 0; i < m_longArray.length(); ++i) {
    str += QString::number(m_longArray.at(i)) + QLatin1Char('\t');

    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 6);
  m_prograssBar->setValue(100);

  return m_printRetString;
}

//////////////////////////////////////////////////////////////////////////

TzOpenArrayTests::TzOpenArrayTests() {
  initProfile();
  initData();
}

TzOpenArrayTests::~TzOpenArrayTests() {
  unloadData();
  unloadProfile();
}

bool TzOpenArrayTests::startAllTest() {
  // TODO
  printArrays();
  commonTests();
  return false;
}

bool TzOpenArrayTests::startOneTest(int testId) {
  // TODO
  printArrays();
  return false;
}

bool TzOpenArrayTests::startSomeTest(int startId, int endId) {
  // TODO
  printArrays();
  return false;
}

bool TzOpenArrayTests::startSomeTest(const std::vector<int>& ids) {
  // TODO
  printArrays();
  return false;
}

void TzOpenArrayTests::showTestLog() {
  // TODO
}

void TzOpenArrayTests::initProfile() {
  // TODO
}

void TzOpenArrayTests::initData() {
  ArrayTestUtils<float>::generateRealData(m_floatArray);
  ArrayTestUtils<double>::generateRealData(m_doubleArray);
  ArrayTestUtils<unsigned int>::generateIntData(m_uintArray);
  ArrayTestUtils<int>::generateIntData(m_intArray);
  ArrayTestUtils<short>::generateIntData(m_shortArray);
  ArrayTestUtils<long>::generateIntData(m_longArray);
}

void TzOpenArrayTests::unloadProfile() {
  // TODO
}

void TzOpenArrayTests::unloadData() {
  // TODO
}

std::string TzOpenArrayTests::printArrays(void) {
  m_prograssBar->setValue(0);
  m_edit->append(QStringLiteral("This is a float random array's output:"));
  QString str;
  // deal with the float array.
  for (decltype(m_floatArray.length()) i = 0; i < m_floatArray.length(); ++i) {
    str += QString::number(m_floatArray.at(i)) + QLatin1Char('\t');

    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 1);

  // deal with the double array.
  m_edit->append(QStringLiteral("This is a double random array's output:"));
  for (decltype(m_doubleArray.length()) i = 0; i < m_doubleArray.length();
       ++i) {
    str += QString::number(m_doubleArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 2);

  // deal with the int array.
  m_edit->append(QStringLiteral("This is a int random array's output:"));
  for (decltype(m_intArray.length()) i = 0; i < m_intArray.length(); ++i) {
    str += QString::number(m_intArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 3);

  // deal with the short array.
  m_edit->append(QStringLiteral("This is a short random array's output:"));
  for (decltype(m_shortArray.length()) i = 0; i < m_shortArray.length(); ++i) {
    str += QString::number(m_shortArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 4);

  // deal with the uint array.
  m_edit->append(QStringLiteral("This is a uint random array's output:"));
  for (decltype(m_uintArray.length()) i = 0; i < m_uintArray.length(); ++i) {
    str += QString::number(m_uintArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 5);

  // deal with the long array.
  m_edit->append(QStringLiteral("This is a long random array's output:"));
  for (decltype(m_longArray.length()) i = 0; i < m_longArray.length(); ++i) {
    str += QString::number(m_longArray.at(i)) + QLatin1Char('\t');
    if (i % 8 == 0) {
      m_edit->append(str);
      str.clear();
    }
  }
  m_prograssBar->setValue(100 / 6 * 6);
  m_prograssBar->setValue(100);

  return m_printRetString;
}

bool TzOpenArrayTests::commonTests() {
  ArrayTestUtils<float>::commonInterfaceTests(m_floatArray);
  ArrayTestUtils<double>::commonInterfaceTests(m_doubleArray);
  ArrayTestUtils<unsigned int>::commonInterfaceTests(m_uintArray);
  ArrayTestUtils<int>::commonInterfaceTests(m_intArray);
  ArrayTestUtils<short>::commonInterfaceTests(m_shortArray);
  ArrayTestUtils<long>::commonInterfaceTests(m_longArray);
  return true;
}

TZ_NAMESPACE_END(TzSoftTest)

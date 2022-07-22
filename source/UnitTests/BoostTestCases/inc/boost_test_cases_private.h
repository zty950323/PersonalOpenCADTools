/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This is a private header for inner use.
 */

#ifndef SOURCE_BOOST_TESTS_CASES_INC_CORE_PRIVATE_H_
#define SOURCE_BOOST_TESTS_CASES_INC_CORE_PRIVATE_H_

#include "zsofts_compiler_specific.h"

namespace TzSoft {
enum class BoostTestCasesPrivateFlags {
  kPrivateNone = 0,
};

class TzBoostCasesPrivate {
 public:
  explicit TzBoostCasesPrivate(const BoostTestCasesPrivateFlags& flag);
  ~TzBoostCasesPrivate() = default;

 private:
  BoostTestCasesPrivateFlags m_privateFlag;
};
}  // namespace TzSoft

#endif  // SOURCE_BOOST_TESTS_CASES_INC_CORE_PRIVATE_H_

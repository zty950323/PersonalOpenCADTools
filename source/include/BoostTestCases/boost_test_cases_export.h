/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This is a export file for BoostTestCases project.
 */

#ifndef SOURCE_INCLUDE_BOOST_TEST_CASES_CORE_EXPORT_H_
#define SOURCE_INCLUDE_BOOST_TEST_CASES_CORE_EXPORT_H_

#include "zsofts_compiler_specific.h"

#ifdef TZ_SOFT_BOOST_TEST_CASES_MODULE
#define TZ_BOOST_TEST_CASES__EXPORT TZ_EXPORT
#define TZ_BOOST_TEST_CASES__STATIC_EXPORT TZ_EXPORT
#define TZ_BOOST_TEST_CASES__EXPORT_STATIC
#define TZ_BOOST_TEST_CASES__C_EXPORT TZ_C_EXPORT
#else
#define TZ_BOOST_TEST_CASES__EXPORT TZ_IMPORT
#define TZ_BOOST_TEST_CASES__STATIC_EXPORT
#define TZ_BOOST_TEST_CASES__EXPORT_STATIC TZ_EXPORT
#define TZ_BOOST_TEST_CASES__C_EXPORT TZ_C_EXPORT
#endif

#endif  // SOURCE_INCLUDE_BOOST_TEST_CASES_CORE_EXPORT_H_

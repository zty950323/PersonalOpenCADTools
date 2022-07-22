///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "basic_test_all_cases_run.h"

int main(int argc, char* argv[]) {
  /* code */
  Basic::TzBasicAllTestCases::getInstance().runAllTestCase(argc, argv);
  system("pause");
  return 0;
}
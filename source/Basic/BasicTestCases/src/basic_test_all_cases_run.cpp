///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_test_all_cases_run.h"

#include <iostream>

#include "basic_example_boost_acc.h"
#include "basic_test_basicTools_cases.h"
#include "basic_test_boost_some_test_cases.h"

namespace Basic {
int TzBasicAllTestCases::runAllTestCase(int argc, char* argv[]) {
  int choice = 0;

  while (true) {
    std::cout << "Please choose what you what to test:\n "
              << "0 is to exit this part.\n"
              << "1 is to show and chose all the boost test cases.\n"
              << "2 is to show and chose all the BasicTools test cases.\n"
              << "3 is to show the example for boost accumulators.\n"
              << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 0: {
        std::cout << "Bye! Program Exit!" << std::endl;
        return choice;
      } break;
      case 1: {
        TzBoostAlgorithmTestCases::getInstance().runAllTestCases();

      } break;
      case 2: {
        TzBasicToolsTestCases::getInstance().runAllTestCases(argc, argv);
      } break;
      case 3: {
        TzBasicBoostAccExample::getInstance().runAllTestCase(argc, argv);
      } break;
      default:
        break;
    }
  }

  return choice;
}
}  // namespace Basic
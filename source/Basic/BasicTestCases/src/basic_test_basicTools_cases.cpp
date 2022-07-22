///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_test_basicTools_cases.h"

#include <iostream>

#include "basic_test_folly_cases.h"

namespace Basic {
bool TzBasicToolsTestCases::runAllTestCases(int argc, char* argv[]) {
  int choice = 0;

  while (true) {
    std::cout << "Please choose what you what to test:\n "
              << "0 is to exit this part.\n"
              << "1 is to show and chose all the basic array's cases.\n"
              << "2 is to show and chose all the basic bit flags test cases.\n"
              << "3 is to show and chose all the RBTree test cases.\n"
              << "4 is to show and chose all the folly test cases. \n"
              << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 0: {
        std::cout << "Bye! Program Exit!" << std::endl;
        exit(choice);
      } break;
      case 1: {
        TzBasicArrayTestCases::getInstance().runAllTestCases();
      } break;
      case 2: {
        TzBasicToolsTestCases::getInstance().runAllTestCases(argc, argv);
      } break;
      case 3: {
        TzBasicBitFlagTestCases::getInstance().runAllTest();
      } break;
      case 4: {
        TzFollyArenaTestCase::getInstance().runAllCases(argc, argv);
      } break;
      default:
        break;
    }
  }

  return choice;
}
}  // namespace Basic
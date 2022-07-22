///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_test_boost_some_test_cases.h"

#include <iostream>
#include <vector>

#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/timer.hpp>

namespace Basic
{
    bool isOdd(int i)
    {
        return i % 2 == 1;
    }

    bool lessThan10(int i)
    {
        return i < 10;
    }

    void TzBoostAlgorithmTestCases::runAllTestCases()
    {
        useFunc_all_of_case_01();
        useTimerCase_01();
    }

    void TzBoostAlgorithmTestCases::useFunc_all_of_case_01(void)
    {
        std::vector<int >c;
        c.push_back(0);
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);
        c.push_back(14);
        c.push_back(15);

        // using boost::algorithm;
        std::cout << boost::algorithm::all_of(c, isOdd) << std::endl;
        std::cout << boost::algorithm::all_of(c.begin(), c.end(), lessThan10) << std::endl;
        std::cout << boost::algorithm::all_of(c.begin(), c.begin() + 3, lessThan10) << std::endl;
        std::cout << boost::algorithm::all_of(c.end(), c.end(), isOdd) << std::endl;  // empty range
        std::cout << boost::algorithm::all_of_equal(c, 3) << std::endl;
        std::cout << boost::algorithm::all_of_equal(c.begin() + 3, c.begin() + 4, 3) << std::endl;
        std::cout << boost::algorithm::all_of_equal(c.begin(), c.begin(), 99) << std::endl;  // empty range
    }

    void TzBoostAlgorithmTestCases::useTimerCase_01()
    {
        using namespace boost;
        timer t;
        std::cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << std::endl;
        std::cout << "min timespan:" << t.elapsed_min() << "s" << std::endl;
        std::cout << "now time elapsed:" << t.elapsed() << "s" << std::endl;
    }
}
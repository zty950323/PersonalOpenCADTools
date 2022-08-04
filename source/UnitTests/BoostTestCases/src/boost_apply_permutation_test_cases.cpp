/**
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 1. You can modify and use this program at will.
 * 2. But it is suggested that it is more suitable for learning and teaching
 * purposes.
 *
 * @version 1.0
 * @brief This file provides some test cases for boost::apply_permutation as example.
 * @file boost_apply_permutaion_test_cases.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-08-04
 * @date Created: 2022-08-04
 * @date Last modified: 2022-08-04
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 * RefLink: @link https://en.jinzhao.wiki/wiki/Boyer%E2%80%93Moore_string-search_algorithm @endlink
 */

#include "boost_apply_permutation_test_cases.h"

#include <string>
#include <iostream>  //  For cout, etc.

#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>

namespace ba = boost::algorithm;

const std::string haystack("ABACAB is it everywhere!");
const std::string needle1("ACAB");
const std::string needle2("not ABA");

namespace TzSoft
{
    namespace UnitTests
    {
        void ApplyPermutationTestCases::testCaseEntry()
        {
            boostExampleCase();
            personalCase();
        }

        void ApplyPermutationTestCases::boostExampleCase()
        {
            //  In search.hpp, there are generic implementations of three classic sequence search
            //  algorithms. They all have the same (dual) interface.

            //  There is a procedural interface, based on std::search:
            if (ba::boyer_moore_search(haystack.begin(), haystack.end(), needle1.begin(), needle1.end()) != std::make_pair(haystack.end(), haystack.end()))
                std::cout << "Found '" << needle1 << "'  in '" << haystack << "' (boyer-moore 1)" << std::endl;
            else
                std::cout << "Did NOT find '" << needle1 << "'  in '" << haystack << "' (boyer-moore 1)" << std::endl;

            //  If you plan on searching for the same pattern in several different data sets,
            //  you can create a search object and use that over and over again - amortizing the setup
            //  costs across several searches
            ba::boyer_moore<std::string::const_iterator> search1(needle1.begin(), needle1.end());
            if (search1(haystack.begin(), haystack.end()) != std::make_pair(haystack.end(), haystack.end()))
                std::cout << "Found '" << needle1 << "'  in '" << haystack << "' (boyer-moore 2)" << std::endl;
            else
                std::cout << "Did NOT find '" << needle1 << "'  in '" << haystack << "' (boyer-moore 2)" << std::endl;

            //  There is also an implementation of boyer-moore-horspool searching
            if (ba::boyer_moore_horspool_search(haystack.begin(), haystack.end(), needle1.begin(), needle1.end()) != std::make_pair(haystack.end(), haystack.end()))
                std::cout << "Found '" << needle1 << "'  in '" << haystack << "' (boyer-moore-horspool)" << std::endl;
            else
                std::cout << "Did NOT find '" << needle1 << "'  in '" << haystack << "' (boyer-moore-horspool)" << std::endl;

            //  And also the knuth-pratt-morris search algorithm
            if (ba::knuth_morris_pratt_search(haystack.begin(), haystack.end(), needle1.begin(), needle1.end()) != std::make_pair(haystack.end(), haystack.end()))
                std::cout << "Found '" << needle1 << "'  in '" << haystack << "' (knuth_morris_pratt)" << std::endl;
            else
                std::cout << "Did NOT find '" << needle1 << "'  in '" << haystack << "' (knuth_morris_pratt)" << std::endl;
        }

        void ApplyPermutationTestCases::personalCase()
        {
        }
    } // namespace UnitTests
} // namespace TzSoft

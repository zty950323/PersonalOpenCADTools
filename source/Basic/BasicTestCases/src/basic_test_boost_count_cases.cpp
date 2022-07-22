///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

//  (C) Copyright Eric Niebler 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "basic_test_boost_count_cases.h"

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/framework/accumulator_set.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <sstream>

using namespace boost;
using namespace unit_test;
using namespace accumulators;

///////////////////////////////////////////////////////////////////////////////
// test_stat
//
void test_stat()
{
    accumulator_set<int, stats<tag::count> > acc;

    acc(1);
    BOOST_CHECK_EQUAL(1u, count(acc));

    acc(1);
    BOOST_CHECK_EQUAL(2u, count(acc));

    acc(1);
    BOOST_CHECK_EQUAL(3u, count(acc));

    acc(1);
    BOOST_CHECK_EQUAL(4u, count(acc));

    acc(1);
    BOOST_CHECK_EQUAL(5u, count(acc));
}

///////////////////////////////////////////////////////////////////////////////
// test_persistency
//
void test_persistency()
{
    // "persistent" storage
    std::stringstream ss;
    {
        accumulator_set<int, stats<tag::count> > acc;
        acc(1);
        acc(1);
        acc(1);
        acc(1);
        BOOST_CHECK_EQUAL(4u, count(acc));
        // boost::archive::text_oarchive oa(ss);
        // acc.serialize(oa, 0);
    }
    accumulator_set<int, stats<tag::count> > acc;
    BOOST_CHECK_EQUAL(0u, count(acc));
    //boost::archive::text_iarchive ia(ss);
    //acc.serialize(ia, 0);
    //BOOST_CHECK_EQUAL(4u, count(acc));
}

///////////////////////////////////////////////////////////////////////////////
// init_unit_test_suite
//

boost::unit_test::test_suite* Basic::TzBoostCountTestCases::init_unit_test_suite(int argc, char* argv[])
{
    test_suite* test = BOOST_TEST_SUITE("count test");

    test->add(BOOST_TEST_CASE(&test_stat));
    test->add(BOOST_TEST_CASE(&test_persistency));

    return test;
}

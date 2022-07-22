///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef DA0B259C_95BA_49BE_B860_DCDFCDC8A5A2
#define DA0B259C_95BA_49BE_B860_DCDFCDC8A5A2

#include "DesignPatternTools/basic_open_singleTon.h"

#include <boost/test/unit_test.hpp>

namespace Basic 
{
    class TzBoostCountTestCases : public TzSingleTon<TzBoostCountTestCases>
    {
        friend class TzSingleTon<TzBoostCountTestCases>;
    public:
        boost::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] );
    };
}

#endif /* DA0B259C_95BA_49BE_B860_DCDFCDC8A5A2 */

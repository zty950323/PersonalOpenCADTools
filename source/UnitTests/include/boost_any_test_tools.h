/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This is a tools file for BoostTestCases and will used in AnyTestTools.
 */

#ifndef _BOOST_ANY_TEST_TOOLS_H_H_
#define _BOOST_ANY_TEST_TOOLS_H_H_

namespace TzSoftAnyTestTools
{
    template <typename string_type, typename function_type>
    struct AnyTestData
    {
        string_type name;
        function_type action;

        static AnyTestData make(string_type name, function_type action)
        {
            AnyTestData result; // MSVC aggreggate initializer bugs
            result.name = name;
            result.action = action;
            return result;
        }
    };
}

#endif // _BOOST_ANY_TEST_TOOLS_H_H_

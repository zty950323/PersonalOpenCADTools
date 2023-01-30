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
 * @brief This file provides private class for UiToolsUtilityImp using.
 * @file gui_tools_utility_imp_p.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-11-01
 * @date Created: 2022-11-01
 * @date Last modified: 2022-11-01
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "gui_tools_utility_imp_p.h"

namespace TzSoft
{
    UiToolsUtilityImpPrivate::UiToolsUtilityImpPrivate(void)
    {
    }

    UiToolsUtilityImpPrivate::~UiToolsUtilityImpPrivate(void)
    {
    }

    TzDrawHelpers* UiToolsUtilityImpPrivate::drawHelpers(void)
    {
        return nullptr;
    }

    const TzDrawHelpers* UiToolsUtilityImpPrivate::cDrawHeplers(void)
    {
        return nullptr;
    }

    void UiToolsUtilityImpPrivate::setDrawHelper(TzDrawHelpers* pDrawHelper)
    {
    }
}  // namespace TzSoft

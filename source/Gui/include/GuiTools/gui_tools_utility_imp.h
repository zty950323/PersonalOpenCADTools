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
 * @brief This file provides basic object in Ui projects used.
 * codec.
 * @file gui_tools_utility_imp.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-11-01
 * @date Created: 2022-11-01
 * @date Last modified: 2022-11-01
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "gui_tools_utility_base.h"
#include "gui_tools_utility_imp_p.h"
#include "gui_tools_export.h"

#include "DesignPatternTools/basic_open_singleTon.h"

#ifndef _GUI_TOOLS_UTILITY_IMP_H_
#define _GUI_TOOLS_UTILITY_IMP_H_

namespace TzSoft
{
    class TZ_GUI_TOOLS_STATIC_EXPORT UiToolsUtilityImp final : public UiToolsUtilityBase, public Basic::TzSingleTon<UiToolsUtilityImp>
    {
    public:
        TzDrawHelpers *drawHelpers(void) override;
        const TzDrawHelpers *cDrawHeplers(void) override;
        // TODO (Tom Zhao) : Add some new tools in our gui project and provide them here.

        UiToolsUtilityImp(void);
        ~UiToolsUtilityImp(void);

    private:
        friend class UiToolsUtilityImpPrivate;
        UiToolsUtilityImpPrivate *m_pPrivate;
    };
} // namespace TzSoft

#endif // _GUI_TOOLS_UTILITY_IMP_H_

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
* @file gui_core_object.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2022-10-25
* @date Created: 2022-10-25
* @date Last modified: 2022-10-25
*
* Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "gui_core_object.h"
#include "gui_core_object_p.h"

namespace TzSoft
{
    TObjectPrivate::TObjectPrivate(TObject* pObject)
        : q_ptr(pObject)
    {
    }

    TObjectPrivate::~TObjectPrivate()
    {
    }

    TObject::TObject(TObject* pParent)
    {
    }

    TObject::~TObject()
    {
    }
}  // namespace TzSoft

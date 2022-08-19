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
* @brief This file provides a tool with the capabilities of a basic 64-bit codec.
* @file basic_binary_data.h
* @author Tom Zhao(18872770445@163.com)
* @since 2022-07-26
* @date Created: 2022-07-26
* @date Last modified: 2022-07-26
*
* Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "BasicTools/basic_binary_data.h"

namespace Basic
{
    BinaryData::BinaryData()
        : Array<uint8_t>()
    {
    }

    BinaryData::BinaryData(const BinaryData& other)
    {
        BinaryData::operator=(other);
    }

    BinaryData::~BinaryData()
    {
    }

    BinaryData& BinaryData::operator=(const BinaryData& other)
    {
        assign(0, other.logicalLength(), other);
        return *this;
    }

    void BinaryData::assign(size_t srcFirst, size_t srcLast, const BinaryData& src)
    {
        removeAll();
        if (srcFirst <= srcLast && srcLast >= 0)
        {
            size_t nLen = srcLast - srcFirst;
            setLogicalLength(nLen);
            memcpy_s(asArrayPtr(), nLen, src.asArrayPtr() + srcFirst, nLen);
        }
    }

}  // namespace Basic
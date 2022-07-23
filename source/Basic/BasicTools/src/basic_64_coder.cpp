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
 * @brief This file provides a tool with the capabilities of a basic 64-bit
 * codec.
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-07-23
 * @date Created: 2022-07-23
 * @date Last modified: 2022-07-23
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "BasicTools/basic_64_coder.h"

namespace
{
    static const std::string basic64Chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    static inline bool is_base64(unsigned char c) {
        return (isalnum(c) || (c == '+') || (c == '/'));
    }
}  // namesapce

namespace Basic
{
    std::string base64Encode(unsigned char const* bytesToEncode, unsigned int inLength)
    {
        std::string ret;
        int i = 0;
        int j = 0;
        unsigned char charArray3[3];
        unsigned char charArray4[4];

        while (inLength--)
        {
            charArray3[i++] = *(bytesToEncode++);
            if (i == 3) {
                charArray4[0] = (charArray3[0] & 0xfc) >> 2;
                charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
                charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
                charArray4[3] = charArray3[2] & 0x3f;

                for (i = 0; (i < 4); i++)
                    ret += basic64Chars[charArray4[i]];
                i = 0;
            }
        }

        if (i)
        {
            for (j = i; j < 3; j++)
                charArray3[j] = '\0';

            charArray4[0] = (charArray3[0] & 0xfc) >> 2;
            charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
            charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
            charArray4[3] = charArray3[2] & 0x3f;

            for (j = 0; (j < i + 1); j++)
                ret += basic64Chars[charArray4[j]];

            while ((i++ < 3))
                ret += '=';
        }

        return ret;
    }

    std::string TZ_BASIC_STATIC_EXPORT base64Decode(const std::string& encodedString)
    {
        auto inLenth = encodedString.size();
        int i = 0;
        int j = 0;
        int in_ = 0;
        unsigned char charArray4[4], charArray3[3];
        std::string ret;

        while (inLenth-- && (encodedString[in_] != '=') && is_base64(encodedString[in_]))
        {
            charArray4[i++] = encodedString[in_]; in_++;
            if (i == 4) {
                for (i = 0; i < 4; i++)
                    charArray4[i] = static_cast<unsigned char>(basic64Chars.find(charArray4[i]));

                charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
                charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
                charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

                for (i = 0; (i < 3); i++)
                    ret += charArray3[i];
                i = 0;
            }
        }

        if (i)
        {
            for (j = i; j < 4; j++)
                charArray4[j] = 0;

            for (j = 0; j < 4; j++)
                charArray4[j] = static_cast<unsigned char>(basic64Chars.find(charArray4[j]));

            charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
            charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
            charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

            for (j = 0; (j < i - 1); j++) ret += charArray3[j];
        }

        return ret;
    }
}  // namespace Basic

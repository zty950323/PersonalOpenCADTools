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
 * @brief Definition of String class. The object is generic string represention in the platform,
 * which intergrated different types of string conversion and function. Users can use
 * this class to perform various operations about characters.
 * @file basic_defines.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-01-19
 * @date Created: 2023-01-19
 * @date Last modified: 2023-01-19
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _BASIC_STRING_H_H_
#define _BASIC_STRING_H_H_

#include "platform_types.h"
#include "basic_export.h"

#pragma pach(push, 1)

namespace Basic
{
    class TZ_BASIC_STATIC_EXPORT String
    {
    public:
        String(void);
        String(TZCHAR ch);
        String(TZWCHAR wch);
        String(const TZCHAR* pSz);
        String(const TZWCHAR* pWsz);
        String(const String& acs);

        enum class StrArgs : TZUINT8
        {
            kAppRes = 0x0001,
            kSigned = 0x0002,
            kUnSigned = 0x0003,
            kHex = 0x0004
        };

        String(StrArgs nCtorFlags, TZUINT32 nArg);

#if defined(TZ_WINDOWS)
        String(HINSTANCE hDll, TZUINT32 nId);
#endif
        ~String(void);

        const TZCHAR* ansiPtr(void) const;
        const TZCHAR* kszPtr(void) const;
        const TZWCHAR* kwszPtr(void) const;

#if (TZ_BUILD_CHARACTERS == TZ_CHARACTERS_UNICODE)
        const TZWCHAR* constPtr(void) const;
        const TZWCHAR* kTCharPtr(void) const;
#else
        const TZCHAR* constPtr(void) const;
        const TZCHAR* kTCharPtr(void) const;
#endif
        operator const char* (void) const;
        operator const wchar_t* (void) const;

        TZBOOL isEmpty(void) const;
        TZUINT64 length(void) const;
        TZUINT64 tCharLength(void) const;

        TZBOOL isAscii(void) const;

        enum ParseFlag
        {
            kZero = 0x0000,
            kMinus1 = 0x0001,
            kAssert = 0x0002,
            kExcept = 0x0004,
            kNoEmpty = 0x0008,
            kDefault = (kAssert | kZero)
        };

        TZINT32 asDeci(ParseFlag = ParseFlag::kDefault) const;
        TZINT32 asHex(ParseFlag = ParseFlag::kDefault) const;

        TZUINT32 asUDeci(ParseFlag = ParseFlag::kDefault) const;
        TZUINT32 asUHex(ParseFlag = ParseFlag::kDefault) const;

        TZINT64 asDeci64(ParseFlag = ParseFlag::kDefault) const;
        TZINT64 asHex64(ParseFlag = ParseFlag::kDefault) const;

        TZUINT64 asUDeci64(ParseFlag = ParseFlag::kDefault) const;
        TZUINT64 asUHex64(ParseFlag = ParseFlag::kDefault) const;

        TZINT32 find(TZCHAR ch) const;
        TZINT32 find(const TZCHAR* pSz) const;
        TZINT32 find(const String& acs) const;
        TZINT32 findOneOf(const TZTCHAR* pSz) const;

        TZINT32 findRev(TZCHAR ch) const;
        TZINT32 findRev(const TZCHAR* pSz) const;
        TZINT32 findRev(const String& acs) const;
        TZINT32 findOneOfRev(const TZTCHAR* pSz) const;

        String mid(TZINT32 nStart, TZINT32 nNumChars) const;
        String subStr(TZINT32 numChars) const;
        String subStr(TZINT32 nStart, TZINT32 nNumChars) const;
        String subStrRev(TZINT32 numChars) const;

        String& assign(TZCHAR ch);
        String& assign(TZWCHAR wch);
        String& assign(const TZCHAR* pSz);
        String& assign(const TZWCHAR* pWsz);
        String& assign(const String& acs);

        String& operator = (TZCHAR ch);
        String& operator = (TZWCHAR wch);
        String& operator = (const TZCHAR* pSz);
        String& operator = (const TZWCHAR* pWsz);
        String& operator = (const String& acs);

        String& clear(void);

        void format(const TZCHAR* pSzFmt, ...);
        void formatV(const TZCHAR* pSzFmt, va_list args);

        String& operator += (TZCHAR ch);
        String& operator += (TZWCHAR ch);
        String& operator += (const TZCHAR* pSz);
        String& operator += (const TZWCHAR* pWsz);
        String& operator += (const String& acs);

        String& append(TZCHAR ch);
        String& append(TZWCHAR ch);
        String& append(const TZCHAR* pSz);
        String& append(const TZWCHAR* pWsz);
        String& append(const String& acs);

        String& operator + (TZCHAR ch);
        String& operator + (TZWCHAR ch);
        String& operator + (const TZCHAR* pSz);
        String& operator + (const TZWCHAR* pWsz);
        String& operator + (const String& acs);
    };
} // namespace Basic

#pragma pack(pop)

#endif // _BASIC_STRING_H_H_

/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_DESIGNPATTERNTOOLS_BASIC_OPEN_SINGLETON_H_
#define SOURCE_INCLUDE_DESIGNPATTERNTOOLS_BASIC_OPEN_SINGLETON_H_

#include <utility>

#include "basic_export.h"

namespace Basic
{
    template <class T>
    class TZ_BASIC_STATIC_EXPORT TzSingleTon
    {
    public:
        inline static T* getPointer()
        {
            static T* _ins = new T;
            return _ins;
        }

        inline static T& getInstance()
        {
            static T ref;
            return ref;
        }

        TzSingleTon(T&&) = delete;
        TzSingleTon(const TzSingleTon&) = delete;
        TzSingleTon& operator=(const TzSingleTon&) = delete;

    protected:
        TzSingleTon() = default;
        virtual ~TzSingleTon() = default;
    };
} // namespace Basic

#endif // SOURCE_INCLUDE_DESIGNPATTERNTOOLS_BASIC_OPEN_SINGLETON_H_

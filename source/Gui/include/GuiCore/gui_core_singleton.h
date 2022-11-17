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
 * @file gui_core_singleton.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-11-01
 * @date Created: 2022-11-01
 * @date Last modified: 2022-11-01
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_SINGLETON_H_
#define _GUI_CORE_SINGLETON_H_

#include <utility>

#include "core_export.h"

#include <QtCore/qglobal.h>

namespace TzSoft
{
    template <class T>
    class TZ_GUI_CORE_STATIC_EXPORT TSingleTonBase
    {
    public:
        QT_DEPRECATED_X("Use ref")
        static inline T* instance()
        {
            static T* _instance = new T;
            return _instance;
        }

        static T& ref()
        {
            static T instance;
            return instance;
        }

        TzSingleTon(T&&) = delete;
        TzSingleTon(const T&) = delete;
        void& operator=(const T&) = delete;

    protected:
        TzSingleTon() = default;
        virtual ~TzSingleTon() = default;
    };
} // namespace TzSoft

#endif // _GUI_CORE_SINGLETON_H_

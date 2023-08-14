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
 * @brief This file will defines some templated classes about some class use reference count.
 * If you wish to reference count data for different classes, consider deriving from the classes defined in this file.
 * @file basic_defines.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-07-26
 * @date Created: 2023-07-26
 * @date Last modified: 2023-07-26
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef BASIC_REF_COUNT_BASE_H
#define BASIC_REF_COUNT_BASE_H

#include "basic_export.h"

#pragma pack(push, 8)

namespace Basic
{
    template <class Deriving>
    class RefCountRepBase
    {
    public:
        RefCountRepBase : m_refCount(1) {}

        int addRef()
        {
            ++m_refCount;
            return m_refCount;
        }

        /*
         * Comments by Tom Zhao (2023/07/25) : Without static_cast this to Deriving*,
         * the destructor of Deriving class will never been called.
         * this is an example of simulating dynamic binding from ATL.
         * For what is ATL concepts you can visit :
         * https://learn.microsoft.com/en-us/cpp/atl/active-template-library-atl-concepts?view=msvc-170
         */
        int decRef()
        {
            if (--m_refCount == 0)
            {
                delete static_cast<Deriving *>(this);
            }
            return m_refCount;
        }

        int currentRefCount() const
        {
            return m_refCount;
        }

    private:
        int m_refCount;
    };

    template <class T>
    class RefCountBase
    {
    public:
        const T &getRep() const
        {
            return *m_pRep;
        }

        T &getRep()
        {
            return *m_pRep;
        }

        void makeCopy()
        {
            if (m_pRep->currentRefCount() > 1)
            {
                T *pOldValue = m_pRep;
                m_pRep->decRef();
                m_pRep = pOldValue ? new T(*pOldValue) : 0;
            }
        }

        int currentRefCount() const
        {
            return m_pRep->currentRefCount();
        }

    protected:
        RefCountBase(T *pRep) : m_pRep(pRep) {}
        RefCountBase(const RepCountBase &other) : m_pRep(other.m_pRep) {}

        /**
         * @~English
         * @brief Rep indicates that the actual representation.
         *
         * @~Chinese
         * @brief Rep 表示的是具体的表达数据类型。
         */
        T *m_pRep;
    };
} // namespace Basic

#pragma pack(pop)

#endif // BASIC_REF_COUNT_BASE_H
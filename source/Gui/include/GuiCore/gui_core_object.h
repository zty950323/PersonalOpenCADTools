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
* @file gui_core_object.h
* @author Tom Zhao(18872770445@163.com)
* @since 2022-10-25
* @date Created: 2022-10-25
* @date Last modified: 2022-10-25
*
* Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GUI_CORE_OBJECT_H_
#define _GUI_CORE_OBJECT_H_

#include "zsofts_compiler_specific.h"
#include "gui_core_export.h"

#include <QScopedPointer>

namespace TzSoft
{
#define T_DECLARE_PRIVATE(Class) Q_DECLARE_PRIVATE_D(qGetPtrHelper(m_pPrivate), Class)
#define T_DECLARE_PUBLIC(Class) Q_DECLARE_PUBLIC(Class)
#define T_D(Class) Q_D(Class)
#define T_Q(Class) Q_Q(Class)
#define T_DC(Class) Q_D(const Class)
#define T_QC(Class) Q_Q(const Class)
#define T_PRIVATE_SLOT(Func) Q_PRIVATE_SLOT(d_func(), Func)

    class TObjectPrivate;

    class TZ_GUI_CORE_STATIC_EXPORT TObject
    {
    protected:
        TObject(TObject* pParent = nullptr);
        TObject(TObjectPrivate& dPrivate, TObject* pParent = nullptr);
        virtual ~TObject();

        QScopedPointer<TObjectPrivate> m_pPrivate;

        Q_DISABLE_COPY(TObject)
        T_DECLARE_PRIVATE(TObject)
    };
}  // namespace TzSoft

#endif  // _GUI_CORE_OBJECT_H_

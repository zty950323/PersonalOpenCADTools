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
 * @brief This file provides basic error service in Ui projects used.
 * codec.
 * @file gui_core_error_unit.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-10-25
 * @date Created: 2022-10-31
 * @date Last modified: 2022-10-31
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_ERROR_UNITS_H_
#define _GUI_CORE_ERROR_UNITS_H_

#include "zsofts_compiler_specific.h"
#include "core_export.h"

#include <QString>
#include <QDebug>

namespace TzSoft
{
    class TErrorUnit final
    {
    public:
        /*!
         * @brief 默认构造函数
         * @attention 错误代码默认为-1，错误信息默认为空
         */
        TErrorUnit() noexcept
            : m_code(-1), m_msg()
        {
        }

        /*!
         * @brief 拷贝构造函数
         */
        TErrorUnit(const TErrorUnit& other) noexcept
            : m_code(other.m_code), m_msg(other.m_msg)
        {
        }

        /*!
         * @brief 移动构造函数
         * @attention 移动后原对象不可用
         */
        TErrorUnit(TErrorUnit&& other) noexcept
            : m_code(other.m_code), m_msg(std::move(other).m_msg)
        {
        }

        /*!
         * @brief 构造函数
         * @param[in] code 错误代码
         * @param[in] msg  错误信息
         */
        TErrorUnit(qint64 code, const QString& msg) noexcept
            : m_code(code), m_msg(msg)
        {
        }

        /*!
         * @brief 构造函数
         * @param[in] code 错误代码
         * @param[in] msg  错误信息
         * @attention 使用此构造函数后原错误信息不可用
         */
        TErrorUnit(qint64 code, QString&& msg) noexcept
            : m_code(code), m_msg(std::move(msg))
        {
        }

        /*!
         * @brief 重载拷贝赋值运算符
         */
        TErrorUnit& operator=(const TErrorUnit& other)
        {
            m_code = other.m_code;
            m_msg = other.m_msg;
            return *this;
        }

        /*!
         * @brief 重载移动赋值运算符
         * @attention 赋值后原对象不可用
         */
        TErrorUnit& operator=(TErrorUnit&& other)
        {
            m_code = other.m_code;
            m_msg = std::move(other).m_msg;
            return *this;
        }

        /*!
         * @brief 默认析构函数
         */
        ~TErrorUnit() = default;

        /*!
         * @brief 获取错误代码
         * @return 错误代码
         */
        qint64 getErrorCode() const noexcept { return m_code; }

        /*!
         * @brief 设置错误代码
         * @param[in] code 错误代码
         */
        void setErrorCode(qint64 code) & noexcept { m_code = code; }

        /*!
         * @brief 获取错误信息
         * @return 错误信息的const引用
         */
        const QString& getErrorMessage() const& { return m_msg; }

        /*!
         * @brief 获取错误信息
         * @attention 函数返回错误信息后，原信息不可用
         * @return 错误信息
         */
        QString getErrorMessage() const&& { return std::move(m_msg); }

        /*!
         * @brief 设置错误信息
         * @param[in] msg 错误信息
         */
        void setErrorMessage(const QString& msg)& { m_msg = msg; }

        /*!
         * @brief 重载相等运算符
         */
        friend bool operator==(const TErrorUnit& x, const TErrorUnit& y) noexcept { return x.m_code == y.m_code and x.m_msg == y.m_msg; }

        /*!
         * @brief 重载不等运算符
         */
        friend bool operator!=(const TErrorUnit& x, const TErrorUnit& y) noexcept { return !(x == y); }

        /*!
         * @brief 重载输出运算符
         */
        friend QDebug operator<<(QDebug debug, const TErrorUnit& e)
        {
            debug << "Error Code:" << e.m_code << "Message:" << e.m_msg;
            return debug;
        }

    private:
        qint64 m_code;
        QString m_msg;
    };
} // namespace TzSoft

#endif // _GUI_CORE_ERROR_UNITS_H_

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
 * @file gui_core_error_service.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-10-25
 * @date Created: 2022-10-31
 * @date Last modified: 2022-10-31
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_ERROR_SERVICE_H_
#define _GUI_CORE_ERROR_SERVICE_H_

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
         * @brief Ĭ�Ϲ��캯��
         * @attention �������Ĭ��Ϊ-1��������ϢĬ��Ϊ��
         */
        TErrorUnit() noexcept
            : m_code(-1)
            , m_msg()
        {
        }

        /*!
         * @brief �������캯��
         */
        TErrorUnit(const TErrorUnit& other) noexcept
            : m_code(other.m_code)
            , m_msg(other.m_msg)
        {
        }

        /*!
         * @brief �ƶ����캯��
         * @attention �ƶ���ԭ���󲻿���
         */
        TErrorUnit(TErrorUnit&& other) noexcept
            : m_code(other.m_code)
            , m_msg(std::move(other).m_msg)
        {
        }

        /*!
         * @brief ���캯��
         * @param[in] code �������
         * @param[in] msg  ������Ϣ
         */
        TErrorUnit(qint64 code, const QString &msg) noexcept
            : m_code(code)
            , m_msg(msg)
        {
        }

        /*!
         * @brief ���캯��
         * @param[in] code �������
         * @param[in] msg  ������Ϣ
         * @attention ʹ�ô˹��캯����ԭ������Ϣ������
         */
        TErrorUnit(qint64 code, QString &&msg) noexcept
            : m_code(code)
            , m_msg(std::move(msg))
        {
        }

        /*!
         * @brief ���ؿ�����ֵ�����
         */
        TErrorUnit &operator=(const TErrorUnit& other)
        {
            m_code = other.m_code;
            m_msg = other.m_msg;
            return *this;
        }

        /*!
         * @brief �����ƶ���ֵ�����
         * @attention ��ֵ��ԭ���󲻿���
         */
        TErrorUnit& operator=(TErrorUnit&& other)
        {
            m_code = other.m_code;
            m_msg = std::move(other).m_msg;
            return *this;
        }

        /*!
         * @brief Ĭ����������
         */
        ~TErrorUnit() = default;

        /*!
         * @brief ��ȡ�������
         * @return �������
         */
        qint64 getErrorCode() const noexcept { return m_code; }

        /*!
         * @brief ���ô������
         * @param[in] code �������
         */
        void setErrorCode(qint64 code) &noexcept { m_code = code; }

        /*!
         * @brief ��ȡ������Ϣ
         * @return ������Ϣ��const����
         */
        const QString& getErrorMessage() const& { return m_msg; }

        /*!
         * @brief ��ȡ������Ϣ
         * @attention �������ش�����Ϣ��ԭ��Ϣ������
         * @return ������Ϣ
         */
        QString getErrorMessage() const&& { return std::move(m_msg); }

        /*!
         * @brief ���ô�����Ϣ
         * @param[in] msg ������Ϣ
         */
        void setErrorMessage(const QString& msg) & { m_msg = msg; }

        /*!
         * @brief ������������
         */
        friend bool operator==(const TErrorUnit &x, const TErrorUnit &y) noexcept { return x.m_code == y.m_code and x.m_msg == y.m_msg; }

        /*!
         * @brief ���ز��������
         */
        friend bool operator!=(const TErrorUnit &x, const TErrorUnit &y) noexcept { return !(x == y); }

        /*!
         * @brief ������������
         */
        friend QDebug operator<<(QDebug debug, const TErrorUnit &e)
        {
            debug << "Error Code:" << e.m_code << "Message:" << e.m_msg;
            return debug;
        }

    private:
        qint64 m_code;
        QString m_msg;
    };
}  // namespace TzSoft

#endif // _GUI_CORE_ERROR_SERVICE_H_

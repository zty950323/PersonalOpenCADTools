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
 * @file gui_core_expected_tools.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-10-31
 * @date Created: 2022-10-31
 * @date Last modified: 2022-10-31
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_EXPECTED_TOOLS_H_
#define _GUI_CORE_EXPECTED_TOOLS_H_

#include "gui_core_error_unit.h"
#include "core_defines.h"

#include <cassert>
#include <cstdlib>
#include <exception>
#include <initializer_list>
#include <memory>
#include <type_traits>

namespace TzSoft
{
#define likely(x) __builtin_expect(static_cast<long int>((x)), 1)
#define unlikely(x) __builtin_expect(reinterpret_cast<long int>((x)), 0)

#if __cpp_exceptions
#define _TEXPECTED_THROW_OR_ABORT(_EXC) (throw(_EXC))
#else
#define _TEXPECTED_THROW_OR_ABORT(_EXC) (std::abort())
#endif

    template <typename T, typename E>
    class TExpectedTools;

    template <typename E>
    class TUnexpectedTools;

    template <bool v>
    using _bool_constant = std::integral_constant<bool, v>;

    /*!
     * @brief 原位构造标签
     */
    enum class emplace_tag
    {
        USE_EMPLACE /**< 使用原位构造 */
    };

    /*!
     * @brief 从TUnexpectedTools构造标签
     */
    enum class tunexpected_tag
    {
        TUNEXPECTED /**< 从TUnexpectedTools构造 */
    };

    template <typename Type>
    struct remove_cvref
    {
        using type = typename std::remove_cv<typename std::remove_reference<Type>::type>::type;
    };

    template <typename E>
    class bad_result_access;

    template <>
    class bad_result_access<void> : public std::exception
    {
    protected:
        bad_result_access() noexcept {}
        bad_result_access(const bad_result_access &) = default;
        bad_result_access(bad_result_access &&) = default;
        bad_result_access &operator=(const bad_result_access &) = default;
        bad_result_access &operator=(bad_result_access &&) = default;
        ~bad_result_access() = default;

    public:
        const char *what() const noexcept override { return "bad access to TExpectedTools without value"; }
    };

    template <typename E>
    class bad_result_access : public bad_result_access<void>
    {
    public:
        explicit bad_result_access(E _e)
            : m_error(std::move(_e))
        {
        }

        E &error() &noexcept { return m_error; }
        const E &error() const &noexcept { return m_error; }

        E error() &&noexcept { return std::move(m_error); }
        const E error() const &&noexcept { return std::move(m_error); }

    private:
        E m_error;
    };

    template <typename Type, typename... Args>
    auto construct_at(Type *p, Args &&...args) noexcept(noexcept(::new ((void *)0) Type(std::declval<Args>()...)))
        -> decltype(::new ((void *)0) Type(std::declval<Args>()...))
    {
        return ::new ((void *)p) Type(std::forward<Args>(args)...);
    }

    namespace __texpected
    {
        template <typename ObjType>
        void destroy_at_obj(ObjType *p)
        {
            p->~ObjType();
        }

        template <typename ArrType>
        void destroy_at_arr(ArrType *p)
        {
            for (auto &elem : *p)
            {
                destroy_at_obj(std::addressof(elem));
            }
        }
    } // namespace __texpected

    template <typename Type, typename std::enable_if<std::is_array<Type>::value, bool>::type = true>
    void destroy_at(Type *p)
    {
        __texpected::destroy_at_arr(p);
    }

    template <typename Type, typename std::enable_if<!std::is_array<Type>::value, bool>::type = true>
    void destroy_at(Type *p)
    {
        __texpected::destroy_at_obj(p);
    }

    namespace __texpected
    {
        template <typename T>
        struct Guard
        {
            static_assert(std::is_nothrow_move_constructible<T>::value, "type T must bu nothrow_move_constructible");
            explicit Guard(T &_x)
                : m_guarded(std::addressof(_x)), m_tmp(std::move(_x))
            {
                destroy_at(m_guarded);
            }

            ~Guard()
            {
                if (unlikely(m_guarded))
                {
                    construct_at(m_guarded, std::move(m_tmp));
                }
            }

            Guard(const Guard &) = delete;
            Guard &operator=(const Guard &) = delete;

            T &&release() noexcept { return std::move(m_tmp); }

        private:
            T *m_guarded;
            T m_tmp;
        };
    } // namespace __texpected

    namespace __texpected
    {

        template <typename T>
        struct _is_texpected : public std::false_type
        {
        };

        template <typename T, typename E>
        struct _is_texpected<TExpectedTools<T, E>> : public std::true_type
        {
        };

        template <typename T>
        struct _is_tunexpected : public std::false_type
        {
        };

        template <typename T>
        struct _is_tunexpected<TUnexpectedTools<T>> : public std::true_type
        {
        };

        template <typename E>
        constexpr bool _can_be_tunexpected()
        {
            return std::is_object<E>::value and !std::is_array<E>::value and !_is_tunexpected<E>() and !std::is_const<E>::value and
                   !std::is_volatile<E>::value;
        }

        template <typename Tp,
                  typename Up,
                  typename Vp,
                  typename std::enable_if<std::is_nothrow_constructible<Tp, Vp>::value and std::is_nothrow_move_constructible<Tp>::value,
                                          bool>::type = true>
        void reinit(Tp *_newVal, Up *_oldVal, Vp &&_arg) noexcept(std::is_nothrow_constructible<Tp, Vp>::value)
        {
            destroy_at(_oldVal);
            construct_at(_newVal, std::forward<Vp>(_arg));
        }

        template <typename Tp,
                  typename Up,
                  typename Vp,
                  typename std::enable_if<std::is_nothrow_constructible<Tp, Vp>::value and !std::is_nothrow_move_constructible<Tp>::value,
                                          bool>::type = true>
        void reinit(Tp *_newVal, Up *_oldVal, Vp &&_arg) noexcept(std::is_nothrow_constructible<Tp, Vp>::value)
        {
            destroy_at(_oldVal);
            construct_at(_newVal, std::forward<Vp>(_arg));
        }

        template <typename Tp,
                  typename Up,
                  typename Vp,
                  typename std::enable_if<!std::is_nothrow_constructible<Tp, Vp>::value and std::is_nothrow_move_constructible<Tp>::value,
                                          bool>::type = true>
        void reinit(Tp *_newVal, Up *_oldVal, Vp &&_arg) noexcept(std::is_nothrow_constructible<Tp, Vp>::value)
        {
            Tp _tmp(std::forward<Vp>(_arg));
            destroy_at(_oldVal);
            construct_at(_newVal, std::move(_tmp));
        }

        template <
            typename Tp,
            typename Up,
            typename Vp,
            typename std::enable_if<!std::is_nothrow_constructible<Tp, Vp>::value and !std::is_nothrow_move_constructible<Tp>::value,
                                    bool>::type = true>
        void reinit(Tp *_newVal, Up *_oldVal, Vp &&_arg) noexcept(std::is_nothrow_constructible<Tp, Vp>::value)
        {
            __texpected::Guard<Up> _guard(*_oldVal);
            construct_at(_newVal, std::forward<Vp>(_arg));
            _guard.release();
        }

    } // namespace __texpected

    /*!
     * @brief
     * 类模板TzSoft::TUnexpectedTools代表一个TzSoft::::TExpectedTools中存储的不期待的值
     * @tparam E
     * 不期待的值的类型，该类型不能是非对象类型，数组类型，TzSoft::TUnexpectedTools的特化类型或有cv限定符的类型
     */
    template <typename E = TErrorUnit>
    class TUnexpectedTools
    {
        static_assert(__texpected::_can_be_tunexpected<E>(), "can't be tunexpected");

    public:
        /*!
         * @brief TzSoft::TUnexpectedTools的默认拷贝构造函数
         */
        constexpr TUnexpectedTools(const TUnexpectedTools &) = default;

        /*!
         * @brief TzSoft::TUnexpectedTools的默认移动构造函数
         */
        constexpr TUnexpectedTools(TUnexpectedTools &&) = default;

        /*!
         * @brief 使用类型E直接初始化一个TzSoft::TUnexpectedTools对象
         * @tparam Er 错误类型，默认为E
         * @param[in] _e 一个类型为Er的值
         */
        template <typename Er = E,
                  typename std::enable_if<!std::is_same<typename remove_cvref<Er>::type, TUnexpectedTools>::value and
                                              !std::is_same<typename remove_cvref<Er>::type, emplace_tag>::value and
                                              std::is_constructible<E, Er>::value,
                                          bool>::type = true>
        constexpr explicit TUnexpectedTools(Er &&_e) noexcept(std::is_nothrow_constructible<E, Er>::value)
            : m_error(std::forward<Er>(_e))
        {
        }

        /*!
         * @brief
         * 直接从参数构造出一个包含错误类型为E的对象的TzSoft::TUnexpectedTools对象
         * @tparam Args 可变参数模板类型，这里是构造类型为E的对象所需要的参数的类型
         * @param[in] args 构造类型为E的对象用到的参数
         * @attention
         * 为了区分是构造E还是TzSoft::TUnexpectedTools，需要在第一个参数使用emplace_tag进行标识
         */
        template <typename... Args>
        constexpr explicit TUnexpectedTools(emplace_tag, Args &&...args) noexcept(std::is_nothrow_constructible<E, Args...>::value)
            : m_error(std::forward<Args>(args)...)
        {
            static_assert(std::is_constructible<E, Args...>::value, "can't construct E from args.");
        }

        /*!
         * @brief
         * 从参数和初始化列表构造出一个包含错误类型为E的对象的TzSoft::TUnexpectedTools对象
         * @tparam U 初始化列表的模板类型
         * @tparam Args 可变参数模板类型，这里是构造类型为E的对象所需要的参数的类型
         * @param _li 模板类型为U的初始化列表
         * @param[in] args 构造类型为E的对象用到的参数
         * @attention
         * 为了区分是构造E还是TzSoft::TUnexpectedTools，需要在第一个参数使用emplace_tag进行标识
         */
        template <typename U, typename... Args>
        constexpr explicit TUnexpectedTools(emplace_tag, std::initializer_list<U> _li, Args &&...args) noexcept(
            std::is_nothrow_constructible<E, std::initializer_list<U> &, Args...>::value)
            : m_error(_li, std::forward<Args>(args)...)
        {
        }

        /*!
         * @brief TzSoft::TUnexpectedTools的默认拷贝赋值运算符
         */
        TUnexpectedTools &operator=(const TUnexpectedTools &) = default;

        /*!
         * @brief TzSoft::TUnexpectedTools的默认移动赋值运算符
         */
        TUnexpectedTools &operator=(TUnexpectedTools &&) = default;

        /*!
         * @brief 获取TzSoft::TUnexpectedTools持有的不期待值
         * @return 不期待值的const左值引用
         */
        constexpr const E &error() const &noexcept { return m_error; }

        /*!
         * @brief 获取TzSoft::TUnexpectedTools持有的不期待值
         * @return 不期待值的左值引用
         */
        E &error() &noexcept { return m_error; }

        /*!
         * @brief 获取TzSoft::TUnexpectedTools持有的不期待值
         * @attention 获取后原TzSoft::TUnexpectedTools不可用
         * @return 不期待值的const右值引用
         */
        constexpr const E &&error() const &&noexcept { return std::move(m_error); }

        /*!
         * @brief 获取TzSoft::TUnexpectedTools持有的不期待值
         * @attention 获取后原TzSoft::TUnexpectedTools不可用
         * @return 不期待值的右值引用
         */
        E &&error() &&noexcept { return std::move(m_error); }

        /*!
         * @brief 交换两个TzSoft::TUnexpectedTools的值
         * @param[in] _other 另一个模板参数为E的TzSoft::TUnexpectedTools对象
         */
        void swap(TUnexpectedTools &_other)
        {
            using std::swap;
            swap(m_error, _other.m_error);
        }

        /*!
         * @brief 重载相等运算符
         * @tparam Er 另一个TzSoft::TUnexpectedTools的模板类型
         * @param[in] _x 模板参数为E的TzSoft::TUnexpectedTools对象
         * @param[in] _y 模板参数为Er的TzSoft::TUnexpectedTools对象
         */
        template <typename Er>
        friend constexpr bool operator==(const TUnexpectedTools &_x, const TUnexpectedTools<Er> _y)
        {
            return _x.m_error == _y.error();
        }

        /*!
         * @brief 交换两个TzSoft::TUnexpectedTools的值
         */
        friend void swap(TUnexpectedTools &_x, TUnexpectedTools &_y) { _x.swap(_y); }

    private:
        E m_error;
    };

    /*!
     * @brief
     * 模板类TzSoft::TExpectedTools提供存储两个值之一的方式。TzSoft::TExpectedTools的对象要么保有一个期待的T类型值，要么保有一个不期待的E类型值，不会没有值。
     * @tparam T 期待的类型
     * @tparam E 不期待的类型
     */
    template <typename T, typename E = TErrorUnit>
    class TExpectedTools
    {
        template <typename, typename>
        friend class TExpectedTools;
        static_assert(!std::is_reference<T>::value, "type T can't be reference type");
        static_assert(!std::is_function<T>::value, "type T can't be function type");
        static_assert(!std::is_same<typename std::remove_cv<T>::type, tunexpected_tag>::value, "type T can't be tunexpected_tag");
        static_assert(!std::is_same<typename std::remove_cv<T>::type, emplace_tag>::value, "type T can't be emplace_tag");
        static_assert(!__texpected::_is_tunexpected<typename std::remove_cv<T>::type>::value, "type T can't be TUnexpectedTools");
        static_assert(__texpected::_can_be_tunexpected<E>(), "type E can't be tunexpected");

        template <typename U, typename G, typename Unex = TUnexpectedTools<E>>
        static constexpr bool __cons_from_DExpected()
        {
            return std::is_constructible<T, TExpectedTools<U, G> &>::value or std::is_constructible<T, TExpectedTools<U, G>>::value or
                   std::is_constructible<T, const TExpectedTools<U, G>>::value or
                   std::is_constructible<T, const TExpectedTools<U, G> &>::value or std::is_convertible<TExpectedTools<U, G> &, T>::value or
                   std::is_convertible<TExpectedTools<U, G>, T>::value or std::is_convertible<const TExpectedTools<U, G> &, T>::value or
                   std::is_convertible<const TExpectedTools<U, G>, T>::value or std::is_constructible<Unex, TExpectedTools<U, G> &>::value or
                   std::is_constructible<Unex, TExpectedTools<U, G>>::value or
                   std::is_constructible<Unex, const TExpectedTools<U, G> &>::value or
                   std::is_constructible<Unex, const TExpectedTools<U, G>>::value;
        }

        template <typename U, typename G>
        static constexpr bool __explicit_conv()
        {
            return !std::is_convertible<U, T>::value or !std::is_convertible<G, E>::value;
        }

        static constexpr bool des_value()
        {
            return !std::is_trivially_destructible<T>::value or !std::is_trivially_destructible<E>::value;
        }

        template <typename V>
        void assign_val(V &&_v)
        {
            if (m_has_value)
            {
                m_value = std::forward<V>(_v);
            }
            else
            {
                __texpected::reinit(std::addressof(m_value), std::addressof(m_error), std::forward<V>(_v));
                m_has_value = true;
            }
        }

        template <typename V>
        void assign_err(V &&_v)
        {
            if (m_has_value)
            {
                __texpected::reinit(std::addressof(m_error), std::addressof(m_value), std::forward<V>(_v));
                m_has_value = false;
            }
            else
            {
                m_error = std::forward<V>(_v);
            }
        }

        template <typename Ep = E, typename std::enable_if<std::is_nothrow_move_constructible<Ep>::value, bool>::type = true>
        void swap_val_err(TExpectedTools &_other) noexcept(
            std::is_nothrow_move_constructible<Ep>::value and std::is_nothrow_move_constructible<T>::value)
        {
            __texpected::Guard<E> _guard(_other.m_error);
            construct_at(std::addressof(_other.m_value), std::move(m_value));
            _other.m_has_value = true;
            destroy_at(std::addressof(m_value));
            construct_at(std::addressof(m_error), _guard.release());
            m_has_value = false;
        }

        template <typename Ep = E, typename std::enable_if<!std::is_nothrow_move_constructible<Ep>::value, bool>::type = true>
        void swap_val_err(TExpectedTools &_other) noexcept(
            std::is_nothrow_move_constructible<Ep>::value and std::is_nothrow_move_constructible<T>::value)
        {
            __texpected::Guard<T> _guard(_other.m_value);
            construct_at(std::addressof(m_error), std::move(_other.m_error));
            m_has_value = false;
            destroy_at(std::addressof(_other.m_error));
            construct_at(std::addressof(_other.m_value), _guard.release());
            _other.m_has_value = true;
        }

    public:
        using value_type = T;
        using error_type = E;
        using dunexpected_type = TUnexpectedTools<E>;
        template <typename U>
        using rebind = TExpectedTools<U, error_type>;

        /*!
         * @brief TzSoft::TExpectedTools的默认构造函数
         */
        template <typename std::enable_if<std::is_default_constructible<T>::value, bool>::type = true>
        constexpr TExpectedTools() noexcept(std::is_nothrow_default_constructible<T>::value)
            : m_has_value(true), m_value()
        {
        }

        /*!
         * @brief TzSoft::TExpectedTools的默认拷贝构造函数
         */
        TExpectedTools(const TExpectedTools &) = default;

        /*!
         * @brief TzSoft::TExpectedTools的拷贝构造函数
         */
        template <typename std::enable_if<std::is_copy_constructible<T>::value and std::is_copy_constructible<E>::value and
                                              (!std::is_trivially_copy_constructible<T>::value or
                                               !std::is_trivially_copy_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools(const TExpectedTools &_x) noexcept(
            std::is_nothrow_copy_constructible<T>::value and std::is_nothrow_copy_constructible<E>::value)
            : m_has_value(_x.m_has_value), m_invalid()

        {
            if (m_has_value)
                construct_at(std::addressof(m_value), _x.m_value);
            else
                construct_at(std::addressof(m_error), _x.m_error);
        }

        /*!
         * @brief TzSoft::TExpectedTools的默认移动构造函数
         */
        TExpectedTools(TExpectedTools &&) = default;

        /*!
         * @brief TzSoft::TExpectedTools的移动构造函数
         */
        template <typename std::enable_if<std::is_move_constructible<T>::value and std::is_move_constructible<E>::value and
                                              (!std::is_trivially_move_constructible<T>::value or
                                               !std::is_trivially_move_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools(TExpectedTools &&_x) noexcept(
            std::is_nothrow_move_constructible<T>::value and std::is_nothrow_move_constructible<E>::value)
            : m_has_value(_x.m_has_value), m_invalid()
        {
            if (m_has_value)
                construct_at(std::addressof(m_value), std::move(_x).m_value);
            else
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        /*!
         * @brief TzSoft::TExpectedTools的拷贝构造函数
         * @tparam U 另一个TzSoft::TExpectedTools的期待类型
         * @tparam G 另一个TzSoft::TExpectedTools的不期待类型
         * @param[in] _x 模板类型分别为U和G的TzSoft::TExpectedTools对象
         */
        template <
            typename U,
            typename G,
            typename std::enable_if<std::is_constructible<T, const U &>::value and std::is_constructible<E, const G &>::value and
                                        !__cons_from_DExpected<U, G>() and !__explicit_conv<const U &, const G &>(),
                                    bool>::type = true>
        TExpectedTools(const TExpectedTools<U, G> &_x) noexcept(
            std::is_nothrow_constructible<T, const U &>::value and std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(_x.m_has_value), m_invalid()

        {
            if (m_has_value)
                construct_at(std::addressof(m_value), _x.m_value);
            else
                construct_at(std::addressof(m_error), _x.m_error);
        }

        /*!
         * @brief TzSoft::TExpectedTools的拷贝构造函数
         * @tparam U 另一个TzSoft::TExpectedTools的期待类型
         * @tparam G 另一个TzSoft::TExpectedTools的不期待类型
         * @param[in] _x 模板类型分别为U和G的TzSoft::TExpectedTools对象
         * @attention 该拷贝构造函数有explicit标识
         */
        template <
            typename U,
            typename G,
            typename std::enable_if<std::is_constructible<T, const U &>::value and std::is_constructible<E, const G &>::value and
                                        !__cons_from_DExpected<U, G>() and __explicit_conv<const U &, const G &>(),
                                    bool>::type = true>
        explicit TExpectedTools(const TExpectedTools<U, G> &_x) noexcept(
            std::is_nothrow_constructible<T, const U &>::value and std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(_x.m_has_value), m_invalid()
        {
            if (m_has_value)
                construct_at(std::addressof(m_value), _x.m_value);
            else
                construct_at(std::addressof(m_error), _x.m_error);
        }

        /*!
         * @brief TzSoft::TExpectedTools的移动构造函数
         * @tparam U 另一个TzSoft::TExpectedTools的期待类型
         * @tparam G 另一个TzSoft::TExpectedTools的不期待类型
         * @param[in] _x 模板类型分别为U和G的TzSoft::TExpectedTools对象
         * @attention 构造后另一个TzSoft::TExpectedTools不可用
         */
        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_constructible<T, U>::value and std::is_constructible<E, G>::value and
                                              !__cons_from_DExpected<U, G>() and !__explicit_conv<U, G>(),
                                          bool>::type = true>
        TExpectedTools(TExpectedTools<U, G> &&_x) noexcept(
            std::is_nothrow_constructible<T, U>::value and std::is_nothrow_constructible<E, G>::value)
            : m_has_value(_x.m_has_value), m_invalid()
        {
            if (m_has_value)
                construct_at(std::addressof(m_value), std::move(_x).m_value);
            else
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        /*!
         * @brief TzSoft::TExpectedTools的移动构造函数
         * @tparam U 另一个TzSoft::TExpectedTools的期待类型
         * @tparam G 另一个TzSoft::TExpectedTools的不期待类型
         * @param[in] _x 模板类型分别为U和G的TzSoft::TExpectedTools对象
         * @attention 构造后另一个TzSoft::TExpectedTools不可用，该函数有explicit标识
         */
        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_constructible<T, U>::value and std::is_constructible<E, G>::value and
                                              !__cons_from_DExpected<U, G>() and __explicit_conv<U, G>(),
                                          bool>::type = true>
        explicit TExpectedTools(TExpectedTools<U, G> &&_x) noexcept(
            std::is_nothrow_constructible<T, U>::value and std::is_nothrow_constructible<E, G>::value)
            : m_has_value(_x.m_has_value), m_invalid()
        {
            if (m_has_value)
                construct_at(std::addressof(m_value), std::move(_x).m_value);
            else
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的移动构造函数，直接从期待类型构造出TzSoft::TExpectedTools对象
         * @tparam U TzSoft::TExpectedTools的期待类型，默认为类型T
         * @param[in] _v 期待类型为U的对象
         * @attention 构造后原对象不可用，该函数有explicit标识
         */
        template <typename U = T,
                  typename std::enable_if<!std::is_same<typename remove_cvref<U>::type, TExpectedTools>::value and
                                              !std::is_same<typename remove_cvref<U>::type, emplace_tag>::value and
                                              !__texpected::_is_tunexpected<typename remove_cvref<U>::type>::value and
                                              std::is_constructible<T, U>::value and !std::is_convertible<U, T>::value,
                                          bool>::type = true>
        constexpr explicit TExpectedTools(U &&_v) noexcept(std::is_nothrow_constructible<T, U>::value)
            : m_has_value(true), m_value(std::forward<U>(_v))

        {
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的移动构造函数，直接从期待类型构造出TzSoft::TExpectedTools对象
         * @tparam U TzSoft::TExpectedTools的期待类型，默认为类型T
         * @param[in] _v 期待类型为U的对象
         * @attention 构造后原对象不可用
         */
        template <typename U = T,
                  typename std::enable_if<!std::is_same<typename remove_cvref<U>::type, TExpectedTools>::value and
                                              !std::is_same<typename remove_cvref<U>::type, emplace_tag>::value and
                                              !__texpected::_is_tunexpected<typename remove_cvref<U>::type>::value and
                                              std::is_constructible<T, U>::value and std::is_convertible<U, T>::value,
                                          bool>::type = true>
        constexpr TExpectedTools(U &&_v) noexcept(std::is_nothrow_constructible<T, U>::value)
            : m_has_value(true), m_value(std::forward<U>(_v))
        {
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的拷贝构造函数，从TzSoft::TUnexpectedTools构造出TzSoft::TExpectedTools对象
         * @tparam G TzSoft::TExpectedTools的期待类型，默认为类型E
         * @param[in] _u 期待类型为G的TzSoft::TUnexpectedTools对象
         * @attention 该函数有explicit标识
         */
        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and !std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        constexpr explicit TExpectedTools(const TUnexpectedTools<G> &_u) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(false), m_error(_u.error())
        {
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的拷贝构造函数，从TzSoft::TUnexpectedTools构造出TzSoft::TExpectedTools对象
         * @tparam G TzSoft::TExpectedTools的期待类型，默认为类型E
         * @param[in] _u 期待类型为G的TzSoft::TUnexpectedTools对象
         */
        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        constexpr TExpectedTools(const TUnexpectedTools<G> &_u) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(false), m_error(_u.error())
        {
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的移动构造函数，从TzSoft::TUnexpectedTools构造出TzSoft::TExpectedTools对象
         * @tparam G TzSoft::TExpectedTools的期待类型，默认为类型E
         * @param[in] _u 期待类型为G的TzSoft::TUnexpectedTools对象
         * @attention 构造后原对象不可用，该函数有explicit标识
         */
        template <
            typename G = E,
            typename std::enable_if<std::is_constructible<E, G>::value and !std::is_convertible<G, E>::value, bool>::type = true>
        constexpr explicit TExpectedTools(TUnexpectedTools<G> &&_u) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(false), m_error(std::move(_u).error())
        {
        }

        /*!
         * @brief
         * TzSoft::TExpectedTools的移动构造函数，从TzSoft::TUnexpectedTools构造出TzSoft::TExpectedTools对象
         * @tparam G TzSoft::TExpectedTools的期待类型，默认为类型E
         * @param[in] _u 期待类型为G的TzSoft::TUnexpectedTools对象
         * @attention 构造后原对象不可用
         */
        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, G>::value and std::is_convertible<G, E>::value, bool>::type = true>
        constexpr TExpectedTools(TUnexpectedTools<G> &&_u) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(false), m_error(std::move(_u).error())
        {
        }

        /*!
         * @brief TzSoft::TExpectedTools的转发构造函数，从参数直接构造出期待值
         * @tparam Args 构造期待类型T所用到的参数的类型
         * @param[in] args 构造期待类型T所用到的参数
         * @attention
         * 为了区分是构造T还是TzSoft::TExpectedTools，需要在第一个参数使用emplace_tag进行标识
         */
        template <typename... Args>
        constexpr explicit TExpectedTools(emplace_tag, Args &&...args) noexcept(std::is_nothrow_constructible<T, Args...>::value)
            : m_has_value(true), m_value(std::forward<Args>(args)...)

        {
            static_assert(std::is_constructible<T, Args...>::value, "can't construct T from args.");
        }

        /*!
         * @brief TzSoft::TExpectedTools的转发构造函数，从参数直接构造出期待值
         * @tparam U 初始化列表的模板参数
         * @tparam Args 构造期待类型T所用到的参数的类型
         * @param[in] _li  构造期待类型T所用到的初始化列表
         * @param[in] args 构造期待类型T所用到的参数
         * @attention
         * 为了区分是构造T还是TzSoft::TExpectedTools，需要在第一个参数使用emplace_tag进行标识
         */
        template <typename U, typename... Args>
        constexpr explicit TExpectedTools(emplace_tag, std::initializer_list<U> _li, Args &&...args) noexcept(
            std::is_nothrow_constructible<T, std::initializer_list<U> &, Args...>::value)
            : m_has_value(true), m_value(_li, std::forward<Args>(args)...)
        {
            static_assert(std::is_constructible<T, std::initializer_list<U> &, Args...>::value, "can't construct T from args.");
        }

        /*!
         * @brief TzSoft::TExpectedTools的转发构造函数，从参数直接构造出不期待值
         * @tparam Args 构造不期待类型E所用到的参数的类型
         * @param[in] args 构造不期待类型E所用到的参数
         * @attention
         * 为了区分是构造E还是TzSoft::TExpectedTools，需要在第一个参数使用tunexpected_tag进行标识
         */
        template <typename... Args>
        constexpr explicit TExpectedTools(tunexpected_tag, Args &&...args) noexcept(std::is_nothrow_constructible<E, Args...>::value)
            : m_has_value(false), m_error(std::forward<Args>(args)...)

        {
            static_assert(std::is_constructible<E, Args...>::value, "can't construct E from args.");
        }

        /*!
         * @brief TzSoft::TExpectedTools的转发构造函数，从参数直接构造出不期待值
         * @tparam U 初始化列表的模板参数
         * @tparam Args 构造不期待类型E所用到的参数的类型
         * @param[in] _li  构造不期待类型E所用到的初始化列表
         * @param[in] args 构造不期待类型E所用到的参数
         * @attention
         * 为了区分是构造E还是TzSoft::TExpectedTools，需要在第一个参数使用tunexpected_tag进行标识
         */
        template <typename U, typename... Args>
        constexpr explicit TExpectedTools(tunexpected_tag, std::initializer_list<U> _li, Args &&...args) noexcept(
            std::is_nothrow_constructible<E, std::initializer_list<U> &, Args...>::value)
            : m_has_value(false), m_error(_li, std::forward<Args>(args)...)
        {
            static_assert(std::is_constructible<E, std::initializer_list<U> &, Args...>::value, "can't construct E from args.");
        }

        /*!
         * @brief TzSoft::TExpectedTools的析构函数
         */
        ~TExpectedTools()
        {
            if (des_value())
            {
                if (m_has_value)
                {
                    destroy_at(std::addressof(m_value));
                }
                else
                {
                    destroy_at(std::addressof(m_error));
                }
            }
        }

        /*!
         * @brief TzSoft::TExpectedTools的默认拷贝赋值运算符
         */
        TExpectedTools &operator=(const TExpectedTools &) = delete;

        /*!
         * @brief TzSoft::TExpectedTools的拷贝赋值运算符
         * @param[in] _x 同类型的TzSoft::TExpectedTools对象
         */
        template <typename std::enable_if<std::is_copy_assignable<T>::value and std::is_copy_constructible<T>::value and
                                              std::is_copy_assignable<E>::value and std::is_copy_constructible<E>::value and
                                              (std::is_nothrow_move_constructible<T>::value or
                                               std::is_nothrow_move_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools &operator=(const TExpectedTools &_x) noexcept(
            std::is_nothrow_copy_constructible<T>::value and std::is_nothrow_copy_constructible<E>::value
                and std::is_nothrow_copy_assignable<T>::value and std::is_nothrow_copy_assignable<E>::value)
        {
            if (_x.m_has_value)
                this->assign_val(_x.m_value);
            else
                this->assign_err(_x.m_error);
            return *this;
        }

        /*!
         * @brief TzSoft::TExpectedTools的移动赋值运算符
         * @param[in] _x 同类型的TzSoft::TExpectedTools对象
         * @attention 赋值后原对象不可用
         */
        template <typename std::enable_if<std::is_move_assignable<T>::value and std::is_move_constructible<T>::value and
                                              std::is_move_assignable<E>::value and std::is_move_constructible<E>::value and
                                              (std::is_nothrow_move_constructible<T>::value or
                                               std::is_nothrow_move_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools &operator=(TExpectedTools &&_x) noexcept(
            std::is_nothrow_move_constructible<T>::value and std::is_nothrow_move_constructible<E>::value
                and std::is_nothrow_move_assignable<T>::value and std::is_nothrow_move_assignable<E>::value)
        {
            if (_x.m_has_value)
                assign_val(std::move(_x.m_value));
            else
                assign_err(std::move(_x.m_error));
            return *this;
        }

        /*!
         * @brief TzSoft::TExpectedTools的转发赋值运算符
         * @tparam U 期待类型，默认为T
         * @param[in] _v 期待类型U的对象
         */
        template <
            typename U = T,
            typename std::enable_if<!std::is_same<TExpectedTools, typename remove_cvref<U>::type>::value and
                                        !__texpected::_is_tunexpected<typename remove_cvref<U>::type>::value and
                                        std::is_constructible<T, U>::value and std::is_assignable<T &, U>::value and
                                        (std::is_nothrow_constructible<T, U>::value or std::is_nothrow_move_constructible<T>::value or
                                         std::is_nothrow_move_constructible<E>::value),
                                    bool>::type = true>
        TExpectedTools &operator=(U &&_v)
        {
            assign_val(std::forward<U>(_v));
            return *this;
        }

        /*!
         * @brief TzSoft::TExpectedTools的拷贝赋值运算符
         * @tparam G 不期待类型
         * @param[in] _e 模板类型为G的TzSoft::TUnexpectedTools对象
         */
        template <typename G,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and std::is_assignable<E &, const G &>::value and
                                              (std::is_nothrow_constructible<E, const G &>::value or
                                               std::is_nothrow_move_constructible<T>::value or std::is_move_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools &operator=(const TUnexpectedTools<G> &_e)
        {
            assign_err(_e.error());
            return *this;
        }

        /*!
         * @brief TzSoft::TExpectedTools的移动赋值运算符
         * @tparam G 不期待类型
         * @param[in] _e 模板类型为G的TzSoft::TUnexpectedTools对象
         * @attention 赋值后原对象不可用
         */
        template <typename G,
                  typename std::enable_if<std::is_constructible<E, G>::value and std::is_assignable<E &, G>::value and
                                              (std::is_nothrow_constructible<E, G>::value or
                                               std::is_nothrow_move_constructible<T>::value or std::is_move_constructible<E>::value),
                                          bool>::type = true>
        TExpectedTools &operator=(TUnexpectedTools<G> &&_e)
        {
            assign_err(std::move(_e).error());
            return *this;
        }

        /*!
         * @brief 从参数直接转发构造期待值
         * @tparam Args 构造期待值所用到的参数的类型
         * @param[in] args 构造期待值所用到的参数
         * @return 返回构造好的期待值的引用
         */
        template <typename... Args>
        T &emplace(Args &&...args) noexcept
        {
            static_assert(std::is_nothrow_constructible<T, Args...>::value, "type T should have nothrow_constructible");
            if (m_has_value)
                destroy_at(std::addressof(m_value));
            else
            {
                destroy_at(std::addressof(m_error));
                m_has_value = true;
            }
            construct_at(std::addressof(m_value), std::forward<Args>(args)...);
            return m_value;
        }

        /*!
         * @brief 从参数直接转发构造期待值
         * @tparam U 初始化列表的模板参数
         * @tparam Args 构造期待值所用到的参数的类型
         * @param[in] args 构造期待值所用到的参数
         * @param[in] li 构造期待值所用到的参数化列表
         * @return 返回构造好的期待值的引用
         */
        template <typename U, typename... Args>
        T &emplace(std::initializer_list<U> li, Args &&...args) noexcept
        {
            static_assert(std::is_nothrow_constructible<T, std::initializer_list<U> &, Args...>::value,
                          "type T should have a noexcept constructor");
            if (m_has_value)
                destroy_at(std::addressof(m_value));
            else
            {
                destroy_at(std::addressof(m_error));
            }
            construct_at(std::addressof(m_value), li, std::forward<Args>(args)...);
            return m_value;
        }

        // TODO : 需要swap吗？
        /*!
         * @brief 交换两个TzSoft::TExpectedTools的值
         * @param[in] _x 另一个TzSoft::TExpectedTools对象
         */
        template <typename std::enable_if<std::is_move_constructible<T>::value and std::is_move_constructible<E>::value and
                                              (std::is_nothrow_move_constructible<T>::value or
                                               std::is_nothrow_move_constructible<E>::value),
                                          bool>::type = true>
        void
        swap(TExpectedTools &_x) noexcept(std::is_nothrow_move_constructible<T>::value and std::is_nothrow_move_constructible<E>::value)
        {
            if (m_has_value)
            {
                if (_x.m_has_value)
                {
                    using std::swap;
                    swap(m_value, _x.m_value);
                }
                else
                {
                    this->swap_val_err(_x);
                }
            }
            else
            {
                if (_x.m_has_value)
                    _x.swap_val_err(*this);
                else
                {
                    using std::swap;
                    swap(m_error, _x.m_error);
                }
            }
        }

        /*!
         * @brief 重载箭头运算符
         * @return 一个指向期待值的const指针
         */
        const T *operator->() const noexcept
        {
            assert(m_has_value);
            return std::addressof(m_value);
        }

        /*!
         * @brief 重载箭头运算符
         * @return 一个指向期待值的指针
         */
        T *operator->() noexcept
        {
            assert(m_has_value);
            return std::addressof(m_value);
        }

        /*!
         * @brief 重载解引用运算符
         * @return 一个期待值的const左值引用
         */
        const T &operator*() const &noexcept
        {
            assert(m_has_value);
            return m_value;
        }

        /*!
         * @brief 重载解引用运算符
         * @return 一个期待值的左值引用
         */
        T &operator*() &noexcept
        {
            assert(m_has_value);
            return m_value;
        }

        /*!
         * @brief 重载解引用运算符
         * @return 一个期待值的const右值引用
         */
        const T &&operator*() const &&noexcept
        {
            assert(m_has_value);
            return std::move(m_value);
        }

        /*!
         * @brief 重载解引用运算符
         * @return 一个期待值的右值引用
         */
        T &&operator*() &&noexcept
        {
            assert(m_has_value);
            return std::move(m_value);
        }

        /*!
         * @brief bool转换函数
         * @return 表示TzSoft::TExpectedTools是否有值的bool值
         */
        constexpr explicit operator bool() const noexcept { return m_has_value; }

        /*!
         * @brief 判断TzSoft::TExpectedTools是否有值
         * @return 表示是否有值的bool值
         */
        constexpr bool hasValue() const noexcept { return m_has_value; }

        /*!
         * @brief 获取TzSoft::TExpectedTools的期待值
         * @return 期待值的const左值引用
         */
        const T &value() const &
        {
            if (likely(m_has_value))
            {
                return m_value;
            }
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(m_error));
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的期待值
         * @return 期待值的左值引用
         */
        T &value() &
        {
            if (likely(m_has_value))
            {
                return m_value;
            }
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(m_error));
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的期待值
         * @return 期待值的const右值引用
         * @attention 调用后期待值不可用
         */
        const T &&value() const &&
        {
            if (likely(m_has_value))
            {
                return std::move(m_value);
            }
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(m_error));
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的期待值
         * @return 期待值的右值引用
         * @attention 调用后期待值不可用
         */
        T &&value() &&
        {
            if (likely(m_has_value))
            {
                return std::move(m_value);
            }
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(m_error));
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的不期待值
         * @return 不期待值的const左值引用
         */
        const E &error() const &noexcept
        {
            assert(!m_has_value);
            return m_error;
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的不期待值
         * @return 不期待值的左值引用
         */
        E &error() &noexcept
        {
            assert(!m_has_value);
            return m_error;
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的不期待值
         * @return 不期待值的const右值引用
         * @attention 调用后不期待值不可用
         */
        const E &&error() const &&noexcept
        {
            assert(!m_has_value);
            return std::move(m_error);
        }

        /*!
         * @brief 获取TzSoft::TExpectedTools的不期待值
         * @return 不期待值的右值引用
         * @attention 调用后不期待值不可用
         */
        E &&error() &&noexcept
        {
            assert(!m_has_value);
            return std::move(m_error);
        }

        // TODO : 因为无法确定U转T时是否会抛出异常，所以都按抛出异常来
        /*!
         * @brief 如果有期待值返回期待值，否则返回传入的默认值
         * @tparam U 期待值的类型
         * @param[in] _v 默认的期待值
         * @return 期待值
         */
        template <typename U>
        T value_or(U &&_v) const &
        {
            static_assert(std::is_copy_constructible<T>::value, "type T should have an copy constructor.");
            static_assert(std::is_convertible<U, T>::value, "type U must can be converted to T.");
            if (m_has_value)
                return m_value;
            return static_cast<T>(std::forward<U>(_v));
        }

        /*!
         * @brief 如果有期待值返回期待值，否则返回传入的默认值
         * @tparam U 期待值的类型
         * @param[in] _v 默认的期待值
         * @return 期待值
         * @attention 如果由期待值，调用后原期待值不可用，同时类型U要可以转换成类型T
         */
        template <typename U>
        T value_or(U &&_v) &&
        {
            static_assert(std::is_move_constructible<T>::value, "type T must bu copy_constructible.");
            static_assert(std::is_convertible<U, T>::value, "type U must can be converted to T.");
            if (m_has_value)
                return std::move(m_value);
            return static_cast<T>(std::forward<U>(_v));
        }

        /*!
         *@brief 重载相等运算符
         */
        template <typename U, typename E2, typename std::enable_if<!std::is_void<U>::value, bool>::type = true>
        friend bool
        operator==(const TExpectedTools &_x,
                   const TExpectedTools<U, E2> &_y) noexcept(noexcept(bool(*_x == *_y)) and noexcept(bool(_x.error() == _y.error())))
        {
            if (_x.hasValue())
                return _y.hasValue() and bool(*_x == *_y);
            else
                return !_y.hasValue() and bool(_x.error() == _x.error());
        }

        /*!
         *@brief 重载相等运算符
         */
        template <typename U>
        friend constexpr bool operator==(const TExpectedTools &_x, const U &_v) noexcept(noexcept(bool(*_x == _v)))
        {
            return _x.hasValue() && bool(*_x == _v);
        }

        /*!
         *@brief 重载相等运算符
         */
        template <typename E2>
        friend constexpr bool operator==(const TExpectedTools &_x,
                                         const TUnexpectedTools<E2> &_e) noexcept(noexcept(bool(_x.error() == _e.error())))
        {
            return !_x.hasValue() && bool(_x.error() == _e.error());
        }

        /*!
         *@brief 交换两个TzSoft::TExpectedTools中的值
         */
        friend void swap(TExpectedTools &_x, TExpectedTools &_y) noexcept(noexcept(_x.swap(_y))) { _x.swap(_y); }

    private:
        bool m_has_value;
        union
        {
            struct
            {
            } m_invalid;
            T m_value;
            E m_error;
        };
    };

    /*!
     * @brief 对于TzSoft::TExpectedTools的void偏特化，其他函数参考原模板类
     * @tparam E 不期待值的类型
     */
    template <typename E>
    class TExpectedTools<void, E>
    {
        static_assert(__texpected::_can_be_tunexpected<E>(), "type E can't be TUnexpectedTools.");
        static constexpr bool des_value() { return !std::is_trivially_destructible<E>::value; }

        template <typename, typename>
        friend class TExpectedTools;

        template <typename U, typename G, typename Unex = TUnexpectedTools<E>>
        static constexpr bool __cons_from_DExpected()
        {
            return std::is_constructible<Unex, TExpectedTools<U, G> &>::value and std::is_constructible<Unex, TExpectedTools<U, G>>::value and
                   std::is_constructible<Unex, const TExpectedTools<U, G> &>::value and
                   std::is_constructible<Unex, const TExpectedTools<U, G>>::value;
        }

        template <typename V>
        void assign_err(V &&_v)
        {
            if (m_has_value)
            {
                construct_at(std::addressof(m_error), std::forward<V>(_v));
                m_has_value = false;
            }
            else
            {
                m_error = std::forward<V>(_v);
            }
        }

    public:
        using value_type = void;
        using error_type = E;
        using dunexpected_type = TUnexpectedTools<E>;
        template <typename U>
        using rebind = TExpectedTools<U, error_type>;

        constexpr TExpectedTools() noexcept
            : m_has_value(true), m_void()
        {
        }

        TExpectedTools(const TExpectedTools &) = default;

        template <typename std::enable_if<std::is_copy_constructible<E>::value and !std::is_trivially_copy_constructible<E>::value,
                                          bool>::type = true>
        TExpectedTools(const TExpectedTools &_x) noexcept(std::is_nothrow_copy_constructible<E>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), _x.m_error);
        }

        TExpectedTools(TExpectedTools &&) = default;

        template <typename std::enable_if<std::is_move_constructible<E>::value and !std::is_trivially_move_constructible<E>::value,
                                          bool>::type = true>
        TExpectedTools(TExpectedTools &&_x) noexcept(std::is_nothrow_move_constructible<E>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_void<U>::value and std::is_constructible<E, const G &>::value and
                                              !__cons_from_DExpected<U, G>() and !std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        explicit TExpectedTools(const TExpectedTools<U, G> &_x) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), _x.m_error);
        }

        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_void<U>::value and std::is_constructible<E, const G &>::value and
                                              !__cons_from_DExpected<U, G>() and std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        TExpectedTools(const TExpectedTools<U, G> &_x) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), _x.m_error);
        }

        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_void<U>::value and std::is_constructible<E, G>::value and
                                              __cons_from_DExpected<U, G>() and !std::is_convertible<G, E>::value,
                                          bool>::type = true>
        explicit TExpectedTools(TExpectedTools<U, G> &&_x) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        template <typename U,
                  typename G,
                  typename std::enable_if<std::is_void<U>::value and std::is_constructible<E, G>::value and
                                              __cons_from_DExpected<U, G>() and std::is_convertible<G, E>::value,
                                          bool>::type = true>
        TExpectedTools(TExpectedTools<U, G> &&_x) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(_x.m_has_value), m_void()
        {
            if (!m_has_value)
                construct_at(std::addressof(m_error), std::move(_x).m_error);
        }

        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and !std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        constexpr explicit TExpectedTools(const TUnexpectedTools<G> &_u) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(false), m_error(_u.error())
        {
        }

        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and std::is_convertible<const G &, E>::value,
                                          bool>::type = true>
        constexpr TExpectedTools(const TUnexpectedTools<G> &_u) noexcept(std::is_nothrow_constructible<E, const G &>::value)
            : m_has_value(false), m_error(_u.error())
        {
        }

        template <
            typename G = E,
            typename std::enable_if<std::is_constructible<E, G>::value and !std::is_convertible<G, E>::value, bool>::type = true>
        constexpr explicit TExpectedTools(TUnexpectedTools<G> &&_u) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(false), m_error(std::move(_u).error())
        {
        }

        template <typename G = E,
                  typename std::enable_if<std::is_constructible<E, G>::value and std::is_convertible<G, E>::value, bool>::type = true>
        constexpr TExpectedTools(TUnexpectedTools<G> &&_u) noexcept(std::is_nothrow_constructible<E, G>::value)
            : m_has_value(false), m_error(std::move(_u).error())
        {
        }

        template <typename... Args>
        constexpr explicit TExpectedTools(emplace_tag) noexcept
            : TExpectedTools()
        {
        }

        template <typename... Args>
        constexpr explicit TExpectedTools(tunexpected_tag, Args &&...args) noexcept(std::is_nothrow_constructible<E, Args...>::value)
            : m_has_value(false), m_error(std::forward<Args>(args)...)
        {
            static_assert(std::is_constructible<E, Args...>::value, "type E can't construct from args");
        }

        template <typename U, typename... Args>
        constexpr explicit TExpectedTools(tunexpected_tag,
                                          std::initializer_list<U> _li,
                                          Args &&...args) noexcept(std::is_nothrow_constructible<E, Args...>::value)
            : m_has_value(false), m_error(_li, std::forward<Args>(args)...)
        {
            static_assert(std::is_constructible<E, std::initializer_list<U> &, Args...>::value, "type E can't construct from args");
        }

        ~TExpectedTools()
        {
            if (des_value() and !m_has_value)
            {
                destroy_at(std::addressof(m_error));
            }
        }

        TExpectedTools &operator=(const TExpectedTools &) = delete;

        template <
            typename std::enable_if<std::is_copy_constructible<E>::value and std::is_copy_assignable<E>::value, bool>::type = true>
        TExpectedTools &operator=(const TExpectedTools &_x) noexcept(
            std::is_nothrow_copy_constructible<E>::value and std::is_nothrow_copy_assignable<E>::value)
        {
            if (_x.m_has_value)
                emplace();
            else
                assign_err(_x.m_error);
            return *this;
        }

        template <
            typename std::enable_if<std::is_move_constructible<E>::value and std::is_move_assignable<E>::value, bool>::type = true>
        TExpectedTools &
        operator=(TExpectedTools &&_x) noexcept(std::is_nothrow_move_constructible<E>::value and std::is_nothrow_move_assignable<E>::value)
        {
            if (_x.m_has_value)
                emplace();
            else
                assign_err(std::move(_x.m_error));
            return *this;
        }

        template <typename G,
                  typename std::enable_if<std::is_constructible<E, const G &>::value and std::is_assignable<E &, const G &>::value,
                                          bool>::type = true>
        TExpectedTools &operator=(const TUnexpectedTools<G> &_e)
        {
            assign_err(_e.error());
            return *this;
        }

        template <
            typename G,
            typename std::enable_if<std::is_constructible<E, G>::value and std::is_assignable<E &, G>::value, bool>::type = true>
        TExpectedTools &operator=(TUnexpectedTools<G> &&_e)
        {
            assign_err(std::move(_e.error()));
            return *this;
        }

        void emplace() noexcept
        {
            if (!m_has_value)
            {
                destroy_at(std::addressof(m_error));
                m_has_value = true;
            }
        }

        template <typename std::enable_if<std::is_move_constructible<E>::value, bool>::type = true>
        void swap(TExpectedTools &_x) noexcept(std::is_nothrow_move_constructible<E>::value)
        {
            if (m_has_value)
            {
                if (!_x.m_has_value)
                {
                    construct_at(std::addressof(m_error), std::move(_x.m_error));
                    destroy_at(std::addressof(_x.m_error));
                    m_has_value = false;
                    _x.m_has_value = true;
                }
            }
            else
            {
                if (_x.m_has_value)
                {
                    construct_at(std::addressof(_x.m_error), std::move(m_error));
                    destroy_at(std::addressof(m_error));
                    m_has_value = true;
                    _x.m_has_value = false;
                }
                else
                {
                    using std::swap;
                    swap(m_error, _x.m_error);
                }
            }
        }

        constexpr explicit operator bool() const noexcept { return m_has_value; }

        constexpr bool hasValue() const noexcept { return m_has_value; }

        void operator*() const noexcept { assert(m_has_value); }

        void value() const &
        {
            if (likely(m_has_value))
                return;
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(m_error));
        }

        void value() &&
        {
            if (likely(m_has_value))
                return;
            _TEXPECTED_THROW_OR_ABORT(bad_result_access<E>(std::move(m_error)));
        }

        const E &error() const &noexcept
        {
            assert(!m_has_value);
            return m_error;
        }

        E &error() &noexcept
        {
            assert(!m_has_value);
            return m_error;
        }

        const E &&error() const &&noexcept
        {
            assert(!m_has_value);
            return std::move(m_error);
        }

        E &&error() &&noexcept
        {
            assert(!m_has_value);
            return std::move(m_error);
        }

        template <typename U, typename E2, typename std::enable_if<std::is_void<U>::value, bool>::type = true>
        friend bool operator==(const TExpectedTools &_x, const TExpectedTools<U, E2> &_y) noexcept(noexcept(bool(_x.error() == _y.error())))
        {
            if (_x.hasValue())
                return _y.hasValue();
            else
                return !_y.hasValue() and bool(_x.error() == _y.error());
        }

        template <typename E2>
        friend bool operator==(const TExpectedTools &_x, const TUnexpectedTools<E2> &_e) noexcept(noexcept(bool(_x.error() == _e.error())))
        {
            return !_x.hasValue() && bool(_x.error() == _e.error());
        }

        // TODO : 可能没有swap
        friend void swap(TExpectedTools &_x, TExpectedTools &_y) noexcept(noexcept(_x.swap(_y))) { _x.swap(_y); }

    private:
        bool m_has_value;
        union
        {
            struct
            {
            } m_void;
            E m_error;
        };
    };
} // namespace TzSoft

#endif // _GUI_CORE_ERROR_UNITS_H_

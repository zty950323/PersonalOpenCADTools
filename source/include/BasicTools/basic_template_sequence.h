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
 * @brief This file provides a series of definitions of the expansion capabilities of the sequence parameters of the template.
 * @file basic_template_sequence.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2024-01-08
 * @date Created: 2024-01-08
 * @date Last modified: 2024-01-08
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef BASIC_TEMPLATE_SEQUENCE_H
#define BASIC_TEMPLATE_SEQUENCE_H

namespace Basic
{
    template <typename T, T... indices>
    struct IntegerSequence
    {
        using value_type = T;
        static constexpr size_t size() noexcept
        {
            return sizeof...(indices);
        }

        T &operator[](size_t index)
        {
            return get(index);
        }

        const T &operator[](size_t index) const
        {
            return get(index);
        }

        T get(std::size_t index) const
        {
            return Basic::IntegerSequence<T, indices...>::get(index);
        }
    };

    template <size_t... indices>
    using IndexSequence = IntegerSequence<size_t, indices...>;

    namespace SequencePrivate
    {
        template <typename T, T... indices, T... indicesInSeq>
        IntegerSequence<T, indicesInSeq..., indices...> concat(IntegerSequence<T, indices...>, IntegerSequence<T, indicesInSeq...>);

        template <typename T, size_t n>
        struct MakeIntegerSequenceImp
        {
            using Type = decltype(concat<T, static_cast<T>(n - 2), static_cast<T>(n - 1)>(typename MakeIntegerSequenceImp<T, n - 2>::Type{}));
        };

        template <typename T>
        struct MakeIntegerSequenceImp<T, 0>
        {
            using Type = IntegerSequence<T>;
        };

        template <typename T>
        struct MakeIntegerSequenceImp<T, 1>
        {
            using Type = IntegerSequence<T, 0>;
        };

        template <typename T>
        struct MakeIntegerSequenceImp<T, 2>
        {
            using Type = IntegerSequence<T, 0, 1>;
        };

        template <typename T>
        struct MakeIntegerSequenceImp<T, 3>
        {
            using Type = IntegerSequence<T, 0, 1, 2>;
        };

        // In the case of demand scenarios in the future, we can define more sequence representations.
    } // namespace SequencePrivate

    template <typename T, T n>
    using MakeIntegerSequence = typename SequencePrivate::MakeIntegerSequenceImp<T, n>::Type;

    template <size_t n>
    using MakeIndexSequence = MakeIntegerSequence<size_t, n>;

    template <typename... Ts>
    using IndexSequenceFor = MakeIndexSequence<sizeof...(Ts)>;
} // namespace Basic

#endif // BASIC_TEMPLATE_SEQUENCE_H

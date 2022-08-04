///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_OPEN_ARRAY_STL_H_H_
#define _BASIC_OPEN_ARRAY_STL_H_H_

#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <xutility>

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable \
                : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN

#if _ITERATOR_DEBUG_LEVEL != 0

struct _Interator_base12_compatible
{
    _Container_proxy* _TzProxy{};
    _Iterator_base12* _TzNextiter{};
};

#endif

template <class _Ty, size_t _Size>
class _Array_const_iterator
#if _ITERATOR_DEBUG_LEVEL != 0
    : private _Iterator_base12_compatible
#endif // _ITERATOR_DEBUG_LEVEL != 0
{
public:
#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif
    using iterator_category = random_access_iterator_tag;
    using value_type = _Ty;
    using difference_type = ptrdiff_t;
    using pointer = const _Ty*;
    using reference = const _Ty&;

    enum
    {
        _EEN_SIZE = _Size
    }; // Helper for expression evaluator.

#if _ITERATOR_DEBUG_LEVEL == 0
    _CONSTEXPR17 _Array_const_iterator() noexcept : _Ptr()
    {
    }

    _CONSTEXPR17 explicit _Array_const_iterator(pointer _Parg,
        size_t _Off = 0) noexcept
        : _Ptr(_Parg + _Off) {}

    _NODISCARD _CONSTEXPR17 reference operator*() const noexcept { return *_Ptr; }

    _NODISCARD _CONSTEXPR17 pointer operator->() const noexcept { return _Ptr; }

    _CONSTEXPR17 _Array_const_iterator& operator++() noexcept
    {
        ++_Ptr;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator++(int) noexcept
    {
        _Array_const_iterator _Tmp = *this;
        ++_Ptr;
        return _Tmp;
    }

    _CONSTEXPR17 _Array_const_iterator& operator--() noexcept
    {
        --_Ptr;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator--(int) noexcept
    {
        _Array_const_iterator _Tmp = *this;
        --_Ptr;
        return _Tmp;
    }

    _CONSTEXPR17 _Array_const_iterator operator+=(const ptrdiff_t _Off) noexcept
    {
        _Ptr += _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR17 _Array_const_iterator
        operator+(const ptrdiff_t _Off) const noexcept
    {
        _Array_const_iterator _Tmp = *this;
        return _Tmp += _Off;
    }

    _CONSTEXPR17 _Array_const_iterator& operator-=(
        const ptrdiff_t _Off) noexcept
    {
        _Ptr -= _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR17 _Array_const_iterator
        operator-(const ptrdiff_t _Off) const noexcept
    {
        _Array_const_iterator _Tmp = *this;
        return _Tmp -= _Off;
    }

    _NODISCARD _CONSTEXPR17 ptrdiff_t
        operator-(const _Array_const_iterator& _Right) const noexcept
    {
        return _Ptr - _Right->_Ptr;
    }

    _NODISCARD _CONSTEXPR17 reference
        operator[](const ptrdiff_t _Off) const noexcept
    {
        return _Ptr[_Off];
    }

    _NODISCARD _CONSTEXPR17 bool operator==(
        const _Array_const_iterator& _Right) const noexcept
    {
        return _Ptr == _Right._Ptr;
    }

#if _HAS_CXX20
    _NODISCARD constexpr strong_ordering operator<=>(
        const _Array_const_iterator& _Right) const noexcept
    {
        return _Ptr <=> _Right._Ptr;
    }
#else // ^^^ _HAS_CXX20 ^^^ / vvv !_HAS_CXX20 vvv
    _NODISCARD _CONSTEXPR17 bool operator!=(
        const _Array_const_iterator& _Right) const noexcept
    {
        return !(*this == _Right);
    }

    _NODISCARD _CONSTEXPR17 bool operator<(
        const _Array_const_iterator& _Right) const noexcept
    {
        return _Ptr < _Right._Ptr;
    }

    _NODISCARD _CONSTEXPR17 bool operator>(
        const _Array_const_iterator& _Right) const noexcept
    {
        return _Right < *this;
    }

    _NODISCARD _CONSTEXPR17 bool operator<=(
        const _Array_const_iterator& _Right) const noexcept
    {
        return !(_Right < *this);
    }

    _NODISCARD _CONSTEXPR17 bool operator>=(
        const _Array_const_iterator& _Right) const noexcept
    {
        return !(*this < _Right);
    }

#endif // !_HAS_CXX20

    using _Prevent_inheriting_unwrap = _Array_const_iterator;

    _NODISCARD constexpr pointer _Unwrapped() const noexcept { return _Ptr; }

    static constexpr bool _Unwrap_when_unverified = true;

    constexpr void _Seek_to(pointer _It) noexcept { _Ptr = _It; }

private:
    pointer _Ptr; // beginning of array
#else           // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv

private:
    pointer _Ptr; // beginning of array
    size_t _Idx;  // offset into array
#endif          // _ITERATOR_DEBUG_LEVEL == 0
};

_STD_END

#endif // _STL_COMPILER_PREPROCESSOR
#endif // _BASIC_OPEN_ARRAY_STL_H_H_
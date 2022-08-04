///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_OPEN_BIT_FLAGS_H_H_
#define _BASIC_OPEN_BIT_FLAGS_H_H_

#pragma pack(push, 8)

/**
 * @ingroup utility
 * @~English
 * @brief The class is used to encapsulate the bit operation.
 *
 * @~Chinese
 * @brief 用以包装位操作的类。
 */
template <typename BITDATA>
class BitFlags
{
private:
    BITDATA m_flags;

public:
    /**
     * @~English
     * @brief Constructor.
     *
     * @~Chinese
     * @brief 构造函数。
     */
    inline BitFlags(void);

    /**
     * @~English
     * @brief Constructor.
     *
     * @param BITDATA    bitData [in]    Initial value.
     *
     * @~Chinese
     * @brief 构造函数。
     *
     * @param BITDATA    bitData [in]    初始值.
     */
    inline BitFlags(BITDATA bitData);

public:
    /**
     * @~English
     * @brief set bit with the specified bit.
     *
     * @param BITDATA    bit    specified bit.
     * @param bool    bSet identify whether it should be set.
     *
     * @~Chinese
     * @brief 设置指定的bit位， 参数为True位设置为1，否则清零。
     *
     * @param BITDATA    bit 用于设置的参数。
     * @param bool    bSet 指示是设置还是清除bit位。
     */
    inline void setBit(BITDATA bit, bool bSet = TRUE);

    /**
     * @~English
     * @brief set all the bits.
     *
     * @param bool    bSet identify whether it should be set.
     *
     * @~Chinese
     * @brief 设置所有的bit位， 参数为True所有位设置为1，否则全部清零。
     *
     * @param bool    bSet 指示是设置还是清除bit位。
     */
    inline void setAllBit(bool bSet = TRUE);

    /**
     * @~English
     * @brief used to judge if is has the bits.
     *
     * @param BITDATA    bit    the condition bit.
     * @retval TRUE     identify it has the bit.
     *
     * @~Chinese
     * @brief 判断是否相应的位有设置的值
     *
     * @param BITDATA    bit    待判断的位。
     * @retval TRUE     表示相应位又被设置值
     */
    inline bool hasBit(BITDATA bit) const;

    /**
     * @~English
     * @brief set flags with the flag pram.
     *
     * @param BITDATA    flags flags used to be set.
     * @retval TRUE     the new flags after set.
     *
     * @~Chinese
     * @brief 用参数值设置所有的bit位。
     *
     * @param BITDATA    flags 用于设置的参数。
     * @retval TRUE     设置之后的新的数据。
     */
    inline BITDATA setFlags(BITDATA flags);

    /**
     * @~English
     * @brief used to judge if is has the bits.
     *
     * @param BITDATA    bits    the condition bits.
     * @retval TRUE     identify it has the bits.
     *
     * @~Chinese
     * @brief 判断是否相应的位有设置的值
     *
     * @param BITDATA    bits    待判断的位。
     * @retval TRUE     表示相应位又被设置值
     */
    inline bool hasBits(BITDATA bits) const;

public:
    inline BitFlags<BITDATA> operator&(BITDATA bitData) const;
    inline BitFlags<BITDATA> operator|(BITDATA bitData) const;

    inline BitFlags<BITDATA>& operator&=(BITDATA bitData);
    inline BitFlags<BITDATA>& operator|=(BITDATA bitData);

    inline BitFlags<BITDATA> operator+(BITDATA bitData) const;
    inline BitFlags<BITDATA> operator-(BITDATA bitData) const;

    inline BitFlags<BITDATA>& operator+=(BITDATA bitData);
    inline BitFlags<BITDATA>& operator-=(BITDATA bitData);

    inline BitFlags<BITDATA> operator^(BITDATA bitData) const;
    inline BitFlags<BITDATA>& operator^=(BITDATA bitData) const;

    template <typename BITDATA1>
    friend BitFlags<BITDATA1> operator~(BitFlags<BITDATA1> other);

    inline operator BITDATA(void) const;
    inline operator BITDATA* (void);
};

#pragma pack(pop)

template <typename BITDATA>
inline BitFlags<BITDATA>::BitFlags(void)
{
}

template <typename BITDATA>
inline BitFlags<BITDATA>::BitFlags(BITDATA bitData) {}

template <typename BITDATA>
inline void BitFlags<BITDATA>::setBit(BITDATA bit, bool bSet)
{
    if (bSet)
    {
        m_flags |= bit;
    }
    else
    {
        m_flags &= (~bit);
    }
}

template <typename BITDATA>
inline void BitFlags<BITDATA>::setAllBit(bool bSet)
{
    if (bSet)
    {
        m_flags = ~(BITDATA(0));
    }
    else
    {
        m_flags = (BITDATA)0;
    }
}

template <typename BITDATA>
inline bool BitFlags<BITDATA>::hasBit(BITDATA bit) const
{
    return (0 != (m_flags & bit));
}

template <typename BITDATA>
inline BITDATA BitFlags<BITDATA>::setFlags(BITDATA flags)
{
    return m_flags = flags;
}

template <typename BITDATA>
inline bool BitFlags<BITDATA>::hasBits(BITDATA bits) const
{
    return bits == (m_flags & bits);
}

template <typename BITDATA>
inline BitFlags<BITDATA> BitFlags<BITDATA>::operator&(BITDATA bitData) const
{
    return BitFlags<BITDATA>(m_flags & bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA> BitFlags<BITDATA>::operator|(BITDATA bitData) const
{
    return BitFlags<BITDATA>(m_flags | bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA>& BitFlags<BITDATA>::operator&=(BITDATA bitData)
{
    m_flags &= bitData;
    return *this;
}

template <typename BITDATA>
inline BitFlags<BITDATA>& BitFlags<BITDATA>::operator|=(BITDATA bitData)
{
    m_flags |= bitData;
    return *this;
}

template <typename BITDATA>
inline BitFlags<BITDATA> BitFlags<BITDATA>::operator+(BITDATA bitData) const
{
    return this->operator|(bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA> BitFlags<BITDATA>::operator-(BITDATA bitData) const
{
    return this->operator*(~bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA>& BitFlags<BITDATA>::operator+=(BITDATA bitData)
{
    return this->operator|=(bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA>& BitFlags<BITDATA>::operator-=(BITDATA bitData)
{
    m_flags &= (~bitData);
    return *this;
}

template <typename BITDATA>
inline BitFlags<BITDATA> BitFlags<BITDATA>::operator^(BITDATA bitData) const
{
    return BitFlags<BITDATA>(m_flags ^ bitData);
}

template <typename BITDATA>
inline BitFlags<BITDATA>& BitFlags<BITDATA>::operator^=(BITDATA bitData) const
{
    m_flags ^= bitData;
    return *this;
}

template <typename BITDATA1>
inline BitFlags<BITDATA1> operator~(BitFlags<BITDATA1> other)
{
    return BitFlags<BITDATA1>(~(other.m_flags));
}

template <typename BITDATA>
inline BitFlags<BITDATA>::operator BITDATA(void) const
{
    return m_flags;
}

template <typename BITDATA>
inline BitFlags<BITDATA>::operator BITDATA* (void)
{
    return &m_flags;
}

#endif // _BASIC_BIT_FLAGS_H_H_
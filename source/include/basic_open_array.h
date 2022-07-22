///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_OPEN_ARRAY_H_H_
#define _BASIC_OPEN_ARRAY_H_H_

#include <assert.h>
#include <memory.h>
#include <stdlib.h>

#include <algorithm>
#include <type_traits>

#pragma pack(push, 8)
#pragma warning(disable : 4251)

using index_t = size_t;
#define invalid_index ((index_t)-1)
#define TZARRAY_GROWTH_THRESHOLD 0x10000

/**
 * @addtogroup utility
 *    @{
 */

namespace Basic {

template <class T>
class ArrayMemAssignor {
 public:
  static void copy(T *pDest, size_t nBufLen, const T *pSource, size_t nCount,
                   bool bMove, bool bSameBuffer) {
    assert((nCount <= nBufLen) && (nCount >= 0 && nCount < 0x40000000));
    assert(pSource > pDest || (pDest >= pSource + nCount));
    assert(bMove || !bSameBuffer);

    if (nCount > 0) {
      if (bSameBuffer) {
        memmove_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
      } else {
        memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
      }
    }
  }
};

template <class T>
class ArrayObjectAssignor {
 public:
  static void copy(T *pDest, size_t nBufLen, const T *pSource, size_t nCount,
                   bool bMove, bool bSameBuffer) {
    assert((nCount <= nBufLen) && (nCount >= 0 && nCount < 0x40000000));
    assert(pSource > pDest || (pDest >= pSource + nCount));
    assert(bMove || !bSameBuffer);

    while (nCount--) {
      *pDest = *pSource;
      pDest++;
      pSource++;
    }
  }
};

template <typename T, bool>
struct ArrayElementAssignorSelector;

template <typename T>
struct ArrayElementAssignorSelector<T, false> {
  using assignor = ArrayObjectAssignor<T>;
};

template <typename T>
struct ArrayElementAssignorSelector<T, true> {
  using assignor = ArrayObjectAssignor<T>;
};

template <typename T>
struct ArrayElementAssignor
    : public ArrayElementAssignorSelector<T, std::is_pod<T>::value>::assignor {
};

/**
 *        @~English
 *        @brief The Array class is a container of sequential elements, like
 * std::vector.
 *
 *        @~Chinese
 *        @brief Array 类是一个顺序元素的容器类，类似std::vector
 */

template <typename T, typename A = typename ArrayElementAssignor<T>>
class Array {
 public:
  /**
   *        @~English
   *        @brief Constructor for the Array class.
   *
   *        @param initPhysicalLength    [in] Initial physical length
   *        @param initGrowLength         [in] Initial grow length
   *
   *        @~Chinese
   *        @brief Array 类的构造函数
   *
   *        @param initPhysicalLength    [in] 初始物理长度。
   *        @param initGrowLength         [in] 初始增长长度。
   */
  Array(size_t initPhysicalLength = 0, long initGrowLength = 8);

  /**
   *        @~English
   *        @brief Copy constructor for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的拷贝构造函数。
   */
  Array(const Array<T, A> &);

  /**
   *        @~English
   *        @brief Move constructor for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的移动构造函数。
   */
  Array(Array<T, A> &);

  /**
   *        @~English
   *        @brief Destructor for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的析构函数。
   */
  ~Array();

  /**
   *        @~English
   *        @brief Copy assignment for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的复制赋值操作符。
   */
  Array<T, A> &operator=(const Array<T, A> &);

  /**
   *        @~English
   *        @brief Move assignment for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的移动赋值操作符。
   */
  Array<T, A> &operator=(Array<T, A> &);

  /**
   *        @~English
   *        @brief Equal operator for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的相等操作符。
   */
  bool operator==(const Array<T, A> &) const;

  /**
   *        @~English
   *        @brief Equal operator for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的下标操作符。
   */
  T &operator[](index_t);

  /**
   *        @~English
   *        @brief Equal operator for the Array class.
   *
   *        @~Chinese
   *        @brief Array 类的下标操作符。
   */
  const T &operator[](index_t) const;

  /**
   *        @~English
   *        @brief Get an element at the given index.
   *
   *        @param index         [in] The given index from witch the element is
   * obtained.
   *        @return                    The obtained element.
   *
   *        @~Chinese
   *        @brief 返回指定位置的元素的引用。
   *
   *        @param index         [in] 指定的索引值，从该索引值获取对应的元素.
   *        @return                    获取到的元素.
   *
   */
  const T &at(index_t index) const;

  /**
   *        @~English
   *        @brief Get an element at the given index.
   *
   *        @param index         [in] The given index from witch the element is
   * obtained.
   *        @return                    The obtained element.
   *
   *        @~Chinese
   *        @brief 返回指定位置的元素的引用。
   *
   *        @param index         [in] 指定的索引值，从该索引值获取对应的元素.
   *        @return                    获取到的元素.
   *
   */
  T &at(index_t index);

  /**
   *        @~English
   *        @brief Set a new value for an element at the given index.
   *
   *        @param index         [in] The given index from witch the element is
   * obtained.
   *        @param value         [in] The new value to assign.
   *        @return                    The reference of the array itself.
   *
   *        @~Chinese
   *        @brief 设置指定位置的元素的值。
   *
   *        @param index         [in] 指定的索引值，从该索引值获取对应的元素.
   *        @param value         [in] 有待设置的新值.
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &setAt(index_t index, const T &value);

  /**
   *        @~English
   *        @brief Set a new value for all elements of the array.
   *
   *        @param value         [in] The new value to assign.
   *        @return                    The reference of the array itself.
   *
   *        @~Chinese
   *        @brief 设置所有位置的元素的值。
   *
   *        @param value         [in] 有待设置的新值.
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &setAll(const T &value);

  /**
   *        @~English
   *        @brief Return the    first element of the array.
   *        @return                    The reference of  first element of the
   * array.
   *
   *        @~Chinese
   *        @brief 返回第一个元素的值的引用。
   *
   *        @return                    Array第一个元素的的引用.
   *
   */
  T &first();

  /**
   *        @~English
   *        @brief Return the    first element of the array.
   *        @return                    The reference of  first element of the
   * array.
   *
   *        @~Chinese
   *        @brief 返回第一个元素的值的引用。
   *
   *        @return                    Array第一个元素的的引用.
   *
   */
  const T &first() const;

  /**
   *        @~English
   *        @brief Return the    last element of the array.
   *        @return                    The reference of  last element of the
   * array.
   *
   *        @~Chinese
   *        @brief 返回第一个元素的值的引用。
   *
   *        @return                    Array最后一个元素的的引用.
   *
   */
  T &last();

  /**
   *        @~English
   *        @brief Return the    last element of the array.
   *        @return                    The reference of  last element of the
   * array.
   *
   *        @~Chinese
   *        @brief 返回第一个元素的值的引用。
   *
   *        @return                    Array最后一个元素的的引用.
   *
   */
  const T &last() const;

  /**
   *        @~English
   *        @brief Append a new element at the end of the array.
   *
   *        @param value         [in] The new value to be appended.
   *        @return                    The index of the appended element.
   *
   *        @~Chinese
   *        @brief 在数组末尾添加一个新的元素。
   *
   *        @param value         [in] 待增加元素的值
   *        @return                    增加元素的最新的索引.
   *
   */
  size_t append(const T &value);

  /**
   *        @~English
   *        @brief Append a new array at the end of the array.
   *
   *        @param array             [in] The new array to be appended.
   *        @return                    The reference of the array itself.
   *
   *        @~Chinese
   *        @brief 在数组末尾添加一个新的数组。
   *
   *        @param value         [in] 待增加元素的值
   *        @return                    新的Array本身自身的引用。
   *
   */
  Array<T, A> &append(const Array<T, A> &array);

  /**
   *        @~English
   *        @brief Insert a new array at the index of the array.
   *
   *        @param index         [in] The given index.
   *        @param value         [in] The element to be inserted.
   *        @return                    The reference of the array itself.
   *
   *        @~Chinese
   *        @brief 在数组指定位置插入一个新的数组。
   *
   *        @param index         [in] 指定的索引
   *        @param value         [in] 待插入的元素.
   *        @return                    新的Array本身自身的引用。
   *
   */
  Array<T, A> &insertAt(index_t index, const T &value);

  /**
   *        @~English
   *        @brief Remove an element at the given index.
   *
   *        @param index         [in] The given index.
   *        @return                    The reference of the array itself.
   *
   *        @~Chinese
   *        @brief 删除指定索引出的一个元素。
   *
   *        @param index         [in] 指定的索引
   *        @return                    新的Array本身自身的引用。
   *
   */
  Array<T, A> &removeAt(index_t index);

  /**
   *        @~English
   *        @brief Remove an element at the first occurrence of value searching
   * from index start onwards.
   *
   *        @param value         [in] The value which we want to remove.
   *        @param start             [in] The index from which we start to
   * search.
   *        @return                    true = removed, false = not removed.
   *
   *        @~Chinese
   *        @brief 删除首次值等于value的元素，从start索引开始向前搜索。
   *
   *        @param value         [in] 想要删除的值.
   *        @param start             [in] 搜索的索引起始值.
   *        @return                    true = 删除, false = 未删除.
   *
   */
  bool remove(const T &value, index_t start = 0);

  /**
   *        @~English
   *        @brief Remove the first element.
   *        @return                    The reference of the array.
   *
   *        @~Chinese
   *        @brief 删除数组第一个元素。
   *
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &removeFirst();

  /**
   *        @~English
   *        @brief Remove the last element.
   *        @return                    The reference of the array.
   *
   *        @~Chinese
   *        @brief 删除数组最后一个元素。
   *
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &removeLast();

  /**
   *        @~English
   *        @brief Remove all the elements in the array.
   *        @return                    The reference of the array.
   *
   *        @~Chinese
   *        @brief 删除数组所有元素。
   *
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &removeAll();

  /**
   *        @~English
   *        @brief Remove a sub sequence of the elements from the array.
   *        @param startIndex             [in] The index from which to start
   * remove.
   *        @param endIndex             [in] The index from which to stop
   * remove.
   *        @return                            The reference of the array.
   *
   *        @~Chinese
   *        @brief 删除数组所有元素。
   *
   *        @param startIndex             [in] 起始删除的索引.
   *        @param endIndex             [in] 结束删除的索引.
   *        @return                    Array本身的引用.
   *
   */
  Array<T, A> &removeSubArray(index_t startIndex, index_t endIndex);

  /**
   *        @~English
   *        @brief Indicate whether the array contains an element equals value
   * searching from index start.
   *        @param value             [in] The value to search.
   *        @param start                 [in] The index from which to start
   * search.
   *        @return                        true = contained, false = not
   * contained.
   *
   *        @~Chinese
   *        @brief
   * 判断一个Array中是否存在一个值为value的元素，从start索引开始搜索。
   *
   *        @param value             [in] 待查找的值.
   *        @param start                 [in] 起始的搜索索引.
   *        @return                        true = 包含, false = 不包含.
   *
   */
  bool contains(const T &value, index_t start = 0) const;

  /**
   *        @~English
   *        @brief Find an element equals value from the array.
   *        @param value                     [in] The value to search.
   *        @param foundAt                 [in] The index of the found element.
   *        @param start                         [in] The index from which to
   * start search.
   *        @return                        true = contained, false = not
   * contained.
   *
   *        @~Chinese
   *        @brief 从Array中查找值为value的元素。
   *
   *        @param value                     [in] 待查找的值.
   *        @param foundAt                 [in] 找到的元素的索引.
   *        @param start                         [in] 起始的搜索索引.
   *        @return                        true = 包含, false = 不包含.
   *
   */
  bool find(const T &value, index_t &index, index_t start = 0) const;

  /**
   *        @~English
   *        @brief Find an element equals value from the array.
   *        @param value                     [in] The value to search.
   *        @return                                The index of the found
   * element.
   *
   *        @~Chinese
   *        @brief 从Array中查找值为value的元素。
   *
   *        @param value                     [in] 待查找的值.
   *        @return                                找到的元素的索引.
   *
   */
  index_t find(const T &value) const;

  /**
   *        @~English
   *        @brief Find an element equals value from the array.
   *        @param value                     [in] The value to search.
   *        @param start                         [in] The index from which to
   * start search.
   *        @return                                The index of the found
   * element.
   *
   *        @~Chinese
   *        @brief 从Array中查找值为value的元素。
   *
   *        @param value                     [in] 待查找的值.
   *        @param start                         [in] 起始的搜索索引.
   *        @return                                找到的元素的索引.
   *
   */
  index_t findFrom(const T &value, index_t start) const;

  /**
   *        @~English
   *        @brief Return the number of elements in the array.
   *
   *        @return                                The number of elements.
   *
   *        @~Chinese
   *        @brief 返回Array中的元素个数。
   *
   *        @return                                元素个数.
   *
   */
  size_t length() const;

  /**
   *        @~English
   *        @brief Check whether the array is empty.
   *
   *        @return                                true = empty, false = not
   * empty.
   *
   *        @~Chinese
   *        @brief 检查数组是否是空的数组。
   *
   *        @return                                true = 空数组， false =
   * 非空数组.
   *
   */
  bool isEmpty() const;

  /**
   *        @~English
   *        @brief Return the logical length of the array.
   *
   *        @return                                The logical length.
   *
   *        @~Chinese
   *        @brief 返回逻辑长度。
   *
   *        @return                                逻辑长度.
   *
   */
  size_t logicalLength() const;

  /**
   *        @~English
   *        @brief Set the logical length of the array.
   *
   *        @return                                The reference of the array
   * itself.
   *
   *        @~Chinese
   *        @brief 返回数组本身的引用。
   *
   *        @return                                数组本身的引用.
   *
   */
  Array<T, A> &setLogicalLength(size_t);

  /**
   *        @~English
   *        @brief Return the physical length of the array.
   *
   *        @return                                The physical length.
   *
   *        @~Chinese
   *        @brief 返回数组的物理长度。
   *
   *        @return                                物理长度.
   *
   */
  size_t physicalLength() const;

  /**
   *        @~English
   *        @brief Set the physical length of the array.
   *
   *        @return                                The reference of the array
   * itself.
   *
   *        @~Chinese
   *        @brief 设置数组的物理长度。
   *
   *        @return                                数组本身的引用.
   *
   */
  Array<T, A> &setPhysicalLength(size_t);

  /**
   *        @~English
   *        @brief Return the grow length of the array.
   *
   *        @return                                The grow length.
   *
   *        @~Chinese
   *        @brief 返回数组的增长长度。
   *
   *        @return                                增长长度.
   *
   */
  long growLength() const;

  /**
   *        @~English
   *        @brief Set the grow length of the array.
   *
   *        @return                                The reference of the array
   * itself.
   *
   *        @~Chinese
   *        @brief 设置数组的增长长度。
   *
   *        @return                                数组本身的引用.
   *
   */
  Array<T, A> &setGrowLength(long);

  /**
   *        @~English
   *        @brief reverse the order of the array.
   *
   *        @return                                The reference of the array
   * itself.
   *
   *        @~Chinese
   *        @brief 逆转数组元素的顺序。
   *
   *        @return                                数组本身的引用.
   *
   */
  Array<T, A> &reverse();

  /**
   *        @~English
   *        @brief Exchange the two elements.
   *        @param i1                             [in] The index of the first
   * element to exchange.
   *        @param i2                             [in] The index of the second
   * element to exchange.
   *        @return                                The reference of the array
   * itself.
   *
   *        @~Chinese
   *        @brief 交换Array中的两个元素。
   *
   *        @param i1                             [in] 要交换的第一个元素的索引.
   *        @param i2                             [in] 要交换的第二个元素的索引.
   *        @return                                Array自身的引用.
   *
   */
  Array<T, A> &swap(index_t i1, index_t i2);

  /**
   *        @~English
   *        @brief Return the underlay dynamic allocated array.
   *
   *        @return                                The pointer of the underlay
   * array.
   *
   *        @~Chinese
   *        @brief 返回Array类底下动态分配的数组。
   *
   *        @return                                Array类底下数组的指针.
   *
   */
  const T *asArrayPtr() const;

  /**
   *        @~English
   *        @brief Return the underlay dynamic allocated array.
   *
   *        @return                                The pointer of the underlay
   * array.
   *
   *        @~Chinese
   *        @brief 返回Array类底下动态分配的数组。
   *
   *        @return                                Array类底下数组的指针.
   *
   */
  T *asArrayPtr();

  /**
   *        @~English
   *        @brief Return the pointer of the first element. Usual used as
   * iterator.
   *
   *        @return                                The pointer pointed to the
   * first element.
   *
   *        @~Chinese
   *        @brief 返回首元素的指针，通常作为迭代器使用。
   *
   *        @return                                指向首元素的指针.
   *
   */
  const T *begin() const;

  /**
   *        @~English
   *        @brief Return the pointer of the first element. Usual used as
   * iterator.
   *
   *        @return                                The pointer pointed to the
   * first element.
   *
   *        @~Chinese
   *        @brief 返回首元素的指针，通常作为迭代器使用。
   *
   *        @return                                指向首元素的指针.
   *
   */
  T *begin();

  /**
   *        @~English
   *        @brief Return the pointer of the one-beyond-last element. Usual used
   * as iterator.
   *
   *        @return                                The pointer pointed to the
   * one-beyond-last element.
   *
   *        @~Chinese
   *        @brief 返回尾元素的指针，通常作为迭代器使用。
   *
   *        @return                                指向尾元素的指针.
   *
   */
  const T *end() const;

  /**
   *        @~English
   *        @brief Return the pointer of the one-beyond-last element. Usual used
   * as iterator.
   *
   *        @return                                The pointer pointed to the
   * one-beyond-last element.
   *
   *        @~Chinese
   *        @brief 返回尾元素的指针，通常作为迭代器使用。
   *
   *        @return                                指向尾元素的指针.
   *
   */
  T *end();

 protected:
  bool allocPhysBuf();
  bool deletePhysBuf(T *pBuf, size_t nCount);
  bool isValid(index_t) const;

 public:
  static const bool m_bSafeToMemCpy =
      std::is_same<A, ArrayMemAssignor<T>>::value;
  T *m_pArray;
  size_t m_physicalLen;
  size_t m_logicalLen;
  long m_growLen;
};

/** @} */

#pragma pack(pop)

// Inline implement:

template <class T, class A>
inline bool Array<T, A>::contains(const T &value,
                                  index_t start /* = 0 */) const {
  return findFrom(value, start) != -1;
}

template <typename T, typename A>
inline bool Array<T, A>::find(const T &value, index_t &index,
                              index_t start) const {
  const index_t nFoundAt = findFrom(value, start);

  if (nFoundAt == invalid_index) {
    return false;
  }

  index = nFoundAt;
  return true;
}

template <typename T, typename A>
inline index_t Array<T, A>::find(const T &value) const {
  return findFrom(value, 0);
}

template <typename T, typename A>
inline index_t Array<T, A>::findFrom(const T &value, index_t start) const {
  assert(start >= 0);
  if (start < 0) {
    return -1;
  }

  for (index_t i = start; i < (index_t)m_logicalLen; ++i) {
    if (m_pArray[i] == value) {
      return i;
    }
  }
  return -1;
}

template <class T, class A>
inline size_t Array<T, A>::length() const {
  return m_logicalLen;
}

template <class T, class A>
inline bool Array<T, A>::isEmpty() const {
  return m_logicalLen == 0;
}

template <class T, class A>
inline size_t Array<T, A>::logicalLength() const {
  return m_logicalLen;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::setLogicalLength(size_t n) {
  assert(n >= 0);
  if (n < 0) {
    n = 0;
  }
  assert(n < 0x40000000);
  if (n > m_physicalLen) {
    const size_t growth = (m_physicalLen * sizeof(T)) < TZARRAY_GROWTH_THRESHOLD
                              ? m_physicalLen
                              : TZARRAY_GROWTH_THRESHOLD / sizeof(T);

    size_t minSize = m_physicalLen + std::max<size_t>(growth, m_growLen);
    if (n > minSize) {
      minSize = n;
    }
    setPhysicalLength(minSize);
  }
  m_logicalLen = n;
  assert(m_logicalLen <= m_physicalLen);
  return *this;
}

template <class T, class A>
inline size_t Array<T, A>::physicalLength() const {
  return m_physicalLen;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::setPhysicalLength(size_t n) {
  assert(n >= 0 && n < 0x40000000);
  if (n == m_physicalLen || n < 0) {
    return *this;
  }

  assert((m_physicalLen >= m_logicalLen) &&
         (m_physicalLen == 0) == (m_pArray == nullptr));
  T *pOldArray = m_pArray;
  const size_t nOldLen = m_physicalLen;

  m_physicalLen = n;
  m_pArray = nullptr;
  if (m_physicalLen < m_logicalLen) {
    m_logicalLen = m_physicalLen;
  }
  if ((m_physicalLen != 0) && allocPhysBuf()) {
    A::copy(m_pArray, m_physicalLen, pOldArray, m_logicalLen, true, false);
  }

  deletePhysBuf(pOldArray, nOldLen);
  return *this;
}

template <class T, class A>
inline long Array<T, A>::growLength() const {
  return m_growLen;
}

template <class T, class A>
inline const T *Array<T, A>::asArrayPtr() const {
  m_pArray;
}

template <class T, class A>
inline T *Array<T, A>::asArrayPtr() {
  return m_pArray;
}

template <class T, class A>
inline const T *Array<T, A>::begin() const {
  return m_pArray;
}

template <class T, class A>
inline T *Array<T, A>::begin() {
  return m_pArray;
}

template <class T, class A>
inline const T *Array<T, A>::end() const {
  return m_pArray + m_logicalLen;
}

template <class T, class A>
inline T *Array<T, A>::end() {
  return m_pArray + m_logicalLen;
}

template <typename T, typename A>
inline bool Array<T, A>::allocPhysBuf() {
  assert(m_physicalLen > 0);
  assert(nullptr == m_pArray);
  m_pArray = new T[m_physicalLen];
  assert(nullptr != m_pArray);

  if (nullptr == m_pArray) {
    m_physicalLen = 0;
    m_logicalLen = 0;
    return false;
  }
  return true;
}

template <typename T, typename A>
inline bool Array<T, A>::deletePhysBuf(T *pBuf, size_t nCount) {
  if (nullptr == pBuf) {
    assert(0 == nCount);
  } else {
    assert(nCount > 0);
    delete[] pBuf;
  }
  return true;
}

template <class T, class A>
inline bool Array<T, A>::isValid(index_t i) const {
  return i >= 0 && i < (index_t)m_logicalLen;
}

template <class T, class A>
inline const T &Array<T, A>::operator[](index_t i) const {
  assert(isValid(i));
  return m_pArray[i];
}

template <class T, class A>
inline T &Array<T, A>::operator[](index_t i) {
  assert(isValid(i));
  return m_pArray[i];
}

template <class T, class A>
inline const T &Array<T, A>::at(index_t i) const {
  assert(isValid(i));
  return m_pArray[i];
}

template <class T, class A>
inline T &Array<T, A>::at(index_t i) {
  assert(isValid(i));
  return m_pArray[i];
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::setAt(index_t index, const T &value) {
  assert(isValid(index));
  m_pArray[index] = value;
  return *this;
}

template <class T, class A>
inline const T &Array<T, A>::first() const {
  assert(!isEmpty());
  return m_pArray[0];
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::setAll(const T &value) {
  for (index_t i = 0; i < m_logicalLen; ++i) {
    m_pArray[i] = value;
  }
  return *this;
}

template <class T, class A>
inline T &Array<T, A>::first() {
  assert(!isEmpty());
  return m_pArray[0];
}

template <class T, class A>
inline const T &Array<T, A>::last() const {
  assert(!isEmpty());
  return m_pArray[m_logicalLen - 1];
}

template <class T, class A>
inline T &Array<T, A>::last() {
  assert(!isEmpty());
  return m_pArray[m_logicalLen - 1];
}

template <class T, class A>
inline size_t Array<T, A>::append(const T &value) {
  insertAt(m_logicalLen, value);
  return m_logicalLen - 1;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::append(const Array<T, A> &array) {
  const size_t otherLen = array.length();
  if (0 == otherLen) {
    return *this;
  }

  size_t newLen = m_logicalLen + otherLen;
  if (newLen > m_physicalLen) {
    setPhysicalLength(m_logicalLen + std::max<size_t>(otherLen, m_growLen));
  }
  A::copy(m_pArray + m_logicalLen, (m_physicalLen - m_logicalLen),
          array.m_pArray, otherLen, false, false);
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::insertAt(index_t index, const T &value) {
  assert(index >= 0 && index <= (index_t)m_logicalLen);
  if (index < 0 || index > (index_t)m_logicalLen) {
    return *this;
  }
  const T tmp(value);
  if (m_logicalLen >= m_physicalLen) {
    assert(m_logicalLen == m_physicalLen);
    size_t growth = (m_logicalLen * sizeof(T)) < TZARRAY_GROWTH_THRESHOLD
                        ? m_logicalLen
                        : TZARRAY_GROWTH_THRESHOLD / sizeof(T);
    setPhysicalLength(m_logicalLen + std::max<size_t>(growth, m_growLen));
  }

  if (index != (index_t)m_logicalLen) {
    assert(m_logicalLen >= 0);
    T *p = m_pArray + m_logicalLen;
    T *pStop = m_pArray + index;
    do {
      *p = *(p - 1);
    } while (--p != pStop);
  }
  m_pArray[index] = tmp;
  m_logicalLen++;
  return *this;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::removeAt(index_t index) {
  assert(isValid(index));
  assert(m_logicalLen <= m_physicalLen);
  assert(!isEmpty());
  if (isEmpty() || !isValid(index)) {
    return *this;
  }

  if (index < (index_t)m_logicalLen - 1) {
    A::copy(m_pArray + index, m_physicalLen - index, m_pArray + index + 1,
            m_logicalLen - 1 - index, true, true);
  }
  m_logicalLen--;
  return *this;
}

template <typename T, typename A>
inline bool Array<T, A>::remove(const T &value, index_t start) {
  const index_t i = findFrom(value, start);
  if (invalid_index == i) {
    return false;
  }
  removeAt(i);
  return true;
}

template <class T, class A>
inline Array<T, A> &Array<T, A>::removeFirst() {
  assert(!isEmpty());
  return removeAt(0);
}

template <class T, class A>
inline Array<T, A> &Array<T, A>::removeLast() {
  assert(!isEmpty());
  if (!isEmpty()) {
    m_logicalLen--;
  }
  return *this;
}

template <class T, class A>
inline Array<T, A> &Array<T, A>::removeAll() {
  setLogicalLength(0);
  return *this;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::removeSubArray(index_t startIndex,
                                                index_t endIndex) {
  assert(isValid(startIndex));
  assert(startIndex <= endIndex);

  if (endIndex >= m_logicalLen - 1) {
    m_logicalLen = startIndex;
    return *this;
  }

  const index_t kNumToRemove = endIndex + 1 - startIndex;
  const index_t kNumToShift = m_logicalLen - 1 - endIndex;
  assert(kNumToShift >= 1);
  A::copy(m_pArray + startIndex, m_physicalLen - startIndex,
          m_pArray + endIndex + 1, kNumToShift, true, true);
  m_logicalLen -= kNumToRemove;
  return *this;
}

template <class T, class A>
inline Array<T, A> &Array<T, A>::setGrowLength(long glen) {
  assert(glen > 0);
  m_growLen = glen;
  return *this;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::reverse() {
  for (size_t i = 0; i < m_logicalLen / 2; ++i) {
    const T tmp = m_pArray[i];
    m_pArray[i] = m_pArray[m_logicalLen - 1 - i];
    m_pArray[m_logicalLen - 1 - i] = tmp;
  }
  return *this;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::swap(index_t i1, index_t i2) {
  assert(isValid(i1));
  assert(isValid(i2));

  if (i1 == i2) {
    return *this;
  }

  const T tmp = m_pArray[i1];
  m_pArray[i1] = m_pArray[i2];
  m_pArray[i2] = tmp;
  return *this;
}

#define openLowMemBail() assert(false)

template <class T, class A>
Array<T, A>::Array(size_t ph1, long gr1)
    : m_pArray(nullptr), m_physicalLen(ph1), m_logicalLen(0), m_growLen(gr1) {
  assert(m_growLen > 0);
  if (m_physicalLen > 0) {
    allocPhysBuf();
  }
}

template <class T, class A>
Array<T, A>::Array(const Array<T, A> &src)
    : m_pArray(nullptr),
      m_physicalLen(src.m_physicalLen),
      m_logicalLen(src.m_logicalLen),
      m_growLen(src.m_growLen) {
  assert(m_physicalLen > m_logicalLen);
  if (m_logicalLen <= 0) {
    assert(0 == m_logicalLen);
    m_physicalLen = 0;
  }
  if (m_physicalLen <= 0) {
    assert((0 == m_physicalLen) && (0 == m_logicalLen));
  } else {
    assert(m_logicalLen > 0);
    if (allocPhysBuf()) {
      A::copy(m_pArray, m_physicalLen, src.m_pArray, m_logicalLen, false,
              false);
    }
  }
}

template <class T, class A>
Array<T, A>::Array(Array<T, A> &src)
    : m_pArray(nullptr),
      m_physicalLen(src.m_physicalLen),
      m_logicalLen(src.m_logicalLen),
      m_growLen(src.m_growLen) {
  src.m_pArray = nullptr;
  src.m_physicalLen = 0;
  src.m_logicalLen = 0;
  src.m_growLen = 8;
}

template <class T, class A>
Array<T, A>::~Array() {
  deletePhysBuf(m_pArray, m_physicalLen);
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::operator=(const Array<T, A> &src) {
  if (this != src) {
    if (src.m_logicalLen <= 0) {
      assert(0 == src.m_logicalLen);
      m_logicalLen = 0;
    } else {
      if (m_physicalLen < src.m_logicalLen) {
        if (nullptr != m_pArray) {
          deletePhysBuf(m_pArray, m_physicalLen);
          m_pArray = nullptr;
        }
        m_physicalLen = src.m_logicalLen;
        if (!allocPhysBuf()) {
          return *this;
        }
      }
      m_physicalLen = src.m_logicalLen;
      assert((m_logicalLen > 0) && (m_physicalLen >= m_logicalLen));
      A::copy(m_pArray, m_physicalLen, src.m_pArray, m_logicalLen, false,
              false);
    }
  }
  return *this;
}

template <typename T, typename A>
inline Array<T, A> &Array<T, A>::operator=(Array<T, A> &src) {
  if (this != src) {
    m_physicalLen = src.m_physicalLen;
    m_pArray = src.m_pArray;
    m_logicalLen = src.m_logicalLen;
    src.m_pArray = nullptr;
    src.m_physicalLen = 0;
    src.m_logicalLen = 0;
    src.m_growLen = 8;
  }
}

template <typename T, typename A>
inline bool Array<T, A>::operator==(const Array<T, A> &cpr) const {
  if (m_logicalLen == cpr.m_logicalLen) {
    for (index_t i = 0; i < m_logicalLen; ++i) {
      if (m_pArray[i] != cpr.m_pArray[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

}  // namespace Basic

#endif
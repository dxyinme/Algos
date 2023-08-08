#pragma once
#ifndef SORT_SORT_HPP_
#define SORT_SORT_HPP_

#include <cstddef>
#include <iostream>

namespace sort
{

  template <typename T>
  void Swap(T &a, T &b)
  {
    T t = a;
    a = b;
    b = t;
  }

  template <typename ValueType>
  class DefaultComparator
  {
  public:
    const bool Less(const ValueType &a, const ValueType &b) const
    {
      return a < b;
    }
  };

  // sort range [beginIdx, endIdx)

#pragma region QuickSort

  size_t GetPartitionIdx(size_t begin, size_t end)
  {
    return (begin + end) / 2;
  }

  template <typename T, typename Comparator>
  void QuickSort(
      T *arr, size_t beginIdx, size_t endIdx, const Comparator &cmp)
  {
    if (endIdx - beginIdx < 2)
      return;
    int partitionIdx = GetPartitionIdx(beginIdx, endIdx - 1);
    T x = arr[partitionIdx];
    size_t i = beginIdx;
    size_t j = endIdx - 1;
    while (i <= j)
    {
      // arr[j] > x
      while (cmp.Less(x, arr[j]))
        j--;

      // arr[i] < x
      while (cmp.Less(arr[i], x))
        i++;

      if (i <= j)
      {
        Swap(arr[i], arr[j]);
        i++;
        j--;
      }
    }
    if (beginIdx <= j)
      QuickSort(arr, beginIdx, j + 1, cmp);

    if (i < endIdx - 1)
      QuickSort(arr, i, endIdx, cmp);
  }

#pragma endregion

#pragma region MergeSort

  template <typename T, typename Comparator>
  void mergeSortedSubArrays(
      T *arr,
      size_t l, size_t m, size_t r,
      const Comparator &cmp,
      T *tmp)
  {
    size_t i = l;
    size_t j = m;
    size_t k = l;
    while (i < m && j < r)
    {
      if (cmp.Less(arr[j], arr[i]))
      {
        tmp[k++] = arr[j++];
      }
      else
      {
        tmp[k++] = arr[i++];
      }
    }
    while (i < m)
    {
      tmp[k++] = arr[i++];
    }

    while (j < r)
    {
      tmp[k++] = arr[j++];
    }
    for (size_t idx = l; idx < r; idx++)
    {
      arr[idx] = tmp[idx];
    }
  }

  template <typename T, typename Comparator>
  void mergeSort(T *arr, size_t beginIdx, size_t endIdx, const Comparator &cmp, T *tmp)
  {
    if (endIdx - beginIdx < 2)
    {
      return;
    }

    size_t mid = (beginIdx + endIdx) / 2;
    mergeSort(arr, beginIdx, mid, cmp, tmp);
    mergeSort(arr, mid, endIdx, cmp, tmp);
    mergeSortedSubArrays(arr, beginIdx, mid, endIdx, cmp, tmp);
  }

  template <typename T, typename Comparator>
  void MergeSort(T *arr, size_t beginIdx, size_t endIdx, const Comparator &cmp)
  {
    T *tmp = new T[endIdx - beginIdx + 5];
    mergeSort(arr + beginIdx, 0, endIdx - beginIdx, cmp, tmp);
    delete[] tmp;
  }

#pragma endregion
} // namespace sort

#endif
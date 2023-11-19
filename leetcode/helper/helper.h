#pragma once
#ifndef _ALGOS_LEETCODE_HELPER_H
#define _ALGOS_LEETCODE_HELPER_H
#include <iostream>
#include <vector>

namespace lchelper
{

  template <typename T>
  void print1(std::vector<T> &v)
  {
    for (auto iter : v)
    {
      std::cout << iter << ",";
    }
    std::cout << "\n";
  }

  template <typename T>
  void print1(std::vector<T> &&v)
  {
    for (auto iter : v)
    {
      std::cout << iter << ",";
    }
    std::cout << "\n";
  }

  template <typename T>
  void print2(std::vector<std::vector<T>> &&v2)
  {
    for (auto v : v2)
    {
      print1(v);
    }
    std::cout << "\n";
  }

  template <typename T>
  void print2(std::vector<std::vector<T>> &v2)
  {
    for (auto v : v2)
    {
      print1(v);
    }
    std::cout << "\n";
  }
} // namespace lchelper

#endif

#pragma once
#ifndef BASELIB_BASELIB_HPP_
#define BASELIB_BASELIB_HPP_

#include <cstdlib>

namespace baselib
{

  void RandomArray(int *arr, size_t length)
  {
    for (size_t i = 0; i < length; i++)
    {
      arr[i] = rand();
    }
  }

} // namespace baselib

#endif
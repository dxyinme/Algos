#pragma once
#ifndef BASELIB_MINITEST_HPP_
#define BASELIB_MINITEST_HPP_
#include <string>
#include <cstring>
#include <sstream>
#include "baselib/log.hpp"

namespace baselib
{

  template <typename T>
  static const char *Str(T v)
  {
    std::stringstream ss;
    ss << v;
    return ss.str().c_str();
  }

  template <typename T>
  static void AssertEqual(const T &expected, const T &value)
  {
    bool v = (expected == value);
    if (!v)
    {
      Outf("expected: %s, but: %s", Str(expected), Str(value));
    }
  }

} // namespace baselib

#endif
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
  std::string Str(T v)
  {
    std::stringstream ss;
    ss << v;
    return ss.str();
  }

  template <typename T>
  static void AssertEqual(const T &expected, const T &value)
  {
    bool v = (expected == value);
    if (!v)
    {
      Outf("expected: %s, but: %s", Str(expected).c_str(), Str(value).c_str());
    }
  }

  template <typename T>
  static void AssertNotBigger(const T &a, const T &b)
  {
    if (b < a)
    {
      Outf("expected %s <= %s, but failed", Str(a).c_str(), Str(b).c_str());
    }
  }

} // namespace baselib

#endif
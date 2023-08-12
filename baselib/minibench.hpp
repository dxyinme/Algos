#pragma once
#ifndef BASELIB_MINIBENCH_HPP_
#define BASELIB_MINIBENCH_HPP_
#include <cstdlib>
#include <chrono>
namespace baselib
{
  class StopWatch
  {
  private:
    std::chrono::_V2::system_clock::time_point _last;

  public:
    StopWatch()
    {
      _last = std::chrono::system_clock::now();
    }
    double Tick()
    {
      auto _now = std::chrono::system_clock::now();
      double ret = std::chrono::duration_cast<std::chrono::duration<double>>(_now - _last).count();
      _last = _now;
      return ret;
    }
  };
} // namespace baselib

#endif
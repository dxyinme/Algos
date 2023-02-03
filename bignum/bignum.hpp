#pragma once
#ifndef BIGNUM_BIGNUM_HPP_
#define BIGNUM_BIGNUM_HPP_
#include <cstdlib>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

namespace bignum
{
  const char NEGATIVE = '-';
  class Int
  {
  private:
    int len_, cap_, f_;
    std::vector<int8_t> num_;

    // return -1, abs(this) < abs(other)
    // return 0,  abs(this) == abs(other)
    // return 1,  abs(this) > abs(other)
    int absEqual(const Int &other) const
    {
      if (len_ == other.len_)
      {
        for (int i = len_ - 1; i >= 0; i--)
        {
          if (num_[i] != other.num_[i])
          {
            return num_[i] < other.num_[i] ? -1 : 1;
          }
        }
        return 0;
      }
      return len_ < other.len_ ? -1 : 1;
    }

    void sameSideAdd(const Int &other)
    {
      int l = std::max(len_, other.len_);
      for (int i = 0; i < l; i++)
      {
        num_[i] += other.num_[i];
        if (num_[i] >= 10)
        {
          num_[i + 1]++;
          num_[i] %= 10;
        }
      }
      if (l < cap_ && num_[l] > 0)
        l++;
      len_ = l;
    }

    void diffSideAdd(const Int &other)
    {
      int fx = absEqual(other);
      if (fx == 0)
      {
        Set("0");
        return;
      }
      f_ *= fx;
      int l = std::max(len_, other.len_);
      for (int i = 0; i < l; i++)
      {
        num_[i] = fx * (num_[i] - other.num_[i]);
        while (num_[i] < 0)
        {
          num_[i] += 10;
          num_[i + 1] -= fx;
        }
      }
      if (l < cap_ && num_[l] != 0)
        l++;
      while (l > 0 && num_[l - 1] == 0)
      {
        l--;
      }
      if (l == 0)
      {
        l = 1;
        num_[0] = 0;
        f_ = 1;
      }
      len_ = l;
    }

  public:
    Int(int cap)
    {
      assert(cap > 0);
      len_ = 1;
      cap_ = cap;
      num_.resize(cap_, 0);
      num_[0] = 0;
      f_ = 1;
    }

    bool IsNegative() const
    {
      return f_ == -1;
    }

    void Add(const Int &other)
    {
      if (other.IsNegative() == IsNegative())
      {
        sameSideAdd(other);
      }
      else
      {
        diffSideAdd(other);
      }
    }

    void Dec(const Int &other)
    {
      if (other.IsNegative() == IsNegative())
      {
        diffSideAdd(other);
      }
      else
      {
        sameSideAdd(other);
      }
    }

    std::string ToString()
    {
      std::string r;
      if (len_ == 0)
        return "0";
      if (f_ == -1)
      {
        r.push_back(NEGATIVE);
      }
      for (int i = len_ - 1; i >= 0; i--)
      {
        r.push_back(num_[i] + '0');
      }
      return r;
    }

    void Set(const std::string &s)
    {
      if (s.empty())
        return;
      int idx = 0;
      if (*s.begin() == NEGATIVE)
      {
        idx++;
        f_ = -1;
      }
      else
      {
        f_ = 1;
      }
      len_ = s.size() - idx;
      if (cap_ < len_)
        return;
      for (int i = 0, j = s.size() - 1; i < len_; i++, j--)
      {
        num_[i] = s[j] - '0';
      }
    }

    void Set(int v)
    {
      Set(std::to_string(v));
    }
  };
} // namespace bignum

#endif
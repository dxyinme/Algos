#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

namespace leetcode::T87
{

  class Solution
  {
  private:
    int state_[34][34][34];
    string sa, sb;
    bool isSameCharSet(string a, string b)
    {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      return a == b;
    }

  public:
    bool dfs(int fa, int fb, int len)
    {
      if (state_[fa][fb][len])
        return state_[fa][fb][len] == 1;
      auto a = sa.substr(fa, len), b = sb.substr(fb, len);
      if (!isSameCharSet(a, b))
      {
        state_[fa][fb][len] = 2;
        return false;
      }
      if (a == b)
      {
        state_[fa][fb][len] = 1;
        return true;
      }
      for (int i = 1; i < len; i++)
      {
        if (dfs(fa, fb + len - i, i) && dfs(fa + i, fb, len - i))
        {
          state_[fa][fb][len] = 1;
          return true;
        }
        if (dfs(fa, fb, i) && dfs(fa + i, fb + i, len - i))
        {
          state_[fa][fb][len] = 1;
          return true;
        }
      }
      state_[fa][fb][len] = 2;
      return false;
    }

    bool isScramble(string s1, string s2)
    {
      memset(state_, 0, sizeof(state_));
      sa = s1;
      sb = s2;
      return dfs(0, 0, s1.size());
    }
  };
} // namespace leetcode::T87

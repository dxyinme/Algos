#include <vector>
#include <set>
#include <tuple>
using namespace std;
namespace leetcode::T1923
{
  class Solution
  {
  public:
    using LL = long long;
    const LL B = 1e5 + 7;
    const LL mod = 1713302033171;

    bool check(const vector<vector<int>> &paths, int shortest_idx, int len)
    {
      const auto &s = paths[shortest_idx];
      vector<set<LL>> exist(paths.size());
      LL val = 0;
      LL faclen = 1;
      for (int i = 1; i < len; i++)
        faclen = (faclen * B) % mod;
      for (int i = 0; i < len; i++)
        val = (val * B % mod + s[i]) % mod;
      set<LL> pp;
      for (int i = 0; i + len < s.size(); i++)
      {
        pp.insert(val);
        val = ((val % mod - s[i] * faclen % mod + mod) * B % mod + s[i + len]) % mod;
      }
      pp.insert(val);
      for (int t = 0; t < paths.size(); t++)
      {
        if (t == shortest_idx)
          continue;
        const auto &p = paths[t];
        val = 0;
        for (int i = 0; i < len; i++)
          val = (val * B % mod + p[i]) % mod;
        for (int i = 0; i + len < p.size(); i++)
        {
          exist[t].insert(val);
          val = ((val - p[i] * faclen % mod + mod) * B % mod + p[i + len]) % mod;
        }
        exist[t].insert(val);
      }

      for (const auto &v : pp)
      {
        bool ok = true;
        for (int i = 0; i < paths.size(); i++)
        {
          if (i == shortest_idx)
            continue;
          if (exist[i].find(v) == exist[i].end())
          {
            ok = false;
            break;
          }
        }
        if (!ok)
          continue;
        else
          return true;
      }
      return false;
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
      int shortest = 0;
      for (int i = 0; i < paths.size(); i++)
      {
        if (paths[i].size() < paths[shortest].size())
          shortest = i;
      }

      int L = 1, R = paths[shortest].size(), ans = 0;
      while (L <= R)
      {
        int M = (L + R) / 2;
        if (check(paths, shortest, M))
        {
          ans = M;
          L = M + 1;
        }
        else
        {
          R = M - 1;
        }
      }
      return ans;
    }
  };
} // namespace T1923
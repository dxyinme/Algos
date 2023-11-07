#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

namespace leetcode::T44
{
  class Solution
  {
  public:
    bool isMatch(string s, string p)
    {
      int n = s.size(), m = p.size();
      vector<vector<int>> f(n + 5, vector<int>(m + 5, 0));
      vector<vector<int>> g(n + 5, vector<int>(m + 5, 0));
      f[0][0] = 1;
      for (int i = 0; i <= n; i++)
        g[i][0] = 1;

      for (int i = 0; i <= n; i++)
      {
        for (int j = 1; j <= m; j++)
        {
          if (p[j - 1] != '*' && p[j - 1] != '?')
          {
            if (i > 0 && p[j - 1] == s[i - 1])
            {
              f[i][j] |= f[i - 1][j - 1];
            }
          }
          else
          {
            if (p[j - 1] == '?')
            {
              if (i > 0 && j > 0)
                f[i][j] |= f[i - 1][j - 1];
            }
            else
            {
              // cout << i << "," << j << ":" << g[i][j - 1] << endl;
              f[i][j] |= g[i][j - 1];
            }
          }
          if (i > 0)
            g[i][j] = (g[i - 1][j] | f[i][j]);
          if (p[j - 1] == '*')
            g[i][j] |= g[i][j - 1];
        }
      }
      return f[n][m] == 1;
    }
  };

} // namespace leetcode::T44

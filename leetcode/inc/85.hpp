#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

namespace leetcode::T85
{
  class Solution
  {
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
      int n = matrix.size();
      int m = matrix[0].size();

      vector<vector<int>> ft(n + 1, vector<int>(m + 1, 0));

      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (matrix[i][j] == '1')
          {
            if (i == 0)
            {
              ft[i][j] = 0;
            }
            else
            {
              if (matrix[i - 1][j] == '1')
              {
                ft[i][j] = ft[i - 1][j];
              }
              else
              {
                ft[i][j] = i;
              }
            }
          }
        }
      }

      int ans = 0;
      stack<int> st;
      vector<int> lt(m), rt(m), a(m);
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (matrix[i][j] == '1')
            a[j] = i - ft[i][j] + 1;
          else
            a[j] = 0;
          lt[j] = rt[j] = j;
        }
        for (int j = 0; j < m; j++)
        {
          while (!st.empty() && a[st.top()] > a[j])
          {
            rt[st.top()] = j - 1;
            st.pop();
          }
          st.push(j);
        }
        while (!st.empty())
        {
          rt[st.top()] = m - 1;
          st.pop();
        }

        for (int j = m - 1; j >= 0; j--)
        {
          while (!st.empty() && a[st.top()] > a[j])
          {
            lt[st.top()] = j + 1;
            st.pop();
          }
          st.push(j);
        }
        while (!st.empty())
        {
          lt[st.top()] = 0;
          st.pop();
        }

        for (int j = 0; j < m; j++)
        {
          ans = max(ans, (rt[j] - lt[j] + 1) * a[j]);
        }
      }
      return ans;
    }
  };

} // namespace leetcode::T85

#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
namespace leetcode::T2736
{
  class Solution
  {
  public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
      vector<tuple<int, int, int>> qs;
      vector<tuple<int, int>> p;
      int n = nums1.size();
      vector<int> ans(queries.size());
      for (int i = 0; i < (int)queries.size(); i++)
      {
        qs.push_back({queries[i][0], queries[i][1], i});
      }
      for (int i = 0; i < n; i++)
      {
        p.push_back({nums1[i], nums2[i]});
      }
      sort(p.begin(), p.end());
      reverse(p.begin(), p.end());
      sort(qs.begin(), qs.end());
      reverse(qs.begin(), qs.end());
      vector<tuple<int, long long>> st;

      int idx = 0;
      for (const auto &q : qs)
      {
        auto &[x, y, i] = q;
        while (idx < n)
        {
          auto &[a, b] = p[idx];
          if (a < x)
            break;
          while (!st.empty() && get<1>(st.back()) <= a + b)
          {
            st.pop_back();
          }
          if (st.empty() || get<0>(st.back()) < b)
          {
            st.push_back({b, 0LL + a + b});
          }
          idx++;
        }
        int result = lower_bound(st.begin(), st.end(), make_tuple(y, 0LL)) - st.begin();
        if (result < (int)st.size())
          ans[i] = get<1>(st[result]);
        else
          ans[i] = -1;
      }
      return ans;
    }
  };
} // namespace T2736
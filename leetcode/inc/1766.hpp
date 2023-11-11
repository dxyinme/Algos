#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

namespace leetcode::T1766
{
  class Solution
  {
    const int MAXNUMS = 50;
    void dfs(
        const vector<vector<int>> &g,
        const vector<int> &nums,
        const vector<vector<int>> &bag,
        vector<set<tuple<int, int>>> &states,
        vector<int> &ans,
        int depth,
        int x,
        int fa)
    {
      int p = -1;
      auto v = nums[x];
      for (int i = 1; i <= MAXNUMS; i++)
      {
        if (bag[v][i])
        {
          if (states[i].empty())
            continue;
          if (ans[x] == -1)
          {
            ans[x] = get<1>(*--states[i].end());
            p = get<0>(*--states[i].end());
          }
          else
          {
            if (get<0>(*--states[i].end()) > p)
            {
              ans[x] = get<1>(*--states[i].end());
              p = get<0>(*--states[i].end());
            }
          }
        }
      }

      states[v].insert({depth, x});
      for (auto to : g[x])
      {
        if (fa == to)
          continue;
        dfs(g, nums, bag, states, ans, depth + 1, to, x);
      }
      states[v].erase({depth, x});
    }

  public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
      int n = nums.size();
      vector<vector<int>> g(n + 5, vector<int>());

      for (auto &edge : edges)
      {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
      }

      vector<int> ans(n, -1);
      vector<vector<int>> bag(MAXNUMS + 5, vector<int>(MAXNUMS + 5, 0));
      for (int i = 1; i <= MAXNUMS; i++)
      {
        for (int j = i; j <= MAXNUMS; j++)
        {
          bag[i][j] = bag[j][i] = (__gcd(i, j) == 1);
        }
      }

      vector<set<tuple<int, int>>> states(MAXNUMS + 5, set<tuple<int, int>>());
      dfs(g, nums, bag, states, ans, 0, 0, -1);
      return ans;
    }
  };
} // namespace leetcode::T1766

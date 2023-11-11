#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

namespace leetcode::T39
{
  class Solution
  {
    void dfs(int idx, const vector<int> &candidates, int target, vector<int> &states, vector<vector<int>> &ans, int sum)
    {
      if (sum >= target)
      {
        if (sum == target)
          ans.push_back(states);
        return;
      }
      if (idx >= candidates.size())
        return;

      dfs(idx + 1, candidates, target, states, ans, sum);

      states.push_back(candidates[idx]);
      dfs(idx, candidates, target, states, ans, sum + candidates[idx]);
      states.pop_back();
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
      vector<vector<int>> ans;
      vector<int> states;
      dfs(0, candidates, target, states, ans, 0);
      return ans;
    }
  };
} // namespace leetcode::T39

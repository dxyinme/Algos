#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
namespace leetcode::T2432
{
  class Solution
  {
    int sumDigits(int v)
    {
      int sum = 0;
      while (v)
      {
        sum += v % 10;
        v /= 10;
      }
      return sum;
    }

  public:
    int maximumSum(vector<int> &nums)
    {
      map<int, vector<int>> mp;
      int n = nums.size();
      for (int i = 0; i < n; i++)
      {
        mp[sumDigits(nums[i])].push_back(i);
      }
      int ans = -1;
      for (auto &[sum, vec] : mp)
      {
        if (vec.size() <= 1)
        {
          continue;
        }
        sort(vec.begin(), vec.end(), [&nums](const int &x, const int &y) -> bool
             { return nums[x] > nums[y]; });
        ans = max(ans, nums[vec[0]] + nums[vec[1]]);
      }
      return ans;
    }
  };
} // namespace T2432
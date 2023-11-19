#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
namespace leetcode::T689
{
  class Solution
  {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
      int n = nums.size();
      vector<int> s(n + 5);
      s[0] = 0;
      for (int i = 0; i < n; i++)
      {
        s[i + 1] = s[i] + nums[i];
      }
      vector<tuple<int, int>> prek(n + 5), backk(n + 5);
      prek[0] = {0, 1};
      for (int i = 0; i + k < n; i++)
      {
        auto sum = s[i + k] - s[i];
        prek[i + 1] = max(prek[i], {sum, -i});
      }
      for (int i = n - k; i >= 0; i--)
      {
        auto sum = s[i + k] - s[i];
        backk[i + 1] = max(backk[i + 2], {sum, -i});
      }

      // for (int i = 0; i + k <= n; i++)
      // {
      //   cout << "(" << get<0>(prek[i]) << "," << get<1>(prek[i]) << "),";
      // }
      // cout << "\n";
      // for (int i = 0; i + k <= n; i++)
      // {
      //   cout << "(" << get<0>(backk[i]) << "," << get<1>(backk[i]) << "),";
      // }
      // cout << "\n";

      vector<int> ans;
      int maxSum = 0;
      for (int i = k; i + k < n; i++)
      {
        auto sum = s[i + k] - s[i] + get<0>(prek[i - k + 1]) + get<0>(backk[i + k + 1]);
        if (sum > maxSum)
        {
          maxSum = sum;
          ans = vector<int>{-get<1>(prek[i - k + 1]), i, -get<1>(backk[i + k + 1])};
        }
      }
      // cout << maxSum << endl;
      return ans;
    }
  };
} // namespace T689
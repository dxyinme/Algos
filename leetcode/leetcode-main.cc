#include <iostream>
#include "leetcode/inc/1923.hpp"

int main()
{
  leetcode::T1923::Solution s;
  auto vec = vector<vector<int>>{
      {0, 1, 2, 3, 4},
      {2, 3, 4},
      {4, 0, 1, 2, 3}};
  cout << s.longestCommonSubpath(5, vec) << endl;
}
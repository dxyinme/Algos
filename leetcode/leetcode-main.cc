#include <iostream>
#include "leetcode/inc/1923.hpp"
#include "leetcode/inc/1368.hpp"

int main()
{
  leetcode::T1368::Solution s;
  auto vec = vector<vector<int>>{
      {1, 1, 1, 1},
      {2, 2, 2, 2},
      {1, 1, 1, 1},
      {2, 2, 2, 2}};

  auto vec2 = vector<vector<int>>{
      {1, 1, 3},
      {3, 2, 2},
      {1, 1, 4},
  };

  auto vec3 = vector<vector<int>>{
      {1, 2},
      {4, 3},
  };

  auto vec4 = vector<vector<int>>{
      {2, 2, 2},
      {2, 2, 2},
  };
  cout << s.minCost(vec) << endl;
}
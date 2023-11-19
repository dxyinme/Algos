#include <iostream>

using namespace std;

#include "leetcode/helper/helper.h"
#include "leetcode/inc/1766.hpp"
#include "leetcode/inc/87.hpp"
#include "leetcode/inc/85.hpp"
#include "leetcode/inc/715.hpp"
#include "leetcode/inc/2736.hpp"
#include "leetcode/inc/2432.hpp"
#include "leetcode/inc/689.hpp"

int main()
{
    leetcode::T689::Solution s;
    vector<int> n{1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;
    lchelper::print1(s.maxSumOfThreeSubarrays(n, k));
    vector<int> n1{1, 2, 1, 2, 1, 2, 1, 2, 1};
    int k1 = 2;
    lchelper::print1(s.maxSumOfThreeSubarrays(n1, k1));
    vector<int> n2{4, 3, 2, 1};
    int k2 = 1;
    lchelper::print1(s.maxSumOfThreeSubarrays(n2, k2));
    return 0;
}
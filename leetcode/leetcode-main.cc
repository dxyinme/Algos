#include <iostream>
#include "leetcode/inc/1923.hpp"
#include "leetcode/inc/1368.hpp"
#include "leetcode/inc/44.hpp"

int main()
{
    leetcode::T44::Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("cb", "?a") << endl;
    cout << s.isMatch("adceb", "*a*b") << endl;
    cout << s.isMatch("", "*****") << endl;
    return 0;
}
#include <iostream>
#include "leetcode/inc/1923.hpp"
#include "leetcode/inc/1368.hpp"
#include "leetcode/inc/44.hpp"
#include "leetcode/inc/39.hpp"
#include "leetcode/inc/1766.hpp"
#include "leetcode/inc/715.hpp"

#include "leetcode/helper/helper.h"

int main()
{
    enum OPTYPE
    {
        addRange,
        removeRange,
        queryRange,
    };
    leetcode::T715::RangeModule rangeModule;

    vector<tuple<OPTYPE, int, int>> input1{
        {addRange, 10, 20},
        {removeRange, 14, 16},
        {queryRange, 10, 14},
        {queryRange, 13, 15},
        {queryRange, 16, 17},
    };
    for (auto input : input1)
    {
        switch (get<0>(input))
        {
        case addRange:
            rangeModule.addRange(get<1>(input), get<2>(input));
            break;
        case removeRange:
            rangeModule.removeRange(get<1>(input), get<2>(input));
            break;
        case queryRange:
            cout << rangeModule.queryRange(get<1>(input), get<2>(input)) << "\n";
            break;
        }
    }
    return 0;
}
// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2272 lang=cpp
 * @lcpr version=30204
 *
 * [2272] 最大波动的子字符串
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int largestVariance(string s)
    {
        int ans = 0;
        for (char a = 'a'; a <= 'z'; a++)
        {
            for (char b = 'a'; b <= 'z'; b++)
            {
                if (a == b)
                    continue;

                int f = 0, g = -1e6;
                for (auto &nowChar : s)
                {
                    if (nowChar != a && nowChar != b)
                        continue;

                    if (nowChar == a)
                        f++, g++;
                    else
                        g = max(f, g) - 1, f = 0;

                    ans = max(ans, g);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=largestVariance
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "aababbb"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n
// @lcpr case=end

 */

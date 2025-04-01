/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 * @lcpr version=30204
 *
 * [2140] 解决智力问题
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
#define ll long long
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        // [skip, solved]
        vector<vector<ll>> dp(n, vector<ll>(2));
        dp[n - 1][1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i)
        {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
            dp[i][1] = questions[i][0];
            if (i + questions[i][1] < n)
                dp[i][1] += dp[i + questions[i][1]][0];
        }
        return max(dp[0][0], dp[0][1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,2],[4,3],[4,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3],[4,4],[5,5]]\n
// @lcpr case=end

 */

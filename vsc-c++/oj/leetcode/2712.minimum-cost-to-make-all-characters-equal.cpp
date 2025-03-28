/*
 * @lc app=leetcode.cn id=2712 lang=cpp
 * @lcpr version=30204
 *
 * [2712] 使所有字符相等的最小成本
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
    long long minimumCost(string s)
    {
        int n = s.length();
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = s[i] - '0';

        vector<vector<ll>> dppre(n, vector<ll>(2));
        dppre[0][v[0] ^ 1] = 1;
        for (int i = 1; i < n; i++)
        {
            dppre[i] = dppre[i - 1];
            dppre[i][v[i] ^ 1] += v[i] == v[i - 1] ? 1 : (i << 1) + 1;
        }

        vector<vector<ll>> dpsuf(n, vector<ll>(2));
        dpsuf[n - 1][v[n - 1] ^ 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            dpsuf[i] = dpsuf[i + 1];
            dpsuf[i][v[i] ^ 1] += v[i] == v[i + 1] ? 1 : (n << 1) - (i << 1) - 1;
        }

        ll res = LONG_LONG_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, min(dppre[i][0] + dpsuf[i][0], dppre[i][1] + dpsuf[i][1]));
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "0011"\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n
// @lcpr case=end

 */

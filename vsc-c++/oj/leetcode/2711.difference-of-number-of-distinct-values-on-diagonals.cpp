// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2711 lang=cpp
 * @lcpr version=30204
 *
 * [2711] 对角线上不同值的数量差
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        auto in = [&](int x, int y) -> bool
        {
            return x >= 0 && y >= 0 && x < m && y < n;
        };

        auto add = [&](vector<int> &sum, int l, int r, int val) -> void
        {
            if (l >= sum.size())
                return;
            sum[l] += val;
            sum[r] -= val;
        };

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, set<int>> mp;
            int x = 0, y = i;
            while (in(x, y))
            {
                mp[grid[x][y]].insert(x);
                x++, y++;
            }

            vector<int> nowansSum(x + 10);

            for (auto &[_, s] : mp)
            {
                if (s.size() == 1)
                {
                    int tmp = *s.begin();
                    add(nowansSum, 0, tmp, -1);
                    add(nowansSum, tmp + 1, x, 1);
                }
                else
                {
                    int l = *s.begin(), r = *s.rbegin();
                    add(nowansSum, 0, l + 1, -1);
                    add(nowansSum, r, x, 1);
                }
            }

            for (int j = 1; j < x; j++)
                nowansSum[j] += nowansSum[j - 1];

            for (int x = 0, y = i; in(x, y); x++, y++)
            {
                ans[x][y] = abs(nowansSum[x]);
            }
        }

        for (int i = 1; i < m; i++)
        {
            unordered_map<int, set<int>> mp;
            int x = i, y = 0;
            while (in(x, y))
            {
                mp[grid[x][y]].insert(y);
                x++, y++;
            }

            vector<int> nowansSum(y + 10);
            for (auto &[_, s] : mp)
            {
                if (s.size() == 1)
                {
                    int tmp = *s.begin();
                    cout << i << ' ' << tmp << ' ' << x << '\n';
                    add(nowansSum, 0, tmp, -1);
                    add(nowansSum, tmp + 1, y, 1);
                }
                else
                {
                    int l = *s.begin(), r = *s.rbegin();
                    add(nowansSum, 0, l + 1, -1);
                    add(nowansSum, r, y, 1);
                }
            }

            for (int j = 1; j < y; j++)
                nowansSum[j] += nowansSum[j - 1];

            for (int x = i, y = 0; in(x, y); x++, y++)
                ans[x][y] = abs(nowansSum[y]);
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=differenceOfDistinctValues
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,2,3],[3,1,5],[3,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

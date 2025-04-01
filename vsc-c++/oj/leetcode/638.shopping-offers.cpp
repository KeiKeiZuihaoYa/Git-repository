// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=638 lang=cpp
 * @lcpr version=30204
 *
 * [638] 大礼包
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
    int n;
    unordered_map<int, int> memo;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs)
    {
        n = price.size();
        memo.clear();

        vector<vector<int>> filtspe;
        for (auto &vec : special)
        {
            int nowsum = 0;
            for (int i = 0; i < n; ++i)
                nowsum += vec[i] * price[i];

            if (nowsum <= vec[n])
                continue;
            filtspe.push_back(vec);
        }

        int currneeds = 0;
        for (int i = 0; i < n; i++)
        {
            currneeds |= (needs[i] << (i << 2));
        }

        return dfs(price, filtspe, currneeds);
    }

    int dfs(vector<int> &price, vector<vector<int>> &spec, int currneeds)
    {
        if (memo.count(currneeds))
            return memo[currneeds];

        int currBestPric = 0;

        for (int i = 0; i < n; i++)
        {
            // 掩码
            int nowneed = (currneeds >> (i << 2)) & 15;
            currBestPric += nowneed * price[i];
        }

        for (auto &vec : spec)
        {
            int currpric = 0, flag = 0, nxtneed = 0;
            for (int i = 0; i < n; i++)
            {
                int nowneed = (currneeds >> (i << 2)) & 15;
                if (vec[i] > nowneed)
                {
                    flag = 1;
                    break;
                }
                nxtneed |= ((nowneed - vec[i]) << (i << 2));
            }
            if (flag)
                continue;

            currBestPric =
                min(currBestPric, dfs(price, spec, nxtneed) + vec[n]);
        }

        return memo[currneeds] = currBestPric;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,5]\n[[3,0,5],[1,2,10]]\n[3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[[1,1,0,4],[2,2,1,9]]\n[1,2,1]\n
// @lcpr case=end

 */

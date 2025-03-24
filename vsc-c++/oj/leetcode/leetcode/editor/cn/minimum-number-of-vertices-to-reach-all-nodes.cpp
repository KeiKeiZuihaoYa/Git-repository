/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 * @lcpr version=30104
 *
 * [1557] 可以到达所有点的最少点数目
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> v(n), res;
        for(auto &vec : edges)
            v[vec[0]]++;
        for (int i = 0; i < n; i++)
            if(!v[i])
                res.push_back(i);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[2,5],[3,4],[4,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[2,1],[3,1],[1,4],[2,4]]\n
// @lcpr case=end

 */

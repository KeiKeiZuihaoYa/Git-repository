/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 * @lcpr version=30204
 *
 * [2874] 有序三元组中的最大值 II
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
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        pre[0] = nums[0], suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], nums[i]);

        for (int i = n - 2; i >= 0; --i)
            suf[i] = max(suf[i + 1], nums[i]);

        long long ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, 1LL * (pre[i - 1] - nums[i]) * suf[i + 1]);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [12,6,1,2,7]\n
// @lcpr case=end


/*
// @lcpr case=start
// [6,11,12,12,7,9,2,11,12,4,19,14,16,8,16]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,4,19]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

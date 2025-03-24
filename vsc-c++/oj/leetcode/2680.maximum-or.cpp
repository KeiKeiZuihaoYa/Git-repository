// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 * @lcpr version=30204
 *
 * [2680] 最大或值
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
    long long maximumOr(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
            return 1LL * nums[0] << k;

        vector<ll> pre(n), suf(n);
        pre[0] = nums[0], suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] | nums[i];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] | nums[i];

        ll maxx = 0;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            v[i] = nums[i];
        while (k)
        {
            int nowMult = -1;
            ll nowMultMax = -1;
            for (int i = 0; i < n; i++)
            {
                ll t = v[i] << k;
                t |= (i == 0 ? 0 : pre[i - 1]) | (i == n - 1 ? 0 : suf[i + 1]);
                //  cout << i << ' ' << t << ' ' << nowMultMax << '\n'
                //  << pre[i] << ' ' << suf[i] << '\n';
                if (t > nowMultMax)
                    nowMultMax = t, nowMult = i;
                else if (t == nowMultMax)
                {
                    if (v[i] > v[nowMult])
                        nowMultMax = t, nowMult = i;
                }
            }

            // cout << nowMult << '\n';

            v[nowMult] <<= k;
            maxx = max(maxx, nowMultMax);
            // for (int i = nowMult; i < n; i++)
            //     pre[i] = (i == 0 ? 0 : pre[i - 1]) | v[i];
            // for (int i = nowMult; i >= 0; i--)
            //     suf[i] = (i == n - 1 ? 0 : suf[i + 1]) | v[i];
            k = 0;
        }
        return maxx;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximumOr
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [12,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [8,1,2]\n2\n
// @lcpr case=end

 */

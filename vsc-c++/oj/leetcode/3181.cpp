#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int maxTotalReward(vector<int> &rewardValues)
{
    sort(rewardValues.begin(), rewardValues.end());
    rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()),
                       rewardValues.end());

    int rs = rewardValues.size(), res = 0;
    const int maxx = rewardValues.back() * 2 - 1;
    bitset<100000> dp, tmp;
    dp[0] = 1;

    if (rs >= 2 && rewardValues[rs - 2] == rewardValues[rs - 1] - 1)
        return maxx;

    for (auto i : rewardValues)
    {
        for (int j = 0; j <= i; j++)
            tmp[j] = dp[j];
        dp |= tmp << i;
    }

    for (int i = maxx; i >= 0; i--)
        if (dp[i])
        {
            res = i;
            break;
        }

    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> v = {5, 8, 9, 12};
    cout << maxTotalReward(v) << endl;

    return 0;
}
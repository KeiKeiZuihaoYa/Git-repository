#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> &candyType)
{
    int n = candyType.size();
    unordered_set<int> candy_set;
    for (auto i : candyType)
        candy_set.insert(i);

    return min(n >> 1, (int)candy_set.size());
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}
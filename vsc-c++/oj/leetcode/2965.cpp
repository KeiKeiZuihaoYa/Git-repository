#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    unordered_map<int, int> mp; // number -> cnt

    for (int i = 1; i <= n * m; i++)
        mp[i]++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (--mp[grid[i][j]] == 0)
                mp.erase(grid[i][j]);

    vector<int> res(2);
    for (auto &[a, b] : mp)
        if (b == -1)
            res[0] = a;
        else
            res[1] = a;

    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}
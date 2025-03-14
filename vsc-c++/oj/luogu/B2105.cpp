#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> b(m, vector<int>(k));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int sum = 0;
            for (int l = 0; l < m; l++)
                sum += a[i][l] * b[l][j];
            cout << sum << " ";
        }
        cout << "\n";
    }

    return 0;
}
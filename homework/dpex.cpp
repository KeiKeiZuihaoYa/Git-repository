#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf = 0x3f3f3f3f << 1;

class liancheng
{
public:
    void main()
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (auto &i : a)
            cin >> i;

        for (int r = 1; r < n; r++)
            for (int i = 1; i <= n - r; i++)
            {
                int j = i + r;
                dp[i][j] = inf;

                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }

        cout << dp[1][n] << endl;
    }
};

class LCS
{
public:
    void main()
    {
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        cout << dp[n][m] << endl;
    }
};

class bag01
{
public:
    int n, m;
    void main()
    {
        cin >> n >> m;
        vector<int> v(n + 1), w(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i] >> w[i];

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)     // item
            for (int j = 0; j <= m; j++) // cap
                if (j >= w[i])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                else
                    dp[i][j] = dp[i - 1][j];

        cout << dp[n][m] << endl;
    }
};

class bitSearchTree
{
public:
    void main()
    {
        int n;
        cin >> n;
        vector<double> a(n), p(n);
        vector<vector<double>> c(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i] = c[i][i] = a[i];
            p[i] += (i == 0 ? 0 : p[i - 1]);
        }

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0, j; i <= n - l; i++)
            {
                j = i + l - 1;
                c[i][j] = 9e18;
                double tt = p[j] - (i == 0 ? 0 : p[i - 1]), t = tt;

                for (int k = i; k <= j; k++, t = tt)
                {
                    if (i != k)
                        t += c[i][k - 1];
                    if (j != k)
                        t += c[k + 1][j];
                    c[i][j] = min(c[i][j], t);
                }
            }
        }

        cout << fixed << setprecision(3) << c[0][n - 1] << endl;
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int op;
    cin >> op;

    switch (op)
    {
    case 1:
    {
        liancheng lc;
        lc.main();
        break;
    }
    case 2:
    {
        LCS lcs;
        lcs.main();
        break;
    }
    case 3:
    {
        bag01 b;
        b.main();
        break;
    }
    case 4:
    {
        bitSearchTree bst;
        bst.main();
        break;
    }
    }

    return 0;
}
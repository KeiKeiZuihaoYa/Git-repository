#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, tmp2, mark = 1;

        cin >> n;
        cin.ignore();
        double tmp1 = pow(n, 0.5);
        string s;
        getline(cin, s);
        if (tmp1 - (ll)tmp1 == 0)
        {
            int lineTot = (int)tmp1; // 一行的个数

            vector<string> v;
            for (int i = 0; i < s.length(); i += lineTot)
                v.push_back(s.substr(i, lineTot));

            for (int i = 0; i < v.size(); i++)
            {
                if (i == 0 || i == v.size() - 1) // 是否是第一行或最后一行
                {
                    for (auto j : v[i])
                        if (j == '0') // false
                            goto FALSE;
                }
                else
                {
                    if (v[i].front() != '1' || v[i].back() != '1')
                        goto FALSE;

                    for (int j = 1; j < v[i].length() - 1; j++) // 中间的部分
                        if (v[i][j] == '0')
                            goto FALSE;
                }
            }
            cout << "Yes" << '\n';
        }
        else
        FALSE:
            cout << "No" << '\n';
    }

    return 0;
}
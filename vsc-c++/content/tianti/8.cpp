#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        int maxx = *max_element(v.begin(), v.end());
        int res = -1;

        for (int i = 0; i < n; i++)
        {
            if (v[i] != maxx)
                continue;
            bool flag1 = false, flag2 = false;
            flag1 = i != 0 && v[i - 1] < v[i];
            flag2 = i != n - 1 && v[i + 1] < v[i];
            if (flag1 || flag2)
            {
                res = i + 1;
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
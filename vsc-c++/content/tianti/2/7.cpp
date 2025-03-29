#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    k--;

    int cnt = 0, i = 0;
    while (i < n)
    {
        if (!v[i] || v[i] < v[k])
            break;
        else
            i++, cnt++;
    }

    cout << cnt;

    return 0;
}
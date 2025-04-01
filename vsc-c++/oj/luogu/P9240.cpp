#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n;
vector<P> v;

bool ch(int x)
{
    for (auto &[i, j] : v)
    {
        if (i / x < j)
            return false;
    }
    return true;
}

bool ch2(int x)
{
    for (auto &[i, j] : v)
    {
        if (i / x != j)
            return false;
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i.first >> i.second;

    ll l = 1, r = 1e9 + 10, mid, res;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (ch(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    ll minn = res;
    while (minn > 1)
    {
        if (ch2(minn - 1))
            --minn;
        else
            break;
    }

    cout << minn << ' ' << res;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n, m; // 2 | 1

bool ch(ll now)
{
    bool flag = true;
    ll x = 0, t1 = n, t2 = m;
    ll tmp = now / 2;
    while (x < now)
    {
        if (x + 1 == now)
        {
            t2 -= now;
            ++x;
        }
        else
        {
            t1 -= tmp;
            if (now % 2)
                t2 -= 2;
            x += 2;
        }

        if (t1 < 0)
        {
            t1 *= -1;
            t2 -= (t1 * 4);
            t1 = 0;
        }

        if (t2 < 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    n = 7385137888721;
    m = 10470245;

    ll l = 1,
       r = 2e15, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (ch(mid + (mid % 2)))
            res = max(res, mid), l = mid + 1;
        else
            r = mid - 1;
    }

    if (ch(res + 1))
        res++;

    cout << res;

    return 0;
}
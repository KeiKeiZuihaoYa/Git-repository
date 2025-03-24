#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    int ans = 0;
    ans += (x >> 1) * y;
    ans += (x % 2) * (y >> 1);
    cout << ans;

    return 0;
}
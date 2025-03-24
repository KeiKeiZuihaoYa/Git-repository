#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    int res = 0;
    res += (a / 2) * b;
    res += (a % 2) * (b >> 1);
    cout << res;

    return 0;
}